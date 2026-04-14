// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from vision_interface:msg/CalParam.idl
// generated code does not contain a copyright notice
#include "vision_interface/msg/detail/cal_param__rosidl_typesupport_fastrtps_cpp.hpp"
#include "vision_interface/msg/detail/cal_param__struct.hpp"

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

namespace vision_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vision_interface
cdr_serialize(
  const vision_interface::msg::CalParam & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: pitch_compensation
  cdr << ros_message.pitch_compensation;
  // Member: yaw_compensation
  cdr << ros_message.yaw_compensation;
  // Member: z_compensation
  cdr << ros_message.z_compensation;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vision_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  vision_interface::msg::CalParam & ros_message)
{
  // Member: pitch_compensation
  cdr >> ros_message.pitch_compensation;

  // Member: yaw_compensation
  cdr >> ros_message.yaw_compensation;

  // Member: z_compensation
  cdr >> ros_message.z_compensation;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vision_interface
get_serialized_size(
  const vision_interface::msg::CalParam & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: pitch_compensation
  {
    size_t item_size = sizeof(ros_message.pitch_compensation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: yaw_compensation
  {
    size_t item_size = sizeof(ros_message.yaw_compensation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: z_compensation
  {
    size_t item_size = sizeof(ros_message.z_compensation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vision_interface
max_serialized_size_CalParam(
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


  // Member: pitch_compensation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: yaw_compensation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: z_compensation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vision_interface::msg::CalParam;
    is_plain =
      (
      offsetof(DataType, z_compensation) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _CalParam__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const vision_interface::msg::CalParam *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _CalParam__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<vision_interface::msg::CalParam *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _CalParam__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const vision_interface::msg::CalParam *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _CalParam__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_CalParam(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _CalParam__callbacks = {
  "vision_interface::msg",
  "CalParam",
  _CalParam__cdr_serialize,
  _CalParam__cdr_deserialize,
  _CalParam__get_serialized_size,
  _CalParam__max_serialized_size
};

static rosidl_message_type_support_t _CalParam__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_CalParam__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace vision_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_vision_interface
const rosidl_message_type_support_t *
get_message_type_support_handle<vision_interface::msg::CalParam>()
{
  return &vision_interface::msg::typesupport_fastrtps_cpp::_CalParam__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vision_interface, msg, CalParam)() {
  return &vision_interface::msg::typesupport_fastrtps_cpp::_CalParam__handle;
}

#ifdef __cplusplus
}
#endif
