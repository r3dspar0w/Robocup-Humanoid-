// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from booster_msgs:msg/RpcReqMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_MSGS__MSG__DETAIL__RPC_REQ_MSG__STRUCT_H_
#define BOOSTER_MSGS__MSG__DETAIL__RPC_REQ_MSG__STRUCT_H_

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

/// Struct defined in msg/RpcReqMsg in the package booster_msgs.
typedef struct booster_msgs__msg__RpcReqMsg
{
  rosidl_runtime_c__String uuid;
  rosidl_runtime_c__String header;
  rosidl_runtime_c__String body;
} booster_msgs__msg__RpcReqMsg;

// Struct for a sequence of booster_msgs__msg__RpcReqMsg.
typedef struct booster_msgs__msg__RpcReqMsg__Sequence
{
  booster_msgs__msg__RpcReqMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} booster_msgs__msg__RpcReqMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_MSGS__MSG__DETAIL__RPC_REQ_MSG__STRUCT_H_
