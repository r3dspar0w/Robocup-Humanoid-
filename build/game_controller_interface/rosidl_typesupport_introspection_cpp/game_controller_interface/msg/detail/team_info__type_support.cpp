// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from game_controller_interface:msg/TeamInfo.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "game_controller_interface/msg/detail/team_info__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace game_controller_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TeamInfo_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) game_controller_interface::msg::TeamInfo(_init);
}

void TeamInfo_fini_function(void * message_memory)
{
  auto typed_message = static_cast<game_controller_interface::msg::TeamInfo *>(message_memory);
  typed_message->~TeamInfo();
}

size_t size_function__TeamInfo__coach_message(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TeamInfo__coach_message(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__TeamInfo__coach_message(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__TeamInfo__coach_message(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__TeamInfo__coach_message(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__TeamInfo__coach_message(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__TeamInfo__coach_message(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

void resize_function__TeamInfo__coach_message(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__TeamInfo__players(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<game_controller_interface::msg::RobotInfo> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TeamInfo__players(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<game_controller_interface::msg::RobotInfo> *>(untyped_member);
  return &member[index];
}

void * get_function__TeamInfo__players(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<game_controller_interface::msg::RobotInfo> *>(untyped_member);
  return &member[index];
}

void fetch_function__TeamInfo__players(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const game_controller_interface::msg::RobotInfo *>(
    get_const_function__TeamInfo__players(untyped_member, index));
  auto & value = *reinterpret_cast<game_controller_interface::msg::RobotInfo *>(untyped_value);
  value = item;
}

void assign_function__TeamInfo__players(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<game_controller_interface::msg::RobotInfo *>(
    get_function__TeamInfo__players(untyped_member, index));
  const auto & value = *reinterpret_cast<const game_controller_interface::msg::RobotInfo *>(untyped_value);
  item = value;
}

void resize_function__TeamInfo__players(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<game_controller_interface::msg::RobotInfo> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TeamInfo_message_member_array[9] = {
  {
    "team_number",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::TeamInfo, team_number),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "field_player_colour",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::TeamInfo, field_player_colour),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "score",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::TeamInfo, score),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "penalty_shot",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::TeamInfo, penalty_shot),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "single_shots",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::TeamInfo, single_shots),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "coach_sequence",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::TeamInfo, coach_sequence),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "coach_message",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::TeamInfo, coach_message),  // bytes offset in struct
    nullptr,  // default value
    size_function__TeamInfo__coach_message,  // size() function pointer
    get_const_function__TeamInfo__coach_message,  // get_const(index) function pointer
    get_function__TeamInfo__coach_message,  // get(index) function pointer
    fetch_function__TeamInfo__coach_message,  // fetch(index, &value) function pointer
    assign_function__TeamInfo__coach_message,  // assign(index, value) function pointer
    resize_function__TeamInfo__coach_message  // resize(index) function pointer
  },
  {
    "coach",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<game_controller_interface::msg::RobotInfo>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::TeamInfo, coach),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "players",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<game_controller_interface::msg::RobotInfo>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::TeamInfo, players),  // bytes offset in struct
    nullptr,  // default value
    size_function__TeamInfo__players,  // size() function pointer
    get_const_function__TeamInfo__players,  // get_const(index) function pointer
    get_function__TeamInfo__players,  // get(index) function pointer
    fetch_function__TeamInfo__players,  // fetch(index, &value) function pointer
    assign_function__TeamInfo__players,  // assign(index, value) function pointer
    resize_function__TeamInfo__players  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TeamInfo_message_members = {
  "game_controller_interface::msg",  // message namespace
  "TeamInfo",  // message name
  9,  // number of fields
  sizeof(game_controller_interface::msg::TeamInfo),
  TeamInfo_message_member_array,  // message members
  TeamInfo_init_function,  // function to initialize message memory (memory has to be allocated)
  TeamInfo_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TeamInfo_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TeamInfo_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace game_controller_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<game_controller_interface::msg::TeamInfo>()
{
  return &::game_controller_interface::msg::rosidl_typesupport_introspection_cpp::TeamInfo_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, game_controller_interface, msg, TeamInfo)() {
  return &::game_controller_interface::msg::rosidl_typesupport_introspection_cpp::TeamInfo_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
