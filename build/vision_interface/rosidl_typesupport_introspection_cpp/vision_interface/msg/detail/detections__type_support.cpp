// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from vision_interface:msg/Detections.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "vision_interface/msg/detail/detections__struct.hpp"
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

void Detections_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) vision_interface::msg::Detections(_init);
}

void Detections_fini_function(void * message_memory)
{
  auto typed_message = static_cast<vision_interface::msg::Detections *>(message_memory);
  typed_message->~Detections();
}

size_t size_function__Detections__detected_objects(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vision_interface::msg::DetectedObject> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Detections__detected_objects(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vision_interface::msg::DetectedObject> *>(untyped_member);
  return &member[index];
}

void * get_function__Detections__detected_objects(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vision_interface::msg::DetectedObject> *>(untyped_member);
  return &member[index];
}

void fetch_function__Detections__detected_objects(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vision_interface::msg::DetectedObject *>(
    get_const_function__Detections__detected_objects(untyped_member, index));
  auto & value = *reinterpret_cast<vision_interface::msg::DetectedObject *>(untyped_value);
  value = item;
}

void assign_function__Detections__detected_objects(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vision_interface::msg::DetectedObject *>(
    get_function__Detections__detected_objects(untyped_member, index));
  const auto & value = *reinterpret_cast<const vision_interface::msg::DetectedObject *>(untyped_value);
  item = value;
}

void resize_function__Detections__detected_objects(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vision_interface::msg::DetectedObject> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Detections__radar_x(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Detections__radar_x(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__Detections__radar_x(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__Detections__radar_x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__Detections__radar_x(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__Detections__radar_x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__Detections__radar_x(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__Detections__radar_x(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Detections__radar_y(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Detections__radar_y(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__Detections__radar_y(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__Detections__radar_y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__Detections__radar_y(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__Detections__radar_y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__Detections__radar_y(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__Detections__radar_y(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Detections__corner_pos(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Detections__corner_pos(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__Detections__corner_pos(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__Detections__corner_pos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__Detections__corner_pos(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__Detections__corner_pos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__Detections__corner_pos(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__Detections__corner_pos(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Detections_message_member_array[5] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface::msg::Detections, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "detected_objects",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vision_interface::msg::DetectedObject>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface::msg::Detections, detected_objects),  // bytes offset in struct
    nullptr,  // default value
    size_function__Detections__detected_objects,  // size() function pointer
    get_const_function__Detections__detected_objects,  // get_const(index) function pointer
    get_function__Detections__detected_objects,  // get(index) function pointer
    fetch_function__Detections__detected_objects,  // fetch(index, &value) function pointer
    assign_function__Detections__detected_objects,  // assign(index, value) function pointer
    resize_function__Detections__detected_objects  // resize(index) function pointer
  },
  {
    "radar_x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface::msg::Detections, radar_x),  // bytes offset in struct
    nullptr,  // default value
    size_function__Detections__radar_x,  // size() function pointer
    get_const_function__Detections__radar_x,  // get_const(index) function pointer
    get_function__Detections__radar_x,  // get(index) function pointer
    fetch_function__Detections__radar_x,  // fetch(index, &value) function pointer
    assign_function__Detections__radar_x,  // assign(index, value) function pointer
    resize_function__Detections__radar_x  // resize(index) function pointer
  },
  {
    "radar_y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface::msg::Detections, radar_y),  // bytes offset in struct
    nullptr,  // default value
    size_function__Detections__radar_y,  // size() function pointer
    get_const_function__Detections__radar_y,  // get_const(index) function pointer
    get_function__Detections__radar_y,  // get(index) function pointer
    fetch_function__Detections__radar_y,  // fetch(index, &value) function pointer
    assign_function__Detections__radar_y,  // assign(index, value) function pointer
    resize_function__Detections__radar_y  // resize(index) function pointer
  },
  {
    "corner_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface::msg::Detections, corner_pos),  // bytes offset in struct
    nullptr,  // default value
    size_function__Detections__corner_pos,  // size() function pointer
    get_const_function__Detections__corner_pos,  // get_const(index) function pointer
    get_function__Detections__corner_pos,  // get(index) function pointer
    fetch_function__Detections__corner_pos,  // fetch(index, &value) function pointer
    assign_function__Detections__corner_pos,  // assign(index, value) function pointer
    resize_function__Detections__corner_pos  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Detections_message_members = {
  "vision_interface::msg",  // message namespace
  "Detections",  // message name
  5,  // number of fields
  sizeof(vision_interface::msg::Detections),
  Detections_message_member_array,  // message members
  Detections_init_function,  // function to initialize message memory (memory has to be allocated)
  Detections_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Detections_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Detections_message_members,
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
get_message_type_support_handle<vision_interface::msg::Detections>()
{
  return &::vision_interface::msg::rosidl_typesupport_introspection_cpp::Detections_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vision_interface, msg, Detections)() {
  return &::vision_interface::msg::rosidl_typesupport_introspection_cpp::Detections_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
