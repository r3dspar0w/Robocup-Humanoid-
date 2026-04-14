// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vision_interface:msg/LineSegments.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vision_interface/msg/detail/line_segments__rosidl_typesupport_introspection_c.h"
#include "vision_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vision_interface/msg/detail/line_segments__functions.h"
#include "vision_interface/msg/detail/line_segments__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `coordinates`
// Member `coordinates_uv`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__LineSegments_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vision_interface__msg__LineSegments__init(message_memory);
}

void vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__LineSegments_fini_function(void * message_memory)
{
  vision_interface__msg__LineSegments__fini(message_memory);
}

size_t vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__size_function__LineSegments__coordinates(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__get_const_function__LineSegments__coordinates(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__get_function__LineSegments__coordinates(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__fetch_function__LineSegments__coordinates(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__get_const_function__LineSegments__coordinates(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__assign_function__LineSegments__coordinates(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__get_function__LineSegments__coordinates(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__resize_function__LineSegments__coordinates(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__size_function__LineSegments__coordinates_uv(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__get_const_function__LineSegments__coordinates_uv(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__get_function__LineSegments__coordinates_uv(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__fetch_function__LineSegments__coordinates_uv(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__get_const_function__LineSegments__coordinates_uv(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__assign_function__LineSegments__coordinates_uv(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__get_function__LineSegments__coordinates_uv(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__resize_function__LineSegments__coordinates_uv(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__LineSegments_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__LineSegments, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "coordinates",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__LineSegments, coordinates),  // bytes offset in struct
    NULL,  // default value
    vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__size_function__LineSegments__coordinates,  // size() function pointer
    vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__get_const_function__LineSegments__coordinates,  // get_const(index) function pointer
    vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__get_function__LineSegments__coordinates,  // get(index) function pointer
    vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__fetch_function__LineSegments__coordinates,  // fetch(index, &value) function pointer
    vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__assign_function__LineSegments__coordinates,  // assign(index, value) function pointer
    vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__resize_function__LineSegments__coordinates  // resize(index) function pointer
  },
  {
    "coordinates_uv",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__LineSegments, coordinates_uv),  // bytes offset in struct
    NULL,  // default value
    vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__size_function__LineSegments__coordinates_uv,  // size() function pointer
    vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__get_const_function__LineSegments__coordinates_uv,  // get_const(index) function pointer
    vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__get_function__LineSegments__coordinates_uv,  // get(index) function pointer
    vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__fetch_function__LineSegments__coordinates_uv,  // fetch(index, &value) function pointer
    vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__assign_function__LineSegments__coordinates_uv,  // assign(index, value) function pointer
    vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__resize_function__LineSegments__coordinates_uv  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__LineSegments_message_members = {
  "vision_interface__msg",  // message namespace
  "LineSegments",  // message name
  3,  // number of fields
  sizeof(vision_interface__msg__LineSegments),
  vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__LineSegments_message_member_array,  // message members
  vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__LineSegments_init_function,  // function to initialize message memory (memory has to be allocated)
  vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__LineSegments_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__LineSegments_message_type_support_handle = {
  0,
  &vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__LineSegments_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vision_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vision_interface, msg, LineSegments)() {
  vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__LineSegments_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__LineSegments_message_type_support_handle.typesupport_identifier) {
    vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__LineSegments_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vision_interface__msg__LineSegments__rosidl_typesupport_introspection_c__LineSegments_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
