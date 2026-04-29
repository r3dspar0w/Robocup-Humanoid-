use serde::{Deserialize, Serialize};

use crate::action::{Action, ActionContext, VAction};
use crate::actions::SwitchHalf;
use crate::timer::{BehaviorAtZero, RunCondition, SignedDuration, Timer};
use crate::types::{Penalty, Phase, SetPlay, State};

/// This struct defines an action which corresponds to the referee call "Finish" (or rather
/// two/three successive whistles).
#[derive(Clone, Debug, Deserialize, PartialEq, Serialize)]
pub struct FinishHalf;

impl Action for FinishHalf {
    fn execute(&self, c: &mut ActionContext) {
        // Cancel all penalty timers.
        c.game.teams.values_mut().for_each(|team| {
            team.players
                .iter_mut()
                .filter(|player| {
                    !matches!(
                        player.penalty,
                        Penalty::NoPenalty | Penalty::SentOff | Penalty::Substitute
                    )
                })
                .for_each(|player| {
                    player.penalty_timer = Timer::Started {
                        remaining: SignedDuration::ZERO,
                        run_condition: RunCondition::ReadyOrPlaying,
                        behavior_at_zero: BehaviorAtZero::Clip,
                    };
                })
        });

        c.game.secondary_timer = Timer::Stopped;
        c.game.timeout_rewind_timer = Timer::Stopped;
        c.game.set_play = SetPlay::NoSetPlay;
        c.game.kicking_side = None;
        c.game.state = State::Finished;

        // After the first half, a timer counts down the half-time break. It is intentional that
        // there is no timer after the second half or after an extra half, because the rule book
        // does not specify any specific duration.
        if c.game.phase == Phase::FirstHalf {
            c.game.secondary_timer = Timer::Started {
                remaining: c
                    .params
                    .competition
                    .half_time_break_duration
                    .try_into()
                    .unwrap(),
                run_condition: RunCondition::Always,
                behavior_at_zero: BehaviorAtZero::Overflow,
            };
            c.game.switch_half_timer = Timer::Started {
                remaining: (c.params.competition.half_time_break_duration / 2)
                    .try_into()
                    .unwrap(),
                run_condition: RunCondition::Always,
                behavior_at_zero: BehaviorAtZero::Expire(vec![VAction::SwitchHalf(SwitchHalf)]),
            };
        }
    }

    fn is_legal(&self, c: &ActionContext) -> bool {
        c.game.phase != Phase::PenaltyShootout
            && (c.game.state == State::Playing
                || c.game.state == State::Ready
                || c.game.state == State::Set)
    }
}
