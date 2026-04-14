// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vision_interface:msg/LineSegments.idl
// generated code does not contain a copyright notice
#include "vision_interface/msg/detail/line_segments__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `coordinates`
// Member `coordinates_uv`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
vision_interface__msg__LineSegments__init(vision_interface__msg__LineSegments * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    vision_interface__msg__LineSegments__fini(msg);
    return false;
  }
  // coordinates
  if (!rosidl_runtime_c__float__Sequence__init(&msg->coordinates, 0)) {
    vision_interface__msg__LineSegments__fini(msg);
    return false;
  }
  // coordinates_uv
  if (!rosidl_runtime_c__float__Sequence__init(&msg->coordinates_uv, 0)) {
    vision_interface__msg__LineSegments__fini(msg);
    return false;
  }
  return true;
}

void
vision_interface__msg__LineSegments__fini(vision_interface__msg__LineSegments * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // coordinates
  rosidl_runtime_c__float__Sequence__fini(&msg->coordinates);
  // coordinates_uv
  rosidl_runtime_c__float__Sequence__fini(&msg->coordinates_uv);
}

bool
vision_interface__msg__LineSegments__are_equal(const vision_interface__msg__LineSegments * lhs, const vision_interface__msg__LineSegments * rhs)
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
  // coordinates
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->coordinates), &(rhs->coordinates)))
  {
    return false;
  }
  // coordinates_uv
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->coordinates_uv), &(rhs->coordinates_uv)))
  {
    return false;
  }
  return true;
}

bool
vision_interface__msg__LineSegments__copy(
  const vision_interface__msg__LineSegments * input,
  vision_interface__msg__LineSegments * output)
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
  // coordinates
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->coordinates), &(output->coordinates)))
  {
    return false;
  }
  // coordinates_uv
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->coordinates_uv), &(output->coordinates_uv)))
  {
    return false;
  }
  return true;
}

vision_interface__msg__LineSegments *
vision_interface__msg__LineSegments__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__LineSegments * msg = (vision_interface__msg__LineSegments *)allocator.allocate(sizeof(vision_interface__msg__LineSegments), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vision_interface__msg__LineSegments));
  bool success = vision_interface__msg__LineSegments__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vision_interface__msg__LineSegments__destroy(vision_interface__msg__LineSegments * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vision_interface__msg__LineSegments__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vision_interface__msg__LineSegments__Sequence__init(vision_interface__msg__LineSegments__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__LineSegments * data = NULL;

  if (size) {
    data = (vision_interface__msg__LineSegments *)allocator.zero_allocate(size, sizeof(vision_interface__msg__LineSegments), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vision_interface__msg__LineSegments__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vision_interface__msg__LineSegments__fini(&data[i - 1]);
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
vision_interface__msg__LineSegments__Sequence__fini(vision_interface__msg__LineSegments__Sequence * array)
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
      vision_interface__msg__LineSegments__fini(&array->data[i]);
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

vision_interface__msg__LineSegments__Sequence *
vision_interface__msg__LineSegments__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__LineSegments__Sequence * array = (vision_interface__msg__LineSegments__Sequence *)allocator.allocate(sizeof(vision_interface__msg__LineSegments__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vision_interface__msg__LineSegments__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vision_interface__msg__LineSegments__Sequence__destroy(vision_interface__msg__LineSegments__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vision_interface__msg__LineSegments__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vision_interface__msg__LineSegments__Sequence__are_equal(const vision_interface__msg__LineSegments__Sequence * lhs, const vision_interface__msg__LineSegments__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vision_interface__msg__LineSegments__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vision_interface__msg__LineSegments__Sequence__copy(
  const vision_interface__msg__LineSegments__Sequence * input,
  vision_interface__msg__LineSegments__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vision_interface__msg__LineSegments);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vision_interface__msg__LineSegments * data =
      (vision_interface__msg__LineSegments *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vision_interface__msg__LineSegments__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vision_interface__msg__LineSegments__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vision_interface__msg__LineSegments__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
