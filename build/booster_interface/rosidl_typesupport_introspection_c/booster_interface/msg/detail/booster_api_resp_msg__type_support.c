// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from booster_interface:msg/BoosterApiRespMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "booster_interface/msg/detail/booster_api_resp_msg__rosidl_typesupport_introspection_c.h"
#include "booster_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "booster_interface/msg/detail/booster_api_resp_msg__functions.h"
#include "booster_interface/msg/detail/booster_api_resp_msg__struct.h"


// Include directives for member types
// Member `body`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void booster_interface__msg__BoosterApiRespMsg__rosidl_typesupport_introspection_c__BoosterApiRespMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  booster_interface__msg__BoosterApiRespMsg__init(message_memory);
}

void booster_interface__msg__BoosterApiRespMsg__rosidl_typesupport_introspection_c__BoosterApiRespMsg_fini_function(void * message_memory)
{
  booster_interface__msg__BoosterApiRespMsg__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember booster_interface__msg__BoosterApiRespMsg__rosidl_typesupport_introspection_c__BoosterApiRespMsg_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(booster_interface__msg__BoosterApiRespMsg, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "body",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(booster_interface__msg__BoosterApiRespMsg, body),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers booster_interface__msg__BoosterApiRespMsg__rosidl_typesupport_introspection_c__BoosterApiRespMsg_message_members = {
  "booster_interface__msg",  // message namespace
  "BoosterApiRespMsg",  // message name
  2,  // number of fields
  sizeof(booster_interface__msg__BoosterApiRespMsg),
  booster_interface__msg__BoosterApiRespMsg__rosidl_typesupport_introspection_c__BoosterApiRespMsg_message_member_array,  // message members
  booster_interface__msg__BoosterApiRespMsg__rosidl_typesupport_introspection_c__BoosterApiRespMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  booster_interface__msg__BoosterApiRespMsg__rosidl_typesupport_introspection_c__BoosterApiRespMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t booster_interface__msg__BoosterApiRespMsg__rosidl_typesupport_introspection_c__BoosterApiRespMsg_message_type_support_handle = {
  0,
  &booster_interface__msg__BoosterApiRespMsg__rosidl_typesupport_introspection_c__BoosterApiRespMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_booster_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, msg, BoosterApiRespMsg)() {
  if (!booster_interface__msg__BoosterApiRespMsg__rosidl_typesupport_introspection_c__BoosterApiRespMsg_message_type_support_handle.typesupport_identifier) {
    booster_interface__msg__BoosterApiRespMsg__rosidl_typesupport_introspection_c__BoosterApiRespMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &booster_interface__msg__BoosterApiRespMsg__rosidl_typesupport_introspection_c__BoosterApiRespMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
