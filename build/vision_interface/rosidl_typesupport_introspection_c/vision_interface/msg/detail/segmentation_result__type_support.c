// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vision_interface:msg/SegmentationResult.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vision_interface/msg/detail/segmentation_result__rosidl_typesupport_introspection_c.h"
#include "vision_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vision_interface/msg/detail/segmentation_result__functions.h"
#include "vision_interface/msg/detail/segmentation_result__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `lines`
#include "vision_interface/msg/segmentation_line.h"
// Member `lines`
#include "vision_interface/msg/detail/segmentation_line__rosidl_typesupport_introspection_c.h"
// Member `points`
#include "vision_interface/msg/segmentation_point.h"
// Member `points`
#include "vision_interface/msg/detail/segmentation_point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__SegmentationResult_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vision_interface__msg__SegmentationResult__init(message_memory);
}

void vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__SegmentationResult_fini_function(void * message_memory)
{
  vision_interface__msg__SegmentationResult__fini(message_memory);
}

size_t vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__size_function__SegmentationResult__lines(
  const void * untyped_member)
{
  const vision_interface__msg__SegmentationLine__Sequence * member =
    (const vision_interface__msg__SegmentationLine__Sequence *)(untyped_member);
  return member->size;
}

const void * vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__get_const_function__SegmentationResult__lines(
  const void * untyped_member, size_t index)
{
  const vision_interface__msg__SegmentationLine__Sequence * member =
    (const vision_interface__msg__SegmentationLine__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__get_function__SegmentationResult__lines(
  void * untyped_member, size_t index)
{
  vision_interface__msg__SegmentationLine__Sequence * member =
    (vision_interface__msg__SegmentationLine__Sequence *)(untyped_member);
  return &member->data[index];
}

void vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__fetch_function__SegmentationResult__lines(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vision_interface__msg__SegmentationLine * item =
    ((const vision_interface__msg__SegmentationLine *)
    vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__get_const_function__SegmentationResult__lines(untyped_member, index));
  vision_interface__msg__SegmentationLine * value =
    (vision_interface__msg__SegmentationLine *)(untyped_value);
  *value = *item;
}

void vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__assign_function__SegmentationResult__lines(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vision_interface__msg__SegmentationLine * item =
    ((vision_interface__msg__SegmentationLine *)
    vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__get_function__SegmentationResult__lines(untyped_member, index));
  const vision_interface__msg__SegmentationLine * value =
    (const vision_interface__msg__SegmentationLine *)(untyped_value);
  *item = *value;
}

bool vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__resize_function__SegmentationResult__lines(
  void * untyped_member, size_t size)
{
  vision_interface__msg__SegmentationLine__Sequence * member =
    (vision_interface__msg__SegmentationLine__Sequence *)(untyped_member);
  vision_interface__msg__SegmentationLine__Sequence__fini(member);
  return vision_interface__msg__SegmentationLine__Sequence__init(member, size);
}

size_t vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__size_function__SegmentationResult__points(
  const void * untyped_member)
{
  const vision_interface__msg__SegmentationPoint__Sequence * member =
    (const vision_interface__msg__SegmentationPoint__Sequence *)(untyped_member);
  return member->size;
}

const void * vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__get_const_function__SegmentationResult__points(
  const void * untyped_member, size_t index)
{
  const vision_interface__msg__SegmentationPoint__Sequence * member =
    (const vision_interface__msg__SegmentationPoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__get_function__SegmentationResult__points(
  void * untyped_member, size_t index)
{
  vision_interface__msg__SegmentationPoint__Sequence * member =
    (vision_interface__msg__SegmentationPoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__fetch_function__SegmentationResult__points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vision_interface__msg__SegmentationPoint * item =
    ((const vision_interface__msg__SegmentationPoint *)
    vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__get_const_function__SegmentationResult__points(untyped_member, index));
  vision_interface__msg__SegmentationPoint * value =
    (vision_interface__msg__SegmentationPoint *)(untyped_value);
  *value = *item;
}

void vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__assign_function__SegmentationResult__points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vision_interface__msg__SegmentationPoint * item =
    ((vision_interface__msg__SegmentationPoint *)
    vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__get_function__SegmentationResult__points(untyped_member, index));
  const vision_interface__msg__SegmentationPoint * value =
    (const vision_interface__msg__SegmentationPoint *)(untyped_value);
  *item = *value;
}

bool vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__resize_function__SegmentationResult__points(
  void * untyped_member, size_t size)
{
  vision_interface__msg__SegmentationPoint__Sequence * member =
    (vision_interface__msg__SegmentationPoint__Sequence *)(untyped_member);
  vision_interface__msg__SegmentationPoint__Sequence__fini(member);
  return vision_interface__msg__SegmentationPoint__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__SegmentationResult_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__SegmentationResult, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "lines",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__SegmentationResult, lines),  // bytes offset in struct
    NULL,  // default value
    vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__size_function__SegmentationResult__lines,  // size() function pointer
    vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__get_const_function__SegmentationResult__lines,  // get_const(index) function pointer
    vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__get_function__SegmentationResult__lines,  // get(index) function pointer
    vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__fetch_function__SegmentationResult__lines,  // fetch(index, &value) function pointer
    vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__assign_function__SegmentationResult__lines,  // assign(index, value) function pointer
    vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__resize_function__SegmentationResult__lines  // resize(index) function pointer
  },
  {
    "points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__SegmentationResult, points),  // bytes offset in struct
    NULL,  // default value
    vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__size_function__SegmentationResult__points,  // size() function pointer
    vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__get_const_function__SegmentationResult__points,  // get_const(index) function pointer
    vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__get_function__SegmentationResult__points,  // get(index) function pointer
    vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__fetch_function__SegmentationResult__points,  // fetch(index, &value) function pointer
    vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__assign_function__SegmentationResult__points,  // assign(index, value) function pointer
    vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__resize_function__SegmentationResult__points  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__SegmentationResult_message_members = {
  "vision_interface__msg",  // message namespace
  "SegmentationResult",  // message name
  3,  // number of fields
  sizeof(vision_interface__msg__SegmentationResult),
  vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__SegmentationResult_message_member_array,  // message members
  vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__SegmentationResult_init_function,  // function to initialize message memory (memory has to be allocated)
  vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__SegmentationResult_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__SegmentationResult_message_type_support_handle = {
  0,
  &vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__SegmentationResult_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vision_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vision_interface, msg, SegmentationResult)() {
  vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__SegmentationResult_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__SegmentationResult_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vision_interface, msg, SegmentationLine)();
  vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__SegmentationResult_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vision_interface, msg, SegmentationPoint)();
  if (!vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__SegmentationResult_message_type_support_handle.typesupport_identifier) {
    vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__SegmentationResult_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vision_interface__msg__SegmentationResult__rosidl_typesupport_introspection_c__SegmentationResult_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
