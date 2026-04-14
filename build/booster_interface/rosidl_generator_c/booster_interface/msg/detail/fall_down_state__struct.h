// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_interface:msg/FallDownState.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__FALL_DOWN_STATE__STRUCT_H_
#define BOOSTER_INTERFACE__MSG__DETAIL__FALL_DOWN_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'IS_READY'.
enum
{
  booster_interface__msg__FallDownState__IS_READY = 0ul
};

/// Constant 'IS_FALLING'.
enum
{
  booster_interface__msg__FallDownState__IS_FALLING = 1ul
};

/// Constant 'HAS_FALLEN'.
enum
{
  booster_interface__msg__FallDownState__HAS_FALLEN = 2ul
};

/// Constant 'IS_GETTING_UP'.
enum
{
  booster_interface__msg__FallDownState__IS_GETTING_UP = 3ul
};

/// Struct defined in msg/FallDownState in the package booster_interface.
typedef struct booster_interface__msg__FallDownState
{
  uint32_t fall_down_state;
  bool is_recovery_available;
} booster_interface__msg__FallDownState;

// Struct for a sequence of booster_interface__msg__FallDownState.
typedef struct booster_interface__msg__FallDownState__Sequence
{
  booster_interface__msg__FallDownState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_interface__msg__FallDownState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__FALL_DOWN_STATE__STRUCT_H_
