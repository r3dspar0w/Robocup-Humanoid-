// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vision_interface:msg/SegmentationLine.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_LINE__STRUCT_H_
#define VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_LINE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'label'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SegmentationLine in the package vision_interface.
typedef struct vision_interface__msg__SegmentationLine
{
  rosidl_runtime_c__String label;
  double x1;
  double y1;
  double x2;
  double y2;
  double u1;
  double v1;
  double u2;
  double v2;
} vision_interface__msg__SegmentationLine;

// Struct for a sequence of vision_interface__msg__SegmentationLine.
typedef struct vision_interface__msg__SegmentationLine__Sequence
{
  vision_interface__msg__SegmentationLine * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vision_interface__msg__SegmentationLine__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_LINE__STRUCT_H_
