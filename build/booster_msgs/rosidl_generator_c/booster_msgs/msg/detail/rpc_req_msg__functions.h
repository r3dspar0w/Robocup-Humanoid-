// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from booster_msgs:msg/RpcReqMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_MSGS__MSG__DETAIL__RPC_REQ_MSG__FUNCTIONS_H_
#define BOOSTER_MSGS__MSG__DETAIL__RPC_REQ_MSG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "booster_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "booster_msgs/msg/detail/rpc_req_msg__struct.h"

/// Initialize msg/RpcReqMsg message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * booster_msgs__msg__RpcReqMsg
 * )) before or use
 * booster_msgs__msg__RpcReqMsg__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
bool
booster_msgs__msg__RpcReqMsg__init(booster_msgs__msg__RpcReqMsg * msg);

/// Finalize msg/RpcReqMsg message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
void
booster_msgs__msg__RpcReqMsg__fini(booster_msgs__msg__RpcReqMsg * msg);

/// Create msg/RpcReqMsg message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * booster_msgs__msg__RpcReqMsg__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
booster_msgs__msg__RpcReqMsg *
booster_msgs__msg__RpcReqMsg__create();

/// Destroy msg/RpcReqMsg message.
/**
 * It calls
 * booster_msgs__msg__RpcReqMsg__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
void
booster_msgs__msg__RpcReqMsg__destroy(booster_msgs__msg__RpcReqMsg * msg);

/// Check for msg/RpcReqMsg message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
bool
booster_msgs__msg__RpcReqMsg__are_equal(const booster_msgs__msg__RpcReqMsg * lhs, const booster_msgs__msg__RpcReqMsg * rhs);

/// Copy a msg/RpcReqMsg message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
bool
booster_msgs__msg__RpcReqMsg__copy(
  const booster_msgs__msg__RpcReqMsg * input,
  booster_msgs__msg__RpcReqMsg * output);

/// Initialize array of msg/RpcReqMsg messages.
/**
 * It allocates the memory for the number of elements and calls
 * booster_msgs__msg__RpcReqMsg__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
bool
booster_msgs__msg__RpcReqMsg__Sequence__init(booster_msgs__msg__RpcReqMsg__Sequence * array, size_t size);

/// Finalize array of msg/RpcReqMsg messages.
/**
 * It calls
 * booster_msgs__msg__RpcReqMsg__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
void
booster_msgs__msg__RpcReqMsg__Sequence__fini(booster_msgs__msg__RpcReqMsg__Sequence * array);

/// Create array of msg/RpcReqMsg messages.
/**
 * It allocates the memory for the array and calls
 * booster_msgs__msg__RpcReqMsg__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
booster_msgs__msg__RpcReqMsg__Sequence *
booster_msgs__msg__RpcReqMsg__Sequence__create(size_t size);

/// Destroy array of msg/RpcReqMsg messages.
/**
 * It calls
 * booster_msgs__msg__RpcReqMsg__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
void
booster_msgs__msg__RpcReqMsg__Sequence__destroy(booster_msgs__msg__RpcReqMsg__Sequence * array);

/// Check for msg/RpcReqMsg message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
bool
booster_msgs__msg__RpcReqMsg__Sequence__are_equal(const booster_msgs__msg__RpcReqMsg__Sequence * lhs, const booster_msgs__msg__RpcReqMsg__Sequence * rhs);

/// Copy an array of msg/RpcReqMsg messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
bool
booster_msgs__msg__RpcReqMsg__Sequence__copy(
  const booster_msgs__msg__RpcReqMsg__Sequence * input,
  booster_msgs__msg__RpcReqMsg__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_MSGS__MSG__DETAIL__RPC_REQ_MSG__FUNCTIONS_H_
