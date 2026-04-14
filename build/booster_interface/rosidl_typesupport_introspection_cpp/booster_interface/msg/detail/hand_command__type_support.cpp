// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from booster_interface:msg/HandCommand.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "booster_interface/msg/detail/hand_command__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace booster_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void HandCommand_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) booster_interface::msg::HandCommand(_init);
}

void HandCommand_fini_function(void * message_memory)
{
  auto typed_message = static_cast<booster_interface::msg::HandCommand *>(message_memory);
  typed_message->~HandCommand();
}

size_t size_function__HandCommand__hand_param(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<booster_interface::msg::HandParam> *>(untyped_member);
  return member->size();
}

const void * get_const_function__HandCommand__hand_param(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<booster_interface::msg::HandParam> *>(untyped_member);
  return &member[index];
}

void * get_function__HandCommand__hand_param(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<booster_interface::msg::HandParam> *>(untyped_member);
  return &member[index];
}

void fetch_function__HandCommand__hand_param(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const booster_interface::msg::HandParam *>(
    get_const_function__HandCommand__hand_param(untyped_member, index));
  auto & value = *reinterpret_cast<booster_interface::msg::HandParam *>(untyped_value);
  value = item;
}

void assign_function__HandCommand__hand_param(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<booster_interface::msg::HandParam *>(
    get_function__HandCommand__hand_param(untyped_member, index));
  const auto & value = *reinterpret_cast<const booster_interface::msg::HandParam *>(untyped_value);
  item = value;
}

void resize_function__HandCommand__hand_param(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<booster_interface::msg::HandParam> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember HandCommand_message_member_array[4] = {
  {
    "hand_param",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<booster_interface::msg::HandParam>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(booster_interface::msg::HandCommand, hand_param),  // bytes offset in struct
    nullptr,  // default value
    size_function__HandCommand__hand_param,  // size() function pointer
    get_const_function__HandCommand__hand_param,  // get_const(index) function pointer
    get_function__HandCommand__hand_param,  // get(index) function pointer
    fetch_function__HandCommand__hand_param,  // fetch(index, &value) function pointer
    assign_function__HandCommand__hand_param,  // assign(index, value) function pointer
    resize_function__HandCommand__hand_param  // resize(index) function pointer
  },
  {
    "force_mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(booster_interface::msg::HandCommand, force_mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "hand_index",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(booster_interface::msg::HandCommand, hand_index),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "hand_type",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(booster_interface::msg::HandCommand, hand_type),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers HandCommand_message_members = {
  "booster_interface::msg",  // message namespace
  "HandCommand",  // message name
  4,  // number of fields
  sizeof(booster_interface::msg::HandCommand),
  HandCommand_message_member_array,  // message members
  HandCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  HandCommand_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t HandCommand_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &HandCommand_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace booster_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<booster_interface::msg::HandCommand>()
{
  return &::booster_interface::msg::rosidl_typesupport_introspection_cpp::HandCommand_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, booster_interface, msg, HandCommand)() {
  return &::booster_interface::msg::rosidl_typesupport_introspection_cpp::HandCommand_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
