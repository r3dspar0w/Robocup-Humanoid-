// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from vision_interface:msg/SegmentationResult.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "vision_interface/msg/detail/segmentation_result__struct.hpp"
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

void SegmentationResult_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) vision_interface::msg::SegmentationResult(_init);
}

void SegmentationResult_fini_function(void * message_memory)
{
  auto typed_message = static_cast<vision_interface::msg::SegmentationResult *>(message_memory);
  typed_message->~SegmentationResult();
}

size_t size_function__SegmentationResult__lines(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vision_interface::msg::SegmentationLine> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SegmentationResult__lines(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vision_interface::msg::SegmentationLine> *>(untyped_member);
  return &member[index];
}

void * get_function__SegmentationResult__lines(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vision_interface::msg::SegmentationLine> *>(untyped_member);
  return &member[index];
}

void fetch_function__SegmentationResult__lines(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vision_interface::msg::SegmentationLine *>(
    get_const_function__SegmentationResult__lines(untyped_member, index));
  auto & value = *reinterpret_cast<vision_interface::msg::SegmentationLine *>(untyped_value);
  value = item;
}

void assign_function__SegmentationResult__lines(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vision_interface::msg::SegmentationLine *>(
    get_function__SegmentationResult__lines(untyped_member, index));
  const auto & value = *reinterpret_cast<const vision_interface::msg::SegmentationLine *>(untyped_value);
  item = value;
}

void resize_function__SegmentationResult__lines(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vision_interface::msg::SegmentationLine> *>(untyped_member);
  member->resize(size);
}

size_t size_function__SegmentationResult__points(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vision_interface::msg::SegmentationPoint> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SegmentationResult__points(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vision_interface::msg::SegmentationPoint> *>(untyped_member);
  return &member[index];
}

void * get_function__SegmentationResult__points(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vision_interface::msg::SegmentationPoint> *>(untyped_member);
  return &member[index];
}

void fetch_function__SegmentationResult__points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vision_interface::msg::SegmentationPoint *>(
    get_const_function__SegmentationResult__points(untyped_member, index));
  auto & value = *reinterpret_cast<vision_interface::msg::SegmentationPoint *>(untyped_value);
  value = item;
}

void assign_function__SegmentationResult__points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vision_interface::msg::SegmentationPoint *>(
    get_function__SegmentationResult__points(untyped_member, index));
  const auto & value = *reinterpret_cast<const vision_interface::msg::SegmentationPoint *>(untyped_value);
  item = value;
}

void resize_function__SegmentationResult__points(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vision_interface::msg::SegmentationPoint> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SegmentationResult_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface::msg::SegmentationResult, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "lines",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vision_interface::msg::SegmentationLine>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface::msg::SegmentationResult, lines),  // bytes offset in struct
    nullptr,  // default value
    size_function__SegmentationResult__lines,  // size() function pointer
    get_const_function__SegmentationResult__lines,  // get_const(index) function pointer
    get_function__SegmentationResult__lines,  // get(index) function pointer
    fetch_function__SegmentationResult__lines,  // fetch(index, &value) function pointer
    assign_function__SegmentationResult__lines,  // assign(index, value) function pointer
    resize_function__SegmentationResult__lines  // resize(index) function pointer
  },
  {
    "points",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vision_interface::msg::SegmentationPoint>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface::msg::SegmentationResult, points),  // bytes offset in struct
    nullptr,  // default value
    size_function__SegmentationResult__points,  // size() function pointer
    get_const_function__SegmentationResult__points,  // get_const(index) function pointer
    get_function__SegmentationResult__points,  // get(index) function pointer
    fetch_function__SegmentationResult__points,  // fetch(index, &value) function pointer
    assign_function__SegmentationResult__points,  // assign(index, value) function pointer
    resize_function__SegmentationResult__points  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SegmentationResult_message_members = {
  "vision_interface::msg",  // message namespace
  "SegmentationResult",  // message name
  3,  // number of fields
  sizeof(vision_interface::msg::SegmentationResult),
  SegmentationResult_message_member_array,  // message members
  SegmentationResult_init_function,  // function to initialize message memory (memory has to be allocated)
  SegmentationResult_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SegmentationResult_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SegmentationResult_message_members,
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
get_message_type_support_handle<vision_interface::msg::SegmentationResult>()
{
  return &::vision_interface::msg::rosidl_typesupport_introspection_cpp::SegmentationResult_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vision_interface, msg, SegmentationResult)() {
  return &::vision_interface::msg::rosidl_typesupport_introspection_cpp::SegmentationResult_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
