# CMD to run for motion

**cmd to build**

```
colcon build --packages-select motion_control brain
source install/setup.bash
ros2 launch brain launch.py use_custom_walk:=true
```

**cmd to verify**

```
find . -path 'motion_control_logsevents.log'
tail -f motion_control_logs/*/events.log
```

To run custom walk directly (skip start pose)

```
./scripts/start.sh use_custom_walk:=true use_start_pose:=false
```

To run actuator monitor only (no policy, no `/low_cmd` output)

```
colcon build --packages-select motion_control
source install/setup.bash
ros2 launch motion_control actuator_monitor.launch.py
```

The node prints motor values from `/low_state` and writes CSV samples to:

```
motion_control_logs/*_actuator_monitor_*/actuator_samples.csv
```
