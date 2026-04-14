// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from game_controller_interface:msg/GameControlData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "game_controller_interface/msg/detail/game_control_data__struct.hpp"
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

void GameControlData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) game_controller_interface::msg::GameControlData(_init);
}

void GameControlData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<game_controller_interface::msg::GameControlData *>(message_memory);
  typed_message->~GameControlData();
}

size_t size_function__GameControlData__header(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__GameControlData__header(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint8_t, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__GameControlData__header(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint8_t, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__GameControlData__header(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__GameControlData__header(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__GameControlData__header(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__GameControlData__header(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

size_t size_function__GameControlData__secondary_state_info(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__GameControlData__secondary_state_info(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint8_t, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__GameControlData__secondary_state_info(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint8_t, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__GameControlData__secondary_state_info(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__GameControlData__secondary_state_info(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__GameControlData__secondary_state_info(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__GameControlData__secondary_state_info(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

size_t size_function__GameControlData__teams(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__GameControlData__teams(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<game_controller_interface::msg::TeamInfo, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__GameControlData__teams(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<game_controller_interface::msg::TeamInfo, 2> *>(untyped_member);
  return &member[index];
}

void fetch_function__GameControlData__teams(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const game_controller_interface::msg::TeamInfo *>(
    get_const_function__GameControlData__teams(untyped_member, index));
  auto & value = *reinterpret_cast<game_controller_interface::msg::TeamInfo *>(untyped_value);
  value = item;
}

void assign_function__GameControlData__teams(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<game_controller_interface::msg::TeamInfo *>(
    get_function__GameControlData__teams(untyped_member, index));
  const auto & value = *reinterpret_cast<const game_controller_interface::msg::TeamInfo *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GameControlData_message_member_array[15] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::GameControlData, header),  // bytes offset in struct
    nullptr,  // default value
    size_function__GameControlData__header,  // size() function pointer
    get_const_function__GameControlData__header,  // get_const(index) function pointer
    get_function__GameControlData__header,  // get(index) function pointer
    fetch_function__GameControlData__header,  // fetch(index, &value) function pointer
    assign_function__GameControlData__header,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "version",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::GameControlData, version),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "packet_number",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::GameControlData, packet_number),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "players_per_team",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::GameControlData, players_per_team),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "game_type",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::GameControlData, game_type),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::GameControlData, state),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "first_half",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::GameControlData, first_half),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "kick_off_team",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::GameControlData, kick_off_team),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "secondary_state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::GameControlData, secondary_state),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "secondary_state_info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::GameControlData, secondary_state_info),  // bytes offset in struct
    nullptr,  // default value
    size_function__GameControlData__secondary_state_info,  // size() function pointer
    get_const_function__GameControlData__secondary_state_info,  // get_const(index) function pointer
    get_function__GameControlData__secondary_state_info,  // get(index) function pointer
    fetch_function__GameControlData__secondary_state_info,  // fetch(index, &value) function pointer
    assign_function__GameControlData__secondary_state_info,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "drop_in_team",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::GameControlData, drop_in_team),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "drop_in_time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::GameControlData, drop_in_time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "secs_remaining",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::GameControlData, secs_remaining),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "secondary_time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::GameControlData, secondary_time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "teams",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<game_controller_interface::msg::TeamInfo>(),  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(game_controller_interface::msg::GameControlData, teams),  // bytes offset in struct
    nullptr,  // default value
    size_function__GameControlData__teams,  // size() function pointer
    get_const_function__GameControlData__teams,  // get_const(index) function pointer
    get_function__GameControlData__teams,  // get(index) function pointer
    fetch_function__GameControlData__teams,  // fetch(index, &value) function pointer
    assign_function__GameControlData__teams,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GameControlData_message_members = {
  "game_controller_interface::msg",  // message namespace
  "GameControlData",  // message name
  15,  // number of fields
  sizeof(game_controller_interface::msg::GameControlData),
  GameControlData_message_member_array,  // message members
  GameControlData_init_function,  // function to initialize message memory (memory has to be allocated)
  GameControlData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GameControlData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GameControlData_message_members,
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
get_message_type_support_handle<game_controller_interface::msg::GameControlData>()
{
  return &::game_controller_interface::msg::rosidl_typesupport_introspection_cpp::GameControlData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, game_controller_interface, msg, GameControlData)() {
  return &::game_controller_interface::msg::rosidl_typesupport_introspection_cpp::GameControlData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
