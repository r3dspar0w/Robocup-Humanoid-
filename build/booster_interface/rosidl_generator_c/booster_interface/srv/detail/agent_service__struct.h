// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_interface:srv/AgentService.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__SRV__DETAIL__AGENT_SERVICE__STRUCT_H_
#define BOOSTER_INTERFACE__SRV__DETAIL__AGENT_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'body'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/AgentService in the package booster_interface.
typedef struct booster_interface__srv__AgentService_Request
{
  rosidl_runtime_c__String body;
} booster_interface__srv__AgentService_Request;

// Struct for a sequence of booster_interface__srv__AgentService_Request.
typedef struct booster_interface__srv__AgentService_Request__Sequence
{
  booster_interface__srv__AgentService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_interface__srv__AgentService_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'body'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/AgentService in the package booster_interface.
typedef struct booster_interface__srv__AgentService_Response
{
  rosidl_runtime_c__String body;
} booster_interface__srv__AgentService_Response;

// Struct for a sequence of booster_interface__srv__AgentService_Response.
typedef struct booster_interface__srv__AgentService_Response__Sequence
{
  booster_interface__srv__AgentService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_interface__srv__AgentService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_INTERFACE__SRV__DETAIL__AGENT_SERVICE__STRUCT_H_
