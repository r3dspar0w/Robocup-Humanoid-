// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from booster_interface:msg/RemoteControllerState.idl
// generated code does not contain a copyright notice
#include "booster_interface/msg/detail/remote_controller_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "booster_interface/msg/detail/remote_controller_state__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace booster_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_booster_interface
cdr_serialize(
  const booster_interface::msg::RemoteControllerState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: event
  cdr << ros_message.event;
  // Member: lx
  cdr << ros_message.lx;
  // Member: ly
  cdr << ros_message.ly;
  // Member: rx
  cdr << ros_message.rx;
  // Member: ry
  cdr << ros_message.ry;
  // Member: a
  cdr << (ros_message.a ? true : false);
  // Member: b
  cdr << (ros_message.b ? true : false);
  // Member: x
  cdr << (ros_message.x ? true : false);
  // Member: y
  cdr << (ros_message.y ? true : false);
  // Member: lb
  cdr << (ros_message.lb ? true : false);
  // Member: rb
  cdr << (ros_message.rb ? true : false);
  // Member: lt
  cdr << (ros_message.lt ? true : false);
  // Member: rt
  cdr << (ros_message.rt ? true : false);
  // Member: ls
  cdr << (ros_message.ls ? true : false);
  // Member: rs
  cdr << (ros_message.rs ? true : false);
  // Member: back
  cdr << (ros_message.back ? true : false);
  // Member: start
  cdr << (ros_message.start ? true : false);
  // Member: hat_c
  cdr << (ros_message.hat_c ? true : false);
  // Member: hat_u
  cdr << (ros_message.hat_u ? true : false);
  // Member: hat_d
  cdr << (ros_message.hat_d ? true : false);
  // Member: hat_l
  cdr << (ros_message.hat_l ? true : false);
  // Member: hat_r
  cdr << (ros_message.hat_r ? true : false);
  // Member: hat_lu
  cdr << (ros_message.hat_lu ? true : false);
  // Member: hat_ld
  cdr << (ros_message.hat_ld ? true : false);
  // Member: hat_ru
  cdr << (ros_message.hat_ru ? true : false);
  // Member: hat_rd
  cdr << (ros_message.hat_rd ? true : false);
  // Member: hat_pos
  cdr << ros_message.hat_pos;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_booster_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  booster_interface::msg::RemoteControllerState & ros_message)
{
  // Member: event
  cdr >> ros_message.event;

  // Member: lx
  cdr >> ros_message.lx;

  // Member: ly
  cdr >> ros_message.ly;

  // Member: rx
  cdr >> ros_message.rx;

  // Member: ry
  cdr >> ros_message.ry;

  // Member: a
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.a = tmp ? true : false;
  }

  // Member: b
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.b = tmp ? true : false;
  }

  // Member: x
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.x = tmp ? true : false;
  }

  // Member: y
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.y = tmp ? true : false;
  }

  // Member: lb
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.lb = tmp ? true : false;
  }

  // Member: rb
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.rb = tmp ? true : false;
  }

  // Member: lt
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.lt = tmp ? true : false;
  }

  // Member: rt
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.rt = tmp ? true : false;
  }

  // Member: ls
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.ls = tmp ? true : false;
  }

  // Member: rs
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.rs = tmp ? true : false;
  }

  // Member: back
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.back = tmp ? true : false;
  }

  // Member: start
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.start = tmp ? true : false;
  }

  // Member: hat_c
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.hat_c = tmp ? true : false;
  }

  // Member: hat_u
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.hat_u = tmp ? true : false;
  }

  // Member: hat_d
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.hat_d = tmp ? true : false;
  }

  // Member: hat_l
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.hat_l = tmp ? true : false;
  }

  // Member: hat_r
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.hat_r = tmp ? true : false;
  }

  // Member: hat_lu
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.hat_lu = tmp ? true : false;
  }

  // Member: hat_ld
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.hat_ld = tmp ? true : false;
  }

  // Member: hat_ru
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.hat_ru = tmp ? true : false;
  }

  // Member: hat_rd
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.hat_rd = tmp ? true : false;
  }

  // Member: hat_pos
  cdr >> ros_message.hat_pos;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_booster_interface
get_serialized_size(
  const booster_interface::msg::RemoteControllerState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: event
  {
    size_t item_size = sizeof(ros_message.event);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: lx
  {
    size_t item_size = sizeof(ros_message.lx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ly
  {
    size_t item_size = sizeof(ros_message.ly);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rx
  {
    size_t item_size = sizeof(ros_message.rx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ry
  {
    size_t item_size = sizeof(ros_message.ry);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a
  {
    size_t item_size = sizeof(ros_message.a);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: b
  {
    size_t item_size = sizeof(ros_message.b);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: x
  {
    size_t item_size = sizeof(ros_message.x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: y
  {
    size_t item_size = sizeof(ros_message.y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: lb
  {
    size_t item_size = sizeof(ros_message.lb);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rb
  {
    size_t item_size = sizeof(ros_message.rb);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: lt
  {
    size_t item_size = sizeof(ros_message.lt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rt
  {
    size_t item_size = sizeof(ros_message.rt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ls
  {
    size_t item_size = sizeof(ros_message.ls);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rs
  {
    size_t item_size = sizeof(ros_message.rs);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: back
  {
    size_t item_size = sizeof(ros_message.back);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: start
  {
    size_t item_size = sizeof(ros_message.start);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hat_c
  {
    size_t item_size = sizeof(ros_message.hat_c);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hat_u
  {
    size_t item_size = sizeof(ros_message.hat_u);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hat_d
  {
    size_t item_size = sizeof(ros_message.hat_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hat_l
  {
    size_t item_size = sizeof(ros_message.hat_l);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hat_r
  {
    size_t item_size = sizeof(ros_message.hat_r);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hat_lu
  {
    size_t item_size = sizeof(ros_message.hat_lu);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hat_ld
  {
    size_t item_size = sizeof(ros_message.hat_ld);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hat_ru
  {
    size_t item_size = sizeof(ros_message.hat_ru);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hat_rd
  {
    size_t item_size = sizeof(ros_message.hat_rd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hat_pos
  {
    size_t item_size = sizeof(ros_message.hat_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_booster_interface
max_serialized_size_RemoteControllerState(
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


  // Member: event
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: lx
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: ly
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: rx
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: ry
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: a
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: b
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: lb
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rb
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: lt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: ls
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rs
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: back
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: start
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: hat_c
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: hat_u
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: hat_d
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: hat_l
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: hat_r
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: hat_lu
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: hat_ld
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: hat_ru
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: hat_rd
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: hat_pos
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
    using DataType = booster_interface::msg::RemoteControllerState;
    is_plain =
      (
      offsetof(DataType, hat_pos) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _RemoteControllerState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const booster_interface::msg::RemoteControllerState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RemoteControllerState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<booster_interface::msg::RemoteControllerState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RemoteControllerState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const booster_interface::msg::RemoteControllerState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RemoteControllerState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RemoteControllerState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RemoteControllerState__callbacks = {
  "booster_interface::msg",
  "RemoteControllerState",
  _RemoteControllerState__cdr_serialize,
  _RemoteControllerState__cdr_deserialize,
  _RemoteControllerState__get_serialized_size,
  _RemoteControllerState__max_serialized_size
};

static rosidl_message_type_support_t _RemoteControllerState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RemoteControllerState__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace booster_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_booster_interface
const rosidl_message_type_support_t *
get_message_type_support_handle<booster_interface::msg::RemoteControllerState>()
{
  return &booster_interface::msg::typesupport_fastrtps_cpp::_RemoteControllerState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, booster_interface, msg, RemoteControllerState)() {
  return &booster_interface::msg::typesupport_fastrtps_cpp::_RemoteControllerState__handle;
}

#ifdef __cplusplus
}
#endif
