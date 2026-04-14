// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vision_interface:msg/Ball.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__BALL__STRUCT_H_
#define VISION_INTERFACE__MSG__DETAIL__BALL__STRUCT_H_

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

/// Struct defined in msg/Ball in the package vision_interface.
typedef struct vision_interface__msg__Ball
{
  std_msgs__msg__Header header;
  double x;
  double y;
  double confidence;
} vision_interface__msg__Ball;

// Struct for a sequence of vision_interface__msg__Ball.
typedef struct vision_interface__msg__Ball__Sequence
{
  vision_interface__msg__Ball * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vision_interface__msg__Ball__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VISION_INTERFACE__MSG__DETAIL__BALL__STRUCT_H_
