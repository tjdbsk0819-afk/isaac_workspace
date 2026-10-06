#!/usr/bin/env python3
"""Convert chassis Twist commands into Antbot swerve joint commands."""

from __future__ import annotations

import math
from typing import Sequence

from geometry_msgs.msg import Twist
import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy._rclpy_pybind11 import RCLError
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import JointState


STEERING_JOINT_NAMES = (
    "steering_front_left_joint",
    "steering_front_right_joint",
    "steering_rear_left_joint",
    "steering_rear_right_joint",
)
WHEEL_JOINT_NAMES = (
    "wheel_front_left_joint",
    "wheel_front_right_joint",
    "wheel_rear_left_joint",
    "wheel_rear_right_joint",
)


def normalize_angle(angle: float) -> float:
    """Wrap an angle to [-pi, pi), matching the C++ implementation."""

    remainder = math.fmod(angle + math.pi, 2.0 * math.pi)
    if remainder < 0.0:
        remainder += 2.0 * math.pi
    return remainder - math.pi


def angular_distance(source: float, target: float) -> float:
    """Return the absolute shortest angular distance between two angles."""

    return abs(normalize_angle(target - source))


def angle_within_limits(angle: float, lower: float, upper: float) -> bool:
    """Match SwerveMotionControl's wrap-aware steering limit check."""

    normalized = normalize_angle(angle)
    if lower <= upper:
        return lower <= normalized <= upper
    return normalized >= lower or normalized <= upper


def solve_module(
    vx: float,
    vy: float,
    wz: float,
    module_x: float,
    module_y: float,
    steering_to_wheel_offset: float,
    module_angle_offset: float,
    current_angle: float,
    wheel_radius: float,
    steering_lower: float,
    steering_upper: float,
    non_coaxial_ik_iterations: int,
    stopped: bool,
) -> tuple[float, float]:
    """Return one module target using SwerveMotionControl's IK equations."""

    pivot_velocity_x = vx - wz * module_y
    pivot_velocity_y = vy + wz * module_x
    steering_angle_robot = math.atan2(
        pivot_velocity_y,
        pivot_velocity_x + 1.0e-9,
    )

    for _ in range(non_coaxial_ik_iterations):
        offset_velocity_x = (
            -wz * steering_to_wheel_offset * math.cos(steering_angle_robot)
        )
        offset_velocity_y = (
            wz * steering_to_wheel_offset * math.sin(steering_angle_robot)
        )
        contact_velocity_x = pivot_velocity_x + offset_velocity_x
        contact_velocity_y = pivot_velocity_y + offset_velocity_y
        steering_angle_robot = math.atan2(
            contact_velocity_y,
            contact_velocity_x + 1.0e-9,
        )

    final_contact_velocity_x = pivot_velocity_x + (
        -wz * steering_to_wheel_offset * math.cos(steering_angle_robot)
    )
    final_contact_velocity_y = pivot_velocity_y + (
        wz * steering_to_wheel_offset * math.sin(steering_angle_robot)
    )
    target_wheel_speed_mps = math.hypot(
        final_contact_velocity_x,
        final_contact_velocity_y,
    )

    primary_angle = normalize_angle(steering_angle_robot - module_angle_offset)
    primary_wheel_speed = target_wheel_speed_mps / wheel_radius

    if stopped:
        return current_angle, 0.0

    flipped_angle = normalize_angle(primary_angle + math.pi)
    flipped_wheel_speed = -primary_wheel_speed
    primary_valid = angle_within_limits(
        primary_angle,
        steering_lower,
        steering_upper,
    )
    flipped_valid = angle_within_limits(
        flipped_angle,
        steering_lower,
        steering_upper,
    )

    if primary_valid and flipped_valid:
        if angular_distance(current_angle, primary_angle) <= angular_distance(
            current_angle,
            flipped_angle,
        ):
            return primary_angle, primary_wheel_speed
        return flipped_angle, flipped_wheel_speed
    if primary_valid:
        return primary_angle, primary_wheel_speed
    if flipped_valid:
        return flipped_angle, flipped_wheel_speed

    lower_difference = angular_distance(primary_angle, steering_lower)
    upper_difference = angular_distance(primary_angle, steering_upper)
    clamp_epsilon = 1.0e-6
    if lower_difference <= upper_difference:
        constrained_angle = steering_lower + clamp_epsilon
    else:
        constrained_angle = steering_upper - clamp_epsilon

    constrained_angle_robot = constrained_angle + module_angle_offset
    delta_angle = normalize_angle(primary_angle - constrained_angle_robot)
    projected_wheel_speed = (
        target_wheel_speed_mps * math.cos(delta_angle) / wheel_radius
    )
    return constrained_angle, projected_wheel_speed


def solve_swerve_ik(
    vx: float,
    vy: float,
    wz: float,
    module_x_offsets: Sequence[float],
    module_y_offsets: Sequence[float],
    steering_to_wheel_offsets: Sequence[float],
    module_angle_offsets: Sequence[float],
    current_angles: Sequence[float],
    wheel_radius: float,
    steering_limits_lower: Sequence[float],
    steering_limits_upper: Sequence[float],
    wheel_speed_limits_lower: Sequence[float],
    wheel_speed_limits_upper: Sequence[float],
    non_coaxial_ik_iterations: int,
    velocity_deadband: float,
    enabled_wheel_saturation_scaling: bool,
) -> tuple[list[float], list[float]]:
    """Compute steering targets and wheel velocities like SwerveMotionControl."""

    if wheel_radius <= 0.0:
        raise ValueError("wheel_radius must be positive")

    module_parameters = (
        module_x_offsets,
        module_y_offsets,
        steering_to_wheel_offsets,
        module_angle_offsets,
        current_angles,
        steering_limits_lower,
        steering_limits_upper,
        wheel_speed_limits_lower,
        wheel_speed_limits_upper,
    )
    if any(len(values) != 4 for values in module_parameters):
        raise ValueError("all module parameter lists must contain four values")
    if non_coaxial_ik_iterations < 0:
        raise ValueError("non_coaxial_ik_iterations must not be negative")
    if velocity_deadband < 0.0:
        raise ValueError("velocity_deadband must not be negative")
    if any(
        lower > upper
        for lower, upper in zip(
            wheel_speed_limits_lower,
            wheel_speed_limits_upper,
            strict=True,
        )
    ):
        raise ValueError("wheel speed lower limits must not exceed upper limits")

    stopped = (
        abs(vx) < velocity_deadband
        and abs(vy) < velocity_deadband
        and abs(wz) < velocity_deadband
    )

    steering_targets: list[float] = []
    wheel_velocities: list[float] = []
    for module_index, (module_x, module_y, current_angle) in enumerate(
        zip(
            module_x_offsets,
            module_y_offsets,
            current_angles,
            strict=True,
        )
    ):
        steering, wheel_speed = solve_module(
            vx,
            vy,
            wz,
            module_x,
            module_y,
            steering_to_wheel_offsets[module_index],
            module_angle_offsets[module_index],
            current_angle,
            wheel_radius,
            steering_limits_lower[module_index],
            steering_limits_upper[module_index],
            non_coaxial_ik_iterations,
            stopped,
        )
        steering_targets.append(steering)
        wheel_velocities.append(wheel_speed)

    if enabled_wheel_saturation_scaling:
        scale = 1.0
        for speed, lower, upper in zip(
            wheel_velocities,
            wheel_speed_limits_lower,
            wheel_speed_limits_upper,
            strict=True,
        ):
            if speed > upper and speed > 0.0:
                scale = min(scale, upper / speed)
            elif speed < lower and speed < 0.0:
                scale = min(scale, lower / speed)
        wheel_velocities = [speed * scale for speed in wheel_velocities]

    wheel_velocities = [
        min(max(speed, lower), upper)
        for speed, lower, upper in zip(
            wheel_velocities,
            wheel_speed_limits_lower,
            wheel_speed_limits_upper,
            strict=True,
        )
    ]

    return steering_targets, wheel_velocities


class SwerveIkNode(Node):
    """Translate /cmd_vel into the JointState command consumed by Isaac Sim."""

    def __init__(self) -> None:
        super().__init__("swerve_ik")

        self.declare_parameter("cmd_vel_topic", "/cmd_vel")
        self.declare_parameter("joint_command_topic", "/joint_command")
        self.declare_parameter("joint_state_topic", "/joint_states")
        self.declare_parameter("publish_rate", 20.0)
        self.declare_parameter("command_timeout", 0.5)
        self.declare_parameter("wheel_radius", 0.103)
        self.declare_parameter(
            "module_x_offsets",
            [0.265, 0.265, -0.265, -0.265],
        )
        self.declare_parameter(
            "module_y_offsets",
            [0.256, -0.256, 0.256, -0.256],
        )
        self.declare_parameter(
            "steering_to_wheel_y_offsets",
            [0.0555, -0.0555, 0.0555, -0.0555],
        )
        self.declare_parameter("module_angle_offsets", [0.0] * 4)
        self.declare_parameter("module_steering_limit_lower", [-0.959] * 4)
        self.declare_parameter("module_steering_limit_upper", [0.959] * 4)
        self.declare_parameter("module_wheel_speed_limit_lower", [-50.0] * 4)
        self.declare_parameter("module_wheel_speed_limit_upper", [50.0] * 4)
        self.declare_parameter("non_coaxial_ik_iterations", 0)
        self.declare_parameter("velocity_deadband", 0.01)
        self.declare_parameter("enabled_wheel_saturation_scaling", True)

        self._module_x_offsets = list(
            self.get_parameter("module_x_offsets").value
        )
        self._module_y_offsets = list(
            self.get_parameter("module_y_offsets").value
        )
        self._steering_to_wheel_offsets = list(
            self.get_parameter("steering_to_wheel_y_offsets").value
        )
        self._module_angle_offsets = list(
            self.get_parameter("module_angle_offsets").value
        )
        self._steering_limits_lower = list(
            self.get_parameter("module_steering_limit_lower").value
        )
        self._steering_limits_upper = list(
            self.get_parameter("module_steering_limit_upper").value
        )
        self._wheel_speed_limits_lower = list(
            self.get_parameter("module_wheel_speed_limit_lower").value
        )
        self._wheel_speed_limits_upper = list(
            self.get_parameter("module_wheel_speed_limit_upper").value
        )
        module_parameters = (
            self._module_x_offsets,
            self._module_y_offsets,
            self._steering_to_wheel_offsets,
            self._module_angle_offsets,
            self._steering_limits_lower,
            self._steering_limits_upper,
            self._wheel_speed_limits_lower,
            self._wheel_speed_limits_upper,
        )
        if any(len(values) != 4 for values in module_parameters):
            raise ValueError("all module parameter lists need four values")

        self._wheel_radius = float(self.get_parameter("wheel_radius").value)
        self._non_coaxial_ik_iterations = int(
            self.get_parameter("non_coaxial_ik_iterations").value
        )
        self._velocity_deadband = float(
            self.get_parameter("velocity_deadband").value
        )
        self._enabled_wheel_saturation_scaling = bool(
            self.get_parameter("enabled_wheel_saturation_scaling").value
        )
        self._command_timeout = float(
            self.get_parameter("command_timeout").value
        )
        publish_rate = float(self.get_parameter("publish_rate").value)
        if publish_rate <= 0.0:
            raise ValueError("publish_rate must be positive")

        self._latest_twist = Twist()
        self._last_command_time = None
        self._current_steering = [0.0] * 4
        self._timed_out = False

        cmd_vel_topic = str(self.get_parameter("cmd_vel_topic").value)
        joint_command_topic = str(
            self.get_parameter("joint_command_topic").value
        )
        joint_state_topic = str(self.get_parameter("joint_state_topic").value)

        self._publisher = self.create_publisher(
            JointState,
            joint_command_topic,
            10,
        )
        self._cmd_vel_subscription = self.create_subscription(
            Twist,
            cmd_vel_topic,
            self._on_cmd_vel,
            10,
        )
        self._joint_state_subscription = self.create_subscription(
            JointState,
            joint_state_topic,
            self._on_joint_state,
            qos_profile_sensor_data,
        )
        self._timer = self.create_timer(1.0 / publish_rate, self._publish_command)

        self.get_logger().info(
            f"Swerve IK ready: {cmd_vel_topic} -> {joint_command_topic}"
        )

    def _on_cmd_vel(self, message: Twist) -> None:
        self._latest_twist = message
        self._last_command_time = self.get_clock().now()
        self._timed_out = False

    def _on_joint_state(self, message: JointState) -> None:
        indices = {name: index for index, name in enumerate(message.name)}
        for target_index, name in enumerate(STEERING_JOINT_NAMES):
            message_index = indices.get(name)
            if message_index is None or message_index >= len(message.position):
                continue
            value = float(message.position[message_index])
            if math.isfinite(value):
                self._current_steering[target_index] = value

    def _command_is_stale(self) -> bool:
        if self._last_command_time is None:
            return True
        elapsed = (self.get_clock().now() - self._last_command_time).nanoseconds
        return elapsed * 1.0e-9 > self._command_timeout

    def _publish_command(self) -> None:
        if self._command_is_stale():
            vx = vy = wz = 0.0
            if self._last_command_time is not None and not self._timed_out:
                self.get_logger().warning("cmd_vel timed out; stopping wheels")
                self._timed_out = True
        else:
            vx = float(self._latest_twist.linear.x)
            vy = float(self._latest_twist.linear.y)
            wz = float(self._latest_twist.angular.z)

        steering, wheel_velocities = solve_swerve_ik(
            vx,
            vy,
            wz,
            self._module_x_offsets,
            self._module_y_offsets,
            self._steering_to_wheel_offsets,
            self._module_angle_offsets,
            self._current_steering,
            self._wheel_radius,
            self._steering_limits_lower,
            self._steering_limits_upper,
            self._wheel_speed_limits_lower,
            self._wheel_speed_limits_upper,
            self._non_coaxial_ik_iterations,
            self._velocity_deadband,
            self._enabled_wheel_saturation_scaling,
        )
        self._publish_joint_state(steering, wheel_velocities)

    def _publish_joint_state(
        self,
        steering: Sequence[float],
        wheel_velocities: Sequence[float],
    ) -> None:
        message = JointState()
        message.header.stamp = self.get_clock().now().to_msg()
        message.name = list(STEERING_JOINT_NAMES + WHEEL_JOINT_NAMES)
        message.position = list(steering) + [0.0] * 4
        message.velocity = [0.0] * 4 + list(wheel_velocities)
        self._publisher.publish(message)

    def publish_stop(self) -> None:
        """Publish a final zero-wheel-speed command while holding steering."""

        self._publish_joint_state(self._current_steering, [0.0] * 4)


def main(args=None) -> None:
    rclpy.init(args=args)
    node = SwerveIkNode()
    try:
        rclpy.spin(node)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    except RCLError:
        if rclpy.ok():
            raise
    finally:
        if rclpy.ok():
            node.publish_stop()
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == "__main__":
    main()
