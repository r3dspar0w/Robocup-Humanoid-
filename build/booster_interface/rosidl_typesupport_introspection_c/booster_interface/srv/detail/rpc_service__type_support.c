// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from booster_interface:srv/RpcService.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "booster_interface/srv/detail/rpc_service__rosidl_typesupport_introspection_c.h"
#include "booster_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "booster_interface/srv/detail/rpc_service__functions.h"
#include "booster_interface/srv/detail/rpc_service__struct.h"


// Include directives for member types
// Member `msg`
#include "booster_interface/msg/booster_api_req_msg.h"
// Member `msg`
#include "booster_interface/msg/detail/booster_api_req_msg__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void booster_interface__srv__RpcService_Request__rosidl_typesupport_introspection_c__RpcService_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  booster_interface__srv__RpcService_Request__init(message_memory);
}

void booster_interface__srv__RpcService_Request__rosidl_typesupport_introspection_c__RpcService_Request_fini_function(void * message_memory)
{
  booster_interface__srv__RpcService_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember booster_interface__srv__RpcService_Request__rosidl_typesupport_introspection_c__RpcService_Request_message_member_array[1] = {
  {
    "msg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(booster_interface__srv__RpcService_Request, msg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers booster_interface__srv__RpcService_Request__rosidl_typesupport_introspection_c__RpcService_Request_message_members = {
  "booster_interface__srv",  // message namespace
  "RpcService_Request",  // message name
  1,  // number of fields
  sizeof(booster_interface__srv__RpcService_Request),
  booster_interface__srv__RpcService_Request__rosidl_typesupport_introspection_c__RpcService_Request_message_member_array,  // message members
  booster_interface__srv__RpcService_Request__rosidl_typesupport_introspection_c__RpcService_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  booster_interface__srv__RpcService_Request__rosidl_typesupport_introspection_c__RpcService_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t booster_interface__srv__RpcService_Request__rosidl_typesupport_introspection_c__RpcService_Request_message_type_support_handle = {
  0,
  &booster_interface__srv__RpcService_Request__rosidl_typesupport_introspection_c__RpcService_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_booster_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, srv, RpcService_Request)() {
  booster_interface__srv__RpcService_Request__rosidl_typesupport_introspection_c__RpcService_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, msg, BoosterApiReqMsg)();
  if (!booster_interface__srv__RpcService_Request__rosidl_typesupport_introspection_c__RpcService_Request_message_type_support_handle.typesupport_identifier) {
    booster_interface__srv__RpcService_Request__rosidl_typesupport_introspection_c__RpcService_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &booster_interface__srv__RpcService_Request__rosidl_typesupport_introspection_c__RpcService_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "booster_interface/srv/detail/rpc_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "booster_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "booster_interface/srv/detail/rpc_service__functions.h"
// already included above
// #include "booster_interface/srv/detail/rpc_service__struct.h"


// Include directives for member types
// Member `msg`
#include "booster_interface/msg/booster_api_resp_msg.h"
// Member `msg`
#include "booster_interface/msg/detail/booster_api_resp_msg__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void booster_interface__srv__RpcService_Response__rosidl_typesupport_introspection_c__RpcService_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  booster_interface__srv__RpcService_Response__init(message_memory);
}

void booster_interface__srv__RpcService_Response__rosidl_typesupport_introspection_c__RpcService_Response_fini_function(void * message_memory)
{
  booster_interface__srv__RpcService_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember booster_interface__srv__RpcService_Response__rosidl_typesupport_introspection_c__RpcService_Response_message_member_array[1] = {
  {
    "msg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(booster_interface__srv__RpcService_Response, msg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers booster_interface__srv__RpcService_Response__rosidl_typesupport_introspection_c__RpcService_Response_message_members = {
  "booster_interface__srv",  // message namespace
  "RpcService_Response",  // message name
  1,  // number of fields
  sizeof(booster_interface__srv__RpcService_Response),
  booster_interface__srv__RpcService_Response__rosidl_typesupport_introspection_c__RpcService_Response_message_member_array,  // message members
  booster_interface__srv__RpcService_Response__rosidl_typesupport_introspection_c__RpcService_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  booster_interface__srv__RpcService_Response__rosidl_typesupport_introspection_c__RpcService_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t booster_interface__srv__RpcService_Response__rosidl_typesupport_introspection_c__RpcService_Response_message_type_support_handle = {
  0,
  &booster_interface__srv__RpcService_Response__rosidl_typesupport_introspection_c__RpcService_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_booster_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, srv, RpcService_Response)() {
  booster_interface__srv__RpcService_Response__rosidl_typesupport_introspection_c__RpcService_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, msg, BoosterApiRespMsg)();
  if (!booster_interface__srv__RpcService_Response__rosidl_typesupport_introspection_c__RpcService_Response_message_type_support_handle.typesupport_identifier) {
    booster_interface__srv__RpcService_Response__rosidl_typesupport_introspection_c__RpcService_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &booster_interface__srv__RpcService_Response__rosidl_typesupport_introspection_c__RpcService_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "booster_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "booster_interface/srv/detail/rpc_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers booster_interface__srv__detail__rpc_service__rosidl_typesupport_introspection_c__RpcService_service_members = {
  "booster_interface__srv",  // service namespace
  "RpcService",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // booster_interface__srv__detail__rpc_service__rosidl_typesupport_introspection_c__RpcService_Request_message_type_support_handle,
  NULL  // response message
  // booster_interface__srv__detail__rpc_service__rosidl_typesupport_introspection_c__RpcService_Response_message_type_support_handle
};

static rosidl_service_type_support_t booster_interface__srv__detail__rpc_service__rosidl_typesupport_introspection_c__RpcService_service_type_support_handle = {
  0,
  &booster_interface__srv__detail__rpc_service__rosidl_typesupport_introspection_c__RpcService_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, srv, RpcService_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, srv, RpcService_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_booster_interface
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, srv, RpcService)() {
  if (!booster_interface__srv__detail__rpc_service__rosidl_typesupport_introspection_c__RpcService_service_type_support_handle.typesupport_identifier) {
    booster_interface__srv__detail__rpc_service__rosidl_typesupport_introspection_c__RpcService_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)booster_interface__srv__detail__rpc_service__rosidl_typesupport_introspection_c__RpcService_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, srv, RpcService_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, booster_interface, srv, RpcService_Response)()->data;
  }

  return &booster_interface__srv__detail__rpc_service__rosidl_typesupport_introspection_c__RpcService_service_type_support_handle;
}
