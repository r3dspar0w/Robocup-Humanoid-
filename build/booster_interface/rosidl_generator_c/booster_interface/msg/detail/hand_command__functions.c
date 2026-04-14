// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from booster_interface:msg/HandCommand.idl
// generated code does not contain a copyright notice
#include "booster_interface/msg/detail/hand_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `hand_param`
#include "booster_interface/msg/detail/hand_param__functions.h"

bool
booster_interface__msg__HandCommand__init(booster_interface__msg__HandCommand * msg)
{
  if (!msg) {
    return false;
  }
  // hand_param
  if (!booster_interface__msg__HandParam__Sequence__init(&msg->hand_param, 0)) {
    booster_interface__msg__HandCommand__fini(msg);
    return false;
  }
  // force_mode
  // hand_index
  // hand_type
  return true;
}

void
booster_interface__msg__HandCommand__fini(booster_interface__msg__HandCommand * msg)
{
  if (!msg) {
    return;
  }
  // hand_param
  booster_interface__msg__HandParam__Sequence__fini(&msg->hand_param);
  // force_mode
  // hand_index
  // hand_type
}

bool
booster_interface__msg__HandCommand__are_equal(const booster_interface__msg__HandCommand * lhs, const booster_interface__msg__HandCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // hand_param
  if (!booster_interface__msg__HandParam__Sequence__are_equal(
      &(lhs->hand_param), &(rhs->hand_param)))
  {
    return false;
  }
  // force_mode
  if (lhs->force_mode != rhs->force_mode) {
    return false;
  }
  // hand_index
  if (lhs->hand_index != rhs->hand_index) {
    return false;
  }
  // hand_type
  if (lhs->hand_type != rhs->hand_type) {
    return false;
  }
  return true;
}

bool
booster_interface__msg__HandCommand__copy(
  const booster_interface__msg__HandCommand * input,
  booster_interface__msg__HandCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // hand_param
  if (!booster_interface__msg__HandParam__Sequence__copy(
      &(input->hand_param), &(output->hand_param)))
  {
    return false;
  }
  // force_mode
  output->force_mode = input->force_mode;
  // hand_index
  output->hand_index = input->hand_index;
  // hand_type
  output->hand_type = input->hand_type;
  return true;
}

booster_interface__msg__HandCommand *
booster_interface__msg__HandCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__msg__HandCommand * msg = (booster_interface__msg__HandCommand *)allocator.allocate(sizeof(booster_interface__msg__HandCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(booster_interface__msg__HandCommand));
  bool success = booster_interface__msg__HandCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
booster_interface__msg__HandCommand__destroy(booster_interface__msg__HandCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    booster_interface__msg__HandCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
booster_interface__msg__HandCommand__Sequence__init(booster_interface__msg__HandCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__msg__HandCommand * data = NULL;

  if (size) {
    data = (booster_interface__msg__HandCommand *)allocator.zero_allocate(size, sizeof(booster_interface__msg__HandCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = booster_interface__msg__HandCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        booster_interface__msg__HandCommand__fini(&data[i - 1]);
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
booster_interface__msg__HandCommand__Sequence__fini(booster_interface__msg__HandCommand__Sequence * array)
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
      booster_interface__msg__HandCommand__fini(&array->data[i]);
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

booster_interface__msg__HandCommand__Sequence *
booster_interface__msg__HandCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__msg__HandCommand__Sequence * array = (booster_interface__msg__HandCommand__Sequence *)allocator.allocate(sizeof(booster_interface__msg__HandCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = booster_interface__msg__HandCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
booster_interface__msg__HandCommand__Sequence__destroy(booster_interface__msg__HandCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    booster_interface__msg__HandCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
booster_interface__msg__HandCommand__Sequence__are_equal(const booster_interface__msg__HandCommand__Sequence * lhs, const booster_interface__msg__HandCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!booster_interface__msg__HandCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
booster_interface__msg__HandCommand__Sequence__copy(
  const booster_interface__msg__HandCommand__Sequence * input,
  booster_interface__msg__HandCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(booster_interface__msg__HandCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    booster_interface__msg__HandCommand * data =
      (booster_interface__msg__HandCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!booster_interface__msg__HandCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          booster_interface__msg__HandCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!booster_interface__msg__HandCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
