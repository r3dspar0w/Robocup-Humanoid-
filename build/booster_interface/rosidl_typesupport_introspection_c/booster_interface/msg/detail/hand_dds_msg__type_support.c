// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from booster_interface:msg/HandDdsMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "booster_interface/msg/detail/hand_dds_msg__rosidl_typesupport_introspection_c.h"
#include "booster_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "booster_interface/msg/detail/hand_dds_msg__functions.h"
#include "booster_interface/msg/detail/hand_dds_msg__struct.h"


// Include directives for member types
// Member `hands_vec`
#include "booster_interface/msg/hand_command.h"
// Member `hands_vec`
#include "booster_interface/msg/detail/hand_command__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__HandDdsMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  booster_interface__msg__HandDdsMsg__init(message_memory);
}

void booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__HandDdsMsg_fini_function(void * message_memory)
{
  booster_interface__msg__HandDdsMsg__fini(message_memory);
}

size_t booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__size_function__HandDdsMsg__hands_vec(
  const void * untyped_member)
{
  const booster_interface__msg__HandCommand__Sequence * member =
    (const booster_interface__msg__HandCommand__Sequence *)(untyped_member);
  return member->size;
}

const void * booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__get_const_function__HandDdsMsg__hands_vec(
  const void * untyped_member, size_t index)
{
  const booster_interface__msg__HandCommand__Sequence * member =
    (const booster_interface__msg__HandCommand__Sequence *)(untyped_member);
  return &member->data[index];
}

void * booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__get_function__HandDdsMsg__hands_vec(
  void * untyped_member, size_t index)
{
  booster_interface__msg__HandCommand__Sequence * member =
    (booster_interface__msg__HandCommand__Sequence *)(untyped_member);
  return &member->data[index];
}

void booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__fetch_function__HandDdsMsg__hands_vec(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const booster_interface__msg__HandCommand * item =
    ((const booster_interface__msg__HandCommand *)
    booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__get_const_function__HandDdsMsg__hands_vec(untyped_member, index));
  booster_interface__msg__HandCommand * value =
    (booster_interface__msg__HandCommand *)(untyped_value);
  *value = *item;
}

void booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__assign_function__HandDdsMsg__hands_vec(
  void * untyped_member, size_t index, const void * untyped_value)
{
  booster_interface__msg__HandCommand * item =
    ((booster_interface__msg__HandCommand *)
    booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__get_function__HandDdsMsg__hands_vec(untyped_member, index));
  const booster_interface__msg__HandCommand * value =
    (const booster_interface__msg__HandCommand *)(untyped_value);
  *item = *value;
}

bool booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__resize_function__HandDdsMsg__hands_vec(
  void * untyped_member, size_t size)
{
  booster_interface__msg__HandCommand__Sequence * member =
    (booster_interface__msg__HandCommand__Sequence *)(untyped_member);
  booster_interface__msg__HandCommand__Sequence__fini(member);
  return booster_interface__msg__HandCommand__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__HandDdsMsg_message_member_array[1] = {
  {
    "hands_vec",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(booster_interface__msg__HandDdsMsg, hands_vec),  // bytes offset in struct
    NULL,  // default value
    booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__size_function__HandDdsMsg__hands_vec,  // size() function pointer
    booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__get_const_function__HandDdsMsg__hands_vec,  // get_const(index) function pointer
    booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__get_function__HandDdsMsg__hands_vec,  // get(index) function pointer
    booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__fetch_function__HandDdsMsg__hands_vec,  // fetch(index, &value) function pointer
    booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__assign_function__HandDdsMsg__hands_vec,  // assign(index, value) function pointer
    booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__resize_function__HandDdsMsg__hands_vec  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__HandDdsMsg_message_members = {
  "booster_interface__msg",  // message namespace
  "HandDdsMsg",  // message name
  1,  // number of fields
  sizeof(booster_interface__msg__HandDdsMsg),
  booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__HandDdsMsg_message_member_array,  // message members
  booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__HandDdsMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__HandDdsMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__HandDdsMsg_message_type_support_handle = {
  0,
  &booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__HandDdsMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_booster_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, msg, HandDdsMsg)() {
  booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__HandDdsMsg_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, msg, HandCommand)();
  if (!booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__HandDdsMsg_message_type_support_handle.typesupport_identifier) {
    booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__HandDdsMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &booster_interface__msg__HandDdsMsg__rosidl_typesupport_introspection_c__HandDdsMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
