// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from booster_interface:msg/RawBytesMsg.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "booster_interface/msg/detail/raw_bytes_msg__struct.hpp"
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

void RawBytesMsg_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) booster_interface::msg::RawBytesMsg(_init);
}

void RawBytesMsg_fini_function(void * message_memory)
{
  auto typed_message = static_cast<booster_interface::msg::RawBytesMsg *>(message_memory);
  typed_message->~RawBytesMsg();
}

size_t size_function__RawBytesMsg__msg(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RawBytesMsg__msg(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__RawBytesMsg__msg(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__RawBytesMsg__msg(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__RawBytesMsg__msg(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__RawBytesMsg__msg(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__RawBytesMsg__msg(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

void resize_function__RawBytesMsg__msg(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RawBytesMsg_message_member_array[1] = {
  {
    "msg",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(booster_interface::msg::RawBytesMsg, msg),  // bytes offset in struct
    nullptr,  // default value
    size_function__RawBytesMsg__msg,  // size() function pointer
    get_const_function__RawBytesMsg__msg,  // get_const(index) function pointer
    get_function__RawBytesMsg__msg,  // get(index) function pointer
    fetch_function__RawBytesMsg__msg,  // fetch(index, &value) function pointer
    assign_function__RawBytesMsg__msg,  // assign(index, value) function pointer
    resize_function__RawBytesMsg__msg  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RawBytesMsg_message_members = {
  "booster_interface::msg",  // message namespace
  "RawBytesMsg",  // message name
  1,  // number of fields
  sizeof(booster_interface::msg::RawBytesMsg),
  RawBytesMsg_message_member_array,  // message members
  RawBytesMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  RawBytesMsg_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RawBytesMsg_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RawBytesMsg_message_members,
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
get_message_type_support_handle<booster_interface::msg::RawBytesMsg>()
{
  return &::booster_interface::msg::rosidl_typesupport_introspection_cpp::RawBytesMsg_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, booster_interface, msg, RawBytesMsg)() {
  return &::booster_interface::msg::rosidl_typesupport_introspection_cpp::RawBytesMsg_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
