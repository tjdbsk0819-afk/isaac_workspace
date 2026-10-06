# Antbot Isaac ROS 2 Control Bridge

This package connects the existing `antbot_swerve_controller` to the Isaac Lab
runner without changing the runner's ROS topic contract.

## Data flow

```text
/joint_states -> IsaacTopicSystem::read() -> ros2_control state interfaces
/cmd_vel -> SwerveDriveController -> ros2_control command interfaces
ros2_control commands -> IsaacTopicSystem::write() -> /joint_command
```

The Isaac runner remains responsible for applying `/joint_command` to the GPU
articulation and publishing `/joint_states`.

## Temporary container build

The source is mounted at `/workspace`. Build and install products intentionally
live under `/tmp`, so recreating the container requires rebuilding them.

Install the small launch-time dependencies again after recreating the
container (they are intentionally not baked into the image):

```bash
docker exec -u root isaac-seo-yuna-isaac-lab-1 bash -lc \
  'apt-get update && apt-get install -y --no-install-recommends \
   ros-jazzy-xacro ros-jazzy-ros2launch ros-jazzy-robot-state-publisher'
```

```bash
source /opt/ros/jazzy/setup.bash
mkdir -p /tmp/antbot_control_ws/src
ln -sfn /workspace/antbot/antbot_swerve_controller \
  /tmp/antbot_control_ws/src/antbot_swerve_controller
ln -sfn /workspace/antbot/antbot_isaac_control \
  /tmp/antbot_control_ws/src/antbot_isaac_control
cd /tmp/antbot_control_ws
colcon build --symlink-install \
  --packages-select antbot_swerve_controller antbot_isaac_control
```

## Run

Start `run_antbot.py` first so `/joint_states` is available. In a second shell:

```bash
source /opt/ros/jazzy/setup.bash
source /tmp/antbot_control_ws/install/setup.bash
export RMW_IMPLEMENTATION=rmw_zenoh_cpp
export ROS_DOMAIN_ID=30
ros2 launch antbot_isaac_control antbot_isaac_control.launch.py
```

Do not run `swerve_ik_node.py` at the same time because both paths publish
`/joint_command`.
