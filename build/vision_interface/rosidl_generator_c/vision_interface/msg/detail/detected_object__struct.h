// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vision_interface:msg/DetectedObject.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__DETECTED_OBJECT__STRUCT_H_
#define VISION_INTERFACE__MSG__DETAIL__DETECTED_OBJECT__STRUCT_H_

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
// Member 'color'
#include "rosidl_runtime_c/string.h"
// Member 'target_uv'
// Member 'received_pos'
// Member 'position'
// Member 'position_projection'
// Member 'position_cam'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/DetectedObject in the package vision_interface.
typedef struct vision_interface__msg__DetectedObject
{
  rosidl_runtime_c__String label;
  rosidl_runtime_c__String color;
  double confidence;
  int64_t xmin;
  int64_t ymin;
  int64_t xmax;
  int64_t ymax;
  rosidl_runtime_c__float__Sequence target_uv;
  rosidl_runtime_c__float__Sequence received_pos;
  rosidl_runtime_c__float__Sequence position;
  rosidl_runtime_c__float__Sequence position_projection;
  rosidl_runtime_c__float__Sequence position_cam;
  int32_t position_confidence;
} vision_interface__msg__DetectedObject;

// Struct for a sequence of vision_interface__msg__DetectedObject.
typedef struct vision_interface__msg__DetectedObject__Sequence
{
  vision_interface__msg__DetectedObject * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vision_interface__msg__DetectedObject__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VISION_INTERFACE__MSG__DETAIL__DETECTED_OBJECT__STRUCT_H_
