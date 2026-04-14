// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from game_controller_interface:msg/TeamInfo.idl
// generated code does not contain a copyright notice
#include "game_controller_interface/msg/detail/team_info__rosidl_typesupport_fastrtps_cpp.hpp"
#include "game_controller_interface/msg/detail/team_info__struct.hpp"

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
bool cdr_serialize(
  const game_controller_interface::msg::RobotInfo &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  game_controller_interface::msg::RobotInfo &);
size_t get_serialized_size(
  const game_controller_interface::msg::RobotInfo &,
  size_t current_alignment);
size_t
max_serialized_size_RobotInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace game_controller_interface

// functions for game_controller_interface::msg::RobotInfo already declared above


namespace game_controller_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_game_controller_interface
cdr_serialize(
  const game_controller_interface::msg::TeamInfo & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: team_number
  cdr << ros_message.team_number;
  // Member: field_player_colour
  cdr << ros_message.field_player_colour;
  // Member: score
  cdr << ros_message.score;
  // Member: penalty_shot
  cdr << ros_message.penalty_shot;
  // Member: single_shots
  cdr << ros_message.single_shots;
  // Member: coach_sequence
  cdr << ros_message.coach_sequence;
  // Member: coach_message
  {
    cdr << ros_message.coach_message;
  }
  // Member: coach
  game_controller_interface::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.coach,
    cdr);
  // Member: players
  {
    size_t size = ros_message.players.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      game_controller_interface::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.players[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_game_controller_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  game_controller_interface::msg::TeamInfo & ros_message)
{
  // Member: team_number
  cdr >> ros_message.team_number;

  // Member: field_player_colour
  cdr >> ros_message.field_player_colour;

  // Member: score
  cdr >> ros_message.score;

  // Member: penalty_shot
  cdr >> ros_message.penalty_shot;

  // Member: single_shots
  cdr >> ros_message.single_shots;

  // Member: coach_sequence
  cdr >> ros_message.coach_sequence;

  // Member: coach_message
  {
    cdr >> ros_message.coach_message;
  }

  // Member: coach
  game_controller_interface::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.coach);

  // Member: players
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.players.resize(size);
    for (size_t i = 0; i < size; i++) {
      game_controller_interface::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.players[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_game_controller_interface
get_serialized_size(
  const game_controller_interface::msg::TeamInfo & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: team_number
  {
    size_t item_size = sizeof(ros_message.team_number);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: field_player_colour
  {
    size_t item_size = sizeof(ros_message.field_player_colour);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: score
  {
    size_t item_size = sizeof(ros_message.score);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: penalty_shot
  {
    size_t item_size = sizeof(ros_message.penalty_shot);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: single_shots
  {
    size_t item_size = sizeof(ros_message.single_shots);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: coach_sequence
  {
    size_t item_size = sizeof(ros_message.coach_sequence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: coach_message
  {
    size_t array_size = ros_message.coach_message.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.coach_message[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: coach

  current_alignment +=
    game_controller_interface::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.coach, current_alignment);
  // Member: players
  {
    size_t array_size = ros_message.players.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        game_controller_interface::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.players[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_game_controller_interface
max_serialized_size_TeamInfo(
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


  // Member: team_number
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: field_player_colour
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: score
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: penalty_shot
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: single_shots
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: coach_sequence
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: coach_message
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: coach
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        game_controller_interface::msg::typesupport_fastrtps_cpp::max_serialized_size_RobotInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: players
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
      size_t inner_size =
        game_controller_interface::msg::typesupport_fastrtps_cpp::max_serialized_size_RobotInfo(
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
    using DataType = game_controller_interface::msg::TeamInfo;
    is_plain =
      (
      offsetof(DataType, players) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _TeamInfo__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const game_controller_interface::msg::TeamInfo *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _TeamInfo__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<game_controller_interface::msg::TeamInfo *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _TeamInfo__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const game_controller_interface::msg::TeamInfo *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _TeamInfo__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_TeamInfo(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _TeamInfo__callbacks = {
  "game_controller_interface::msg",
  "TeamInfo",
  _TeamInfo__cdr_serialize,
  _TeamInfo__cdr_deserialize,
  _TeamInfo__get_serialized_size,
  _TeamInfo__max_serialized_size
};

static rosidl_message_type_support_t _TeamInfo__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_TeamInfo__callbacks,
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
get_message_type_support_handle<game_controller_interface::msg::TeamInfo>()
{
  return &game_controller_interface::msg::typesupport_fastrtps_cpp::_TeamInfo__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, game_controller_interface, msg, TeamInfo)() {
  return &game_controller_interface::msg::typesupport_fastrtps_cpp::_TeamInfo__handle;
}

#ifdef __cplusplus
}
#endif
