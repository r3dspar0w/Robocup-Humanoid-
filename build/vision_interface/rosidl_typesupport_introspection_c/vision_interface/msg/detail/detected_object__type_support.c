// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vision_interface:msg/DetectedObject.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vision_interface/msg/detail/detected_object__rosidl_typesupport_introspection_c.h"
#include "vision_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vision_interface/msg/detail/detected_object__functions.h"
#include "vision_interface/msg/detail/detected_object__struct.h"


// Include directives for member types
// Member `label`
// Member `color`
#include "rosidl_runtime_c/string_functions.h"
// Member `target_uv`
// Member `received_pos`
// Member `position`
// Member `position_projection`
// Member `position_cam`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__DetectedObject_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vision_interface__msg__DetectedObject__init(message_memory);
}

void vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__DetectedObject_fini_function(void * message_memory)
{
  vision_interface__msg__DetectedObject__fini(message_memory);
}

size_t vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__size_function__DetectedObject__target_uv(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_const_function__DetectedObject__target_uv(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_function__DetectedObject__target_uv(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__fetch_function__DetectedObject__target_uv(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_const_function__DetectedObject__target_uv(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__assign_function__DetectedObject__target_uv(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_function__DetectedObject__target_uv(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__resize_function__DetectedObject__target_uv(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__size_function__DetectedObject__received_pos(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_const_function__DetectedObject__received_pos(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_function__DetectedObject__received_pos(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__fetch_function__DetectedObject__received_pos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_const_function__DetectedObject__received_pos(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__assign_function__DetectedObject__received_pos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_function__DetectedObject__received_pos(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__resize_function__DetectedObject__received_pos(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__size_function__DetectedObject__position(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_const_function__DetectedObject__position(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_function__DetectedObject__position(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__fetch_function__DetectedObject__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_const_function__DetectedObject__position(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__assign_function__DetectedObject__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_function__DetectedObject__position(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__resize_function__DetectedObject__position(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__size_function__DetectedObject__position_projection(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_const_function__DetectedObject__position_projection(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_function__DetectedObject__position_projection(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__fetch_function__DetectedObject__position_projection(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_const_function__DetectedObject__position_projection(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__assign_function__DetectedObject__position_projection(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_function__DetectedObject__position_projection(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__resize_function__DetectedObject__position_projection(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__size_function__DetectedObject__position_cam(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_const_function__DetectedObject__position_cam(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_function__DetectedObject__position_cam(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__fetch_function__DetectedObject__position_cam(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_const_function__DetectedObject__position_cam(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__assign_function__DetectedObject__position_cam(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_function__DetectedObject__position_cam(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__resize_function__DetectedObject__position_cam(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__DetectedObject_message_member_array[13] = {
  {
    "label",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__DetectedObject, label),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "color",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__DetectedObject, color),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__DetectedObject, confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "xmin",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__DetectedObject, xmin),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ymin",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__DetectedObject, ymin),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "xmax",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__DetectedObject, xmax),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ymax",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__DetectedObject, ymax),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_uv",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__DetectedObject, target_uv),  // bytes offset in struct
    NULL,  // default value
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__size_function__DetectedObject__target_uv,  // size() function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_const_function__DetectedObject__target_uv,  // get_const(index) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_function__DetectedObject__target_uv,  // get(index) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__fetch_function__DetectedObject__target_uv,  // fetch(index, &value) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__assign_function__DetectedObject__target_uv,  // assign(index, value) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__resize_function__DetectedObject__target_uv  // resize(index) function pointer
  },
  {
    "received_pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__DetectedObject, received_pos),  // bytes offset in struct
    NULL,  // default value
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__size_function__DetectedObject__received_pos,  // size() function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_const_function__DetectedObject__received_pos,  // get_const(index) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_function__DetectedObject__received_pos,  // get(index) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__fetch_function__DetectedObject__received_pos,  // fetch(index, &value) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__assign_function__DetectedObject__received_pos,  // assign(index, value) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__resize_function__DetectedObject__received_pos  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__DetectedObject, position),  // bytes offset in struct
    NULL,  // default value
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__size_function__DetectedObject__position,  // size() function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_const_function__DetectedObject__position,  // get_const(index) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_function__DetectedObject__position,  // get(index) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__fetch_function__DetectedObject__position,  // fetch(index, &value) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__assign_function__DetectedObject__position,  // assign(index, value) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__resize_function__DetectedObject__position  // resize(index) function pointer
  },
  {
    "position_projection",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__DetectedObject, position_projection),  // bytes offset in struct
    NULL,  // default value
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__size_function__DetectedObject__position_projection,  // size() function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_const_function__DetectedObject__position_projection,  // get_const(index) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_function__DetectedObject__position_projection,  // get(index) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__fetch_function__DetectedObject__position_projection,  // fetch(index, &value) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__assign_function__DetectedObject__position_projection,  // assign(index, value) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__resize_function__DetectedObject__position_projection  // resize(index) function pointer
  },
  {
    "position_cam",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__DetectedObject, position_cam),  // bytes offset in struct
    NULL,  // default value
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__size_function__DetectedObject__position_cam,  // size() function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_const_function__DetectedObject__position_cam,  // get_const(index) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__get_function__DetectedObject__position_cam,  // get(index) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__fetch_function__DetectedObject__position_cam,  // fetch(index, &value) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__assign_function__DetectedObject__position_cam,  // assign(index, value) function pointer
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__resize_function__DetectedObject__position_cam  // resize(index) function pointer
  },
  {
    "position_confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__DetectedObject, position_confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__DetectedObject_message_members = {
  "vision_interface__msg",  // message namespace
  "DetectedObject",  // message name
  13,  // number of fields
  sizeof(vision_interface__msg__DetectedObject),
  vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__DetectedObject_message_member_array,  // message members
  vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__DetectedObject_init_function,  // function to initialize message memory (memory has to be allocated)
  vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__DetectedObject_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__DetectedObject_message_type_support_handle = {
  0,
  &vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__DetectedObject_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vision_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vision_interface, msg, DetectedObject)() {
  if (!vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__DetectedObject_message_type_support_handle.typesupport_identifier) {
    vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__DetectedObject_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vision_interface__msg__DetectedObject__rosidl_typesupport_introspection_c__DetectedObject_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
