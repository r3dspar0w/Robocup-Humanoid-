// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from booster_interface:msg/LowState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "booster_interface/msg/detail/low_state__struct.hpp"
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

void LowState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) booster_interface::msg::LowState(_init);
}

void LowState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<booster_interface::msg::LowState *>(message_memory);
  typed_message->~LowState();
}

size_t size_function__LowState__motor_state_parallel(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<booster_interface::msg::MotorState> *>(untyped_member);
  return member->size();
}

const void * get_const_function__LowState__motor_state_parallel(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<booster_interface::msg::MotorState> *>(untyped_member);
  return &member[index];
}

void * get_function__LowState__motor_state_parallel(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<booster_interface::msg::MotorState> *>(untyped_member);
  return &member[index];
}

void fetch_function__LowState__motor_state_parallel(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const booster_interface::msg::MotorState *>(
    get_const_function__LowState__motor_state_parallel(untyped_member, index));
  auto & value = *reinterpret_cast<booster_interface::msg::MotorState *>(untyped_value);
  value = item;
}

void assign_function__LowState__motor_state_parallel(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<booster_interface::msg::MotorState *>(
    get_function__LowState__motor_state_parallel(untyped_member, index));
  const auto & value = *reinterpret_cast<const booster_interface::msg::MotorState *>(untyped_value);
  item = value;
}

void resize_function__LowState__motor_state_parallel(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<booster_interface::msg::MotorState> *>(untyped_member);
  member->resize(size);
}

size_t size_function__LowState__motor_state_serial(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<booster_interface::msg::MotorState> *>(untyped_member);
  return member->size();
}

const void * get_const_function__LowState__motor_state_serial(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<booster_interface::msg::MotorState> *>(untyped_member);
  return &member[index];
}

void * get_function__LowState__motor_state_serial(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<booster_interface::msg::MotorState> *>(untyped_member);
  return &member[index];
}

void fetch_function__LowState__motor_state_serial(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const booster_interface::msg::MotorState *>(
    get_const_function__LowState__motor_state_serial(untyped_member, index));
  auto & value = *reinterpret_cast<booster_interface::msg::MotorState *>(untyped_value);
  value = item;
}

void assign_function__LowState__motor_state_serial(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<booster_interface::msg::MotorState *>(
    get_function__LowState__motor_state_serial(untyped_member, index));
  const auto & value = *reinterpret_cast<const booster_interface::msg::MotorState *>(untyped_value);
  item = value;
}

void resize_function__LowState__motor_state_serial(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<booster_interface::msg::MotorState> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LowState_message_member_array[3] = {
  {
    "imu_state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<booster_interface::msg::ImuState>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(booster_interface::msg::LowState, imu_state),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "motor_state_parallel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<booster_interface::msg::MotorState>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(booster_interface::msg::LowState, motor_state_parallel),  // bytes offset in struct
    nullptr,  // default value
    size_function__LowState__motor_state_parallel,  // size() function pointer
    get_const_function__LowState__motor_state_parallel,  // get_const(index) function pointer
    get_function__LowState__motor_state_parallel,  // get(index) function pointer
    fetch_function__LowState__motor_state_parallel,  // fetch(index, &value) function pointer
    assign_function__LowState__motor_state_parallel,  // assign(index, value) function pointer
    resize_function__LowState__motor_state_parallel  // resize(index) function pointer
  },
  {
    "motor_state_serial",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<booster_interface::msg::MotorState>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(booster_interface::msg::LowState, motor_state_serial),  // bytes offset in struct
    nullptr,  // default value
    size_function__LowState__motor_state_serial,  // size() function pointer
    get_const_function__LowState__motor_state_serial,  // get_const(index) function pointer
    get_function__LowState__motor_state_serial,  // get(index) function pointer
    fetch_function__LowState__motor_state_serial,  // fetch(index, &value) function pointer
    assign_function__LowState__motor_state_serial,  // assign(index, value) function pointer
    resize_function__LowState__motor_state_serial  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LowState_message_members = {
  "booster_interface::msg",  // message namespace
  "LowState",  // message name
  3,  // number of fields
  sizeof(booster_interface::msg::LowState),
  LowState_message_member_array,  // message members
  LowState_init_function,  // function to initialize message memory (memory has to be allocated)
  LowState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LowState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LowState_message_members,
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
get_message_type_support_handle<booster_interface::msg::LowState>()
{
  return &::booster_interface::msg::rosidl_typesupport_introspection_cpp::LowState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, booster_interface, msg, LowState)() {
  return &::booster_interface::msg::rosidl_typesupport_introspection_cpp::LowState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
