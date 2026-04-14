// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from game_controller_interface:msg/TeamInfo.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "game_controller_interface/msg/detail/team_info__rosidl_typesupport_introspection_c.h"
#include "game_controller_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "game_controller_interface/msg/detail/team_info__functions.h"
#include "game_controller_interface/msg/detail/team_info__struct.h"


// Include directives for member types
// Member `coach_message`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `coach`
// Member `players`
#include "game_controller_interface/msg/robot_info.h"
// Member `coach`
// Member `players`
#include "game_controller_interface/msg/detail/robot_info__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__TeamInfo_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  game_controller_interface__msg__TeamInfo__init(message_memory);
}

void game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__TeamInfo_fini_function(void * message_memory)
{
  game_controller_interface__msg__TeamInfo__fini(message_memory);
}

size_t game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__size_function__TeamInfo__coach_message(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__get_const_function__TeamInfo__coach_message(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__get_function__TeamInfo__coach_message(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__fetch_function__TeamInfo__coach_message(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__get_const_function__TeamInfo__coach_message(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__assign_function__TeamInfo__coach_message(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__get_function__TeamInfo__coach_message(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__resize_function__TeamInfo__coach_message(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

size_t game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__size_function__TeamInfo__players(
  const void * untyped_member)
{
  const game_controller_interface__msg__RobotInfo__Sequence * member =
    (const game_controller_interface__msg__RobotInfo__Sequence *)(untyped_member);
  return member->size;
}

const void * game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__get_const_function__TeamInfo__players(
  const void * untyped_member, size_t index)
{
  const game_controller_interface__msg__RobotInfo__Sequence * member =
    (const game_controller_interface__msg__RobotInfo__Sequence *)(untyped_member);
  return &member->data[index];
}

void * game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__get_function__TeamInfo__players(
  void * untyped_member, size_t index)
{
  game_controller_interface__msg__RobotInfo__Sequence * member =
    (game_controller_interface__msg__RobotInfo__Sequence *)(untyped_member);
  return &member->data[index];
}

void game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__fetch_function__TeamInfo__players(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const game_controller_interface__msg__RobotInfo * item =
    ((const game_controller_interface__msg__RobotInfo *)
    game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__get_const_function__TeamInfo__players(untyped_member, index));
  game_controller_interface__msg__RobotInfo * value =
    (game_controller_interface__msg__RobotInfo *)(untyped_value);
  *value = *item;
}

void game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__assign_function__TeamInfo__players(
  void * untyped_member, size_t index, const void * untyped_value)
{
  game_controller_interface__msg__RobotInfo * item =
    ((game_controller_interface__msg__RobotInfo *)
    game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__get_function__TeamInfo__players(untyped_member, index));
  const game_controller_interface__msg__RobotInfo * value =
    (const game_controller_interface__msg__RobotInfo *)(untyped_value);
  *item = *value;
}

bool game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__resize_function__TeamInfo__players(
  void * untyped_member, size_t size)
{
  game_controller_interface__msg__RobotInfo__Sequence * member =
    (game_controller_interface__msg__RobotInfo__Sequence *)(untyped_member);
  game_controller_interface__msg__RobotInfo__Sequence__fini(member);
  return game_controller_interface__msg__RobotInfo__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__TeamInfo_message_member_array[9] = {
  {
    "team_number",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__TeamInfo, team_number),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "field_player_colour",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__TeamInfo, field_player_colour),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "score",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__TeamInfo, score),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "penalty_shot",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__TeamInfo, penalty_shot),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "single_shots",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__TeamInfo, single_shots),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "coach_sequence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__TeamInfo, coach_sequence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "coach_message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__TeamInfo, coach_message),  // bytes offset in struct
    NULL,  // default value
    game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__size_function__TeamInfo__coach_message,  // size() function pointer
    game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__get_const_function__TeamInfo__coach_message,  // get_const(index) function pointer
    game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__get_function__TeamInfo__coach_message,  // get(index) function pointer
    game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__fetch_function__TeamInfo__coach_message,  // fetch(index, &value) function pointer
    game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__assign_function__TeamInfo__coach_message,  // assign(index, value) function pointer
    game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__resize_function__TeamInfo__coach_message  // resize(index) function pointer
  },
  {
    "coach",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__TeamInfo, coach),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "players",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__TeamInfo, players),  // bytes offset in struct
    NULL,  // default value
    game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__size_function__TeamInfo__players,  // size() function pointer
    game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__get_const_function__TeamInfo__players,  // get_const(index) function pointer
    game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__get_function__TeamInfo__players,  // get(index) function pointer
    game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__fetch_function__TeamInfo__players,  // fetch(index, &value) function pointer
    game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__assign_function__TeamInfo__players,  // assign(index, value) function pointer
    game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__resize_function__TeamInfo__players  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__TeamInfo_message_members = {
  "game_controller_interface__msg",  // message namespace
  "TeamInfo",  // message name
  9,  // number of fields
  sizeof(game_controller_interface__msg__TeamInfo),
  game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__TeamInfo_message_member_array,  // message members
  game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__TeamInfo_init_function,  // function to initialize message memory (memory has to be allocated)
  game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__TeamInfo_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__TeamInfo_message_type_support_handle = {
  0,
  &game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__TeamInfo_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_game_controller_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, game_controller_interface, msg, TeamInfo)() {
  game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__TeamInfo_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, game_controller_interface, msg, RobotInfo)();
  game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__TeamInfo_message_member_array[8].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, game_controller_interface, msg, RobotInfo)();
  if (!game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__TeamInfo_message_type_support_handle.typesupport_identifier) {
    game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__TeamInfo_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &game_controller_interface__msg__TeamInfo__rosidl_typesupport_introspection_c__TeamInfo_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
