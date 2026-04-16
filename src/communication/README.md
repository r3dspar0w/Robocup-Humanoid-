# communication

Rule-compliant robot-to-robot communication package for RoboCup HSL.

## What this node does

- Sends teammate packets using **UDP broadcast** only.
- Uses team port `10000 + team_id`.
- Keeps packet size below `512` bytes.
- Shares robot pose and ball position from:
  - `/booster_soccer/robot_pose`
  - `/booster_soccer/ball_position`
- Receives teammate packets and publishes:
  - `/booster_soccer/team_ball_teammates` (`communication/msg/TeammateBallArray`)

This matches the new HSL rules for large division wireless team communication:
- UDP broadcast required
- no robot-to-robot unicast
- packet size limit 512 bytes

## Build

```bash
cd ~/Workspace/robocup_demo
./scripts/build.sh
```

## Run

```bash
ros2 launch communication team_communication.launch.py team_id:=67 player_id:=1
```

Optional override:

```bash
ros2 launch communication team_communication.launch.py \
  team_id:=67 player_id:=2 broadcast_address:=255.255.255.255
```

## Notes

- Default send rate is `1.0 Hz` to stay conservative on message budget.
- By default, sending is always enabled (use `send_only_in_counted_states:=true` if needed).
- If you still run the old `brain_communication` module, disable it to avoid duplicate/non-compliant traffic.
