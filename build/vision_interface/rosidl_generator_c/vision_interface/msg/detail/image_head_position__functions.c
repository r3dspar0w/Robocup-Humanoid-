// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vision_interface:msg/ImageHeadPosition.idl
// generated code does not contain a copyright notice
#include "vision_interface/msg/detail/image_head_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `position`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `image`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
vision_interface__msg__ImageHeadPosition__init(vision_interface__msg__ImageHeadPosition * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    vision_interface__msg__ImageHeadPosition__fini(msg);
    return false;
  }
  // position
  if (!geometry_msgs__msg__Pose__init(&msg->position)) {
    vision_interface__msg__ImageHeadPosition__fini(msg);
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__init(&msg->image)) {
    vision_interface__msg__ImageHeadPosition__fini(msg);
    return false;
  }
  return true;
}

void
vision_interface__msg__ImageHeadPosition__fini(vision_interface__msg__ImageHeadPosition * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // position
  geometry_msgs__msg__Pose__fini(&msg->position);
  // image
  sensor_msgs__msg__Image__fini(&msg->image);
}

bool
vision_interface__msg__ImageHeadPosition__are_equal(const vision_interface__msg__ImageHeadPosition * lhs, const vision_interface__msg__ImageHeadPosition * rhs)
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
  // position
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->image), &(rhs->image)))
  {
    return false;
  }
  return true;
}

bool
vision_interface__msg__ImageHeadPosition__copy(
  const vision_interface__msg__ImageHeadPosition * input,
  vision_interface__msg__ImageHeadPosition * output)
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
  // position
  if (!geometry_msgs__msg__Pose__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__copy(
      &(input->image), &(output->image)))
  {
    return false;
  }
  return true;
}

vision_interface__msg__ImageHeadPosition *
vision_interface__msg__ImageHeadPosition__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__ImageHeadPosition * msg = (vision_interface__msg__ImageHeadPosition *)allocator.allocate(sizeof(vision_interface__msg__ImageHeadPosition), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vision_interface__msg__ImageHeadPosition));
  bool success = vision_interface__msg__ImageHeadPosition__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vision_interface__msg__ImageHeadPosition__destroy(vision_interface__msg__ImageHeadPosition * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vision_interface__msg__ImageHeadPosition__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vision_interface__msg__ImageHeadPosition__Sequence__init(vision_interface__msg__ImageHeadPosition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__ImageHeadPosition * data = NULL;

  if (size) {
    data = (vision_interface__msg__ImageHeadPosition *)allocator.zero_allocate(size, sizeof(vision_interface__msg__ImageHeadPosition), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vision_interface__msg__ImageHeadPosition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vision_interface__msg__ImageHeadPosition__fini(&data[i - 1]);
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
vision_interface__msg__ImageHeadPosition__Sequence__fini(vision_interface__msg__ImageHeadPosition__Sequence * array)
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
      vision_interface__msg__ImageHeadPosition__fini(&array->data[i]);
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

vision_interface__msg__ImageHeadPosition__Sequence *
vision_interface__msg__ImageHeadPosition__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__ImageHeadPosition__Sequence * array = (vision_interface__msg__ImageHeadPosition__Sequence *)allocator.allocate(sizeof(vision_interface__msg__ImageHeadPosition__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vision_interface__msg__ImageHeadPosition__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vision_interface__msg__ImageHeadPosition__Sequence__destroy(vision_interface__msg__ImageHeadPosition__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vision_interface__msg__ImageHeadPosition__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vision_interface__msg__ImageHeadPosition__Sequence__are_equal(const vision_interface__msg__ImageHeadPosition__Sequence * lhs, const vision_interface__msg__ImageHeadPosition__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vision_interface__msg__ImageHeadPosition__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vision_interface__msg__ImageHeadPosition__Sequence__copy(
  const vision_interface__msg__ImageHeadPosition__Sequence * input,
  vision_interface__msg__ImageHeadPosition__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vision_interface__msg__ImageHeadPosition);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vision_interface__msg__ImageHeadPosition * data =
      (vision_interface__msg__ImageHeadPosition *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vision_interface__msg__ImageHeadPosition__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vision_interface__msg__ImageHeadPosition__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vision_interface__msg__ImageHeadPosition__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
