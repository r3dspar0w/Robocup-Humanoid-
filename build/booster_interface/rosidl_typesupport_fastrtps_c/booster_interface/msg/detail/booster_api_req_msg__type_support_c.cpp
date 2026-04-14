// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from booster_interface:msg/BoosterApiReqMsg.idl
// generated code does not contain a copyright notice
#include "booster_interface/msg/detail/booster_api_req_msg__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "booster_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "booster_interface/msg/detail/booster_api_req_msg__struct.h"
#include "booster_interface/msg/detail/booster_api_req_msg__functions.h"
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

#include "rosidl_runtime_c/string.h"  // body
#include "rosidl_runtime_c/string_functions.h"  // body

// forward declare type support functions


using _BoosterApiReqMsg__ros_msg_type = booster_interface__msg__BoosterApiReqMsg;

static bool _BoosterApiReqMsg__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _BoosterApiReqMsg__ros_msg_type * ros_message = static_cast<const _BoosterApiReqMsg__ros_msg_type *>(untyped_ros_message);
  // Field name: api_id
  {
    cdr << ros_message->api_id;
  }

  // Field name: body
  {
    const rosidl_runtime_c__String * str = &ros_message->body;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _BoosterApiReqMsg__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _BoosterApiReqMsg__ros_msg_type * ros_message = static_cast<_BoosterApiReqMsg__ros_msg_type *>(untyped_ros_message);
  // Field name: api_id
  {
    cdr >> ros_message->api_id;
  }

  // Field name: body
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->body.data) {
      rosidl_runtime_c__String__init(&ros_message->body);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->body,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'body'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_booster_interface
size_t get_serialized_size_booster_interface__msg__BoosterApiReqMsg(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _BoosterApiReqMsg__ros_msg_type * ros_message = static_cast<const _BoosterApiReqMsg__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name api_id
  {
    size_t item_size = sizeof(ros_message->api_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name body
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->body.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _BoosterApiReqMsg__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_booster_interface__msg__BoosterApiReqMsg(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_booster_interface
size_t max_serialized_size_booster_interface__msg__BoosterApiReqMsg(
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

  // member: api_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: body
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = booster_interface__msg__BoosterApiReqMsg;
    is_plain =
      (
      offsetof(DataType, body) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _BoosterApiReqMsg__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_booster_interface__msg__BoosterApiReqMsg(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_BoosterApiReqMsg = {
  "booster_interface::msg",
  "BoosterApiReqMsg",
  _BoosterApiReqMsg__cdr_serialize,
  _BoosterApiReqMsg__cdr_deserialize,
  _BoosterApiReqMsg__get_serialized_size,
  _BoosterApiReqMsg__max_serialized_size
};

static rosidl_message_type_support_t _BoosterApiReqMsg__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_BoosterApiReqMsg,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, booster_interface, msg, BoosterApiReqMsg)() {
  return &_BoosterApiReqMsg__type_support;
}

#if defined(__cplusplus)
}
#endif
