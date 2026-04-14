// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from booster_interface:msg/HandDdsMsg.idl
// generated code does not contain a copyright notice

#ifndef BOOSTER_INTERFACE__MSG__DETAIL__HAND_DDS_MSG__FUNCTIONS_H_
#define BOOSTER_INTERFACE__MSG__DETAIL__HAND_DDS_MSG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "booster_interface/msg/rosidl_generator_c__visibility_control.h"

#include "booster_interface/msg/detail/hand_dds_msg__struct.h"

/// Initialize msg/HandDdsMsg message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * booster_interface__msg__HandDdsMsg
 * )) before or use
 * booster_interface__msg__HandDdsMsg__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_interface
bool
booster_interface__msg__HandDdsMsg__init(booster_interface__msg__HandDdsMsg * msg);

/// Finalize msg/HandDdsMsg message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_interface
void
booster_interface__msg__HandDdsMsg__fini(booster_interface__msg__HandDdsMsg * msg);

/// Create msg/HandDdsMsg message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * booster_interface__msg__HandDdsMsg__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_interface
booster_interface__msg__HandDdsMsg *
booster_interface__msg__HandDdsMsg__create();

/// Destroy msg/HandDdsMsg message.
/**
 * It calls
 * booster_interface__msg__HandDdsMsg__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_interface
void
booster_interface__msg__HandDdsMsg__destroy(booster_interface__msg__HandDdsMsg * msg);

/// Check for msg/HandDdsMsg message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_interface
bool
booster_interface__msg__HandDdsMsg__are_equal(const booster_interface__msg__HandDdsMsg * lhs, const booster_interface__msg__HandDdsMsg * rhs);

/// Copy a msg/HandDdsMsg message.
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
ROSIDL_GENERATOR_C_PUBLIC_booster_interface
bool
booster_interface__msg__HandDdsMsg__copy(
  const booster_interface__msg__HandDdsMsg * input,
  booster_interface__msg__HandDdsMsg * output);

/// Initialize array of msg/HandDdsMsg messages.
/**
 * It allocates the memory for the number of elements and calls
 * booster_interface__msg__HandDdsMsg__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_interface
bool
booster_interface__msg__HandDdsMsg__Sequence__init(booster_interface__msg__HandDdsMsg__Sequence * array, size_t size);

/// Finalize array of msg/HandDdsMsg messages.
/**
 * It calls
 * booster_interface__msg__HandDdsMsg__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_interface
void
booster_interface__msg__HandDdsMsg__Sequence__fini(booster_interface__msg__HandDdsMsg__Sequence * array);

/// Create array of msg/HandDdsMsg messages.
/**
 * It allocates the memory for the array and calls
 * booster_interface__msg__HandDdsMsg__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_interface
booster_interface__msg__HandDdsMsg__Sequence *
booster_interface__msg__HandDdsMsg__Sequence__create(size_t size);

/// Destroy array of msg/HandDdsMsg messages.
/**
 * It calls
 * booster_interface__msg__HandDdsMsg__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_interface
void
booster_interface__msg__HandDdsMsg__Sequence__destroy(booster_interface__msg__HandDdsMsg__Sequence * array);

/// Check for msg/HandDdsMsg message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_booster_interface
bool
booster_interface__msg__HandDdsMsg__Sequence__are_equal(const booster_interface__msg__HandDdsMsg__Sequence * lhs, const booster_interface__msg__HandDdsMsg__Sequence * rhs);

/// Copy an array of msg/HandDdsMsg messages.
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
ROSIDL_GENERATOR_C_PUBLIC_booster_interface
bool
booster_interface__msg__HandDdsMsg__Sequence__copy(
  const booster_interface__msg__HandDdsMsg__Sequence * input,
  booster_interface__msg__HandDdsMsg__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BOOSTER_INTERFACE__MSG__DETAIL__HAND_DDS_MSG__FUNCTIONS_H_
