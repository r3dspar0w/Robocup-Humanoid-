// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_interface:msg/MotorState.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__MOTOR_STATE__STRUCT_H_
#define BOOSTER_INTERFACE__MSG__DETAIL__MOTOR_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MotorState in the package booster_interface.
typedef struct booster_interface__msg__MotorState
{
  int8_t mode;
  float q;
  float dq;
  float ddq;
  float tau_est;
  /// Motor temperature (int8): actual value, range -100 to 150.
  int8_t temperature;
  /// Motor packet loss count (uint32): actual value, range 0 to 9999999999.
  uint32_t lost;
  /// Motor communication info: array of two uint32s.
  ///   index 0 = error flags (0-255), index 1 = communication frequency (0-800).
  uint32_t reserve[2];
} booster_interface__msg__MotorState;

// Struct for a sequence of booster_interface__msg__MotorState.
typedef struct booster_interface__msg__MotorState__Sequence
{
  booster_interface__msg__MotorState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_interface__msg__MotorState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__MOTOR_STATE__STRUCT_H_
