// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_msgs:msg/BinaryData.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_MSGS__MSG__DETAIL__BINARY_DATA__STRUCT_H_
#define BOOSTER_MSGS__MSG__DETAIL__BINARY_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/BinaryData in the package booster_msgs.
typedef struct booster_msgs__msg__BinaryData
{
  rosidl_runtime_c__uint8__Sequence data;
} booster_msgs__msg__BinaryData;

// Struct for a sequence of booster_msgs__msg__BinaryData.
typedef struct booster_msgs__msg__BinaryData__Sequence
{
  booster_msgs__msg__BinaryData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_msgs__msg__BinaryData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_MSGS__MSG__DETAIL__BINARY_DATA__STRUCT_H_
