// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from game_controller_interface:msg/GameControlData.idl
// generated code does not contain a copyright notice
#include "game_controller_interface/msg/detail/game_control_data__rosidl_typesupport_fastrtps_cpp.hpp"
#include "game_controller_interface/msg/detail/game_control_data__struct.hpp"

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
  const game_controller_interface::msg::TeamInfo &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  game_controller_interface::msg::TeamInfo &);
size_t get_serialized_size(
  const game_controller_interface::msg::TeamInfo &,
  size_t current_alignment);
size_t
max_serialized_size_TeamInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace game_controller_interface


namespace game_controller_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_game_controller_interface
cdr_serialize(
  const game_controller_interface::msg::GameControlData & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  {
    cdr << ros_message.header;
  }
  // Member: version
  cdr << ros_message.version;
  // Member: packet_number
  cdr << ros_message.packet_number;
  // Member: players_per_team
  cdr << ros_message.players_per_team;
  // Member: game_type
  cdr << ros_message.game_type;
  // Member: state
  cdr << ros_message.state;
  // Member: first_half
  cdr << ros_message.first_half;
  // Member: kick_off_team
  cdr << ros_message.kick_off_team;
  // Member: secondary_state
  cdr << ros_message.secondary_state;
  // Member: secondary_state_info
  {
    cdr << ros_message.secondary_state_info;
  }
  // Member: drop_in_team
  cdr << ros_message.drop_in_team;
  // Member: drop_in_time
  cdr << ros_message.drop_in_time;
  // Member: secs_remaining
  cdr << ros_message.secs_remaining;
  // Member: secondary_time
  cdr << ros_message.secondary_time;
  // Member: teams
  {
    for (size_t i = 0; i < 2; i++) {
      game_controller_interface::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.teams[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_game_controller_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  game_controller_interface::msg::GameControlData & ros_message)
{
  // Member: header
  {
    cdr >> ros_message.header;
  }

  // Member: version
  cdr >> ros_message.version;

  // Member: packet_number
  cdr >> ros_message.packet_number;

  // Member: players_per_team
  cdr >> ros_message.players_per_team;

  // Member: game_type
  cdr >> ros_message.game_type;

  // Member: state
  cdr >> ros_message.state;

  // Member: first_half
  cdr >> ros_message.first_half;

  // Member: kick_off_team
  cdr >> ros_message.kick_off_team;

  // Member: secondary_state
  cdr >> ros_message.secondary_state;

  // Member: secondary_state_info
  {
    cdr >> ros_message.secondary_state_info;
  }

  // Member: drop_in_team
  cdr >> ros_message.drop_in_team;

  // Member: drop_in_time
  cdr >> ros_message.drop_in_time;

  // Member: secs_remaining
  cdr >> ros_message.secs_remaining;

  // Member: secondary_time
  cdr >> ros_message.secondary_time;

  // Member: teams
  {
    for (size_t i = 0; i < 2; i++) {
      game_controller_interface::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr,
        ros_message.teams[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_game_controller_interface
get_serialized_size(
  const game_controller_interface::msg::GameControlData & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header
  {
    size_t array_size = 4;
    size_t item_size = sizeof(ros_message.header[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: version
  {
    size_t item_size = sizeof(ros_message.version);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: packet_number
  {
    size_t item_size = sizeof(ros_message.packet_number);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: players_per_team
  {
    size_t item_size = sizeof(ros_message.players_per_team);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: game_type
  {
    size_t item_size = sizeof(ros_message.game_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: state
  {
    size_t item_size = sizeof(ros_message.state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: first_half
  {
    size_t item_size = sizeof(ros_message.first_half);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: kick_off_team
  {
    size_t item_size = sizeof(ros_message.kick_off_team);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: secondary_state
  {
    size_t item_size = sizeof(ros_message.secondary_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: secondary_state_info
  {
    size_t array_size = 4;
    size_t item_size = sizeof(ros_message.secondary_state_info[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: drop_in_team
  {
    size_t item_size = sizeof(ros_message.drop_in_team);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: drop_in_time
  {
    size_t item_size = sizeof(ros_message.drop_in_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: secs_remaining
  {
    size_t item_size = sizeof(ros_message.secs_remaining);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: secondary_time
  {
    size_t item_size = sizeof(ros_message.secondary_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: teams
  {
    size_t array_size = 2;

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        game_controller_interface::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.teams[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_game_controller_interface
max_serialized_size_GameControlData(
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


  // Member: header
  {
    size_t array_size = 4;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: version
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: packet_number
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: players_per_team
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: game_type
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: state
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: first_half
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: kick_off_team
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: secondary_state
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: secondary_state_info
  {
    size_t array_size = 4;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: drop_in_team
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: drop_in_time
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: secs_remaining
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: secondary_time
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: teams
  {
    size_t array_size = 2;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        game_controller_interface::msg::typesupport_fastrtps_cpp::max_serialized_size_TeamInfo(
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
    using DataType = game_controller_interface::msg::GameControlData;
    is_plain =
      (
      offsetof(DataType, teams) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _GameControlData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const game_controller_interface::msg::GameControlData *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GameControlData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<game_controller_interface::msg::GameControlData *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GameControlData__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const game_controller_interface::msg::GameControlData *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GameControlData__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GameControlData(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GameControlData__callbacks = {
  "game_controller_interface::msg",
  "GameControlData",
  _GameControlData__cdr_serialize,
  _GameControlData__cdr_deserialize,
  _GameControlData__get_serialized_size,
  _GameControlData__max_serialized_size
};

static rosidl_message_type_support_t _GameControlData__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GameControlData__callbacks,
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
get_message_type_support_handle<game_controller_interface::msg::GameControlData>()
{
  return &game_controller_interface::msg::typesupport_fastrtps_cpp::_GameControlData__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, game_controller_interface, msg, GameControlData)() {
  return &game_controller_interface::msg::typesupport_fastrtps_cpp::_GameControlData__handle;
}

#ifdef __cplusplus
}
#endif
