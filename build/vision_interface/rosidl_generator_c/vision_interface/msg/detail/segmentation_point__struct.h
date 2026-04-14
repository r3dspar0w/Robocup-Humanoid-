// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vision_interface:msg/SegmentationPoint.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_POINT__STRUCT_H_
#define VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_POINT__STRUCT_H_

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

/// Struct defined in msg/SegmentationPoint in the package vision_interface.
typedef struct vision_interface__msg__SegmentationPoint
{
  rosidl_runtime_c__String label;
  double x;
  double y;
  double u;
  double v;
} vision_interface__msg__SegmentationPoint;

// Struct for a sequence of vision_interface__msg__SegmentationPoint.
typedef struct vision_interface__msg__SegmentationPoint__Sequence
{
  vision_interface__msg__SegmentationPoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vision_interface__msg__SegmentationPoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_POINT__STRUCT_H_
