# motion_control

This package keeps the RoboCup demo project's custom motion glue inside
`Robocup_demo_zyfy`, while still linking to the robot's original firmware
SDK from wherever it is installed on that machine.

## What is included

- `motion_control_node`: a ROS 2 node that owns the project-local RL walking command
  topics and publishes Booster `LowCmd` through `sdk_release`.
- `models/walk/walk.onnx`

The node subscribes to Booster `rt/low_state`, builds the policy observation,
runs `walk.onnx`, and publishes Booster `LowCmd`.
The bundled walk model is checked as a 51-input, 14-output ONNX policy.
This matches B-Human's `Config/Robots/Default/T1/rlWalkingEngine.cfg` contract
for `BoosterWalk/T1.onnx`: 13 controlled joints plus one frequency output.

## SDK path

Do not copy `sdk_release` into this package. Point CMake at the existing SDK:

```bash
export BOOSTER_SDK_ROOT=/path/on/this/machine/to/sdk_release
```

On your personal computer that might be a local development path. On the robot it
can be the original SDK path that came with the robot.

## Build

From `Robocup_demo_zyfy`:

```bash
source /opt/ros/humble/setup.bash
export BOOSTER_SDK_ROOT=/path/to/sdk_release
colcon build --symlink-install --base-paths src --packages-select brain motion_control
```

## Run

```bash
source install/setup.bash
ros2 launch motion_control motion_control.launch.py network_interface:=<robot_network_interface>
```

When using the normal game start script, `motion_control_node` is launched before
`brain` starts. The brain always routes walking commands to the custom policy
topic `/booster_soccer/rl_motion/cmd_vel`; there is no fallback velocity route
through the old Booster walking API.

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

Startup requests `RobotMode::kCustom` through `B1LocoClient` by default so the
custom policy owns walking. Set `MOTION_CONTROL_AUTO_CHANGE_MODE=false` only for
debug sessions where you do not want the launch script to change robot mode.

Velocity command topic:

```bash
ros2 topic pub /booster_soccer/rl_motion/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.1, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.0}}"
```

Use `auto_change_mode:=false` only when you want to launch the node without
requesting `RobotMode::kCustom`.

## Policy mapping

Default observation layout:

```text
projected_gravity(3), gyro(3), cmd_vel(x,y,yaw), walk_cycle(cos,sin),
joint_pos_error(13), joint_vel*0.1(13), previous_requested_offset(13), raw_frequency(1)
```

The 14 policy outputs are interpreted as 13 joint target offsets and one learned
frequency value. The default 13 controlled joints are B-Human's T1
`useWaist = true` order: waist yaw, left leg, right leg.

```text
10,11,12,13,14,15,16,17,18,19,20,21,22
```

If your training used a different joint order, launch with:

```bash
ros2 launch motion_control motion_control.launch.py controlled_joint_indices:="..."
```

For first hardware tests, reduce output size with:

```bash
ros2 launch motion_control motion_control.launch.py action_scale:=0.05 start_enabled:=false
```
