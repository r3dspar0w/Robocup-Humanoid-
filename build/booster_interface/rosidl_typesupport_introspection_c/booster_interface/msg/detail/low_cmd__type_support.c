// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from booster_interface:msg/LowCmd.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "booster_interface/msg/detail/low_cmd__rosidl_typesupport_introspection_c.h"
#include "booster_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "booster_interface/msg/detail/low_cmd__functions.h"
#include "booster_interface/msg/detail/low_cmd__struct.h"


// Include directives for member types
// Member `motor_cmd`
#include "booster_interface/msg/motor_cmd.h"
// Member `motor_cmd`
#include "booster_interface/msg/detail/motor_cmd__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__LowCmd_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  booster_interface__msg__LowCmd__init(message_memory);
}

void booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__LowCmd_fini_function(void * message_memory)
{
  booster_interface__msg__LowCmd__fini(message_memory);
}

size_t booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__size_function__LowCmd__motor_cmd(
  const void * untyped_member)
{
  const booster_interface__msg__MotorCmd__Sequence * member =
    (const booster_interface__msg__MotorCmd__Sequence *)(untyped_member);
  return member->size;
}

const void * booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__get_const_function__LowCmd__motor_cmd(
  const void * untyped_member, size_t index)
{
  const booster_interface__msg__MotorCmd__Sequence * member =
    (const booster_interface__msg__MotorCmd__Sequence *)(untyped_member);
  return &member->data[index];
}

void * booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__get_function__LowCmd__motor_cmd(
  void * untyped_member, size_t index)
{
  booster_interface__msg__MotorCmd__Sequence * member =
    (booster_interface__msg__MotorCmd__Sequence *)(untyped_member);
  return &member->data[index];
}

void booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__fetch_function__LowCmd__motor_cmd(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const booster_interface__msg__MotorCmd * item =
    ((const booster_interface__msg__MotorCmd *)
    booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__get_const_function__LowCmd__motor_cmd(untyped_member, index));
  booster_interface__msg__MotorCmd * value =
    (booster_interface__msg__MotorCmd *)(untyped_value);
  *value = *item;
}

void booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__assign_function__LowCmd__motor_cmd(
  void * untyped_member, size_t index, const void * untyped_value)
{
  booster_interface__msg__MotorCmd * item =
    ((booster_interface__msg__MotorCmd *)
    booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__get_function__LowCmd__motor_cmd(untyped_member, index));
  const booster_interface__msg__MotorCmd * value =
    (const booster_interface__msg__MotorCmd *)(untyped_value);
  *item = *value;
}

bool booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__resize_function__LowCmd__motor_cmd(
  void * untyped_member, size_t size)
{
  booster_interface__msg__MotorCmd__Sequence * member =
    (booster_interface__msg__MotorCmd__Sequence *)(untyped_member);
  booster_interface__msg__MotorCmd__Sequence__fini(member);
  return booster_interface__msg__MotorCmd__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__LowCmd_message_member_array[2] = {
  {
    "cmd_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(booster_interface__msg__LowCmd, cmd_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "motor_cmd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(booster_interface__msg__LowCmd, motor_cmd),  // bytes offset in struct
    NULL,  // default value
    booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__size_function__LowCmd__motor_cmd,  // size() function pointer
    booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__get_const_function__LowCmd__motor_cmd,  // get_const(index) function pointer
    booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__get_function__LowCmd__motor_cmd,  // get(index) function pointer
    booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__fetch_function__LowCmd__motor_cmd,  // fetch(index, &value) function pointer
    booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__assign_function__LowCmd__motor_cmd,  // assign(index, value) function pointer
    booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__resize_function__LowCmd__motor_cmd  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__LowCmd_message_members = {
  "booster_interface__msg",  // message namespace
  "LowCmd",  // message name
  2,  // number of fields
  sizeof(booster_interface__msg__LowCmd),
  booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__LowCmd_message_member_array,  // message members
  booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__LowCmd_init_function,  // function to initialize message memory (memory has to be allocated)
  booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__LowCmd_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__LowCmd_message_type_support_handle = {
  0,
  &booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__LowCmd_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_booster_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, msg, LowCmd)() {
  booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__LowCmd_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, msg, MotorCmd)();
  if (!booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__LowCmd_message_type_support_handle.typesupport_identifier) {
    booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__LowCmd_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &booster_interface__msg__LowCmd__rosidl_typesupport_introspection_c__LowCmd_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
