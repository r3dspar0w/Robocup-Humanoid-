// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from game_controller_interface:msg/TeamInfo.idl
// generated code does not contain a copyright notice
#include "game_controller_interface/msg/detail/team_info__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "game_controller_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "game_controller_interface/msg/detail/team_info__struct.h"
#include "game_controller_interface/msg/detail/team_info__functions.h"
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

#include "game_controller_interface/msg/detail/robot_info__functions.h"  // coach, players
#include "rosidl_runtime_c/primitives_sequence.h"  // coach_message
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // coach_message

// forward declare type support functions
size_t get_serialized_size_game_controller_interface__msg__RobotInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_game_controller_interface__msg__RobotInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, game_controller_interface, msg, RobotInfo)();


using _TeamInfo__ros_msg_type = game_controller_interface__msg__TeamInfo;

static bool _TeamInfo__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TeamInfo__ros_msg_type * ros_message = static_cast<const _TeamInfo__ros_msg_type *>(untyped_ros_message);
  // Field name: team_number
  {
    cdr << ros_message->team_number;
  }

  // Field name: field_player_colour
  {
    cdr << ros_message->field_player_colour;
  }

  // Field name: score
  {
    cdr << ros_message->score;
  }

  // Field name: penalty_shot
  {
    cdr << ros_message->penalty_shot;
  }

  // Field name: single_shots
  {
    cdr << ros_message->single_shots;
  }

  // Field name: coach_sequence
  {
    cdr << ros_message->coach_sequence;
  }

  // Field name: coach_message
  {
    size_t size = ros_message->coach_message.size;
    auto array_ptr = ros_message->coach_message.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: coach
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, game_controller_interface, msg, RobotInfo
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->coach, cdr))
    {
      return false;
    }
  }

  // Field name: players
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, game_controller_interface, msg, RobotInfo
      )()->data);
    size_t size = ros_message->players.size;
    auto array_ptr = ros_message->players.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _TeamInfo__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TeamInfo__ros_msg_type * ros_message = static_cast<_TeamInfo__ros_msg_type *>(untyped_ros_message);
  // Field name: team_number
  {
    cdr >> ros_message->team_number;
  }

  // Field name: field_player_colour
  {
    cdr >> ros_message->field_player_colour;
  }

  // Field name: score
  {
    cdr >> ros_message->score;
  }

  // Field name: penalty_shot
  {
    cdr >> ros_message->penalty_shot;
  }

  // Field name: single_shots
  {
    cdr >> ros_message->single_shots;
  }

  // Field name: coach_sequence
  {
    cdr >> ros_message->coach_sequence;
  }

  // Field name: coach_message
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->coach_message.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->coach_message);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->coach_message, size)) {
      fprintf(stderr, "failed to create array for field 'coach_message'");
      return false;
    }
    auto array_ptr = ros_message->coach_message.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: coach
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, game_controller_interface, msg, RobotInfo
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->coach))
    {
      return false;
    }
  }

  // Field name: players
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, game_controller_interface, msg, RobotInfo
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->players.data) {
      game_controller_interface__msg__RobotInfo__Sequence__fini(&ros_message->players);
    }
    if (!game_controller_interface__msg__RobotInfo__Sequence__init(&ros_message->players, size)) {
      fprintf(stderr, "failed to create array for field 'players'");
      return false;
    }
    auto array_ptr = ros_message->players.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_game_controller_interface
size_t get_serialized_size_game_controller_interface__msg__TeamInfo(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TeamInfo__ros_msg_type * ros_message = static_cast<const _TeamInfo__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name team_number
  {
    size_t item_size = sizeof(ros_message->team_number);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name field_player_colour
  {
    size_t item_size = sizeof(ros_message->field_player_colour);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name score
  {
    size_t item_size = sizeof(ros_message->score);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name penalty_shot
  {
    size_t item_size = sizeof(ros_message->penalty_shot);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name single_shots
  {
    size_t item_size = sizeof(ros_message->single_shots);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name coach_sequence
  {
    size_t item_size = sizeof(ros_message->coach_sequence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name coach_message
  {
    size_t array_size = ros_message->coach_message.size;
    auto array_ptr = ros_message->coach_message.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name coach

  current_alignment += get_serialized_size_game_controller_interface__msg__RobotInfo(
    &(ros_message->coach), current_alignment);
  // field.name players
  {
    size_t array_size = ros_message->players.size;
    auto array_ptr = ros_message->players.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_game_controller_interface__msg__RobotInfo(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _TeamInfo__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_game_controller_interface__msg__TeamInfo(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_game_controller_interface
size_t max_serialized_size_game_controller_interface__msg__TeamInfo(
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

  // member: team_number
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: field_player_colour
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: score
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: penalty_shot
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: single_shots
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: coach_sequence
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: coach_message
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: coach
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_game_controller_interface__msg__RobotInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: players
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_game_controller_interface__msg__RobotInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = game_controller_interface__msg__TeamInfo;
    is_plain =
      (
      offsetof(DataType, players) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _TeamInfo__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_game_controller_interface__msg__TeamInfo(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TeamInfo = {
  "game_controller_interface::msg",
  "TeamInfo",
  _TeamInfo__cdr_serialize,
  _TeamInfo__cdr_deserialize,
  _TeamInfo__get_serialized_size,
  _TeamInfo__max_serialized_size
};

static rosidl_message_type_support_t _TeamInfo__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TeamInfo,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, game_controller_interface, msg, TeamInfo)() {
  return &_TeamInfo__type_support;
}

#if defined(__cplusplus)
}
#endif
