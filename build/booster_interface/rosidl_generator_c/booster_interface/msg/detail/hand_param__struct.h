// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_interface:msg/HandParam.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__HAND_PARAM__STRUCT_H_
#define BOOSTER_INTERFACE__MSG__DETAIL__HAND_PARAM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/HandParam in the package booster_interface.
typedef struct booster_interface__msg__HandParam
{
  int32_t angle;
  int32_t force;
  int32_t speed;
  int32_t seq;
} booster_interface__msg__HandParam;

// Struct for a sequence of booster_interface__msg__HandParam.
typedef struct booster_interface__msg__HandParam__Sequence
{
  booster_interface__msg__HandParam * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_interface__msg__HandParam__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__HAND_PARAM__STRUCT_H_
