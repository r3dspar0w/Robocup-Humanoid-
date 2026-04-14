// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from booster_interface:msg/RawBytesStamped.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "booster_interface/msg/detail/raw_bytes_stamped__rosidl_typesupport_introspection_c.h"
#include "booster_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "booster_interface/msg/detail/raw_bytes_stamped__functions.h"
#include "booster_interface/msg/detail/raw_bytes_stamped__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `msg`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__RawBytesStamped_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  booster_interface__msg__RawBytesStamped__init(message_memory);
}

void booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__RawBytesStamped_fini_function(void * message_memory)
{
  booster_interface__msg__RawBytesStamped__fini(message_memory);
}

size_t booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__size_function__RawBytesStamped__msg(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__get_const_function__RawBytesStamped__msg(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__get_function__RawBytesStamped__msg(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__fetch_function__RawBytesStamped__msg(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__get_const_function__RawBytesStamped__msg(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__assign_function__RawBytesStamped__msg(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__get_function__RawBytesStamped__msg(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__resize_function__RawBytesStamped__msg(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__RawBytesStamped_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(booster_interface__msg__RawBytesStamped, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "msg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(booster_interface__msg__RawBytesStamped, msg),  // bytes offset in struct
    NULL,  // default value
    booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__size_function__RawBytesStamped__msg,  // size() function pointer
    booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__get_const_function__RawBytesStamped__msg,  // get_const(index) function pointer
    booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__get_function__RawBytesStamped__msg,  // get(index) function pointer
    booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__fetch_function__RawBytesStamped__msg,  // fetch(index, &value) function pointer
    booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__assign_function__RawBytesStamped__msg,  // assign(index, value) function pointer
    booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__resize_function__RawBytesStamped__msg  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__RawBytesStamped_message_members = {
  "booster_interface__msg",  // message namespace
  "RawBytesStamped",  // message name
  2,  // number of fields
  sizeof(booster_interface__msg__RawBytesStamped),
  booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__RawBytesStamped_message_member_array,  // message members
  booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__RawBytesStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__RawBytesStamped_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__RawBytesStamped_message_type_support_handle = {
  0,
  &booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__RawBytesStamped_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_booster_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, msg, RawBytesStamped)() {
  booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__RawBytesStamped_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__RawBytesStamped_message_type_support_handle.typesupport_identifier) {
    booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__RawBytesStamped_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &booster_interface__msg__RawBytesStamped__rosidl_typesupport_introspection_c__RawBytesStamped_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
