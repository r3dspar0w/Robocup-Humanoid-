// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_interface:msg/BoosterApiReqMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__BOOSTER_API_REQ_MSG__STRUCT_H_
#define BOOSTER_INTERFACE__MSG__DETAIL__BOOSTER_API_REQ_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'body'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/BoosterApiReqMsg in the package booster_interface.
typedef struct booster_interface__msg__BoosterApiReqMsg
{
  int64_t api_id;
  rosidl_runtime_c__String body;
} booster_interface__msg__BoosterApiReqMsg;

// Struct for a sequence of booster_interface__msg__BoosterApiReqMsg.
typedef struct booster_interface__msg__BoosterApiReqMsg__Sequence
{
  booster_interface__msg__BoosterApiReqMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_interface__msg__BoosterApiReqMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__BOOSTER_API_REQ_MSG__STRUCT_H_
