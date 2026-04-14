// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from game_controller_interface:msg/GameControlData.idl
// generated code does not contain a copyright notice
#include "game_controller_interface/msg/detail/game_control_data__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "game_controller_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "game_controller_interface/msg/detail/game_control_data__struct.h"
#include "game_controller_interface/msg/detail/game_control_data__functions.h"
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

#include "game_controller_interface/msg/detail/team_info__functions.h"  // teams

// forward declare type support functions
size_t get_serialized_size_game_controller_interface__msg__TeamInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_game_controller_interface__msg__TeamInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, game_controller_interface, msg, TeamInfo)();


using _GameControlData__ros_msg_type = game_controller_interface__msg__GameControlData;

static bool _GameControlData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GameControlData__ros_msg_type * ros_message = static_cast<const _GameControlData__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    size_t size = 4;
    auto array_ptr = ros_message->header;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: version
  {
    cdr << ros_message->version;
  }

  // Field name: packet_number
  {
    cdr << ros_message->packet_number;
  }

  // Field name: players_per_team
  {
    cdr << ros_message->players_per_team;
  }

  // Field name: game_type
  {
    cdr << ros_message->game_type;
  }

  // Field name: state
  {
    cdr << ros_message->state;
  }

  // Field name: first_half
  {
    cdr << ros_message->first_half;
  }

  // Field name: kick_off_team
  {
    cdr << ros_message->kick_off_team;
  }

  // Field name: secondary_state
  {
    cdr << ros_message->secondary_state;
  }

  // Field name: secondary_state_info
  {
    size_t size = 4;
    auto array_ptr = ros_message->secondary_state_info;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: drop_in_team
  {
    cdr << ros_message->drop_in_team;
  }

  // Field name: drop_in_time
  {
    cdr << ros_message->drop_in_time;
  }

  // Field name: secs_remaining
  {
    cdr << ros_message->secs_remaining;
  }

  // Field name: secondary_time
  {
    cdr << ros_message->secondary_time;
  }

  // Field name: teams
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, game_controller_interface, msg, TeamInfo
      )()->data);
    size_t size = 2;
    auto array_ptr = ros_message->teams;
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

static bool _GameControlData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GameControlData__ros_msg_type * ros_message = static_cast<_GameControlData__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    size_t size = 4;
    auto array_ptr = ros_message->header;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: version
  {
    cdr >> ros_message->version;
  }

  // Field name: packet_number
  {
    cdr >> ros_message->packet_number;
  }

  // Field name: players_per_team
  {
    cdr >> ros_message->players_per_team;
  }

  // Field name: game_type
  {
    cdr >> ros_message->game_type;
  }

  // Field name: state
  {
    cdr >> ros_message->state;
  }

  // Field name: first_half
  {
    cdr >> ros_message->first_half;
  }

  // Field name: kick_off_team
  {
    cdr >> ros_message->kick_off_team;
  }

  // Field name: secondary_state
  {
    cdr >> ros_message->secondary_state;
  }

  // Field name: secondary_state_info
  {
    size_t size = 4;
    auto array_ptr = ros_message->secondary_state_info;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: drop_in_team
  {
    cdr >> ros_message->drop_in_team;
  }

  // Field name: drop_in_time
  {
    cdr >> ros_message->drop_in_time;
  }

  // Field name: secs_remaining
  {
    cdr >> ros_message->secs_remaining;
  }

  // Field name: secondary_time
  {
    cdr >> ros_message->secondary_time;
  }

  // Field name: teams
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, game_controller_interface, msg, TeamInfo
      )()->data);
    size_t size = 2;
    auto array_ptr = ros_message->teams;
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
size_t get_serialized_size_game_controller_interface__msg__GameControlData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GameControlData__ros_msg_type * ros_message = static_cast<const _GameControlData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header
  {
    size_t array_size = 4;
    auto array_ptr = ros_message->header;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name version
  {
    size_t item_size = sizeof(ros_message->version);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name packet_number
  {
    size_t item_size = sizeof(ros_message->packet_number);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name players_per_team
  {
    size_t item_size = sizeof(ros_message->players_per_team);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name game_type
  {
    size_t item_size = sizeof(ros_message->game_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name state
  {
    size_t item_size = sizeof(ros_message->state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name first_half
  {
    size_t item_size = sizeof(ros_message->first_half);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name kick_off_team
  {
    size_t item_size = sizeof(ros_message->kick_off_team);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name secondary_state
  {
    size_t item_size = sizeof(ros_message->secondary_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name secondary_state_info
  {
    size_t array_size = 4;
    auto array_ptr = ros_message->secondary_state_info;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name drop_in_team
  {
    size_t item_size = sizeof(ros_message->drop_in_team);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name drop_in_time
  {
    size_t item_size = sizeof(ros_message->drop_in_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name secs_remaining
  {
    size_t item_size = sizeof(ros_message->secs_remaining);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name secondary_time
  {
    size_t item_size = sizeof(ros_message->secondary_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name teams
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->teams;

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_game_controller_interface__msg__TeamInfo(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _GameControlData__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_game_controller_interface__msg__GameControlData(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_game_controller_interface
size_t max_serialized_size_game_controller_interface__msg__GameControlData(
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

  // member: header
  {
    size_t array_size = 4;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: version
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: packet_number
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: players_per_team
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: game_type
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: state
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: first_half
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: kick_off_team
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: secondary_state
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: secondary_state_info
  {
    size_t array_size = 4;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: drop_in_team
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: drop_in_time
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: secs_remaining
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: secondary_time
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: teams
  {
    size_t array_size = 2;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_game_controller_interface__msg__TeamInfo(
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
    using DataType = game_controller_interface__msg__GameControlData;
    is_plain =
      (
      offsetof(DataType, teams) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _GameControlData__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_game_controller_interface__msg__GameControlData(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GameControlData = {
  "game_controller_interface::msg",
  "GameControlData",
  _GameControlData__cdr_serialize,
  _GameControlData__cdr_deserialize,
  _GameControlData__get_serialized_size,
  _GameControlData__max_serialized_size
};

static rosidl_message_type_support_t _GameControlData__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GameControlData,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, game_controller_interface, msg, GameControlData)() {
  return &_GameControlData__type_support;
}

#if defined(__cplusplus)
}
#endif
