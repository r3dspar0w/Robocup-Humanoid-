// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from booster_interface:msg/FallDownState.idl
// generated code does not contain a copyright notice
#include "booster_interface/msg/detail/fall_down_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "booster_interface/msg/detail/fall_down_state__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace booster_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_booster_interface
cdr_serialize(
  const booster_interface::msg::FallDownState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: fall_down_state
  cdr << ros_message.fall_down_state;
  // Member: is_recovery_available
  cdr << (ros_message.is_recovery_available ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_booster_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  booster_interface::msg::FallDownState & ros_message)
{
  // Member: fall_down_state
  cdr >> ros_message.fall_down_state;

  // Member: is_recovery_available
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_recovery_available = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_booster_interface
get_serialized_size(
  const booster_interface::msg::FallDownState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: fall_down_state
  {
    size_t item_size = sizeof(ros_message.fall_down_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_recovery_available
  {
    size_t item_size = sizeof(ros_message.is_recovery_available);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_booster_interface
max_serialized_size_FallDownState(
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


  // Member: fall_down_state
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: is_recovery_available
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
    using DataType = booster_interface::msg::FallDownState;
    is_plain =
      (
      offsetof(DataType, is_recovery_available) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _FallDownState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const booster_interface::msg::FallDownState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _FallDownState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<booster_interface::msg::FallDownState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _FallDownState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const booster_interface::msg::FallDownState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _FallDownState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_FallDownState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _FallDownState__callbacks = {
  "booster_interface::msg",
  "FallDownState",
  _FallDownState__cdr_serialize,
  _FallDownState__cdr_deserialize,
  _FallDownState__get_serialized_size,
  _FallDownState__max_serialized_size
};

static rosidl_message_type_support_t _FallDownState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_FallDownState__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace booster_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_booster_interface
const rosidl_message_type_support_t *
get_message_type_support_handle<booster_interface::msg::FallDownState>()
{
  return &booster_interface::msg::typesupport_fastrtps_cpp::_FallDownState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, booster_interface, msg, FallDownState)() {
  return &booster_interface::msg::typesupport_fastrtps_cpp::_FallDownState__handle;
}

#ifdef __cplusplus
}
#endif
