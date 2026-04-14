// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_interface:msg/HandDdsMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__HAND_DDS_MSG__STRUCT_H_
#define BOOSTER_INTERFACE__MSG__DETAIL__HAND_DDS_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'hands_vec'
#include "booster_interface/msg/detail/hand_command__struct.h"

/// Struct defined in msg/HandDdsMsg in the package booster_interface.
typedef struct booster_interface__msg__HandDdsMsg
{
  booster_interface__msg__HandCommand__Sequence hands_vec;
} booster_interface__msg__HandDdsMsg;

// Struct for a sequence of booster_interface__msg__HandDdsMsg.
typedef struct booster_interface__msg__HandDdsMsg__Sequence
{
  booster_interface__msg__HandDdsMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_interface__msg__HandDdsMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__HAND_DDS_MSG__STRUCT_H_
