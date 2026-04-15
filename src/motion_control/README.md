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
