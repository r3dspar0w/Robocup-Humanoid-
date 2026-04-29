# Improvement Feasibility Analysis

Three proposed improvements evaluated against the current codebase.

---

## 1. Tactical Pose Planning — Bézier Curve Approach

### Current State
`StrikerChase::tick()` (via `TickChaseNode`, `brain_tree.cpp:32`) computes a **single instantaneous target point** each tick:
- `target_f` = a point directly behind the ball along the kick direction
- `circle_back` mode: a tangent point on a circle around the ball

The robot walks toward this point with a velocity smoothed over `0.3/0.7` exponential filter. There is no multi-step path, no lookahead, and no constraint on *where the robot arrives from*.

### The Real Problem
The "tap dancing" issue stems from **oscillation around the target point**, not from the path shape. The robot overshoots → corrects → overshoots. A Bézier curve would define a smoother *path*, but the root instability is the **single-tick proportional controller with no position memory**.

### What Bézier Actually Buys You
| Benefit | Applicability Here |
|---|---|
| Smooth, predictable arc around the ball | ✅ Directly useful — replaces the hacky `circle_back` tangent with a proper arc |
| Continuous curvature (no sharp corners) | ✅ Better for a walking biped that cannot stop instantly |
| Defined arrival pose (approach angle) | ✅ **This is the main gain** — you can control the angle the robot arrives from |
| Avoids ball during circumnavigation | ✅ Bézier control points can be placed to keep the arc outside `safe_dist` |

### Feasibility: ✅ High
The math is 4–10 lines of C++. The hard part is placing the **control points** correctly.

### Suggested Implementation
For the `circle_back` case only (approaching from behind the ball):

```
P0 = robot.pos
P3 = target_behind_ball  (kickDir offset)
P1 = P0 + tangent_from_robot * blend_factor
P2 = P3 - tangent_to_approach * blend_factor
```

Evaluate `B(t)` where `t` = fraction of distance already covered. On each tick, advance `t` by `dt / total_arc_length`, then command `vx/vy` toward `B(t+lookahead)`.

**Files to touch:**
- `brain_tree.cpp` — `TickChaseNode()` (lines 84–148): replace `targetType == "circle_back"` block
- Optionally expose `bezier_lookahead` as a BT parameter in `subtree_striker_play.xml`

### Risk
The biggest risk is **ball movement during the curve** (the target `P3` shifts). Must recompute the curve every N ticks when ball moves more than a threshold.

---

## 2. Blind-Spot Dead Reckoning — Odometry Ball Tracking

### Current State
When the robot tilts its head down during `Adjust` / `Kick`, `ballDetected = false`. The code in `CamTrackBall::tick()` (line 340) has a fallback:

```cpp
pitch = headPitch + (ball.pitchToRobot - headPitch) * 0.01;  // extremely slow blend
yaw   = headYaw   + (ball.yawToRobot   - headYaw  ) * 0.01;
```

But `ball.pitchToRobot` and `ball.yawToRobot` are **stale** — they were last updated when the ball was visible. There is no propagation of the robot's own motion into the ball's estimated position.

`ball_memory_timeout: 2.0` in `config.yaml` means the system keeps using the stale reading for up to 2 seconds. During this window, `ball_location_known` stays `true` and `StrikerDecide` remains in `adjust`/`kick`.

### The Real Problem
As the robot walks during `Adjust`, its body translates and rotates. The ball's **position in robot frame** changes even if the ball itself is stationary. Without propagating odometry, the brain is looking for the ball where it was, not where it is now.

### What Dead Reckoning Buys You
- More accurate `ball.posToRobot` estimate during the blind window
- `Kick::onStart()` can use the corrected estimate to align the approach vector
- Reduces "kicking air" when the robot's foot misses because the ball drifted out of the expected corridor

### Feasibility: ✅ High — the data already exists

The brain already has:
- `robotPoseToField` (continuously updated from locator odometry)
- `ball.posToField` (last known absolute field position — does **not** depend on robot frame)

So the fix is: when `!ballDetected && ball_location_known`, compute ball-to-robot via:
```cpp
ball.posToRobot = field2robot(ball.posToField);
ball.yawToRobot = atan2(ball.posToRobot.y, ball.posToRobot.x);
ball.range      = norm(ball.posToRobot.x, ball.posToRobot.y);
```

`field2robot()` already exists in the brain data layer and accounts for the robot's current odometry pose.

### Suggested Implementation

**Where to add it:** `brain.cpp` → `getGameObjects()` or the ball-data update path, in the `!ballDetected` branch inside the `ball_memory_timeout` window.

```cpp
// When ball is not directly seen but memory is valid:
if (!ballDetected && msecsSince(ball.timePoint) < ballMemoryMs) {
    // Re-project from world frame using current odometry
    auto estimated_r = field2robot({ball.posToField.x, ball.posToField.y, 0.0});
    ball.posToRobot.x = estimated_r.x;
    ball.posToRobot.y = estimated_r.y;
    ball.range = norm(estimated_r.x, estimated_r.y);
    ball.yawToRobot = atan2(estimated_r.y, estimated_r.x);
}
```

**Files to touch:**
- `brain.cpp` — ball data update section
- No BT or config changes needed

### Risk
If localization is noisy (which it is during `Adjust` when the head is looking down), `robotPoseToField` may drift. Recommend adding a confidence flag `odom_dead_reckon_active` so the BT can reduce `Kick`'s tolerance slightly when reckoning.

---

## 3. Procedural IK Kicking — Mathematical Foot Posture

### Current State
`Kick::onStart()` (line 1302) computes a **body velocity command**:
```cpp
double adjustedYaw = ball.yawToRobot - yawOffset;
double tx = cos(adjustedYaw) * ball.range;
double ty = sin(adjustedYaw) * ball.range;
// ... scales vx/vy proportionally
client->setVelocity(vx, vy, 0);
```

This is a **walk-through** kick: the robot commands a walking velocity toward the ball, and relies on the Booster SDK's internal gait controller to handle footstep placement. There is no direct control over which foot strikes, foot height, swing trajectory, or contact angle.

The robot **cannot** directly issue foot-level commands through the current API. The `client->setVelocity()` only sends `(vx, vy, vtheta)` to the gait controller.

### The Hard Constraint
> ⚠️ The Booster T1 SDK exposes **only a velocity interface** (`setVelocity`) and **pre-recorded motion clips** (for kick animations). There is no joint-level IK API exposed in this stack.

`RLVisionKick` uses a higher-level ML policy that outputs a **clip trigger**, not IK targets either.

### What "Procedural IK" Would Actually Require
To do foot posture control, you would need one of:
1. **Joint-level torque/position commands** from the Booster SDK (not currently available/documented)
2. A **custom motion retargeting layer** that takes desired foot pose → IK → joint angles → SDK
3. **Offline keyframe animation tuned per approach angle** (closest to what's available now)

### Feasibility: ❌ Low (within current SDK constraints)

However, there is a **meaningful approximation** within reach:

### Achievable Improvement: Angle-Dependent Approach Velocity Profile
Instead of a fixed `yawOffset = -0.1` in config, compute a **per-kick lateral bias** from the approach geometry:

```cpp
// In Kick::onStart():
double lateralBias = clamp(ball.posToRobot.y * 0.3, -0.05, 0.05);
double adjustedYaw = ball.yawToRobot - yawOffset - lateralBias;
```

This steers the walk-through trajectory so the instep (not the toe or heel) is more likely to contact the ball, approximating the effect of "foot angle tuning" without needing IK.

A second improvement: **vx/vy profiling over time**. Instead of constant velocity during the kick window, ramp up midway and taper off:
```
t=0 → 0.3s: slow approach (stabilize stance)
t=0.3s → kick: full velocity burst
```

**Files to touch:**
- `brain_tree.cpp` — `Kick::onStart()` and `Kick::onRunning()` (lines 1302–1396)
- `config.yaml` — add `kick_lateral_bias_gain` parameter

---

---

## 4. Gait Phase Matching — Kick Trigger Synchronization

### What You Proposed
Time the kick trigger to fire precisely when the gait cycle is in the right support-foot phase, so the SDK's gait engine doesn't need to reschedule the kick after an interrupt.

### What the SDK Actually Provides
After auditing every available interface (`robot_client.h`, `robot_client.cpp`, all `.msg` files in `booster_ros2_interface/msg/`):

| Source | Data Available |
|---|---|
| `/low_state` → `LowState.msg` | `ImuState` (roll/pitch/yaw + gyro + acc) + `MotorState[]` (q, dq, tau, temp) |
| `lowStateCallback()` (brain.cpp:1349) | **Only reads** `motor_state_serial[0].q` (head yaw) and `[1].q` (head pitch) — nothing else |
| `MotorState.msg` | `q` (joint angle), `dq` (velocity), `ddq` (acceleration), `tau_est` (torque) |

There is **no explicit gait phase field** (no `support_foot`, `swing_phase`, `step_count`, etc.) exposed in the message interface. The gait phase is internal to the Booster locomotion planner.

### Can We Infer Gait Phase?
Yes — **indirectly**, from the `LowState` data that already arrives:

**Method: Hip/Ankle Roll Oscillation**  
During walking, the robot's CoM shifts left→right in sync with the gait cycle. This is directly observable as a **periodic oscillation in `imu_state.rpy[0]` (roll)** and in the **lateral hip motor `q` values**.

The leg motor indices for the T1 are not documented in the repo, but the `motor_state_parallel` array contains all parallel-mechanism motors. By logging these during walking and identifying which motor index oscillates at gait frequency (~0.5–1 Hz), you can derive phase.

```
Gait phase ≈ atan2(d(roll)/dt, roll)  — a simple phase estimator from IMU
```

**Practical Approximation:**
```cpp
// In lowStateCallback(), add:
data->imuRoll = msg.imu_state.rpy[0];  // already available, not currently stored
data->imuRollRate = msg.imu_state.gyro[1]; // lateral gyro

// Gait phase proxy: CoM is shifting LEFT when roll rate > 0 (right foot becoming support)
// Best kick moment: roll is near zero and rate is becoming negative (left foot support)
bool rightFootSupport = (data->imuRoll > 0.01 && data->imuRollRate > 0);
bool leftFootSupport  = (data->imuRoll < -0.01 && data->imuRollRate < 0);
```

### Feasibility: ✅ Medium (achievable, but requires calibration)

The data is available. The challenge is:
1. **Identifying the correct motor indices** for hip abduction on the T1 (requires a 10-minute logging session during walking)
2. **Gait frequency varies** with walk speed — the phase estimator needs to track this dynamically
3. **Walk-through kick** (`Kick::onStart()`, line 1302) issues velocity commands, not a discrete action trigger — so the "timing window" only matters for the initial velocity burst, not a single-shot signal

### Where to Hook It In

```cpp
// In Kick::onStart() before setVelocity():
double imuRoll = brain->data->imuRoll;
double imuRollRate = brain->data->imuRollRate;
bool phaseReady = (imuRoll < 0.02) && (imuRollRate < 0.0); // Left foot becoming support

if (!phaseReady) {
    // Defer by 1 tick (hold position, wait for phase)
    brain->client->setVelocity(0, 0, 0);
    return NodeStatus::RUNNING;  // stay in onStart state
}
// else proceed with kick velocity command
```

**Files to touch:**
- `brain_data.h` — add `imuRoll`, `imuRollRate` fields
- `brain.cpp` → `lowStateCallback()` (line 1349) — store IMU roll and gyro
- `brain_tree.cpp` → `Kick::onStart()` (line 1302) — add phase gate

### Risk
If phase detection is wrong (bad motor index or noisy IMU), the kick will be deferred indefinitely. Needs a **timeout fallback**: if phase not detected within 500ms, kick anyway.

---

## 5. Multi-clip Dynamic Selection — Kick Action Routing

### What You Proposed
Instead of a single generic kick, dynamically select from multiple named clips (`kick_forward_left`, `kick_forward_right`, `kick_side_tap`) based on the ball's local position and tactical needs.

### What the SDK Actually Provides
After examining all SDK call sites:

| API | What It Does |
|---|---|
| `LocoApiId::kShoot` (used in `RLVisionKick`) | Triggers the RL-based visual kick policy — a **single** opaque action |
| `LocoApiId::kMove` (used in `Kick::onStart()`) | Velocity walk command — not a kick clip |
| `LocoApiId::kGetUp`, `kWaveHand`, `kLieDown` | Hard-coded action clips with no parameters |
| `LocoApiId::kChangeMode` | Mode switch (walk ↔ damping) |

**There is no `LocoApiId::kKickLeft`, `kKickRight`, or `kSideKick` in the SDK.** The `kShoot` ID is the only kick-type action clip, and it takes only a `{"start": bool}` parameter.

### What IS Achievable Within the Current API

**A. Foot Selection via Approach Offset**  
The walk-through kick (`Kick::onStart()`) controls the approach trajectory. By shifting `ty` (lateral offset) in either direction before the kick walk, you steer the instep vs. outside foot contact:

```cpp
// Current code (line 1329):
double adjustedYaw = ball.yawToRobot - yawOffset;
double tx = cos(adjustedYaw) * ball.range;
double ty = sin(adjustedYaw) * ball.range;

// Proposed: dynamic lateral bias from ball.posToRobot.y
double ballLateral = brain->data->ball.posToRobot.y;
double kickBias = 0.0;
if (fabs(ballLateral) > 0.08) {
    // Ball is off-center — bias the approach to use the near foot
    kickBias = (ballLateral > 0) ? -0.05 : +0.05;
}
double adjustedYaw = ball.yawToRobot - yawOffset + kickBias;
```

**B. Tactical Clip Selection for `kShoot` vs. Walk-Through**  
Although we can't select foot animations, we CAN choose **which of the two kick mechanisms** to use based on context:

| Condition | Mechanism | Rationale |
|---|---|---|
| Ball lateral offset < 0.08m, distance < 0.6m, goal wide open | `kShoot` (RL kick) | Maximum power, best accuracy |
| Ball slightly off-center (0.08–0.18m), goal angle tight | Walk-through `Kick` | More forgiving trajectory |
| Ball at corner, need side tap | Walk-through with high `vy`, zero `vx` | Side-foot approximation |

This selection logic belongs in **`StrikerDecide::tick()`** (line 858), not `Kick::onStart()`:

```cpp
// Extend canKickOrCross logic:
bool preferRLKick = ballRange < 0.6 && fabs(ballYaw) < 0.1 && goalAlignedForStraight;
bool preferSideTap = fabs(ballY) > 0.15 && ballRange < 0.5;

// Then in BT XML, route to different Kick parameter sets:
// <Kick _while="decision=='kick_strong'" vx_limit="0.8" vy_limit="0.1" />
// <Kick _while="decision=='kick_side'"  vx_limit="0.1" vy_limit="0.6" />
```

**C. If the SDK Is Updated** — the `ConstructMsg()` template in `message_utils.hpp` (line 14) already supports arbitrary `LocoApiId` + JSON body. When Booster releases a `kKickLeft`/`kKickRight` ID, adding it is a single function call.

### Feasibility: ✅ Medium (soft multi-clip via approach bias + decision routing)

**Files to touch:**
- `brain_tree.cpp` → `StrikerDecide::tick()` — add `kick_side` decision branch
- `brain_tree.cpp` → `Kick::onStart()` — add lateral bias from `ballLateral`
- `subtree_striker_play.xml` — add `<Kick _while="decision=='kick_side'" ...>` with different params
- `robot_client.h` / `robot_client.cpp` — prepare `kickClip(string name)` wrapper for future SDK clips

---

## Summary & Recommendation

| Improvement | Feasibility | Expected Impact | Effort |
|---|---|---|---|
| Bézier curve approach | ✅ High | Medium — smoother arc, better arrival angle | ~2–3 hrs |
| Odometry dead reckoning | ✅ High | **High** — directly fixes blind-window positioning | ~1–2 hrs |
| Procedural IK kicking | ❌ Low (SDK limit) | Low without SDK access | High effort, low return |
| *Approach velocity profiling* (IK substitute) | ✅ High | Medium — better instep contact probability | ~1 hr |
| Gait phase matching | ✅ Medium | Medium — smoother kick initiation | ~3–4 hrs incl. calibration |
| Multi-clip selection (soft, via routing) | ✅ Medium | Medium — tactical foot choice | ~2–3 hrs |
| Multi-clip selection (hard SDK clips) | ❌ Blocked | High if SDK adds IDs | 0 hrs (waiting on Booster) |

**Recommended order of implementation:**
1. **Dead Reckoning** (highest ROI, least risky)
2. **Bézier Approach** (addresses circle_back oscillation)
3. **Multi-clip routing + lateral bias** (soft, within current API)
4. **Gait phase matching** (requires calibration session on physical robot)
5. **Approach velocity profiling** (low-effort IK substitute)
