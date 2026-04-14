// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vision_interface:msg/ImageHeadPosition.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__IMAGE_HEAD_POSITION__STRUCT_H_
#define VISION_INTERFACE__MSG__DETAIL__IMAGE_HEAD_POSITION__STRUCT_H_

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
// Member 'position'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.h"

/// Struct defined in msg/ImageHeadPosition in the package vision_interface.
typedef struct vision_interface__msg__ImageHeadPosition
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Pose position;
  sensor_msgs__msg__Image image;
} vision_interface__msg__ImageHeadPosition;

// Struct for a sequence of vision_interface__msg__ImageHeadPosition.
typedef struct vision_interface__msg__ImageHeadPosition__Sequence
{
  vision_interface__msg__ImageHeadPosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vision_interface__msg__ImageHeadPosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VISION_INTERFACE__MSG__DETAIL__IMAGE_HEAD_POSITION__STRUCT_H_
