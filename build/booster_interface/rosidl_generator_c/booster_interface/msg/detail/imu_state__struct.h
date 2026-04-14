// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_interface:msg/ImuState.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__IMU_STATE__STRUCT_H_
#define BOOSTER_INTERFACE__MSG__DETAIL__IMU_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ImuState in the package booster_interface.
/**
  * （0 -> roll ,1 -> pitch ,2 -> yaw）
 */
typedef struct booster_interface__msg__ImuState
{
  float rpy[3];
  /// （0 -> x ,1 -> y ,2 -> z）
  float gyro[3];
  /// （0 -> x ,1 -> y ,2 -> z）
  float acc[3];
} booster_interface__msg__ImuState;

// Struct for a sequence of booster_interface__msg__ImuState.
typedef struct booster_interface__msg__ImuState__Sequence
{
  booster_interface__msg__ImuState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_interface__msg__ImuState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__IMU_STATE__STRUCT_H_
