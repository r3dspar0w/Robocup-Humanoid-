// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vision_interface:msg/CalParam.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vision_interface/msg/detail/cal_param__rosidl_typesupport_introspection_c.h"
#include "vision_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vision_interface/msg/detail/cal_param__functions.h"
#include "vision_interface/msg/detail/cal_param__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void vision_interface__msg__CalParam__rosidl_typesupport_introspection_c__CalParam_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vision_interface__msg__CalParam__init(message_memory);
}

void vision_interface__msg__CalParam__rosidl_typesupport_introspection_c__CalParam_fini_function(void * message_memory)
{
  vision_interface__msg__CalParam__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vision_interface__msg__CalParam__rosidl_typesupport_introspection_c__CalParam_message_member_array[3] = {
  {
    "pitch_compensation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__CalParam, pitch_compensation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw_compensation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__CalParam, yaw_compensation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z_compensation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__CalParam, z_compensation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vision_interface__msg__CalParam__rosidl_typesupport_introspection_c__CalParam_message_members = {
  "vision_interface__msg",  // message namespace
  "CalParam",  // message name
  3,  // number of fields
  sizeof(vision_interface__msg__CalParam),
  vision_interface__msg__CalParam__rosidl_typesupport_introspection_c__CalParam_message_member_array,  // message members
  vision_interface__msg__CalParam__rosidl_typesupport_introspection_c__CalParam_init_function,  // function to initialize message memory (memory has to be allocated)
  vision_interface__msg__CalParam__rosidl_typesupport_introspection_c__CalParam_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vision_interface__msg__CalParam__rosidl_typesupport_introspection_c__CalParam_message_type_support_handle = {
  0,
  &vision_interface__msg__CalParam__rosidl_typesupport_introspection_c__CalParam_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vision_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vision_interface, msg, CalParam)() {
  if (!vision_interface__msg__CalParam__rosidl_typesupport_introspection_c__CalParam_message_type_support_handle.typesupport_identifier) {
    vision_interface__msg__CalParam__rosidl_typesupport_introspection_c__CalParam_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vision_interface__msg__CalParam__rosidl_typesupport_introspection_c__CalParam_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
