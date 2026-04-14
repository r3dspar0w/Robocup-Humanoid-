// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_interface:msg/RemoteControllerState.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__REMOTE_CONTROLLER_STATE__STRUCT_H_
#define BOOSTER_INTERFACE__MSG__DETAIL__REMOTE_CONTROLLER_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RemoteControllerState in the package booster_interface.
typedef struct booster_interface__msg__RemoteControllerState
{
  /// SDL_EventType, value reference from SDL2/SDL_events.h
  uint32_t event;
  /// left stick horizontal direction, push left to -1, push right to 1
  float lx;
  /// left stick vertical direction, push front to -1, push back to 1
  float ly;
  /// right stick horizontal direction, push left to -1, push right to 1
  float rx;
  /// right stick vertical direction, push front to -1, push back to 1
  float ry;
  bool a;
  bool b;
  bool x;
  bool y;
  bool lb;
  bool rb;
  bool lt;
  bool rt;
  bool ls;
  bool rs;
  bool back;
  bool start;
  /// Hat centered
  bool hat_c;
  /// Hat up
  bool hat_u;
  /// Hat down
  bool hat_d;
  /// Hat left
  bool hat_l;
  /// Hat right
  bool hat_r;
  /// Hat left up
  bool hat_lu;
  /// Hat left down
  bool hat_ld;
  /// Hat right up
  bool hat_ru;
  /// Hat right down
  bool hat_rd;
  /// Hat position, value reference from SDL2/SDL_joystick.h
  uint8_t hat_pos;
} booster_interface__msg__RemoteControllerState;

// Struct for a sequence of booster_interface__msg__RemoteControllerState.
typedef struct booster_interface__msg__RemoteControllerState__Sequence
{
  booster_interface__msg__RemoteControllerState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_interface__msg__RemoteControllerState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__REMOTE_CONTROLLER_STATE__STRUCT_H_
