// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vision_interface:msg/CalParam.idl
// generated code does not contain a copyright notice
#include "vision_interface/msg/detail/cal_param__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
vision_interface__msg__CalParam__init(vision_interface__msg__CalParam * msg)
{
  if (!msg) {
    return false;
  }
  // pitch_compensation
  // yaw_compensation
  // z_compensation
  return true;
}

void
vision_interface__msg__CalParam__fini(vision_interface__msg__CalParam * msg)
{
  if (!msg) {
    return;
  }
  // pitch_compensation
  // yaw_compensation
  // z_compensation
}

bool
vision_interface__msg__CalParam__are_equal(const vision_interface__msg__CalParam * lhs, const vision_interface__msg__CalParam * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pitch_compensation
  if (lhs->pitch_compensation != rhs->pitch_compensation) {
    return false;
  }
  // yaw_compensation
  if (lhs->yaw_compensation != rhs->yaw_compensation) {
    return false;
  }
  // z_compensation
  if (lhs->z_compensation != rhs->z_compensation) {
    return false;
  }
  return true;
}

bool
vision_interface__msg__CalParam__copy(
  const vision_interface__msg__CalParam * input,
  vision_interface__msg__CalParam * output)
{
  if (!input || !output) {
    return false;
  }
  // pitch_compensation
  output->pitch_compensation = input->pitch_compensation;
  // yaw_compensation
  output->yaw_compensation = input->yaw_compensation;
  // z_compensation
  output->z_compensation = input->z_compensation;
  return true;
}

vision_interface__msg__CalParam *
vision_interface__msg__CalParam__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__CalParam * msg = (vision_interface__msg__CalParam *)allocator.allocate(sizeof(vision_interface__msg__CalParam), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vision_interface__msg__CalParam));
  bool success = vision_interface__msg__CalParam__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vision_interface__msg__CalParam__destroy(vision_interface__msg__CalParam * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vision_interface__msg__CalParam__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vision_interface__msg__CalParam__Sequence__init(vision_interface__msg__CalParam__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__CalParam * data = NULL;

  if (size) {
    data = (vision_interface__msg__CalParam *)allocator.zero_allocate(size, sizeof(vision_interface__msg__CalParam), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vision_interface__msg__CalParam__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vision_interface__msg__CalParam__fini(&data[i - 1]);
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
vision_interface__msg__CalParam__Sequence__fini(vision_interface__msg__CalParam__Sequence * array)
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
      vision_interface__msg__CalParam__fini(&array->data[i]);
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

vision_interface__msg__CalParam__Sequence *
vision_interface__msg__CalParam__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__CalParam__Sequence * array = (vision_interface__msg__CalParam__Sequence *)allocator.allocate(sizeof(vision_interface__msg__CalParam__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vision_interface__msg__CalParam__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vision_interface__msg__CalParam__Sequence__destroy(vision_interface__msg__CalParam__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vision_interface__msg__CalParam__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vision_interface__msg__CalParam__Sequence__are_equal(const vision_interface__msg__CalParam__Sequence * lhs, const vision_interface__msg__CalParam__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vision_interface__msg__CalParam__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vision_interface__msg__CalParam__Sequence__copy(
  const vision_interface__msg__CalParam__Sequence * input,
  vision_interface__msg__CalParam__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vision_interface__msg__CalParam);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vision_interface__msg__CalParam * data =
      (vision_interface__msg__CalParam *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vision_interface__msg__CalParam__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vision_interface__msg__CalParam__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vision_interface__msg__CalParam__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
