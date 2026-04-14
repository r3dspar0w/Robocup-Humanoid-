// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from game_controller_interface:msg/GameControlData.idl
// generated code does not contain a copyright notice

#ifndef GAME_CONTROLLER_INTERFACE__MSG__DETAIL__GAME_CONTROL_DATA__STRUCT_H_
#define GAME_CONTROLLER_INTERFACE__MSG__DETAIL__GAME_CONTROL_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'teams'
#include "game_controller_interface/msg/detail/team_info__struct.h"

/// Struct defined in msg/GameControlData in the package game_controller_interface.
/**
  * following include/RoboCupGameControllData.h's RoboCupGameControlData structure
 */
typedef struct game_controller_interface__msg__GameControlData
{
  /// header to identify the structure
  uint8_t header[4];
  /// version of the data structure
  uint16_t version;
  /// number incremented with each packet sent (with wraparound)
  uint8_t packet_number;
  /// the number of players on a team
  uint8_t players_per_team;
  /// type of the game (GAME_ROUNDROBIN, GAME_PLAYOFF, GAME_DROPIN)
  uint8_t game_type;
  /// state of the game (STATE_READY, STATE_PLAYING, etc)
  uint8_t state;
  /// 1 = game in first half, 0 otherwise
  uint8_t first_half;
  /// the team number of the next team to kick off or DROPBALL
  uint8_t kick_off_team;
  /// extra state information - (STATE2_NORMAL, STATE2_PENALTYSHOOT, etc)
  uint8_t secondary_state;
  /// Extra info on the secondary state
  uint8_t secondary_state_info[4];
  /// number of team that caused last drop in
  uint8_t drop_in_team;
  /// number of seconds passed since the last drop in. -1 (0xffff) before first dropin
  uint16_t drop_in_time;
  /// estimate of number of seconds remaining in the half
  uint16_t secs_remaining;
  /// number of seconds shown as secondary time (remaining ready, until free ball, etc)
  uint16_t secondary_time;
  game_controller_interface__msg__TeamInfo teams[2];
} game_controller_interface__msg__GameControlData;

// Struct for a sequence of game_controller_interface__msg__GameControlData.
typedef struct game_controller_interface__msg__GameControlData__Sequence
{
  game_controller_interface__msg__GameControlData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} game_controller_interface__msg__GameControlData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GAME_CONTROLLER_INTERFACE__MSG__DETAIL__GAME_CONTROL_DATA__STRUCT_H_
