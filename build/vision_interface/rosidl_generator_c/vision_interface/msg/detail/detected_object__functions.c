// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vision_interface:msg/DetectedObject.idl
// generated code does not contain a copyright notice
#include "vision_interface/msg/detail/detected_object__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `label`
// Member `color`
#include "rosidl_runtime_c/string_functions.h"
// Member `target_uv`
// Member `received_pos`
// Member `position`
// Member `position_projection`
// Member `position_cam`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
vision_interface__msg__DetectedObject__init(vision_interface__msg__DetectedObject * msg)
{
  if (!msg) {
    return false;
  }
  // label
  if (!rosidl_runtime_c__String__init(&msg->label)) {
    vision_interface__msg__DetectedObject__fini(msg);
    return false;
  }
  // color
  if (!rosidl_runtime_c__String__init(&msg->color)) {
    vision_interface__msg__DetectedObject__fini(msg);
    return false;
  }
  // confidence
  // xmin
  // ymin
  // xmax
  // ymax
  // target_uv
  if (!rosidl_runtime_c__float__Sequence__init(&msg->target_uv, 0)) {
    vision_interface__msg__DetectedObject__fini(msg);
    return false;
  }
  // received_pos
  if (!rosidl_runtime_c__float__Sequence__init(&msg->received_pos, 0)) {
    vision_interface__msg__DetectedObject__fini(msg);
    return false;
  }
  // position
  if (!rosidl_runtime_c__float__Sequence__init(&msg->position, 0)) {
    vision_interface__msg__DetectedObject__fini(msg);
    return false;
  }
  // position_projection
  if (!rosidl_runtime_c__float__Sequence__init(&msg->position_projection, 0)) {
    vision_interface__msg__DetectedObject__fini(msg);
    return false;
  }
  // position_cam
  if (!rosidl_runtime_c__float__Sequence__init(&msg->position_cam, 0)) {
    vision_interface__msg__DetectedObject__fini(msg);
    return false;
  }
  // position_confidence
  return true;
}

void
vision_interface__msg__DetectedObject__fini(vision_interface__msg__DetectedObject * msg)
{
  if (!msg) {
    return;
  }
  // label
  rosidl_runtime_c__String__fini(&msg->label);
  // color
  rosidl_runtime_c__String__fini(&msg->color);
  // confidence
  // xmin
  // ymin
  // xmax
  // ymax
  // target_uv
  rosidl_runtime_c__float__Sequence__fini(&msg->target_uv);
  // received_pos
  rosidl_runtime_c__float__Sequence__fini(&msg->received_pos);
  // position
  rosidl_runtime_c__float__Sequence__fini(&msg->position);
  // position_projection
  rosidl_runtime_c__float__Sequence__fini(&msg->position_projection);
  // position_cam
  rosidl_runtime_c__float__Sequence__fini(&msg->position_cam);
  // position_confidence
}

bool
vision_interface__msg__DetectedObject__are_equal(const vision_interface__msg__DetectedObject * lhs, const vision_interface__msg__DetectedObject * rhs)
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
  // color
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->color), &(rhs->color)))
  {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // xmin
  if (lhs->xmin != rhs->xmin) {
    return false;
  }
  // ymin
  if (lhs->ymin != rhs->ymin) {
    return false;
  }
  // xmax
  if (lhs->xmax != rhs->xmax) {
    return false;
  }
  // ymax
  if (lhs->ymax != rhs->ymax) {
    return false;
  }
  // target_uv
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->target_uv), &(rhs->target_uv)))
  {
    return false;
  }
  // received_pos
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->received_pos), &(rhs->received_pos)))
  {
    return false;
  }
  // position
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // position_projection
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->position_projection), &(rhs->position_projection)))
  {
    return false;
  }
  // position_cam
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->position_cam), &(rhs->position_cam)))
  {
    return false;
  }
  // position_confidence
  if (lhs->position_confidence != rhs->position_confidence) {
    return false;
  }
  return true;
}

bool
vision_interface__msg__DetectedObject__copy(
  const vision_interface__msg__DetectedObject * input,
  vision_interface__msg__DetectedObject * output)
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
  // color
  if (!rosidl_runtime_c__String__copy(
      &(input->color), &(output->color)))
  {
    return false;
  }
  // confidence
  output->confidence = input->confidence;
  // xmin
  output->xmin = input->xmin;
  // ymin
  output->ymin = input->ymin;
  // xmax
  output->xmax = input->xmax;
  // ymax
  output->ymax = input->ymax;
  // target_uv
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->target_uv), &(output->target_uv)))
  {
    return false;
  }
  // received_pos
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->received_pos), &(output->received_pos)))
  {
    return false;
  }
  // position
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // position_projection
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->position_projection), &(output->position_projection)))
  {
    return false;
  }
  // position_cam
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->position_cam), &(output->position_cam)))
  {
    return false;
  }
  // position_confidence
  output->position_confidence = input->position_confidence;
  return true;
}

vision_interface__msg__DetectedObject *
vision_interface__msg__DetectedObject__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__DetectedObject * msg = (vision_interface__msg__DetectedObject *)allocator.allocate(sizeof(vision_interface__msg__DetectedObject), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vision_interface__msg__DetectedObject));
  bool success = vision_interface__msg__DetectedObject__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vision_interface__msg__DetectedObject__destroy(vision_interface__msg__DetectedObject * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vision_interface__msg__DetectedObject__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vision_interface__msg__DetectedObject__Sequence__init(vision_interface__msg__DetectedObject__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__DetectedObject * data = NULL;

  if (size) {
    data = (vision_interface__msg__DetectedObject *)allocator.zero_allocate(size, sizeof(vision_interface__msg__DetectedObject), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vision_interface__msg__DetectedObject__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vision_interface__msg__DetectedObject__fini(&data[i - 1]);
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
vision_interface__msg__DetectedObject__Sequence__fini(vision_interface__msg__DetectedObject__Sequence * array)
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
      vision_interface__msg__DetectedObject__fini(&array->data[i]);
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

vision_interface__msg__DetectedObject__Sequence *
vision_interface__msg__DetectedObject__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__DetectedObject__Sequence * array = (vision_interface__msg__DetectedObject__Sequence *)allocator.allocate(sizeof(vision_interface__msg__DetectedObject__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vision_interface__msg__DetectedObject__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vision_interface__msg__DetectedObject__Sequence__destroy(vision_interface__msg__DetectedObject__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vision_interface__msg__DetectedObject__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vision_interface__msg__DetectedObject__Sequence__are_equal(const vision_interface__msg__DetectedObject__Sequence * lhs, const vision_interface__msg__DetectedObject__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vision_interface__msg__DetectedObject__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vision_interface__msg__DetectedObject__Sequence__copy(
  const vision_interface__msg__DetectedObject__Sequence * input,
  vision_interface__msg__DetectedObject__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vision_interface__msg__DetectedObject);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vision_interface__msg__DetectedObject * data =
      (vision_interface__msg__DetectedObject *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vision_interface__msg__DetectedObject__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vision_interface__msg__DetectedObject__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vision_interface__msg__DetectedObject__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
