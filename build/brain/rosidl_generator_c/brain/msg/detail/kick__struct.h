// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from brain:msg/Kick.idl
// generated code does not contain a copyright notice

#ifndef BRAIN__MSG__DETAIL__KICK__STRUCT_H_
#define BRAIN__MSG__DETAIL__KICK__STRUCT_H_

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

/// Struct defined in msg/Kick in the package brain.
typedef struct brain__msg__Kick
{
  std_msgs__msg__Header header;
  /// ball pos to robot x
  double x;
  /// ball pos to robot y
  double y;
  /// disired kick dir relative to robot, rad
  double dir;
  /// goal pos to robot x
  double goal_x;
  /// goal pos to robot y
  double goal_y;
  /// robot theta to field, rad
  double robot_theta_to_field;
  /// disired kick range
  double power;
} brain__msg__Kick;

// Struct for a sequence of brain__msg__Kick.
typedef struct brain__msg__Kick__Sequence
{
  brain__msg__Kick * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} brain__msg__Kick__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BRAIN__MSG__DETAIL__KICK__STRUCT_H_
