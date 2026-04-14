// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from vision_interface:msg/SegmentationLine.idl
// generated code does not contain a copyright notice

#ifndef VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_LINE__FUNCTIONS_H_
#define VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_LINE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "vision_interface/msg/rosidl_generator_c__visibility_control.h"

#include "vision_interface/msg/detail/segmentation_line__struct.h"

/// Initialize msg/SegmentationLine message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vision_interface__msg__SegmentationLine
 * )) before or use
 * vision_interface__msg__SegmentationLine__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_interface
bool
vision_interface__msg__SegmentationLine__init(vision_interface__msg__SegmentationLine * msg);

/// Finalize msg/SegmentationLine message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_interface
void
vision_interface__msg__SegmentationLine__fini(vision_interface__msg__SegmentationLine * msg);

/// Create msg/SegmentationLine message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vision_interface__msg__SegmentationLine__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_interface
vision_interface__msg__SegmentationLine *
vision_interface__msg__SegmentationLine__create();

/// Destroy msg/SegmentationLine message.
/**
 * It calls
 * vision_interface__msg__SegmentationLine__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_interface
void
vision_interface__msg__SegmentationLine__destroy(vision_interface__msg__SegmentationLine * msg);

/// Check for msg/SegmentationLine message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_interface
bool
vision_interface__msg__SegmentationLine__are_equal(const vision_interface__msg__SegmentationLine * lhs, const vision_interface__msg__SegmentationLine * rhs);

/// Copy a msg/SegmentationLine message.
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
ROSIDL_GENERATOR_C_PUBLIC_vision_interface
bool
vision_interface__msg__SegmentationLine__copy(
  const vision_interface__msg__SegmentationLine * input,
  vision_interface__msg__SegmentationLine * output);

/// Initialize array of msg/SegmentationLine messages.
/**
 * It allocates the memory for the number of elements and calls
 * vision_interface__msg__SegmentationLine__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_interface
bool
vision_interface__msg__SegmentationLine__Sequence__init(vision_interface__msg__SegmentationLine__Sequence * array, size_t size);

/// Finalize array of msg/SegmentationLine messages.
/**
 * It calls
 * vision_interface__msg__SegmentationLine__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_interface
void
vision_interface__msg__SegmentationLine__Sequence__fini(vision_interface__msg__SegmentationLine__Sequence * array);

/// Create array of msg/SegmentationLine messages.
/**
 * It allocates the memory for the array and calls
 * vision_interface__msg__SegmentationLine__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_interface
vision_interface__msg__SegmentationLine__Sequence *
vision_interface__msg__SegmentationLine__Sequence__create(size_t size);

/// Destroy array of msg/SegmentationLine messages.
/**
 * It calls
 * vision_interface__msg__SegmentationLine__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_interface
void
vision_interface__msg__SegmentationLine__Sequence__destroy(vision_interface__msg__SegmentationLine__Sequence * array);

/// Check for msg/SegmentationLine message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_interface
bool
vision_interface__msg__SegmentationLine__Sequence__are_equal(const vision_interface__msg__SegmentationLine__Sequence * lhs, const vision_interface__msg__SegmentationLine__Sequence * rhs);

/// Copy an array of msg/SegmentationLine messages.
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
ROSIDL_GENERATOR_C_PUBLIC_vision_interface
bool
vision_interface__msg__SegmentationLine__Sequence__copy(
  const vision_interface__msg__SegmentationLine__Sequence * input,
  vision_interface__msg__SegmentationLine__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VISION_INTERFACE__MSG__DETAIL__SEGMENTATION_LINE__FUNCTIONS_H_
