// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vision_interface:msg/CalParam.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__CAL_PARAM__STRUCT_H_
#define VISION_INTERFACE__MSG__DETAIL__CAL_PARAM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/CalParam in the package vision_interface.
typedef struct vision_interface__msg__CalParam
{
  /// degs
  float pitch_compensation;
  /// degs
  float yaw_compensation;
  /// m
  float z_compensation;
} vision_interface__msg__CalParam;

// Struct for a sequence of vision_interface__msg__CalParam.
typedef struct vision_interface__msg__CalParam__Sequence
{
  vision_interface__msg__CalParam * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vision_interface__msg__CalParam__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VISION_INTERFACE__MSG__DETAIL__CAL_PARAM__STRUCT_H_
