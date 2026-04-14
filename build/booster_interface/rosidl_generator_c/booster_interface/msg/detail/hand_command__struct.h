// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_interface:msg/HandCommand.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__HAND_COMMAND__STRUCT_H_
#define BOOSTER_INTERFACE__MSG__DETAIL__HAND_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'hand_param'
#include "booster_interface/msg/detail/hand_param__struct.h"

/// Struct defined in msg/HandCommand in the package booster_interface.
typedef struct booster_interface__msg__HandCommand
{
  booster_interface__msg__HandParam__Sequence hand_param;
  int32_t force_mode;
  int32_t hand_index;
  int32_t hand_type;
} booster_interface__msg__HandCommand;

// Struct for a sequence of booster_interface__msg__HandCommand.
typedef struct booster_interface__msg__HandCommand__Sequence
{
  booster_interface__msg__HandCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_interface__msg__HandCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__HAND_COMMAND__STRUCT_H_
