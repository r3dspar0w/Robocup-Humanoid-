// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vision_interface:msg/DetectionsTrack.idl
// generated code does not contain a copyright notice
#include "vision_interface/msg/detail/detections_track__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `ball_type`
#include "rosidl_runtime_c/string_functions.h"
// Member `detected_objects`
#include "vision_interface/msg/detail/detected_object__functions.h"
// Member `radar_x`
// Member `radar_y`
// Member `corner_pos`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
vision_interface__msg__DetectionsTrack__init(vision_interface__msg__DetectionsTrack * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    vision_interface__msg__DetectionsTrack__fini(msg);
    return false;
  }
  // ball_type
  if (!rosidl_runtime_c__String__init(&msg->ball_type)) {
    vision_interface__msg__DetectionsTrack__fini(msg);
    return false;
  }
  // detected_objects
  if (!vision_interface__msg__DetectedObject__Sequence__init(&msg->detected_objects, 0)) {
    vision_interface__msg__DetectionsTrack__fini(msg);
    return false;
  }
  // radar_x
  if (!rosidl_runtime_c__float__Sequence__init(&msg->radar_x, 0)) {
    vision_interface__msg__DetectionsTrack__fini(msg);
    return false;
  }
  // radar_y
  if (!rosidl_runtime_c__float__Sequence__init(&msg->radar_y, 0)) {
    vision_interface__msg__DetectionsTrack__fini(msg);
    return false;
  }
  // corner_pos
  if (!rosidl_runtime_c__float__Sequence__init(&msg->corner_pos, 0)) {
    vision_interface__msg__DetectionsTrack__fini(msg);
    return false;
  }
  return true;
}

void
vision_interface__msg__DetectionsTrack__fini(vision_interface__msg__DetectionsTrack * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // ball_type
  rosidl_runtime_c__String__fini(&msg->ball_type);
  // detected_objects
  vision_interface__msg__DetectedObject__Sequence__fini(&msg->detected_objects);
  // radar_x
  rosidl_runtime_c__float__Sequence__fini(&msg->radar_x);
  // radar_y
  rosidl_runtime_c__float__Sequence__fini(&msg->radar_y);
  // corner_pos
  rosidl_runtime_c__float__Sequence__fini(&msg->corner_pos);
}

bool
vision_interface__msg__DetectionsTrack__are_equal(const vision_interface__msg__DetectionsTrack * lhs, const vision_interface__msg__DetectionsTrack * rhs)
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
  // ball_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->ball_type), &(rhs->ball_type)))
  {
    return false;
  }
  // detected_objects
  if (!vision_interface__msg__DetectedObject__Sequence__are_equal(
      &(lhs->detected_objects), &(rhs->detected_objects)))
  {
    return false;
  }
  // radar_x
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->radar_x), &(rhs->radar_x)))
  {
    return false;
  }
  // radar_y
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->radar_y), &(rhs->radar_y)))
  {
    return false;
  }
  // corner_pos
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->corner_pos), &(rhs->corner_pos)))
  {
    return false;
  }
  return true;
}

bool
vision_interface__msg__DetectionsTrack__copy(
  const vision_interface__msg__DetectionsTrack * input,
  vision_interface__msg__DetectionsTrack * output)
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
  // ball_type
  if (!rosidl_runtime_c__String__copy(
      &(input->ball_type), &(output->ball_type)))
  {
    return false;
  }
  // detected_objects
  if (!vision_interface__msg__DetectedObject__Sequence__copy(
      &(input->detected_objects), &(output->detected_objects)))
  {
    return false;
  }
  // radar_x
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->radar_x), &(output->radar_x)))
  {
    return false;
  }
  // radar_y
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->radar_y), &(output->radar_y)))
  {
    return false;
  }
  // corner_pos
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->corner_pos), &(output->corner_pos)))
  {
    return false;
  }
  return true;
}

vision_interface__msg__DetectionsTrack *
vision_interface__msg__DetectionsTrack__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__DetectionsTrack * msg = (vision_interface__msg__DetectionsTrack *)allocator.allocate(sizeof(vision_interface__msg__DetectionsTrack), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vision_interface__msg__DetectionsTrack));
  bool success = vision_interface__msg__DetectionsTrack__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vision_interface__msg__DetectionsTrack__destroy(vision_interface__msg__DetectionsTrack * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vision_interface__msg__DetectionsTrack__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vision_interface__msg__DetectionsTrack__Sequence__init(vision_interface__msg__DetectionsTrack__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__DetectionsTrack * data = NULL;

  if (size) {
    data = (vision_interface__msg__DetectionsTrack *)allocator.zero_allocate(size, sizeof(vision_interface__msg__DetectionsTrack), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vision_interface__msg__DetectionsTrack__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vision_interface__msg__DetectionsTrack__fini(&data[i - 1]);
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
vision_interface__msg__DetectionsTrack__Sequence__fini(vision_interface__msg__DetectionsTrack__Sequence * array)
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
      vision_interface__msg__DetectionsTrack__fini(&array->data[i]);
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

vision_interface__msg__DetectionsTrack__Sequence *
vision_interface__msg__DetectionsTrack__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_interface__msg__DetectionsTrack__Sequence * array = (vision_interface__msg__DetectionsTrack__Sequence *)allocator.allocate(sizeof(vision_interface__msg__DetectionsTrack__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vision_interface__msg__DetectionsTrack__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vision_interface__msg__DetectionsTrack__Sequence__destroy(vision_interface__msg__DetectionsTrack__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vision_interface__msg__DetectionsTrack__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vision_interface__msg__DetectionsTrack__Sequence__are_equal(const vision_interface__msg__DetectionsTrack__Sequence * lhs, const vision_interface__msg__DetectionsTrack__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vision_interface__msg__DetectionsTrack__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vision_interface__msg__DetectionsTrack__Sequence__copy(
  const vision_interface__msg__DetectionsTrack__Sequence * input,
  vision_interface__msg__DetectionsTrack__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vision_interface__msg__DetectionsTrack);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vision_interface__msg__DetectionsTrack * data =
      (vision_interface__msg__DetectionsTrack *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vision_interface__msg__DetectionsTrack__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vision_interface__msg__DetectionsTrack__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vision_interface__msg__DetectionsTrack__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
