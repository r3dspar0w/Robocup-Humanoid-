// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from booster_interface:srv/AgentService.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "booster_interface/srv/detail/agent_service__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace booster_interface
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _AgentService_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _AgentService_Request_type_support_ids_t;

static const _AgentService_Request_type_support_ids_t _AgentService_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _AgentService_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _AgentService_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _AgentService_Request_type_support_symbol_names_t _AgentService_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, booster_interface, srv, AgentService_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, booster_interface, srv, AgentService_Request)),
  }
};

typedef struct _AgentService_Request_type_support_data_t
{
  void * data[2];
} _AgentService_Request_type_support_data_t;

static _AgentService_Request_type_support_data_t _AgentService_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _AgentService_Request_message_typesupport_map = {
  2,
  "booster_interface",
  &_AgentService_Request_message_typesupport_ids.typesupport_identifier[0],
  &_AgentService_Request_message_typesupport_symbol_names.symbol_name[0],
  &_AgentService_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t AgentService_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_AgentService_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace booster_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<booster_interface::srv::AgentService_Request>()
{
  return &::booster_interface::srv::rosidl_typesupport_cpp::AgentService_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, booster_interface, srv, AgentService_Request)() {
  return get_message_type_support_handle<booster_interface::srv::AgentService_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "booster_interface/srv/detail/agent_service__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace booster_interface
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _AgentService_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _AgentService_Response_type_support_ids_t;

static const _AgentService_Response_type_support_ids_t _AgentService_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _AgentService_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _AgentService_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _AgentService_Response_type_support_symbol_names_t _AgentService_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, booster_interface, srv, AgentService_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, booster_interface, srv, AgentService_Response)),
  }
};

typedef struct _AgentService_Response_type_support_data_t
{
  void * data[2];
} _AgentService_Response_type_support_data_t;

static _AgentService_Response_type_support_data_t _AgentService_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _AgentService_Response_message_typesupport_map = {
  2,
  "booster_interface",
  &_AgentService_Response_message_typesupport_ids.typesupport_identifier[0],
  &_AgentService_Response_message_typesupport_symbol_names.symbol_name[0],
  &_AgentService_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t AgentService_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_AgentService_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace booster_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<booster_interface::srv::AgentService_Response>()
{
  return &::booster_interface::srv::rosidl_typesupport_cpp::AgentService_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, booster_interface, srv, AgentService_Response)() {
  return get_message_type_support_handle<booster_interface::srv::AgentService_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "booster_interface/srv/detail/agent_service__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace booster_interface
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _AgentService_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _AgentService_type_support_ids_t;

static const _AgentService_type_support_ids_t _AgentService_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _AgentService_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _AgentService_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _AgentService_type_support_symbol_names_t _AgentService_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, booster_interface, srv, AgentService)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, booster_interface, srv, AgentService)),
  }
};

typedef struct _AgentService_type_support_data_t
{
  void * data[2];
} _AgentService_type_support_data_t;

static _AgentService_type_support_data_t _AgentService_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _AgentService_service_typesupport_map = {
  2,
  "booster_interface",
  &_AgentService_service_typesupport_ids.typesupport_identifier[0],
  &_AgentService_service_typesupport_symbol_names.symbol_name[0],
  &_AgentService_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t AgentService_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_AgentService_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace booster_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<booster_interface::srv::AgentService>()
{
  return &::booster_interface::srv::rosidl_typesupport_cpp::AgentService_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, booster_interface, srv, AgentService)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<booster_interface::srv::AgentService>();
}

#ifdef __cplusplus
}
#endif
