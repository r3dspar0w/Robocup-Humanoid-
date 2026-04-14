// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from game_controller_interface:msg/RobotInfo.idl
// generated code does not contain a copyright notice
#include "game_controller_interface/msg/detail/robot_info__rosidl_typesupport_fastrtps_cpp.hpp"
#include "game_controller_interface/msg/detail/robot_info__struct.hpp"

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

namespace game_controller_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_game_controller_interface
cdr_serialize(
  const game_controller_interface::msg::RobotInfo & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: penalty
  cdr << ros_message.penalty;
  // Member: secs_till_unpenalised
  cdr << ros_message.secs_till_unpenalised;
  // Member: number_of_warnings
  cdr << ros_message.number_of_warnings;
  // Member: yellow_card_count
  cdr << ros_message.yellow_card_count;
  // Member: red_card_count
  cdr << ros_message.red_card_count;
  // Member: goal_keeper
  cdr << (ros_message.goal_keeper ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_game_controller_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  game_controller_interface::msg::RobotInfo & ros_message)
{
  // Member: penalty
  cdr >> ros_message.penalty;

  // Member: secs_till_unpenalised
  cdr >> ros_message.secs_till_unpenalised;

  // Member: number_of_warnings
  cdr >> ros_message.number_of_warnings;

  // Member: yellow_card_count
  cdr >> ros_message.yellow_card_count;

  // Member: red_card_count
  cdr >> ros_message.red_card_count;

  // Member: goal_keeper
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.goal_keeper = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_game_controller_interface
get_serialized_size(
  const game_controller_interface::msg::RobotInfo & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: penalty
  {
    size_t item_size = sizeof(ros_message.penalty);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: secs_till_unpenalised
  {
    size_t item_size = sizeof(ros_message.secs_till_unpenalised);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: number_of_warnings
  {
    size_t item_size = sizeof(ros_message.number_of_warnings);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: yellow_card_count
  {
    size_t item_size = sizeof(ros_message.yellow_card_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_card_count
  {
    size_t item_size = sizeof(ros_message.red_card_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: goal_keeper
  {
    size_t item_size = sizeof(ros_message.goal_keeper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_game_controller_interface
max_serialized_size_RobotInfo(
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


  // Member: penalty
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: secs_till_unpenalised
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: number_of_warnings
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: yellow_card_count
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: red_card_count
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: goal_keeper
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
    using DataType = game_controller_interface::msg::RobotInfo;
    is_plain =
      (
      offsetof(DataType, goal_keeper) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _RobotInfo__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const game_controller_interface::msg::RobotInfo *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RobotInfo__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<game_controller_interface::msg::RobotInfo *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RobotInfo__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const game_controller_interface::msg::RobotInfo *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RobotInfo__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RobotInfo(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RobotInfo__callbacks = {
  "game_controller_interface::msg",
  "RobotInfo",
  _RobotInfo__cdr_serialize,
  _RobotInfo__cdr_deserialize,
  _RobotInfo__get_serialized_size,
  _RobotInfo__max_serialized_size
};

static rosidl_message_type_support_t _RobotInfo__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RobotInfo__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace game_controller_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_game_controller_interface
const rosidl_message_type_support_t *
get_message_type_support_handle<game_controller_interface::msg::RobotInfo>()
{
  return &game_controller_interface::msg::typesupport_fastrtps_cpp::_RobotInfo__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, game_controller_interface, msg, RobotInfo)() {
  return &game_controller_interface::msg::typesupport_fastrtps_cpp::_RobotInfo__handle;
}

#ifdef __cplusplus
}
#endif
