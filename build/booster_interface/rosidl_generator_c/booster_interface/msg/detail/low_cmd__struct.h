// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_interface:msg/LowCmd.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__LOW_CMD__STRUCT_H_
#define BOOSTER_INTERFACE__MSG__DETAIL__LOW_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'CMD_TYPE_PARALLEL'.
enum
{
  booster_interface__msg__LowCmd__CMD_TYPE_PARALLEL = 0
};

/// Constant 'CMD_TYPE_SERIAL'.
enum
{
  booster_interface__msg__LowCmd__CMD_TYPE_SERIAL = 1
};

// Include directives for member types
// Member 'motor_cmd'
#include "booster_interface/msg/detail/motor_cmd__struct.h"

/// Struct defined in msg/LowCmd in the package booster_interface.
/**
  * constants
 */
typedef struct booster_interface__msg__LowCmd
{
  /// fields
  /// use CMD_TYPE_PARALLEL or CMD_TYPE_SERIAL
  int8_t cmd_type;
  booster_interface__msg__MotorCmd__Sequence motor_cmd;
} booster_interface__msg__LowCmd;

// Struct for a sequence of booster_interface__msg__LowCmd.
typedef struct booster_interface__msg__LowCmd__Sequence
{
  booster_interface__msg__LowCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_interface__msg__LowCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__LOW_CMD__STRUCT_H_
