// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from brain:msg/Kick.idl
// generated code does not contain a copyright notice

#ifndef BRAIN__MSG__DETAIL__KICK__FUNCTIONS_H_
#define BRAIN__MSG__DETAIL__KICK__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "brain/msg/rosidl_generator_c__visibility_control.h"

#include "brain/msg/detail/kick__struct.h"

/// Initialize msg/Kick message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * brain__msg__Kick
 * )) before or use
 * brain__msg__Kick__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_brain
bool
brain__msg__Kick__init(brain__msg__Kick * msg);

/// Finalize msg/Kick message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_brain
void
brain__msg__Kick__fini(brain__msg__Kick * msg);

/// Create msg/Kick message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * brain__msg__Kick__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_brain
brain__msg__Kick *
brain__msg__Kick__create();

/// Destroy msg/Kick message.
/**
 * It calls
 * brain__msg__Kick__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_brain
void
brain__msg__Kick__destroy(brain__msg__Kick * msg);

/// Check for msg/Kick message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_brain
bool
brain__msg__Kick__are_equal(const brain__msg__Kick * lhs, const brain__msg__Kick * rhs);

/// Copy a msg/Kick message.
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
ROSIDL_GENERATOR_C_PUBLIC_brain
bool
brain__msg__Kick__copy(
  const brain__msg__Kick * input,
  brain__msg__Kick * output);

/// Initialize array of msg/Kick messages.
/**
 * It allocates the memory for the number of elements and calls
 * brain__msg__Kick__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_brain
bool
brain__msg__Kick__Sequence__init(brain__msg__Kick__Sequence * array, size_t size);

/// Finalize array of msg/Kick messages.
/**
 * It calls
 * brain__msg__Kick__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_brain
void
brain__msg__Kick__Sequence__fini(brain__msg__Kick__Sequence * array);

/// Create array of msg/Kick messages.
/**
 * It allocates the memory for the array and calls
 * brain__msg__Kick__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_brain
brain__msg__Kick__Sequence *
brain__msg__Kick__Sequence__create(size_t size);

/// Destroy array of msg/Kick messages.
/**
 * It calls
 * brain__msg__Kick__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_brain
void
brain__msg__Kick__Sequence__destroy(brain__msg__Kick__Sequence * array);

/// Check for msg/Kick message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_brain
bool
brain__msg__Kick__Sequence__are_equal(const brain__msg__Kick__Sequence * lhs, const brain__msg__Kick__Sequence * rhs);

/// Copy an array of msg/Kick messages.
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
ROSIDL_GENERATOR_C_PUBLIC_brain
bool
brain__msg__Kick__Sequence__copy(
  const brain__msg__Kick__Sequence * input,
  brain__msg__Kick__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BRAIN__MSG__DETAIL__KICK__FUNCTIONS_H_
