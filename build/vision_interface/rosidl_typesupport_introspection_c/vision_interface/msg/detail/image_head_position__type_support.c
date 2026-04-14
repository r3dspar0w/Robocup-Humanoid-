// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vision_interface:msg/ImageHeadPosition.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vision_interface/msg/detail/image_head_position__rosidl_typesupport_introspection_c.h"
#include "vision_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vision_interface/msg/detail/image_head_position__functions.h"
#include "vision_interface/msg/detail/image_head_position__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `position`
#include "geometry_msgs/msg/pose.h"
// Member `position`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `image`
#include "sensor_msgs/msg/image.h"
// Member `image`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vision_interface__msg__ImageHeadPosition__rosidl_typesupport_introspection_c__ImageHeadPosition_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vision_interface__msg__ImageHeadPosition__init(message_memory);
}

void vision_interface__msg__ImageHeadPosition__rosidl_typesupport_introspection_c__ImageHeadPosition_fini_function(void * message_memory)
{
  vision_interface__msg__ImageHeadPosition__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vision_interface__msg__ImageHeadPosition__rosidl_typesupport_introspection_c__ImageHeadPosition_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__ImageHeadPosition, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__ImageHeadPosition, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "image",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_interface__msg__ImageHeadPosition, image),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vision_interface__msg__ImageHeadPosition__rosidl_typesupport_introspection_c__ImageHeadPosition_message_members = {
  "vision_interface__msg",  // message namespace
  "ImageHeadPosition",  // message name
  3,  // number of fields
  sizeof(vision_interface__msg__ImageHeadPosition),
  vision_interface__msg__ImageHeadPosition__rosidl_typesupport_introspection_c__ImageHeadPosition_message_member_array,  // message members
  vision_interface__msg__ImageHeadPosition__rosidl_typesupport_introspection_c__ImageHeadPosition_init_function,  // function to initialize message memory (memory has to be allocated)
  vision_interface__msg__ImageHeadPosition__rosidl_typesupport_introspection_c__ImageHeadPosition_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vision_interface__msg__ImageHeadPosition__rosidl_typesupport_introspection_c__ImageHeadPosition_message_type_support_handle = {
  0,
  &vision_interface__msg__ImageHeadPosition__rosidl_typesupport_introspection_c__ImageHeadPosition_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vision_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vision_interface, msg, ImageHeadPosition)() {
  vision_interface__msg__ImageHeadPosition__rosidl_typesupport_introspection_c__ImageHeadPosition_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  vision_interface__msg__ImageHeadPosition__rosidl_typesupport_introspection_c__ImageHeadPosition_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  vision_interface__msg__ImageHeadPosition__rosidl_typesupport_introspection_c__ImageHeadPosition_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!vision_interface__msg__ImageHeadPosition__rosidl_typesupport_introspection_c__ImageHeadPosition_message_type_support_handle.typesupport_identifier) {
    vision_interface__msg__ImageHeadPosition__rosidl_typesupport_introspection_c__ImageHeadPosition_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vision_interface__msg__ImageHeadPosition__rosidl_typesupport_introspection_c__ImageHeadPosition_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
