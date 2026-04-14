// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from booster_interface:srv/AgentService.idl
// generated code does not contain a copyright notice
#include "booster_interface/srv/detail/agent_service__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "booster_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "booster_interface/srv/detail/agent_service__struct.h"
#include "booster_interface/srv/detail/agent_service__functions.h"
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


using _AgentService_Request__ros_msg_type = booster_interface__srv__AgentService_Request;

static bool _AgentService_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _AgentService_Request__ros_msg_type * ros_message = static_cast<const _AgentService_Request__ros_msg_type *>(untyped_ros_message);
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

static bool _AgentService_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _AgentService_Request__ros_msg_type * ros_message = static_cast<_AgentService_Request__ros_msg_type *>(untyped_ros_message);
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
size_t get_serialized_size_booster_interface__srv__AgentService_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _AgentService_Request__ros_msg_type * ros_message = static_cast<const _AgentService_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name body
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->body.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _AgentService_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_booster_interface__srv__AgentService_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_booster_interface
size_t max_serialized_size_booster_interface__srv__AgentService_Request(
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
    using DataType = booster_interface__srv__AgentService_Request;
    is_plain =
      (
      offsetof(DataType, body) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _AgentService_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_booster_interface__srv__AgentService_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_AgentService_Request = {
  "booster_interface::srv",
  "AgentService_Request",
  _AgentService_Request__cdr_serialize,
  _AgentService_Request__cdr_deserialize,
  _AgentService_Request__get_serialized_size,
  _AgentService_Request__max_serialized_size
};

static rosidl_message_type_support_t _AgentService_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_AgentService_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, booster_interface, srv, AgentService_Request)() {
  return &_AgentService_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "booster_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "booster_interface/srv/detail/agent_service__struct.h"
// already included above
// #include "booster_interface/srv/detail/agent_service__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// already included above
// #include "rosidl_runtime_c/string.h"  // body
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // body

// forward declare type support functions


using _AgentService_Response__ros_msg_type = booster_interface__srv__AgentService_Response;

static bool _AgentService_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _AgentService_Response__ros_msg_type * ros_message = static_cast<const _AgentService_Response__ros_msg_type *>(untyped_ros_message);
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

static bool _AgentService_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _AgentService_Response__ros_msg_type * ros_message = static_cast<_AgentService_Response__ros_msg_type *>(untyped_ros_message);
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
size_t get_serialized_size_booster_interface__srv__AgentService_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _AgentService_Response__ros_msg_type * ros_message = static_cast<const _AgentService_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name body
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->body.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _AgentService_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_booster_interface__srv__AgentService_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_booster_interface
size_t max_serialized_size_booster_interface__srv__AgentService_Response(
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
    using DataType = booster_interface__srv__AgentService_Response;
    is_plain =
      (
      offsetof(DataType, body) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _AgentService_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_booster_interface__srv__AgentService_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_AgentService_Response = {
  "booster_interface::srv",
  "AgentService_Response",
  _AgentService_Response__cdr_serialize,
  _AgentService_Response__cdr_deserialize,
  _AgentService_Response__get_serialized_size,
  _AgentService_Response__max_serialized_size
};

static rosidl_message_type_support_t _AgentService_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_AgentService_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, booster_interface, srv, AgentService_Response)() {
  return &_AgentService_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "booster_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "booster_interface/srv/agent_service.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t AgentService__callbacks = {
  "booster_interface::srv",
  "AgentService",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, booster_interface, srv, AgentService_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, booster_interface, srv, AgentService_Response)(),
};

static rosidl_service_type_support_t AgentService__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &AgentService__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, booster_interface, srv, AgentService)() {
  return &AgentService__handle;
}

#if defined(__cplusplus)
}
#endif
