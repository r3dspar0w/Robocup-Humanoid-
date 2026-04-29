#!/bin/bash

cd `dirname $0`
cd ..

echo "[STOP EXISTING NODES (IF ANY), TO AVOID CONFLICT]"
./scripts/stop.sh

source /opt/ros/humble/setup.bash
source ./install/setup.bash
export FASTRTPS_DEFAULT_PROFILES_FILE=/opt/booster/BoosterRos2/fastdds_profile_udp_only.xml

TEAM_ID=""
PLAYER_ID=""
for arg in "$@"; do
    case "$arg" in
        team_id:=*) TEAM_ID="${arg#team_id:=}" ;;
        player_id:=*) PLAYER_ID="${arg#player_id:=}" ;;
    esac
done
if [ -z "$TEAM_ID" ]; then
    TEAM_ID=$(grep -m1 "team_id:" src/brain/config/config.yaml | sed -E 's/.*team_id:[[:space:]]*([0-9]+).*/\1/')
fi
if [ -z "$PLAYER_ID" ]; then
    PLAYER_ID=$(grep -m1 "player_id:" src/brain/config/config.yaml | sed -E 's/.*player_id:[[:space:]]*([0-9]+).*/\1/')
fi
ROBOT_COMM_ARGS=()
if [ -n "$TEAM_ID" ]; then
    ROBOT_COMM_ARGS+=("team_id:=$TEAM_ID")
fi
if [ -n "$PLAYER_ID" ]; then
    ROBOT_COMM_ARGS+=("player_id:=$PLAYER_ID")
fi

echo "[START ROBOCUP NODES]"
echo "[START VISION]"
nohup ros2 launch vision launch.py > vision.log 2>&1 &
echo "[START BRAIN]"
nohup ros2 launch brain launch.py "$@"  > brain.log 2>&1 &
echo "[START ROBOT_COMMUNICATION]"
nohup ros2 launch robot_communication launch.py "${ROBOT_COMM_ARGS[@]}" > robot_communication.log 2>&1 &
echo "[START GAME_CONTROLLER]"
nohup ros2 launch game_controller launch.py > game_controller.log 2>&1 &
echo "[START SOUND]"
nohup ros2 run sound_play sound_play_node > sound.log 2>&1 &
echo "[DONE]"

espeak "started" >/dev/null 2>&1 || echo "Started"
