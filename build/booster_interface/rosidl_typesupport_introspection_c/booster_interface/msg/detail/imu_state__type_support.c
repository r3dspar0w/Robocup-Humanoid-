// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from booster_interface:msg/ImuState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "booster_interface/msg/detail/imu_state__rosidl_typesupport_introspection_c.h"
#include "booster_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "booster_interface/msg/detail/imu_state__functions.h"
#include "booster_interface/msg/detail/imu_state__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__ImuState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  booster_interface__msg__ImuState__init(message_memory);
}

void booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__ImuState_fini_function(void * message_memory)
{
  booster_interface__msg__ImuState__fini(message_memory);
}

size_t booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__size_function__ImuState__rpy(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__get_const_function__ImuState__rpy(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__get_function__ImuState__rpy(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__fetch_function__ImuState__rpy(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__get_const_function__ImuState__rpy(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__assign_function__ImuState__rpy(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__get_function__ImuState__rpy(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__size_function__ImuState__gyro(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__get_const_function__ImuState__gyro(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__get_function__ImuState__gyro(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__fetch_function__ImuState__gyro(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__get_const_function__ImuState__gyro(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__assign_function__ImuState__gyro(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__get_function__ImuState__gyro(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__size_function__ImuState__acc(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__get_const_function__ImuState__acc(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__get_function__ImuState__acc(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__fetch_function__ImuState__acc(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__get_const_function__ImuState__acc(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__assign_function__ImuState__acc(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__get_function__ImuState__acc(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__ImuState_message_member_array[3] = {
  {
    "rpy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(booster_interface__msg__ImuState, rpy),  // bytes offset in struct
    NULL,  // default value
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__size_function__ImuState__rpy,  // size() function pointer
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__get_const_function__ImuState__rpy,  // get_const(index) function pointer
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__get_function__ImuState__rpy,  // get(index) function pointer
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__fetch_function__ImuState__rpy,  // fetch(index, &value) function pointer
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__assign_function__ImuState__rpy,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gyro",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(booster_interface__msg__ImuState, gyro),  // bytes offset in struct
    NULL,  // default value
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__size_function__ImuState__gyro,  // size() function pointer
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__get_const_function__ImuState__gyro,  // get_const(index) function pointer
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__get_function__ImuState__gyro,  // get(index) function pointer
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__fetch_function__ImuState__gyro,  // fetch(index, &value) function pointer
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__assign_function__ImuState__gyro,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acc",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(booster_interface__msg__ImuState, acc),  // bytes offset in struct
    NULL,  // default value
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__size_function__ImuState__acc,  // size() function pointer
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__get_const_function__ImuState__acc,  // get_const(index) function pointer
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__get_function__ImuState__acc,  // get(index) function pointer
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__fetch_function__ImuState__acc,  // fetch(index, &value) function pointer
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__assign_function__ImuState__acc,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__ImuState_message_members = {
  "booster_interface__msg",  // message namespace
  "ImuState",  // message name
  3,  // number of fields
  sizeof(booster_interface__msg__ImuState),
  booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__ImuState_message_member_array,  // message members
  booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__ImuState_init_function,  // function to initialize message memory (memory has to be allocated)
  booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__ImuState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__ImuState_message_type_support_handle = {
  0,
  &booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__ImuState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_booster_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, msg, ImuState)() {
  if (!booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__ImuState_message_type_support_handle.typesupport_identifier) {
    booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__ImuState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &booster_interface__msg__ImuState__rosidl_typesupport_introspection_c__ImuState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
