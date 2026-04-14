// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vision_interface:msg/DetectionsTrack.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__DETECTIONS_TRACK__STRUCT_H_
#define VISION_INTERFACE__MSG__DETAIL__DETECTIONS_TRACK__STRUCT_H_

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
// Member 'ball_type'
#include "rosidl_runtime_c/string.h"
// Member 'detected_objects'
#include "vision_interface/msg/detail/detected_object__struct.h"
// Member 'radar_x'
// Member 'radar_y'
// Member 'corner_pos'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/DetectionsTrack in the package vision_interface.
typedef struct vision_interface__msg__DetectionsTrack
{
  std_msgs__msg__Header header;
  /// "yolo" or "pysot" or "none"
  rosidl_runtime_c__String ball_type;
  vision_interface__msg__DetectedObject__Sequence detected_objects;
  rosidl_runtime_c__float__Sequence radar_x;
  rosidl_runtime_c__float__Sequence radar_y;
  rosidl_runtime_c__float__Sequence corner_pos;
} vision_interface__msg__DetectionsTrack;

// Struct for a sequence of vision_interface__msg__DetectionsTrack.
typedef struct vision_interface__msg__DetectionsTrack__Sequence
{
  vision_interface__msg__DetectionsTrack * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vision_interface__msg__DetectionsTrack__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VISION_INTERFACE__MSG__DETAIL__DETECTIONS_TRACK__STRUCT_H_
