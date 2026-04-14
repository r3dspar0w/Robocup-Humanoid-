// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from booster_interface:msg/FallDownState.idl
// generated code does not contain a copyright notice
#include "booster_interface/msg/detail/fall_down_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
booster_interface__msg__FallDownState__init(booster_interface__msg__FallDownState * msg)
{
  if (!msg) {
    return false;
  }
  // fall_down_state
  // is_recovery_available
  return true;
}

void
booster_interface__msg__FallDownState__fini(booster_interface__msg__FallDownState * msg)
{
  if (!msg) {
    return;
  }
  // fall_down_state
  // is_recovery_available
}

bool
booster_interface__msg__FallDownState__are_equal(const booster_interface__msg__FallDownState * lhs, const booster_interface__msg__FallDownState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // fall_down_state
  if (lhs->fall_down_state != rhs->fall_down_state) {
    return false;
  }
  // is_recovery_available
  if (lhs->is_recovery_available != rhs->is_recovery_available) {
    return false;
  }
  return true;
}

bool
booster_interface__msg__FallDownState__copy(
  const booster_interface__msg__FallDownState * input,
  booster_interface__msg__FallDownState * output)
{
  if (!input || !output) {
    return false;
  }
  // fall_down_state
  output->fall_down_state = input->fall_down_state;
  // is_recovery_available
  output->is_recovery_available = input->is_recovery_available;
  return true;
}

booster_interface__msg__FallDownState *
booster_interface__msg__FallDownState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__msg__FallDownState * msg = (booster_interface__msg__FallDownState *)allocator.allocate(sizeof(booster_interface__msg__FallDownState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(booster_interface__msg__FallDownState));
  bool success = booster_interface__msg__FallDownState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
booster_interface__msg__FallDownState__destroy(booster_interface__msg__FallDownState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    booster_interface__msg__FallDownState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
booster_interface__msg__FallDownState__Sequence__init(booster_interface__msg__FallDownState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__msg__FallDownState * data = NULL;

  if (size) {
    data = (booster_interface__msg__FallDownState *)allocator.zero_allocate(size, sizeof(booster_interface__msg__FallDownState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = booster_interface__msg__FallDownState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        booster_interface__msg__FallDownState__fini(&data[i - 1]);
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
booster_interface__msg__FallDownState__Sequence__fini(booster_interface__msg__FallDownState__Sequence * array)
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
      booster_interface__msg__FallDownState__fini(&array->data[i]);
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

booster_interface__msg__FallDownState__Sequence *
booster_interface__msg__FallDownState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__msg__FallDownState__Sequence * array = (booster_interface__msg__FallDownState__Sequence *)allocator.allocate(sizeof(booster_interface__msg__FallDownState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = booster_interface__msg__FallDownState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
booster_interface__msg__FallDownState__Sequence__destroy(booster_interface__msg__FallDownState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    booster_interface__msg__FallDownState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
booster_interface__msg__FallDownState__Sequence__are_equal(const booster_interface__msg__FallDownState__Sequence * lhs, const booster_interface__msg__FallDownState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!booster_interface__msg__FallDownState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
booster_interface__msg__FallDownState__Sequence__copy(
  const booster_interface__msg__FallDownState__Sequence * input,
  booster_interface__msg__FallDownState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(booster_interface__msg__FallDownState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    booster_interface__msg__FallDownState * data =
      (booster_interface__msg__FallDownState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!booster_interface__msg__FallDownState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          booster_interface__msg__FallDownState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!booster_interface__msg__FallDownState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
