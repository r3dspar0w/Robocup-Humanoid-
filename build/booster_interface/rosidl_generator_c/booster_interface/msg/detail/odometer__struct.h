// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_interface:msg/Odometer.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__ODOMETER__STRUCT_H_
#define BOOSTER_INTERFACE__MSG__DETAIL__ODOMETER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Odometer in the package booster_interface.
typedef struct booster_interface__msg__Odometer
{
  float x;
  float y;
  float theta;
} booster_interface__msg__Odometer;

// Struct for a sequence of booster_interface__msg__Odometer.
typedef struct booster_interface__msg__Odometer__Sequence
{
  booster_interface__msg__Odometer * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_interface__msg__Odometer__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__ODOMETER__STRUCT_H_
