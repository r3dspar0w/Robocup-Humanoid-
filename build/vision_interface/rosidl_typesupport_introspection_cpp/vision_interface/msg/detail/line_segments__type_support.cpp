// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from vision_interface:msg/LineSegments.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "vision_interface/msg/detail/line_segments__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace vision_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void LineSegments_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) vision_interface::msg::LineSegments(_init);
}

void LineSegments_fini_function(void * message_memory)
{
  auto typed_message = static_cast<vision_interface::msg::LineSegments *>(message_memory);
  typed_message->~LineSegments();
}

size_t size_function__LineSegments__coordinates(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__LineSegments__coordinates(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__LineSegments__coordinates(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__LineSegments__coordinates(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__LineSegments__coordinates(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__LineSegments__coordinates(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__LineSegments__coordinates(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__LineSegments__coordinates(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__LineSegments__coordinates_uv(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__LineSegments__coordinates_uv(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__LineSegments__coordinates_uv(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__LineSegments__coordinates_uv(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__LineSegments__coordinates_uv(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__LineSegments__coordinates_uv(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__LineSegments__coordinates_uv(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__LineSegments__coordinates_uv(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LineSegments_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface::msg::LineSegments, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "coordinates",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface::msg::LineSegments, coordinates),  // bytes offset in struct
    nullptr,  // default value
    size_function__LineSegments__coordinates,  // size() function pointer
    get_const_function__LineSegments__coordinates,  // get_const(index) function pointer
    get_function__LineSegments__coordinates,  // get(index) function pointer
    fetch_function__LineSegments__coordinates,  // fetch(index, &value) function pointer
    assign_function__LineSegments__coordinates,  // assign(index, value) function pointer
    resize_function__LineSegments__coordinates  // resize(index) function pointer
  },
  {
    "coordinates_uv",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface::msg::LineSegments, coordinates_uv),  // bytes offset in struct
    nullptr,  // default value
    size_function__LineSegments__coordinates_uv,  // size() function pointer
    get_const_function__LineSegments__coordinates_uv,  // get_const(index) function pointer
    get_function__LineSegments__coordinates_uv,  // get(index) function pointer
    fetch_function__LineSegments__coordinates_uv,  // fetch(index, &value) function pointer
    assign_function__LineSegments__coordinates_uv,  // assign(index, value) function pointer
    resize_function__LineSegments__coordinates_uv  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LineSegments_message_members = {
  "vision_interface::msg",  // message namespace
  "LineSegments",  // message name
  3,  // number of fields
  sizeof(vision_interface::msg::LineSegments),
  LineSegments_message_member_array,  // message members
  LineSegments_init_function,  // function to initialize message memory (memory has to be allocated)
  LineSegments_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LineSegments_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LineSegments_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace vision_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vision_interface::msg::LineSegments>()
{
  return &::vision_interface::msg::rosidl_typesupport_introspection_cpp::LineSegments_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vision_interface, msg, LineSegments)() {
  return &::vision_interface::msg::rosidl_typesupport_introspection_cpp::LineSegments_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
