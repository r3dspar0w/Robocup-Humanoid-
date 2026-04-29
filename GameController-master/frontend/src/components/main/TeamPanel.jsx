import { useEffect, useState } from "react";
import ActionButton from "./ActionButton";
import PlayerButton from "./PlayerButton";
import * as actions from "../../actions.js";
import { applyAction } from "../../api.js";

const textClasses = {
  red: "text-red-600",
  blue: "text-blue-600",
  yellow: "text-yellow-400",
  black: "text-black",
  white: "text-black",
  green: "text-green-600",
  orange: "text-orange-400",
  purple: "text-purple-600",
  brown: "text-amber-800",
  gray: "text-gray-600",
};

const TeamHeader = ({ color, isKicking, name }) => {
  return (
    <div className="flex items-center justify-center gap-2">
      <svg
        className={`${isKicking ? "" : "invisible"} text-black`}
        fill="currentColor"
        height="14"
        width="14"
      >
        <circle cx="7" cy="7" r="7" />
      </svg>
      <h1 className={`text-center text-2xl font-semibold ${textClasses[color]}`}>{name}</h1>
    </div>
  );
};

const TeamStats = ({ game, params, side, sign, team }) => {
  return (
    <dl className="flex-1">
      <dt className="sr-only">Score</dt>
      <dd
        className={`font-bold text-4xl ${sign > 0 ? "text-right" : "text-left"} tabular-nums ${
          team.illegalCommunication ? "text-fuchsia-400" : ""
        }`}
      >
        {team.score}
      </dd>

      {game.phase === "penaltyShootout" ? (
        <>
          <dt>Shot{game.kickingSide === side ? "" : "s"}:</dt>
          <dd className="tabular-nums text-right">{team.penaltyShot}</dd>
        </>
      ) : (
        <>
          <dt className={team.illegalCommunication ? "text-fuchsia-400" : ""}>Messages:</dt>
          <dd
            className={`tabular-nums text-right ${
              team.illegalCommunication ? "text-fuchsia-400" : ""
            }`}
          >
            {team.messageBudget}
          </dd>
        </>
      )}

      <dt>Penalties:</dt>
      <dd className="tabular-nums text-right">{team.penaltyCounter}</dd>
    </dl>
  );
};

const FreeKickButton = ({ game, legalTeamActions, side, setPlay, label, action }) => {
  return (
    <ActionButton
      action={{ type: "startSetPlay", args: { side: side, setPlay: setPlay } }}
      active={game.setPlay === setPlay && game.kickingSide === side}
      label={label}
      legal={legalTeamActions[action]}
    />
  );
};

const TeamPanel = ({
  connectionStatus,
  game,
  legalPenaltyActions,
  legalTeamActions,
  params,
  selectedPenaltyCall,
  setSelectedPenaltyCall,
  side,
  sign,
  teamNames,
}) => {
  // This indicates whether we are currently in the process of substitution or player selection.
  const [substitute, setSubstitute] = useState(false);
  // This doubles as carrying the number of the player which is substituted (out) for normal
  // substitutions, and a boolean indicating whether the penalty shoot-out player we are selecting
  // is a field player (false) or a goalkeeper (true). If the substitute state is false, this
  // should always be null.
  const [substitutedPlayer, setSubstitutedPlayer] = useState(null);

  // Thus, the allowed combinations of substituted/substitutedPlayer are:
  // substitute === false && substitutedPlayer === null
  //   -> no substitution / player selecting going on
  // substitute === true && !penaltyShootout && substitutedPlayer === null
  //   -> selecting the player going out
  // substitute === true && !penaltyShootout && substitutedPlayer === 1..20
  //   -> selecting the player coming in
  // substitute === true && penaltyShootout && substitutedPlayer === null
  //   -> selecting the player type (goalkeeper or field player)
  // substitute === true && penaltyShootout && substitutedPlayer === false
  //   -> selecting the player for this shot, wearing a field player jersey
  // substitute === true && penaltyShootout && substitutedPlayer === true
  //   -> selecting the player for this shot, wearing a goalkeeper jersey

  // This is terrible code, I know.
  const selectingPlayerIn = substitute && substitutedPlayer != null;
  const selectingPlayerTypePSO =
    substitute && game.phase === "penaltyShootout" && substitutedPlayer === null;
  const selectingPlayerInPSO =
    substitute && game.phase === "penaltyShootout" && substitutedPlayer != null;

  // The operator can press the shift key to remove penalties early. The main logic is still in
  // the backend, but it is decided here what the user *wants*.
  const [forceUnpenalize, setForceUnpenalize] = useState(false);
  useEffect(() => {
    const onKeydown = (e) => {
      if (e.key === "Shift") {
        setForceUnpenalize(true);
      }
    };
    const onKeyup = (e) => {
      if (e.key === "Shift") {
        setForceUnpenalize(false);
      }
    };
    document.addEventListener("keydown", onKeydown);
    document.addEventListener("keyup", onKeyup);
    return () => {
      document.removeEventListener("keydown", onKeydown);
      document.removeEventListener("keyup", onKeyup);
    };
  });

  const team = game.teams[side];
  const teamConnectionStatus = connectionStatus[side];
  const teamParams = params.game.teams[side];
  const handlePlayerClick = (player) => {
    if (selectingPlayerInPSO) {
      applyAction({
        type: "selectPenaltyShotPlayer",
        args: { side: side, player: player.number, goalkeeper: substitutedPlayer === true },
      });
      setSubstitute(false);
      setSubstitutedPlayer(null);
    } else if (selectingPlayerIn) {
      applyAction({
        type: "substitute",
        args: { side: side, playerOut: substitutedPlayer, playerIn: player.number },
      });
      setSubstitute(false);
      setSubstitutedPlayer(null);
    } else if (substitute) {
      setSubstitutedPlayer(player.number);
    } else if (selectedPenaltyCall != null) {
      applyAction({
        type: "penalize",
        args: {
          side: side,
          player: player.number,
          call: actions.PENALTIES[selectedPenaltyCall][1],
        },
      });
      if (actions.PENALTIES[selectedPenaltyCall][1] != "motionInSet") {
        setSelectedPenaltyCall(null);
      }
    } else {
      applyAction({
        type: "unpenalize",
        args: { side: side, player: player.number, force: forceUnpenalize },
      });
    }
  };

  return (
    <div className="min-w-[290px] flex flex-col gap-2">
      <TeamHeader
        color={teamParams.fieldPlayerColor}
        isKicking={game.kickingSide === side}
        name={teamNames[side]}
      />
      <div className="grid grid-flow-col grid-rows-4 auto-cols-fr gap-2">
        <div className={`col-start-${2 - sign}`}>
          <ActionButton
            action={() => {
              setSubstitute(!substitute);
              setSubstitutedPlayer(null);
            }}
            active={substitute}
            label={game.phase === "penaltyShootout" ? "Select" : "Substitute"}
            legal={true}
          />
        </div>
        <div className={`col-start-${2 - sign}`}>
          <ActionButton
            action={{ type: "timeout", args: { side: side } }}
            label="Timeout"
            legal={legalTeamActions[actions.TIMEOUT]}
          />
        </div>
        <div className={`col-start-${2 - sign}`}>
          <FreeKickButton
            game={game}
            legalTeamActions={legalTeamActions}
            side={side}
            setPlay="directFreeKick"
            label="Direct Free Kick"
            action={actions.DIRECT_FREE_KICK}
          />
        </div>
        <div className={`col-start-${2 - sign}`}>
          <FreeKickButton
            game={game}
            legalTeamActions={legalTeamActions}
            side={side}
            setPlay="throwIn"
            label="Throw-in"
            action={actions.THROW_IN}
          />
        </div>
        <div className="col-start-2 row-span-2">
          <ActionButton
            action={{ type: "goal", args: { side: side } }}
            label="Goal"
            legal={legalTeamActions[actions.GOAL]}
          />
        </div>
        <div className="col-start-2">
          <FreeKickButton
            game={game}
            legalTeamActions={legalTeamActions}
            side={side}
            setPlay="indirectFreeKick"
            label="Indirect Free Kick"
            action={actions.INDIRECT_FREE_KICK}
          />
        </div>
        <div className="col-start-2">
          <FreeKickButton
            game={game}
            legalTeamActions={legalTeamActions}
            side={side}
            setPlay="goalKick"
            label="Goal Kick"
            action={actions.GOAL_KICK}
          />
        </div>
        <div className={`col-start-${2 + sign} row-span-2`}>
          <TeamStats game={game} params={params} side={side} sign={sign} team={team} />
        </div>
        <div className={`col-start-${2 + sign}`}>
          <FreeKickButton
            game={game}
            legalTeamActions={legalTeamActions}
            side={side}
            setPlay="penaltyKick"
            label="Penalty Kick"
            action={actions.PENALTY_KICK}
          />
        </div>
        <div className={`col-start-${2 + sign}`}>
          <FreeKickButton
            game={game}
            legalTeamActions={legalTeamActions}
            side={side}
            setPlay="cornerKick"
            label="Corner Kick"
            action={actions.CORNER_KICK}
          />
        </div>
      </div>
      <div className="grow flex flex-col gap-2 overflow-auto">
        {selectingPlayerTypePSO
          ? [true, false].map((isGoalkeeper) => (
              <PlayerButton
                key={isGoalkeeper}
                color={isGoalkeeper ? teamParams.goalkeeperColor : teamParams.fieldPlayerColor}
                legal={true}
                sign={sign}
                onClick={() => setSubstitutedPlayer(isGoalkeeper)}
                player={null}
              />
            ))
          : team.players
              .map((player, index) => {
                return {
                  ...player,
                  connectionStatus: teamConnectionStatus[index],
                  number: index + 1,
                };
              })
              .filter(
                selectingPlayerInPSO
                  ? () => true
                  : selectingPlayerIn
                  ? (player) => player.penalty === "substitute"
                  : (player) => player.penalty != "substitute"
              )
              .map((player) => (
                <PlayerButton
                  key={player.number}
                  color={
                    (
                      selectingPlayerInPSO
                        ? substitutedPlayer === true
                        : (selectingPlayerIn ? substitutedPlayer : player.number) ===
                          team.goalkeeper
                    )
                      ? teamParams.goalkeeperColor
                      : teamParams.fieldPlayerColor
                  }
                  legal={
                    substitute ||
                    actions.isPenaltyCallLegalForPlayer(
                      legalPenaltyActions,
                      side,
                      player.number,
                      selectedPenaltyCall,
                      forceUnpenalize
                    )
                  }
                  sign={sign}
                  onClick={() => handlePlayerClick(player)}
                  player={player}
                />
              ))}
      </div>
    </div>
  );
};

export default TeamPanel;
