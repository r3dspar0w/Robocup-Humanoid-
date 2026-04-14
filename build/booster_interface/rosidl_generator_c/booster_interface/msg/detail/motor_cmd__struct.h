// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_interface:msg/MotorCmd.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__MOTOR_CMD__STRUCT_H_
#define BOOSTER_INTERFACE__MSG__DETAIL__MOTOR_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MotorCmd in the package booster_interface.
typedef struct booster_interface__msg__MotorCmd
{
  int8_t mode;
  float q;
  float dq;
  float tau;
  float kp;
  float kd;
  float weight;
} booster_interface__msg__MotorCmd;

// Struct for a sequence of booster_interface__msg__MotorCmd.
typedef struct booster_interface__msg__MotorCmd__Sequence
{
  booster_interface__msg__MotorCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_interface__msg__MotorCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__MOTOR_CMD__STRUCT_H_
