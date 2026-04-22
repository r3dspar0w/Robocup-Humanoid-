#!/bin/bash

cd "$(dirname "$0")"
cd ..

source /opt/ros/humble/setup.bash
source install/setup.bash

echo "== ROS nodes =="
ros2 node list | grep -E "motion_control_node|brain|vision|game_controller" || true

echo
echo "== Event timeline =="
tail -n 80 motion_control_events.txt 2>/dev/null || echo "motion_control_events.txt not found"

echo
echo "== Motion-control topics/services =="
ros2 topic list | grep "/booster_soccer/rl_motion" || true
ros2 service list | grep "/booster_soccer/rl_motion" || true

echo
echo "== Last enable value =="
timeout 2 ros2 topic echo --once --qos-reliability reliable --qos-durability transient_local \
  /booster_soccer/rl_motion/enable std_msgs/msg/Bool || true

echo
echo "== Last state value =="
timeout 2 ros2 topic echo --once /booster_soccer/rl_motion/state std_msgs/msg/String || true

echo
echo "== motion_control.log tail =="
tail -n 80 motion_control.log 2>/dev/null || echo "motion_control.log not found"

echo
echo "== brain.log motion-control tail =="
grep -i "motion_control\|RobotClient/setVelocity" brain.log 2>/dev/null | tail -n 80 || echo "brain.log not found or no motion-control lines yet"
