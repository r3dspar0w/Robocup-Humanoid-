// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_interface:srv/RpcService.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__SRV__DETAIL__RPC_SERVICE__STRUCT_H_
#define BOOSTER_INTERFACE__SRV__DETAIL__RPC_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'msg'
#include "booster_interface/msg/detail/booster_api_req_msg__struct.h"

/// Struct defined in srv/RpcService in the package booster_interface.
typedef struct booster_interface__srv__RpcService_Request
{
  booster_interface__msg__BoosterApiReqMsg msg;
} booster_interface__srv__RpcService_Request;

// Struct for a sequence of booster_interface__srv__RpcService_Request.
typedef struct booster_interface__srv__RpcService_Request__Sequence
{
  booster_interface__srv__RpcService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_interface__srv__RpcService_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'msg'
#include "booster_interface/msg/detail/booster_api_resp_msg__struct.h"

/// Struct defined in srv/RpcService in the package booster_interface.
typedef struct booster_interface__srv__RpcService_Response
{
  booster_interface__msg__BoosterApiRespMsg msg;
} booster_interface__srv__RpcService_Response;

// Struct for a sequence of booster_interface__srv__RpcService_Response.
typedef struct booster_interface__srv__RpcService_Response__Sequence
{
  booster_interface__srv__RpcService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_interface__srv__RpcService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_INTERFACE__SRV__DETAIL__RPC_SERVICE__STRUCT_H_
