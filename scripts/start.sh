#!/bin/bash

cd `dirname $0`
cd ..

echo "[STOP EXISTING NODES (IF ANY), TO AVOID CONFLICT]"
./scripts/stop.sh

source /opt/ros/humble/setup.bash
source ./install/setup.bash
export FASTRTPS_DEFAULT_PROFILES_FILE=/opt/booster/BoosterRos2/fastdds_profile_udp_only.xml

echo "[START ROBOCUP NODES]"
echo "[START VISION]"
nohup ros2 launch vision launch.py > vision.log 2>&1 &
echo "[START BRAIN]"
brain_args=("$@")
if [[ ! " $* " =~ "use_custom_walk:=" ]]; then
    brain_args+=("use_custom_walk:=false")
fi
if [[ ! " $* " =~ "use_start_pose:=" ]]; then
    brain_args+=("use_start_pose:=false")
fi
nohup ros2 launch brain launch.py "${brain_args[@]}" > brain.log 2>&1 &
echo "[START GAME_CONTROLLER]"
nohup ros2 launch game_controller launch.py > game_controller.log 2>&1 &
echo "[DONE]"
