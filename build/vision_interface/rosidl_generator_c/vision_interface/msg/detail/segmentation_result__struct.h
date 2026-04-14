// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vision_interface:msg/SegmentationResult.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_RESULT__STRUCT_H_
#define VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_RESULT__STRUCT_H_

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
// Member 'lines'
#include "vision_interface/msg/detail/segmentation_line__struct.h"
// Member 'points'
#include "vision_interface/msg/detail/segmentation_point__struct.h"

/// Struct defined in msg/SegmentationResult in the package vision_interface.
typedef struct vision_interface__msg__SegmentationResult
{
  std_msgs__msg__Header header;
  vision_interface__msg__SegmentationLine__Sequence lines;
  vision_interface__msg__SegmentationPoint__Sequence points;
} vision_interface__msg__SegmentationResult;

// Struct for a sequence of vision_interface__msg__SegmentationResult.
typedef struct vision_interface__msg__SegmentationResult__Sequence
{
  vision_interface__msg__SegmentationResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vision_interface__msg__SegmentationResult__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_RESULT__STRUCT_H_
