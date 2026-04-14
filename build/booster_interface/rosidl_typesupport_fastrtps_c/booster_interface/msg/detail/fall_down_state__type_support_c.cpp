// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from booster_interface:msg/FallDownState.idl
// generated code does not contain a copyright notice
#include "booster_interface/msg/detail/fall_down_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "booster_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "booster_interface/msg/detail/fall_down_state__struct.h"
#include "booster_interface/msg/detail/fall_down_state__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _FallDownState__ros_msg_type = booster_interface__msg__FallDownState;

static bool _FallDownState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _FallDownState__ros_msg_type * ros_message = static_cast<const _FallDownState__ros_msg_type *>(untyped_ros_message);
  // Field name: fall_down_state
  {
    cdr << ros_message->fall_down_state;
  }

  // Field name: is_recovery_available
  {
    cdr << (ros_message->is_recovery_available ? true : false);
  }

  return true;
}

static bool _FallDownState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FallDownState__ros_msg_type * ros_message = static_cast<_FallDownState__ros_msg_type *>(untyped_ros_message);
  // Field name: fall_down_state
  {
    cdr >> ros_message->fall_down_state;
  }

  // Field name: is_recovery_available
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_recovery_available = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_booster_interface
size_t get_serialized_size_booster_interface__msg__FallDownState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FallDownState__ros_msg_type * ros_message = static_cast<const _FallDownState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name fall_down_state
  {
    size_t item_size = sizeof(ros_message->fall_down_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_recovery_available
  {
    size_t item_size = sizeof(ros_message->is_recovery_available);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _FallDownState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_booster_interface__msg__FallDownState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_booster_interface
size_t max_serialized_size_booster_interface__msg__FallDownState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: fall_down_state
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: is_recovery_available
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = booster_interface__msg__FallDownState;
    is_plain =
      (
      offsetof(DataType, is_recovery_available) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _FallDownState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_booster_interface__msg__FallDownState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FallDownState = {
  "booster_interface::msg",
  "FallDownState",
  _FallDownState__cdr_serialize,
  _FallDownState__cdr_deserialize,
  _FallDownState__get_serialized_size,
  _FallDownState__max_serialized_size
};

static rosidl_message_type_support_t _FallDownState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FallDownState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, booster_interface, msg, FallDownState)() {
  return &_FallDownState__type_support;
}

#if defined(__cplusplus)
}
#endif
