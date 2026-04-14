// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vision_interface:msg/SegmentationLine.idl
// generated code does not contain a copyright notice
#include "vision_interface/msg/detail/segmentation_line__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `label`
#include "rosidl_runtime_c/string_functions.h"

bool
vision_interface__msg__SegmentationLine__init(vision_interface__msg__SegmentationLine * msg)
{
  if (!msg) {
    return false;
  }
  // label
  if (!rosidl_runtime_c__String__init(&msg->label)) {
    vision_interface__msg__SegmentationLine__fini(msg);
    return false;
  }
  // x1
  // y1
  // x2
  // y2
  // u1
  // v1
  // u2
  // v2
  return true;
}

void
vision_interface__msg__SegmentationLine__fini(vision_interface__msg__SegmentationLine * msg)
{
  if (!msg) {
    return;
  }
  // label
  rosidl_runtime_c__String__fini(&msg->label);
  // x1
  // y1
  // x2
  // y2
  // u1
  // v1
  // u2
  // v2
}

bool
vision_interface__msg__SegmentationLine__are_equal(const vision_interface__msg__SegmentationLine * lhs, const vision_interface__msg__SegmentationLine * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // label
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->label), &(rhs->label)))
  {
    return false;
  }
  // x1
  if (lhs->x1 != rhs->x1) {
    return false;
  }
  // y1
  if (lhs->y1 != rhs->y1) {
    return false;
  }
  // x2
  if (lhs->x2 != rhs->x2) {
    return false;
  }
  // y2
  if (lhs->y2 != rhs->y2) {
    return false;
  }
  // u1
  if (lhs->u1 != rhs->u1) {
    return false;
  }
  // v1
  if (lhs->v1 != rhs->v1) {
    return false;
  }
  // u2
  if (lhs->u2 != rhs->u2) {
    return false;
  }
  // v2
  if (lhs->v2 != rhs->v2) {
    return false;
  }
  return true;
}

bool
vision_interface__msg__SegmentationLine__copy(
  const vision_interface__msg__SegmentationLine * input,
  vision_interface__msg__SegmentationLine * output)
{
  if (!input || !output) {
    return false;
  }
  // label
  if (!rosidl_runtime_c__String__copy(
      &(input->label), &(output->label)))
  {
    return false;
  }
  // x1
  output->x1 = input->x1;
  // y1
  output->y1 = input->y1;
  // x2
  output->x2 = input->x2;
  // y2
  output->y2 = input->y2;
  // u1
  output->u1 = input->u1;
  // v1
  output->v1 = input->v1;
  // u2
  output->u2 = input->u2;
  // v2
  output->v2 = input->v2;
  return true;
}

vision_interface__msg__SegmentationLine *
vision_interface__msg__SegmentationLine__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__SegmentationLine * msg = (vision_interface__msg__SegmentationLine *)allocator.allocate(sizeof(vision_interface__msg__SegmentationLine), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vision_interface__msg__SegmentationLine));
  bool success = vision_interface__msg__SegmentationLine__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vision_interface__msg__SegmentationLine__destroy(vision_interface__msg__SegmentationLine * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vision_interface__msg__SegmentationLine__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vision_interface__msg__SegmentationLine__Sequence__init(vision_interface__msg__SegmentationLine__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__SegmentationLine * data = NULL;

  if (size) {
    data = (vision_interface__msg__SegmentationLine *)allocator.zero_allocate(size, sizeof(vision_interface__msg__SegmentationLine), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vision_interface__msg__SegmentationLine__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vision_interface__msg__SegmentationLine__fini(&data[i - 1]);
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
vision_interface__msg__SegmentationLine__Sequence__fini(vision_interface__msg__SegmentationLine__Sequence * array)
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
      vision_interface__msg__SegmentationLine__fini(&array->data[i]);
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

vision_interface__msg__SegmentationLine__Sequence *
vision_interface__msg__SegmentationLine__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__SegmentationLine__Sequence * array = (vision_interface__msg__SegmentationLine__Sequence *)allocator.allocate(sizeof(vision_interface__msg__SegmentationLine__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vision_interface__msg__SegmentationLine__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vision_interface__msg__SegmentationLine__Sequence__destroy(vision_interface__msg__SegmentationLine__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vision_interface__msg__SegmentationLine__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vision_interface__msg__SegmentationLine__Sequence__are_equal(const vision_interface__msg__SegmentationLine__Sequence * lhs, const vision_interface__msg__SegmentationLine__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vision_interface__msg__SegmentationLine__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vision_interface__msg__SegmentationLine__Sequence__copy(
  const vision_interface__msg__SegmentationLine__Sequence * input,
  vision_interface__msg__SegmentationLine__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vision_interface__msg__SegmentationLine);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vision_interface__msg__SegmentationLine * data =
      (vision_interface__msg__SegmentationLine *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vision_interface__msg__SegmentationLine__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vision_interface__msg__SegmentationLine__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vision_interface__msg__SegmentationLine__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
