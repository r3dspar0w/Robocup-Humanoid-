#!/bin/bash

cd `dirname $0`
cd ..

EVENTS_LOG="motion_control_events.txt"
log_event() {
  echo "$(date '+%Y-%m-%d %H:%M:%S') $1" | tee -a "$EVENTS_LOG"
}

: > "$EVENTS_LOG"
log_event "[START] RoboCup startup requested"

echo "[STOP EXISTING NODES (IF ANY), TO AVOID CONFLICT]"
log_event "[STOP] Stopping existing nodes to avoid conflicts"
./scripts/stop.sh

source /opt/ros/humble/setup.bash
source ./install/setup.bash
export FASTRTPS_DEFAULT_PROFILES_FILE=/opt/booster/BoosterRos2/fastdds_profile_udp_only.xml
log_event "[ENV] FASTRTPS_DEFAULT_PROFILES_FILE=$FASTRTPS_DEFAULT_PROFILES_FILE"

echo "[START ROBOCUP NODES]"
echo "[START MOTION_CONTROL]"
MOTION_CONTROL_NETWORK_INTERFACE="${MOTION_CONTROL_NETWORK_INTERFACE:-}"
MOTION_CONTROL_AUTO_CHANGE_MODE="${MOTION_CONTROL_AUTO_CHANGE_MODE:-true}"
if [ -z "$MOTION_CONTROL_NETWORK_INTERFACE" ]; then
  echo "[WARN] MOTION_CONTROL_NETWORK_INTERFACE is empty. Example: MOTION_CONTROL_NETWORK_INTERFACE=eth0 ./scripts/start.sh"
  log_event "[WARN] MOTION_CONTROL_NETWORK_INTERFACE is empty"
fi
if [ -z "$BOOSTER_SDK_ROOT" ]; then
  echo "[WARN] BOOSTER_SDK_ROOT is empty. Build may have used a default SDK path; runtime still needs SDK shared libraries reachable."
  log_event "[WARN] BOOSTER_SDK_ROOT is empty"
fi
log_event "[START] motion_control_node network_interface='$MOTION_CONTROL_NETWORK_INTERFACE' auto_change_mode='$MOTION_CONTROL_AUTO_CHANGE_MODE'"
nohup ros2 launch motion_control motion_control.launch.py \
  network_interface:="${MOTION_CONTROL_NETWORK_INTERFACE}" \
  auto_change_mode:="${MOTION_CONTROL_AUTO_CHANGE_MODE}" \
  > motion_control.log 2>&1 &
sleep 1
echo "[START VISION]"
log_event "[START] vision"
nohup ros2 launch vision launch.py show_det:=true > vision.log 2>&1 &
echo "[START BRAIN]"
log_event "[START] brain custom-policy walking"
nohup ros2 launch brain launch.py "$@"  > brain.log 2>&1 &
echo "[START GAME_CONTROLLER]"
log_event "[START] game_controller"
nohup ros2 launch game_controller launch.py > game_controller.log 2>&1 &
echo "[DONE]"
log_event "[DONE] Startup commands issued. Check motion_control.log and brain.log for runtime status."
echo "[LOGS] motion_control.log, brain.log, vision.log, game_controller.log"
echo "[EVENTS] $EVENTS_LOG"
echo "[CHECK] ./scripts/motion_control_status.sh"



    
