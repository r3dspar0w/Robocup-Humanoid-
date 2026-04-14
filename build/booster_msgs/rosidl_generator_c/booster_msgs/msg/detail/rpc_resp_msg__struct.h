// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_msgs:msg/RpcRespMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_MSGS__MSG__DETAIL__RPC_RESP_MSG__STRUCT_H_
#define BOOSTER_MSGS__MSG__DETAIL__RPC_RESP_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'uuid'
// Member 'header'
// Member 'body'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/RpcRespMsg in the package booster_msgs.
typedef struct booster_msgs__msg__RpcRespMsg
{
  rosidl_runtime_c__String uuid;
  rosidl_runtime_c__String header;
  rosidl_runtime_c__String body;
} booster_msgs__msg__RpcRespMsg;

// Struct for a sequence of booster_msgs__msg__RpcRespMsg.
typedef struct booster_msgs__msg__RpcRespMsg__Sequence
{
  booster_msgs__msg__RpcRespMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_msgs__msg__RpcRespMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_MSGS__MSG__DETAIL__RPC_RESP_MSG__STRUCT_H_
