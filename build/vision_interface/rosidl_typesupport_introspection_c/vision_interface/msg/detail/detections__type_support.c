// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vision_interface:msg/Detections.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vision_interface/msg/detail/detections__rosidl_typesupport_introspection_c.h"
#include "vision_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vision_interface/msg/detail/detections__functions.h"
#include "vision_interface/msg/detail/detections__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `detected_objects`
#include "vision_interface/msg/detected_object.h"
// Member `detected_objects`
#include "vision_interface/msg/detail/detected_object__rosidl_typesupport_introspection_c.h"
// Member `radar_x`
// Member `radar_y`
// Member `corner_pos`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vision_interface__msg__Detections__rosidl_typesupport_introspection_c__Detections_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vision_interface__msg__Detections__init(message_memory);
}

void vision_interface__msg__Detections__rosidl_typesupport_introspection_c__Detections_fini_function(void * message_memory)
{
  vision_interface__msg__Detections__fini(message_memory);
}

size_t vision_interface__msg__Detections__rosidl_typesupport_introspection_c__size_function__Detections__detected_objects(
  const void * untyped_member)
{
  const vision_interface__msg__DetectedObject__Sequence * member =
    (const vision_interface__msg__DetectedObject__Sequence *)(untyped_member);
  return member->size;
}

const void * vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_const_function__Detections__detected_objects(
  const void * untyped_member, size_t index)
{
  const vision_interface__msg__DetectedObject__Sequence * member =
    (const vision_interface__msg__DetectedObject__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_function__Detections__detected_objects(
  void * untyped_member, size_t index)
{
  vision_interface__msg__DetectedObject__Sequence * member =
    (vision_interface__msg__DetectedObject__Sequence *)(untyped_member);
  return &member->data[index];
}

void vision_interface__msg__Detections__rosidl_typesupport_introspection_c__fetch_function__Detections__detected_objects(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vision_interface__msg__DetectedObject * item =
    ((const vision_interface__msg__DetectedObject *)
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_const_function__Detections__detected_objects(untyped_member, index));
  vision_interface__msg__DetectedObject * value =
    (vision_interface__msg__DetectedObject *)(untyped_value);
  *value = *item;
}

void vision_interface__msg__Detections__rosidl_typesupport_introspection_c__assign_function__Detections__detected_objects(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vision_interface__msg__DetectedObject * item =
    ((vision_interface__msg__DetectedObject *)
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_function__Detections__detected_objects(untyped_member, index));
  const vision_interface__msg__DetectedObject * value =
    (const vision_interface__msg__DetectedObject *)(untyped_value);
  *item = *value;
}

bool vision_interface__msg__Detections__rosidl_typesupport_introspection_c__resize_function__Detections__detected_objects(
  void * untyped_member, size_t size)
{
  vision_interface__msg__DetectedObject__Sequence * member =
    (vision_interface__msg__DetectedObject__Sequence *)(untyped_member);
  vision_interface__msg__DetectedObject__Sequence__fini(member);
  return vision_interface__msg__DetectedObject__Sequence__init(member, size);
}

size_t vision_interface__msg__Detections__rosidl_typesupport_introspection_c__size_function__Detections__radar_x(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_const_function__Detections__radar_x(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_function__Detections__radar_x(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void vision_interface__msg__Detections__rosidl_typesupport_introspection_c__fetch_function__Detections__radar_x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_const_function__Detections__radar_x(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void vision_interface__msg__Detections__rosidl_typesupport_introspection_c__assign_function__Detections__radar_x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_function__Detections__radar_x(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool vision_interface__msg__Detections__rosidl_typesupport_introspection_c__resize_function__Detections__radar_x(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t vision_interface__msg__Detections__rosidl_typesupport_introspection_c__size_function__Detections__radar_y(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_const_function__Detections__radar_y(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_function__Detections__radar_y(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void vision_interface__msg__Detections__rosidl_typesupport_introspection_c__fetch_function__Detections__radar_y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_const_function__Detections__radar_y(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void vision_interface__msg__Detections__rosidl_typesupport_introspection_c__assign_function__Detections__radar_y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_function__Detections__radar_y(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool vision_interface__msg__Detections__rosidl_typesupport_introspection_c__resize_function__Detections__radar_y(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t vision_interface__msg__Detections__rosidl_typesupport_introspection_c__size_function__Detections__corner_pos(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_const_function__Detections__corner_pos(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_function__Detections__corner_pos(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void vision_interface__msg__Detections__rosidl_typesupport_introspection_c__fetch_function__Detections__corner_pos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_const_function__Detections__corner_pos(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void vision_interface__msg__Detections__rosidl_typesupport_introspection_c__assign_function__Detections__corner_pos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_function__Detections__corner_pos(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool vision_interface__msg__Detections__rosidl_typesupport_introspection_c__resize_function__Detections__corner_pos(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vision_interface__msg__Detections__rosidl_typesupport_introspection_c__Detections_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__Detections, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "detected_objects",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__Detections, detected_objects),  // bytes offset in struct
    NULL,  // default value
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__size_function__Detections__detected_objects,  // size() function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_const_function__Detections__detected_objects,  // get_const(index) function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_function__Detections__detected_objects,  // get(index) function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__fetch_function__Detections__detected_objects,  // fetch(index, &value) function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__assign_function__Detections__detected_objects,  // assign(index, value) function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__resize_function__Detections__detected_objects  // resize(index) function pointer
  },
  {
    "radar_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__Detections, radar_x),  // bytes offset in struct
    NULL,  // default value
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__size_function__Detections__radar_x,  // size() function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_const_function__Detections__radar_x,  // get_const(index) function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_function__Detections__radar_x,  // get(index) function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__fetch_function__Detections__radar_x,  // fetch(index, &value) function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__assign_function__Detections__radar_x,  // assign(index, value) function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__resize_function__Detections__radar_x  // resize(index) function pointer
  },
  {
    "radar_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__Detections, radar_y),  // bytes offset in struct
    NULL,  // default value
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__size_function__Detections__radar_y,  // size() function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_const_function__Detections__radar_y,  // get_const(index) function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_function__Detections__radar_y,  // get(index) function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__fetch_function__Detections__radar_y,  // fetch(index, &value) function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__assign_function__Detections__radar_y,  // assign(index, value) function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__resize_function__Detections__radar_y  // resize(index) function pointer
  },
  {
    "corner_pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__Detections, corner_pos),  // bytes offset in struct
    NULL,  // default value
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__size_function__Detections__corner_pos,  // size() function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_const_function__Detections__corner_pos,  // get_const(index) function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__get_function__Detections__corner_pos,  // get(index) function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__fetch_function__Detections__corner_pos,  // fetch(index, &value) function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__assign_function__Detections__corner_pos,  // assign(index, value) function pointer
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__resize_function__Detections__corner_pos  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vision_interface__msg__Detections__rosidl_typesupport_introspection_c__Detections_message_members = {
  "vision_interface__msg",  // message namespace
  "Detections",  // message name
  5,  // number of fields
  sizeof(vision_interface__msg__Detections),
  vision_interface__msg__Detections__rosidl_typesupport_introspection_c__Detections_message_member_array,  // message members
  vision_interface__msg__Detections__rosidl_typesupport_introspection_c__Detections_init_function,  // function to initialize message memory (memory has to be allocated)
  vision_interface__msg__Detections__rosidl_typesupport_introspection_c__Detections_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vision_interface__msg__Detections__rosidl_typesupport_introspection_c__Detections_message_type_support_handle = {
  0,
  &vision_interface__msg__Detections__rosidl_typesupport_introspection_c__Detections_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vision_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vision_interface, msg, Detections)() {
  vision_interface__msg__Detections__rosidl_typesupport_introspection_c__Detections_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  vision_interface__msg__Detections__rosidl_typesupport_introspection_c__Detections_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vision_interface, msg, DetectedObject)();
  if (!vision_interface__msg__Detections__rosidl_typesupport_introspection_c__Detections_message_type_support_handle.typesupport_identifier) {
    vision_interface__msg__Detections__rosidl_typesupport_introspection_c__Detections_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vision_interface__msg__Detections__rosidl_typesupport_introspection_c__Detections_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
