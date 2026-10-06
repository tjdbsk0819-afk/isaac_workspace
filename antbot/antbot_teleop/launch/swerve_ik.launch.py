#!/usr/bin/env python3
"""Launch the Twist-to-JointState Swerve IK adapter."""

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='antbot_teleop',
            executable='swerve_ik_node',
            name='swerve_ik',
            output='screen',
        ),
    ])
