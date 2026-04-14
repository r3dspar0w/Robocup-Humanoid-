// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from booster_interface:srv/AgentService.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "booster_interface/srv/detail/agent_service__struct.h"
#include "booster_interface/srv/detail/agent_service__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace booster_interface
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _AgentService_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _AgentService_Request_type_support_ids_t;

static const _AgentService_Request_type_support_ids_t _AgentService_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, booster_interface, srv, AgentService_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, srv, AgentService_Request)),
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
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_AgentService_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace booster_interface

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, booster_interface, srv, AgentService_Request)() {
  return &::booster_interface::srv::rosidl_typesupport_c::AgentService_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "booster_interface/srv/detail/agent_service__struct.h"
// already included above
// #include "booster_interface/srv/detail/agent_service__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace booster_interface
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _AgentService_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _AgentService_Response_type_support_ids_t;

static const _AgentService_Response_type_support_ids_t _AgentService_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, booster_interface, srv, AgentService_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, srv, AgentService_Response)),
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
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_AgentService_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace booster_interface

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, booster_interface, srv, AgentService_Response)() {
  return &::booster_interface::srv::rosidl_typesupport_c::AgentService_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "booster_interface/srv/detail/agent_service__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace booster_interface
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _AgentService_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _AgentService_type_support_ids_t;

static const _AgentService_type_support_ids_t _AgentService_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, booster_interface, srv, AgentService)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, srv, AgentService)),
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
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_AgentService_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace booster_interface

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, booster_interface, srv, AgentService)() {
  return &::booster_interface::srv::rosidl_typesupport_c::AgentService_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
