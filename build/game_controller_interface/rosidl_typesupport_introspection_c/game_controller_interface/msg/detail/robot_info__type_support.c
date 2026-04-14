// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from game_controller_interface:msg/RobotInfo.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "game_controller_interface/msg/detail/robot_info__rosidl_typesupport_introspection_c.h"
#include "game_controller_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "game_controller_interface/msg/detail/robot_info__functions.h"
#include "game_controller_interface/msg/detail/robot_info__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void game_controller_interface__msg__RobotInfo__rosidl_typesupport_introspection_c__RobotInfo_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  game_controller_interface__msg__RobotInfo__init(message_memory);
}

void game_controller_interface__msg__RobotInfo__rosidl_typesupport_introspection_c__RobotInfo_fini_function(void * message_memory)
{
  game_controller_interface__msg__RobotInfo__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember game_controller_interface__msg__RobotInfo__rosidl_typesupport_introspection_c__RobotInfo_message_member_array[6] = {
  {
    "penalty",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__RobotInfo, penalty),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "secs_till_unpenalised",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__RobotInfo, secs_till_unpenalised),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "number_of_warnings",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__RobotInfo, number_of_warnings),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yellow_card_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__RobotInfo, yellow_card_count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "red_card_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__RobotInfo, red_card_count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal_keeper",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface__msg__RobotInfo, goal_keeper),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers game_controller_interface__msg__RobotInfo__rosidl_typesupport_introspection_c__RobotInfo_message_members = {
  "game_controller_interface__msg",  // message namespace
  "RobotInfo",  // message name
  6,  // number of fields
  sizeof(game_controller_interface__msg__RobotInfo),
  game_controller_interface__msg__RobotInfo__rosidl_typesupport_introspection_c__RobotInfo_message_member_array,  // message members
  game_controller_interface__msg__RobotInfo__rosidl_typesupport_introspection_c__RobotInfo_init_function,  // function to initialize message memory (memory has to be allocated)
  game_controller_interface__msg__RobotInfo__rosidl_typesupport_introspection_c__RobotInfo_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t game_controller_interface__msg__RobotInfo__rosidl_typesupport_introspection_c__RobotInfo_message_type_support_handle = {
  0,
  &game_controller_interface__msg__RobotInfo__rosidl_typesupport_introspection_c__RobotInfo_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_game_controller_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, game_controller_interface, msg, RobotInfo)() {
  if (!game_controller_interface__msg__RobotInfo__rosidl_typesupport_introspection_c__RobotInfo_message_type_support_handle.typesupport_identifier) {
    game_controller_interface__msg__RobotInfo__rosidl_typesupport_introspection_c__RobotInfo_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &game_controller_interface__msg__RobotInfo__rosidl_typesupport_introspection_c__RobotInfo_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
