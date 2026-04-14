// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vision_interface:msg/SegmentationResult.idl
// generated code does not contain a copyright notice
#include "vision_interface/msg/detail/segmentation_result__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `lines`
#include "vision_interface/msg/detail/segmentation_line__functions.h"
// Member `points`
#include "vision_interface/msg/detail/segmentation_point__functions.h"

bool
vision_interface__msg__SegmentationResult__init(vision_interface__msg__SegmentationResult * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    vision_interface__msg__SegmentationResult__fini(msg);
    return false;
  }
  // lines
  if (!vision_interface__msg__SegmentationLine__Sequence__init(&msg->lines, 0)) {
    vision_interface__msg__SegmentationResult__fini(msg);
    return false;
  }
  // points
  if (!vision_interface__msg__SegmentationPoint__Sequence__init(&msg->points, 0)) {
    vision_interface__msg__SegmentationResult__fini(msg);
    return false;
  }
  return true;
}

void
vision_interface__msg__SegmentationResult__fini(vision_interface__msg__SegmentationResult * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // lines
  vision_interface__msg__SegmentationLine__Sequence__fini(&msg->lines);
  // points
  vision_interface__msg__SegmentationPoint__Sequence__fini(&msg->points);
}

bool
vision_interface__msg__SegmentationResult__are_equal(const vision_interface__msg__SegmentationResult * lhs, const vision_interface__msg__SegmentationResult * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // lines
  if (!vision_interface__msg__SegmentationLine__Sequence__are_equal(
      &(lhs->lines), &(rhs->lines)))
  {
    return false;
  }
  // points
  if (!vision_interface__msg__SegmentationPoint__Sequence__are_equal(
      &(lhs->points), &(rhs->points)))
  {
    return false;
  }
  return true;
}

bool
vision_interface__msg__SegmentationResult__copy(
  const vision_interface__msg__SegmentationResult * input,
  vision_interface__msg__SegmentationResult * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // lines
  if (!vision_interface__msg__SegmentationLine__Sequence__copy(
      &(input->lines), &(output->lines)))
  {
    return false;
  }
  // points
  if (!vision_interface__msg__SegmentationPoint__Sequence__copy(
      &(input->points), &(output->points)))
  {
    return false;
  }
  return true;
}

vision_interface__msg__SegmentationResult *
vision_interface__msg__SegmentationResult__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__SegmentationResult * msg = (vision_interface__msg__SegmentationResult *)allocator.allocate(sizeof(vision_interface__msg__SegmentationResult), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vision_interface__msg__SegmentationResult));
  bool success = vision_interface__msg__SegmentationResult__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vision_interface__msg__SegmentationResult__destroy(vision_interface__msg__SegmentationResult * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vision_interface__msg__SegmentationResult__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vision_interface__msg__SegmentationResult__Sequence__init(vision_interface__msg__SegmentationResult__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__SegmentationResult * data = NULL;

  if (size) {
    data = (vision_interface__msg__SegmentationResult *)allocator.zero_allocate(size, sizeof(vision_interface__msg__SegmentationResult), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vision_interface__msg__SegmentationResult__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vision_interface__msg__SegmentationResult__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
vision_interface__msg__SegmentationResult__Sequence__fini(vision_interface__msg__SegmentationResult__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      vision_interface__msg__SegmentationResult__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

vision_interface__msg__SegmentationResult__Sequence *
vision_interface__msg__SegmentationResult__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__SegmentationResult__Sequence * array = (vision_interface__msg__SegmentationResult__Sequence *)allocator.allocate(sizeof(vision_interface__msg__SegmentationResult__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vision_interface__msg__SegmentationResult__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vision_interface__msg__SegmentationResult__Sequence__destroy(vision_interface__msg__SegmentationResult__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vision_interface__msg__SegmentationResult__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vision_interface__msg__SegmentationResult__Sequence__are_equal(const vision_interface__msg__SegmentationResult__Sequence * lhs, const vision_interface__msg__SegmentationResult__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vision_interface__msg__SegmentationResult__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vision_interface__msg__SegmentationResult__Sequence__copy(
  const vision_interface__msg__SegmentationResult__Sequence * input,
  vision_interface__msg__SegmentationResult__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vision_interface__msg__SegmentationResult);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vision_interface__msg__SegmentationResult * data =
      (vision_interface__msg__SegmentationResult *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vision_interface__msg__SegmentationResult__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vision_interface__msg__SegmentationResult__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vision_interface__msg__SegmentationResult__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
