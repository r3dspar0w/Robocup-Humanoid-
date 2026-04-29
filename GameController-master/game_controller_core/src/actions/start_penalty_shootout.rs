use serde::{Deserialize, Serialize};

use crate::action::{Action, ActionContext};
use crate::timer::Timer;
use crate::types::{Penalty, Phase, SetPlay, Side, SideMapping, State};

/// This struct defines an action which starts a penalty (kick) shoot-out. To disambiguate this
/// from penalty kicks as set plays within the game, penalty kicks in a penalty (kick) shoot-out
/// are mostly referred to as "penalty shots".
#[derive(Clone, Debug, Deserialize, PartialEq, Serialize)]
#[serde(rename_all = "camelCase")]
pub struct StartPenaltyShootout {
    /// This defines the goal on which all penalty shots are taken. Since the home team always has
    /// the first kick, [SideMapping::HomeDefendsLeftGoal] means that the right goal is used.
    pub sides: SideMapping,
}

impl Action for StartPenaltyShootout {
    fn execute(&self, c: &mut ActionContext) {
        // Make all players substitutes.
        c.game.teams.values_mut().for_each(|team| {
            team.goalkeeper = None;
            team.penalty_shot = 0;
            team.penalty_shot_mask = 0;
            team.players.iter_mut().for_each(|player| {
                if player.penalty != Penalty::SentOff {
                    player.penalty = Penalty::Substitute;
                }
                player.penalty_timer = Timer::Stopped;
            });
        });

        c.game.sides = self.sides;
        c.game.phase = Phase::PenaltyShootout;
        c.game.state = State::Initial;
        c.game.set_play = SetPlay::NoSetPlay;
        // "The team listed first on the competition schedule will have the striker robot for the
        // first penalty kick." - HSL rule book 2026 section 14.2
        c.game.kicking_side = Some(Side::Home);
        c.game.primary_timer = Timer::Stopped;
        c.game.secondary_timer = Timer::Stopped;
    }

    fn is_legal(&self, c: &ActionContext) -> bool {
        // If there is extra time, allow penalty shoot-out after second half of extra time.
        c.game.phase
            == (if c.params.competition.extra_half_duration.is_none() {
                Phase::SecondHalf
            } else {
                Phase::SecondExtraHalf
            })
            && c.game.state == State::Finished
            && (c.game.teams[Side::Home].score == c.game.teams[Side::Away].score
                || c.params.game.test.penalty_shootout)
    }
}
