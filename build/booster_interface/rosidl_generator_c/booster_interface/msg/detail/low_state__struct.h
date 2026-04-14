// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_interface:msg/LowState.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__LOW_STATE__STRUCT_H_
#define BOOSTER_INTERFACE__MSG__DETAIL__LOW_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'imu_state'
#include "booster_interface/msg/detail/imu_state__struct.h"
// Member 'motor_state_parallel'
// Member 'motor_state_serial'
#include "booster_interface/msg/detail/motor_state__struct.h"

/// Struct defined in msg/LowState in the package booster_interface.
typedef struct booster_interface__msg__LowState
{
  booster_interface__msg__ImuState imu_state;
  booster_interface__msg__MotorState__Sequence motor_state_parallel;
  booster_interface__msg__MotorState__Sequence motor_state_serial;
} booster_interface__msg__LowState;

// Struct for a sequence of booster_interface__msg__LowState.
typedef struct booster_interface__msg__LowState__Sequence
{
  booster_interface__msg__LowState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_interface__msg__LowState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__LOW_STATE__STRUCT_H_
