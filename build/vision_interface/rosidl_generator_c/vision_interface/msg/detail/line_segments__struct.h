// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vision_interface:msg/LineSegments.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__LINE_SEGMENTS__STRUCT_H_
#define VISION_INTERFACE__MSG__DETAIL__LINE_SEGMENTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'coordinates'
// Member 'coordinates_uv'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/LineSegments in the package vision_interface.
typedef struct vision_interface__msg__LineSegments
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__float__Sequence coordinates;
  rosidl_runtime_c__float__Sequence coordinates_uv;
} vision_interface__msg__LineSegments;

// Struct for a sequence of vision_interface__msg__LineSegments.
typedef struct vision_interface__msg__LineSegments__Sequence
{
  vision_interface__msg__LineSegments * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vision_interface__msg__LineSegments__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VISION_INTERFACE__MSG__DETAIL__LINE_SEGMENTS__STRUCT_H_
