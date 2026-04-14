// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from booster_interface:msg/RemoteControllerState.idl
// generated code does not contain a copyright notice
#include "booster_interface/msg/detail/remote_controller_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "booster_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "booster_interface/msg/detail/remote_controller_state__struct.h"
#include "booster_interface/msg/detail/remote_controller_state__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _RemoteControllerState__ros_msg_type = booster_interface__msg__RemoteControllerState;

static bool _RemoteControllerState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RemoteControllerState__ros_msg_type * ros_message = static_cast<const _RemoteControllerState__ros_msg_type *>(untyped_ros_message);
  // Field name: event
  {
    cdr << ros_message->event;
  }

  // Field name: lx
  {
    cdr << ros_message->lx;
  }

  // Field name: ly
  {
    cdr << ros_message->ly;
  }

  // Field name: rx
  {
    cdr << ros_message->rx;
  }

  // Field name: ry
  {
    cdr << ros_message->ry;
  }

  // Field name: a
  {
    cdr << (ros_message->a ? true : false);
  }

  // Field name: b
  {
    cdr << (ros_message->b ? true : false);
  }

  // Field name: x
  {
    cdr << (ros_message->x ? true : false);
  }

  // Field name: y
  {
    cdr << (ros_message->y ? true : false);
  }

  // Field name: lb
  {
    cdr << (ros_message->lb ? true : false);
  }

  // Field name: rb
  {
    cdr << (ros_message->rb ? true : false);
  }

  // Field name: lt
  {
    cdr << (ros_message->lt ? true : false);
  }

  // Field name: rt
  {
    cdr << (ros_message->rt ? true : false);
  }

  // Field name: ls
  {
    cdr << (ros_message->ls ? true : false);
  }

  // Field name: rs
  {
    cdr << (ros_message->rs ? true : false);
  }

  // Field name: back
  {
    cdr << (ros_message->back ? true : false);
  }

  // Field name: start
  {
    cdr << (ros_message->start ? true : false);
  }

  // Field name: hat_c
  {
    cdr << (ros_message->hat_c ? true : false);
  }

  // Field name: hat_u
  {
    cdr << (ros_message->hat_u ? true : false);
  }

  // Field name: hat_d
  {
    cdr << (ros_message->hat_d ? true : false);
  }

  // Field name: hat_l
  {
    cdr << (ros_message->hat_l ? true : false);
  }

  // Field name: hat_r
  {
    cdr << (ros_message->hat_r ? true : false);
  }

  // Field name: hat_lu
  {
    cdr << (ros_message->hat_lu ? true : false);
  }

  // Field name: hat_ld
  {
    cdr << (ros_message->hat_ld ? true : false);
  }

  // Field name: hat_ru
  {
    cdr << (ros_message->hat_ru ? true : false);
  }

  // Field name: hat_rd
  {
    cdr << (ros_message->hat_rd ? true : false);
  }

  // Field name: hat_pos
  {
    cdr << ros_message->hat_pos;
  }

  return true;
}

static bool _RemoteControllerState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RemoteControllerState__ros_msg_type * ros_message = static_cast<_RemoteControllerState__ros_msg_type *>(untyped_ros_message);
  // Field name: event
  {
    cdr >> ros_message->event;
  }

  // Field name: lx
  {
    cdr >> ros_message->lx;
  }

  // Field name: ly
  {
    cdr >> ros_message->ly;
  }

  // Field name: rx
  {
    cdr >> ros_message->rx;
  }

  // Field name: ry
  {
    cdr >> ros_message->ry;
  }

  // Field name: a
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->a = tmp ? true : false;
  }

  // Field name: b
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->b = tmp ? true : false;
  }

  // Field name: x
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->x = tmp ? true : false;
  }

  // Field name: y
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->y = tmp ? true : false;
  }

  // Field name: lb
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->lb = tmp ? true : false;
  }

  // Field name: rb
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->rb = tmp ? true : false;
  }

  // Field name: lt
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->lt = tmp ? true : false;
  }

  // Field name: rt
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->rt = tmp ? true : false;
  }

  // Field name: ls
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->ls = tmp ? true : false;
  }

  // Field name: rs
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->rs = tmp ? true : false;
  }

  // Field name: back
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->back = tmp ? true : false;
  }

  // Field name: start
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->start = tmp ? true : false;
  }

  // Field name: hat_c
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->hat_c = tmp ? true : false;
  }

  // Field name: hat_u
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->hat_u = tmp ? true : false;
  }

  // Field name: hat_d
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->hat_d = tmp ? true : false;
  }

  // Field name: hat_l
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->hat_l = tmp ? true : false;
  }

  // Field name: hat_r
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->hat_r = tmp ? true : false;
  }

  // Field name: hat_lu
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->hat_lu = tmp ? true : false;
  }

  // Field name: hat_ld
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->hat_ld = tmp ? true : false;
  }

  // Field name: hat_ru
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->hat_ru = tmp ? true : false;
  }

  // Field name: hat_rd
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->hat_rd = tmp ? true : false;
  }

  // Field name: hat_pos
  {
    cdr >> ros_message->hat_pos;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_booster_interface
size_t get_serialized_size_booster_interface__msg__RemoteControllerState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RemoteControllerState__ros_msg_type * ros_message = static_cast<const _RemoteControllerState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name event
  {
    size_t item_size = sizeof(ros_message->event);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name lx
  {
    size_t item_size = sizeof(ros_message->lx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ly
  {
    size_t item_size = sizeof(ros_message->ly);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rx
  {
    size_t item_size = sizeof(ros_message->rx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ry
  {
    size_t item_size = sizeof(ros_message->ry);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a
  {
    size_t item_size = sizeof(ros_message->a);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name b
  {
    size_t item_size = sizeof(ros_message->b);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name lb
  {
    size_t item_size = sizeof(ros_message->lb);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rb
  {
    size_t item_size = sizeof(ros_message->rb);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name lt
  {
    size_t item_size = sizeof(ros_message->lt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rt
  {
    size_t item_size = sizeof(ros_message->rt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ls
  {
    size_t item_size = sizeof(ros_message->ls);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rs
  {
    size_t item_size = sizeof(ros_message->rs);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name back
  {
    size_t item_size = sizeof(ros_message->back);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name start
  {
    size_t item_size = sizeof(ros_message->start);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hat_c
  {
    size_t item_size = sizeof(ros_message->hat_c);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hat_u
  {
    size_t item_size = sizeof(ros_message->hat_u);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hat_d
  {
    size_t item_size = sizeof(ros_message->hat_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hat_l
  {
    size_t item_size = sizeof(ros_message->hat_l);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hat_r
  {
    size_t item_size = sizeof(ros_message->hat_r);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hat_lu
  {
    size_t item_size = sizeof(ros_message->hat_lu);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hat_ld
  {
    size_t item_size = sizeof(ros_message->hat_ld);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hat_ru
  {
    size_t item_size = sizeof(ros_message->hat_ru);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hat_rd
  {
    size_t item_size = sizeof(ros_message->hat_rd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hat_pos
  {
    size_t item_size = sizeof(ros_message->hat_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RemoteControllerState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_booster_interface__msg__RemoteControllerState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_booster_interface
size_t max_serialized_size_booster_interface__msg__RemoteControllerState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: event
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: lx
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ly
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: rx
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ry
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: a
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: b
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: lb
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: rb
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: lt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: rt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: ls
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: rs
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: back
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: start
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: hat_c
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: hat_u
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: hat_d
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: hat_l
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: hat_r
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: hat_lu
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: hat_ld
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: hat_ru
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: hat_rd
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: hat_pos
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = booster_interface__msg__RemoteControllerState;
    is_plain =
      (
      offsetof(DataType, hat_pos) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _RemoteControllerState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_booster_interface__msg__RemoteControllerState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RemoteControllerState = {
  "booster_interface::msg",
  "RemoteControllerState",
  _RemoteControllerState__cdr_serialize,
  _RemoteControllerState__cdr_deserialize,
  _RemoteControllerState__get_serialized_size,
  _RemoteControllerState__max_serialized_size
};

static rosidl_message_type_support_t _RemoteControllerState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RemoteControllerState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, booster_interface, msg, RemoteControllerState)() {
  return &_RemoteControllerState__type_support;
}

#if defined(__cplusplus)
}
#endif
