// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vision_interface:msg/Detections.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__DETECTIONS__STRUCT_H_
#define VISION_INTERFACE__MSG__DETAIL__DETECTIONS__STRUCT_H_

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
// Member 'detected_objects'
#include "vision_interface/msg/detail/detected_object__struct.h"
// Member 'radar_x'
// Member 'radar_y'
// Member 'corner_pos'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Detections in the package vision_interface.
typedef struct vision_interface__msg__Detections
{
  std_msgs__msg__Header header;
  vision_interface__msg__DetectedObject__Sequence detected_objects;
  rosidl_runtime_c__float__Sequence radar_x;
  rosidl_runtime_c__float__Sequence radar_y;
  rosidl_runtime_c__float__Sequence corner_pos;
} vision_interface__msg__Detections;

// Struct for a sequence of vision_interface__msg__Detections.
typedef struct vision_interface__msg__Detections__Sequence
{
  vision_interface__msg__Detections * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vision_interface__msg__Detections__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VISION_INTERFACE__MSG__DETAIL__DETECTIONS__STRUCT_H_
