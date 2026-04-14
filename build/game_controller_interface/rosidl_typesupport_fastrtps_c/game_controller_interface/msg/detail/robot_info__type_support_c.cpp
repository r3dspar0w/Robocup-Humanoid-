// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from game_controller_interface:msg/RobotInfo.idl
// generated code does not contain a copyright notice
#include "game_controller_interface/msg/detail/robot_info__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "game_controller_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "game_controller_interface/msg/detail/robot_info__struct.h"
#include "game_controller_interface/msg/detail/robot_info__functions.h"
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


using _RobotInfo__ros_msg_type = game_controller_interface__msg__RobotInfo;

static bool _RobotInfo__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RobotInfo__ros_msg_type * ros_message = static_cast<const _RobotInfo__ros_msg_type *>(untyped_ros_message);
  // Field name: penalty
  {
    cdr << ros_message->penalty;
  }

  // Field name: secs_till_unpenalised
  {
    cdr << ros_message->secs_till_unpenalised;
  }

  // Field name: number_of_warnings
  {
    cdr << ros_message->number_of_warnings;
  }

  // Field name: yellow_card_count
  {
    cdr << ros_message->yellow_card_count;
  }

  // Field name: red_card_count
  {
    cdr << ros_message->red_card_count;
  }

  // Field name: goal_keeper
  {
    cdr << (ros_message->goal_keeper ? true : false);
  }

  return true;
}

static bool _RobotInfo__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RobotInfo__ros_msg_type * ros_message = static_cast<_RobotInfo__ros_msg_type *>(untyped_ros_message);
  // Field name: penalty
  {
    cdr >> ros_message->penalty;
  }

  // Field name: secs_till_unpenalised
  {
    cdr >> ros_message->secs_till_unpenalised;
  }

  // Field name: number_of_warnings
  {
    cdr >> ros_message->number_of_warnings;
  }

  // Field name: yellow_card_count
  {
    cdr >> ros_message->yellow_card_count;
  }

  // Field name: red_card_count
  {
    cdr >> ros_message->red_card_count;
  }

  // Field name: goal_keeper
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->goal_keeper = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_game_controller_interface
size_t get_serialized_size_game_controller_interface__msg__RobotInfo(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RobotInfo__ros_msg_type * ros_message = static_cast<const _RobotInfo__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name penalty
  {
    size_t item_size = sizeof(ros_message->penalty);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name secs_till_unpenalised
  {
    size_t item_size = sizeof(ros_message->secs_till_unpenalised);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name number_of_warnings
  {
    size_t item_size = sizeof(ros_message->number_of_warnings);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name yellow_card_count
  {
    size_t item_size = sizeof(ros_message->yellow_card_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name red_card_count
  {
    size_t item_size = sizeof(ros_message->red_card_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name goal_keeper
  {
    size_t item_size = sizeof(ros_message->goal_keeper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RobotInfo__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_game_controller_interface__msg__RobotInfo(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_game_controller_interface
size_t max_serialized_size_game_controller_interface__msg__RobotInfo(
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

  // member: penalty
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: secs_till_unpenalised
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: number_of_warnings
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: yellow_card_count
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: red_card_count
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: goal_keeper
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
    using DataType = game_controller_interface__msg__RobotInfo;
    is_plain =
      (
      offsetof(DataType, goal_keeper) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _RobotInfo__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_game_controller_interface__msg__RobotInfo(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RobotInfo = {
  "game_controller_interface::msg",
  "RobotInfo",
  _RobotInfo__cdr_serialize,
  _RobotInfo__cdr_deserialize,
  _RobotInfo__get_serialized_size,
  _RobotInfo__max_serialized_size
};

static rosidl_message_type_support_t _RobotInfo__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RobotInfo,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, game_controller_interface, msg, RobotInfo)() {
  return &_RobotInfo__type_support;
}

#if defined(__cplusplus)
}
#endif
