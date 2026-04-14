// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_interface:msg/ButtonEventMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__BUTTON_EVENT_MSG__STRUCT_H_
#define BOOSTER_INTERFACE__MSG__DETAIL__BUTTON_EVENT_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'PRESS_DOWN'.
enum
{
  booster_interface__msg__ButtonEventMsg__PRESS_DOWN = 0
};

/// Constant 'PRESS_UP'.
enum
{
  booster_interface__msg__ButtonEventMsg__PRESS_UP = 1
};

/// Constant 'SINGLE_CLICK'.
enum
{
  booster_interface__msg__ButtonEventMsg__SINGLE_CLICK = 0
};

/// Constant 'DOUBLE_CLICK'.
enum
{
  booster_interface__msg__ButtonEventMsg__DOUBLE_CLICK = 1
};

/// Constant 'TRIPLE_CLICK'.
enum
{
  booster_interface__msg__ButtonEventMsg__TRIPLE_CLICK = 0
};

/// Constant 'LONG_PRESS_START'.
enum
{
  booster_interface__msg__ButtonEventMsg__LONG_PRESS_START = 1
};

/// Constant 'LONG_PRESS_HOLD'.
enum
{
  booster_interface__msg__ButtonEventMsg__LONG_PRESS_HOLD = 0
};

/// Constant 'LONG_PRESS_END'.
enum
{
  booster_interface__msg__ButtonEventMsg__LONG_PRESS_END = 1
};

/// Struct defined in msg/ButtonEventMsg in the package booster_interface.
/**
  * constants
 */
typedef struct booster_interface__msg__ButtonEventMsg
{
  /// fields
  int8_t event;
  int32_t button;
} booster_interface__msg__ButtonEventMsg;

// Struct for a sequence of booster_interface__msg__ButtonEventMsg.
typedef struct booster_interface__msg__ButtonEventMsg__Sequence
{
  booster_interface__msg__ButtonEventMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_interface__msg__ButtonEventMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__BUTTON_EVENT_MSG__STRUCT_H_
