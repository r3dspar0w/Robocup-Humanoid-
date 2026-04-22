#!/bin/bash

cd "$(dirname "$0")"
cd ..

source /opt/ros/humble/setup.bash
source install/setup.bash

echo "[DISABLE MOTION_CONTROL]"
echo "$(date '+%Y-%m-%d %H:%M:%S') [DISABLE] motion_control requested" >> motion_control_events.txt
ros2 topic pub --once --qos-reliability reliable --qos-durability transient_local \
  /booster_soccer/rl_motion/enable std_msgs/msg/Bool "{data: false}"
