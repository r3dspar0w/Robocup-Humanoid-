// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_interface:msg/RawBytesMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__RAW_BYTES_MSG__STRUCT_H_
#define BOOSTER_INTERFACE__MSG__DETAIL__RAW_BYTES_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'msg'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/RawBytesMsg in the package booster_interface.
typedef struct booster_interface__msg__RawBytesMsg
{
  rosidl_runtime_c__uint8__Sequence msg;
} booster_interface__msg__RawBytesMsg;

// Struct for a sequence of booster_interface__msg__RawBytesMsg.
typedef struct booster_interface__msg__RawBytesMsg__Sequence
{
  booster_interface__msg__RawBytesMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_interface__msg__RawBytesMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__RAW_BYTES_MSG__STRUCT_H_
