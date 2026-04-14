// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from booster_interface:msg/ImuState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "booster_interface/msg/detail/imu_state__struct.hpp"
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

void ImuState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) booster_interface::msg::ImuState(_init);
}

void ImuState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<booster_interface::msg::ImuState *>(message_memory);
  typed_message->~ImuState();
}

size_t size_function__ImuState__rpy(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__ImuState__rpy(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__ImuState__rpy(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__ImuState__rpy(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__ImuState__rpy(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__ImuState__rpy(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__ImuState__rpy(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__ImuState__gyro(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__ImuState__gyro(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__ImuState__gyro(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__ImuState__gyro(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__ImuState__gyro(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__ImuState__gyro(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__ImuState__gyro(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__ImuState__acc(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__ImuState__acc(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__ImuState__acc(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__ImuState__acc(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__ImuState__acc(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__ImuState__acc(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__ImuState__acc(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ImuState_message_member_array[3] = {
  {
    "rpy",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(booster_interface::msg::ImuState, rpy),  // bytes offset in struct
    nullptr,  // default value
    size_function__ImuState__rpy,  // size() function pointer
    get_const_function__ImuState__rpy,  // get_const(index) function pointer
    get_function__ImuState__rpy,  // get(index) function pointer
    fetch_function__ImuState__rpy,  // fetch(index, &value) function pointer
    assign_function__ImuState__rpy,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "gyro",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(booster_interface::msg::ImuState, gyro),  // bytes offset in struct
    nullptr,  // default value
    size_function__ImuState__gyro,  // size() function pointer
    get_const_function__ImuState__gyro,  // get_const(index) function pointer
    get_function__ImuState__gyro,  // get(index) function pointer
    fetch_function__ImuState__gyro,  // fetch(index, &value) function pointer
    assign_function__ImuState__gyro,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "acc",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(booster_interface::msg::ImuState, acc),  // bytes offset in struct
    nullptr,  // default value
    size_function__ImuState__acc,  // size() function pointer
    get_const_function__ImuState__acc,  // get_const(index) function pointer
    get_function__ImuState__acc,  // get(index) function pointer
    fetch_function__ImuState__acc,  // fetch(index, &value) function pointer
    assign_function__ImuState__acc,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ImuState_message_members = {
  "booster_interface::msg",  // message namespace
  "ImuState",  // message name
  3,  // number of fields
  sizeof(booster_interface::msg::ImuState),
  ImuState_message_member_array,  // message members
  ImuState_init_function,  // function to initialize message memory (memory has to be allocated)
  ImuState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ImuState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ImuState_message_members,
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
get_message_type_support_handle<booster_interface::msg::ImuState>()
{
  return &::booster_interface::msg::rosidl_typesupport_introspection_cpp::ImuState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, booster_interface, msg, ImuState)() {
  return &::booster_interface::msg::rosidl_typesupport_introspection_cpp::ImuState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
