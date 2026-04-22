# motion_control

This package keeps the RoboCup demo project's custom motion glue inside
`Robocup_demo_zyfy`, while still linking to the robot's original firmware
SDK from wherever it is installed on that machine.

## What is included

- `motion_control_node`: a ROS 2 node that owns the project-local RL walking command
  topics and publishes Booster `LowCmd` through `sdk_release`.
- `models/walk/T1.onnx` 

The node starts disabled and currently holds a safe stand pose. The next step is
to connect the ONNX observation/action mapping, because the T1 model expects its
exact 51-input observation vector and 14-output action vector.

## SDK path

Do not copy `sdk_release` into this package. Point CMake at the existing SDK:

```bash
export BOOSTER_SDK_ROOT=/path/on/this/machine/to/sdk_release/sdk_release
```

On your personal computer that might be a local development path. On the robot it
can be the original SDK path that came with the robot.

## Build

From `Robocup_demo_zyfy`:

```bash
source /opt/ros/humble/setup.bash
export BOOSTER_SDK_ROOT=/path/to/sdk_release/sdk_release
colcon build --symlink-install --base-paths src --packages-select brain motion_control
```

## Run

```bash
source install/setup.bash
ros2 launch motion_control motion_control.launch.py network_interface:=<robot_network_interface>
```

When using the normal game start script, `motion_control_node` is launched and
enabled automatically before `brain` starts:

```bash
MOTION_CONTROL_NETWORK_INTERFACE=<robot_network_interface> ./scripts/start.sh
```

Check what happened with:

```bash
./scripts/motion_control_status.sh
```

A plain-text startup timeline is also written to:

```text
motion_control_events.txt
```

Set `MOTION_CONTROL_AUTO_CHANGE_MODE=true` only when you want startup to request
`RobotMode::kCustom` through `B1LocoClient`.

The node will not publish low-level commands until enabled. This also tells the
brain to route velocity commands to `motion_control_node` instead of the old
Booster walking API:

```bash
./scripts/enable_motion_control.sh
```

Disable it again with:

```bash
./scripts/disable_motion_control.sh
```

Velocity command topic:

```bash
ros2 topic pub /booster_soccer/rl_motion/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.1, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.0}}"
```

Use `auto_change_mode:=true` only when you are ready for the node to request
`RobotMode::kCustom` through `B1LocoClient`.
