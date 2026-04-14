// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from booster_msgs:msg/RpcRespMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_MSGS__MSG__DETAIL__RPC_RESP_MSG__FUNCTIONS_H_
#define BOOSTER_MSGS__MSG__DETAIL__RPC_RESP_MSG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "booster_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "booster_msgs/msg/detail/rpc_resp_msg__struct.h"

/// Initialize msg/RpcRespMsg message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * booster_msgs__msg__RpcRespMsg
 * )) before or use
 * booster_msgs__msg__RpcRespMsg__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
bool
booster_msgs__msg__RpcRespMsg__init(booster_msgs__msg__RpcRespMsg * msg);

/// Finalize msg/RpcRespMsg message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
void
booster_msgs__msg__RpcRespMsg__fini(booster_msgs__msg__RpcRespMsg * msg);

/// Create msg/RpcRespMsg message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * booster_msgs__msg__RpcRespMsg__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
booster_msgs__msg__RpcRespMsg *
booster_msgs__msg__RpcRespMsg__create();

/// Destroy msg/RpcRespMsg message.
/**
 * It calls
 * booster_msgs__msg__RpcRespMsg__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
void
booster_msgs__msg__RpcRespMsg__destroy(booster_msgs__msg__RpcRespMsg * msg);

/// Check for msg/RpcRespMsg message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
bool
booster_msgs__msg__RpcRespMsg__are_equal(const booster_msgs__msg__RpcRespMsg * lhs, const booster_msgs__msg__RpcRespMsg * rhs);

/// Copy a msg/RpcRespMsg message.
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
booster_msgs__msg__RpcRespMsg__copy(
  const booster_msgs__msg__RpcRespMsg * input,
  booster_msgs__msg__RpcRespMsg * output);

/// Initialize array of msg/RpcRespMsg messages.
/**
 * It allocates the memory for the number of elements and calls
 * booster_msgs__msg__RpcRespMsg__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
bool
booster_msgs__msg__RpcRespMsg__Sequence__init(booster_msgs__msg__RpcRespMsg__Sequence * array, size_t size);

/// Finalize array of msg/RpcRespMsg messages.
/**
 * It calls
 * booster_msgs__msg__RpcRespMsg__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
void
booster_msgs__msg__RpcRespMsg__Sequence__fini(booster_msgs__msg__RpcRespMsg__Sequence * array);

/// Create array of msg/RpcRespMsg messages.
/**
 * It allocates the memory for the array and calls
 * booster_msgs__msg__RpcRespMsg__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
booster_msgs__msg__RpcRespMsg__Sequence *
booster_msgs__msg__RpcRespMsg__Sequence__create(size_t size);

/// Destroy array of msg/RpcRespMsg messages.
/**
 * It calls
 * booster_msgs__msg__RpcRespMsg__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
void
booster_msgs__msg__RpcRespMsg__Sequence__destroy(booster_msgs__msg__RpcRespMsg__Sequence * array);

/// Check for msg/RpcRespMsg message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_msgs
bool
booster_msgs__msg__RpcRespMsg__Sequence__are_equal(const booster_msgs__msg__RpcRespMsg__Sequence * lhs, const booster_msgs__msg__RpcRespMsg__Sequence * rhs);

/// Copy an array of msg/RpcRespMsg messages.
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
booster_msgs__msg__RpcRespMsg__Sequence__copy(
  const booster_msgs__msg__RpcRespMsg__Sequence * input,
  booster_msgs__msg__RpcRespMsg__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_MSGS__MSG__DETAIL__RPC_RESP_MSG__FUNCTIONS_H_
