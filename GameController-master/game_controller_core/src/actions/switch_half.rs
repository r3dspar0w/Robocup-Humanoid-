use serde::{Deserialize, Serialize};

use crate::action::{Action, ActionContext};
use crate::timer::{BehaviorAtZero, RunCondition, Timer};
use crate::types::{Penalty, Phase, State};

/// This struct defines an action that switches from the end of the first half to the beginning of
/// the second half, including the switch of sides.
#[derive(Clone, Debug, Deserialize, PartialEq, Serialize)]
pub struct SwitchHalf;

impl Action for SwitchHalf {
    fn execute(&self, c: &mut ActionContext) {
        // Unpenalize all players that are not substitutes. Maybe picked up players should stay
        // picked up, but the old GameController unpenalized them, too.
        c.game.teams.values_mut().for_each(|team| {
            team.players
                .iter_mut()
                .filter(|player| !matches!(player.penalty, Penalty::SentOff | Penalty::Substitute))
                .for_each(|player| {
                    player.penalty = Penalty::NoPenalty;
                    player.penalty_timer = Timer::Stopped;
                })
        });

        c.game.sides = -c.params.game.side_mapping;
        c.game.phase = match c.game.phase {
            Phase::FirstHalf => Phase::SecondHalf,
            Phase::FirstExtraHalf => Phase::SecondExtraHalf,
            _ => panic!("only possible in a first half"),
        };
        c.game.state = State::Initial;
        c.game.kicking_side = Some(-c.params.game.kick_off_side);

        c.game.primary_timer = Timer::Started {
            remaining: (if c.game.phase == Phase::SecondHalf {
                c.params.competition.half_duration
            } else {
                c.params.competition.extra_half_duration.unwrap()
            })
            .try_into()
            .unwrap(),
            run_condition: RunCondition::MainTimer,
            behavior_at_zero: BehaviorAtZero::Overflow,
        };
        c.game.switch_half_timer = Timer::Stopped;
    }

    fn is_legal(&self, c: &ActionContext) -> bool {
        (c.game.phase == Phase::FirstHalf || c.game.phase == Phase::FirstExtraHalf)
            && c.game.state == State::Finished
    }
}
