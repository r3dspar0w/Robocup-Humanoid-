// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from game_controller_interface:msg/GameControlData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "game_controller_interface/msg/detail/game_control_data__rosidl_typesupport_introspection_c.h"
#include "game_controller_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "game_controller_interface/msg/detail/game_control_data__functions.h"
#include "game_controller_interface/msg/detail/game_control_data__struct.h"


// Include directives for member types
// Member `teams`
#include "game_controller_interface/msg/team_info.h"
// Member `teams`
#include "game_controller_interface/msg/detail/team_info__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__GameControlData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  game_controller_interface__msg__GameControlData__init(message_memory);
}

void game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__GameControlData_fini_function(void * message_memory)
{
  game_controller_interface__msg__GameControlData__fini(message_memory);
}

size_t game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__size_function__GameControlData__header(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__get_const_function__GameControlData__header(
  const void * untyped_member, size_t index)
{
  const uint8_t * member =
    (const uint8_t *)(untyped_member);
  return &member[index];
}

void * game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__get_function__GameControlData__header(
  void * untyped_member, size_t index)
{
  uint8_t * member =
    (uint8_t *)(untyped_member);
  return &member[index];
}

void game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__fetch_function__GameControlData__header(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__get_const_function__GameControlData__header(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__assign_function__GameControlData__header(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__get_function__GameControlData__header(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

size_t game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__size_function__GameControlData__secondary_state_info(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__get_const_function__GameControlData__secondary_state_info(
  const void * untyped_member, size_t index)
{
  const uint8_t * member =
    (const uint8_t *)(untyped_member);
  return &member[index];
}

void * game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__get_function__GameControlData__secondary_state_info(
  void * untyped_member, size_t index)
{
  uint8_t * member =
    (uint8_t *)(untyped_member);
  return &member[index];
}

void game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__fetch_function__GameControlData__secondary_state_info(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__get_const_function__GameControlData__secondary_state_info(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__assign_function__GameControlData__secondary_state_info(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__get_function__GameControlData__secondary_state_info(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

size_t game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__size_function__GameControlData__teams(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__get_const_function__GameControlData__teams(
  const void * untyped_member, size_t index)
{
  const game_controller_interface__msg__TeamInfo * member =
    (const game_controller_interface__msg__TeamInfo *)(untyped_member);
  return &member[index];
}

void * game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__get_function__GameControlData__teams(
  void * untyped_member, size_t index)
{
  game_controller_interface__msg__TeamInfo * member =
    (game_controller_interface__msg__TeamInfo *)(untyped_member);
  return &member[index];
}

void game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__fetch_function__GameControlData__teams(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const game_controller_interface__msg__TeamInfo * item =
    ((const game_controller_interface__msg__TeamInfo *)
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__get_const_function__GameControlData__teams(untyped_member, index));
  game_controller_interface__msg__TeamInfo * value =
    (game_controller_interface__msg__TeamInfo *)(untyped_value);
  *value = *item;
}

void game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__assign_function__GameControlData__teams(
  void * untyped_member, size_t index, const void * untyped_value)
{
  game_controller_interface__msg__TeamInfo * item =
    ((game_controller_interface__msg__TeamInfo *)
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__get_function__GameControlData__teams(untyped_member, index));
  const game_controller_interface__msg__TeamInfo * value =
    (const game_controller_interface__msg__TeamInfo *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__GameControlData_message_member_array[15] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__GameControlData, header),  // bytes offset in struct
    NULL,  // default value
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__size_function__GameControlData__header,  // size() function pointer
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__get_const_function__GameControlData__header,  // get_const(index) function pointer
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__get_function__GameControlData__header,  // get(index) function pointer
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__fetch_function__GameControlData__header,  // fetch(index, &value) function pointer
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__assign_function__GameControlData__header,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "version",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__GameControlData, version),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "packet_number",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__GameControlData, packet_number),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "players_per_team",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__GameControlData, players_per_team),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "game_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__GameControlData, game_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__GameControlData, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "first_half",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__GameControlData, first_half),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kick_off_team",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__GameControlData, kick_off_team),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "secondary_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__GameControlData, secondary_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "secondary_state_info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__GameControlData, secondary_state_info),  // bytes offset in struct
    NULL,  // default value
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__size_function__GameControlData__secondary_state_info,  // size() function pointer
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__get_const_function__GameControlData__secondary_state_info,  // get_const(index) function pointer
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__get_function__GameControlData__secondary_state_info,  // get(index) function pointer
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__fetch_function__GameControlData__secondary_state_info,  // fetch(index, &value) function pointer
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__assign_function__GameControlData__secondary_state_info,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "drop_in_team",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__GameControlData, drop_in_team),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "drop_in_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__GameControlData, drop_in_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "secs_remaining",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__GameControlData, secs_remaining),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "secondary_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__GameControlData, secondary_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "teams",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__GameControlData, teams),  // bytes offset in struct
    NULL,  // default value
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__size_function__GameControlData__teams,  // size() function pointer
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__get_const_function__GameControlData__teams,  // get_const(index) function pointer
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__get_function__GameControlData__teams,  // get(index) function pointer
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__fetch_function__GameControlData__teams,  // fetch(index, &value) function pointer
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__assign_function__GameControlData__teams,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__GameControlData_message_members = {
  "game_controller_interface__msg",  // message namespace
  "GameControlData",  // message name
  15,  // number of fields
  sizeof(game_controller_interface__msg__GameControlData),
  game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__GameControlData_message_member_array,  // message members
  game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__GameControlData_init_function,  // function to initialize message memory (memory has to be allocated)
  game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__GameControlData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__GameControlData_message_type_support_handle = {
  0,
  &game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__GameControlData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_game_controller_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, game_controller_interface, msg, GameControlData)() {
  game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__GameControlData_message_member_array[14].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, game_controller_interface, msg, TeamInfo)();
  if (!game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__GameControlData_message_type_support_handle.typesupport_identifier) {
    game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__GameControlData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &game_controller_interface__msg__GameControlData__rosidl_typesupport_introspection_c__GameControlData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
