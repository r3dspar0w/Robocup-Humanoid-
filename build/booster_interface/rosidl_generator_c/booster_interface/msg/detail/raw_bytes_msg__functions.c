// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from booster_interface:msg/RawBytesMsg.idl
// generated code does not contain a copyright notice
#include "booster_interface/msg/detail/raw_bytes_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `msg`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
booster_interface__msg__RawBytesMsg__init(booster_interface__msg__RawBytesMsg * msg)
{
  if (!msg) {
    return false;
  }
  // msg
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->msg, 0)) {
    booster_interface__msg__RawBytesMsg__fini(msg);
    return false;
  }
  return true;
}

void
booster_interface__msg__RawBytesMsg__fini(booster_interface__msg__RawBytesMsg * msg)
{
  if (!msg) {
    return;
  }
  // msg
  rosidl_runtime_c__uint8__Sequence__fini(&msg->msg);
}

bool
booster_interface__msg__RawBytesMsg__are_equal(const booster_interface__msg__RawBytesMsg * lhs, const booster_interface__msg__RawBytesMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // msg
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->msg), &(rhs->msg)))
  {
    return false;
  }
  return true;
}

bool
booster_interface__msg__RawBytesMsg__copy(
  const booster_interface__msg__RawBytesMsg * input,
  booster_interface__msg__RawBytesMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // msg
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->msg), &(output->msg)))
  {
    return false;
  }
  return true;
}

booster_interface__msg__RawBytesMsg *
booster_interface__msg__RawBytesMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__msg__RawBytesMsg * msg = (booster_interface__msg__RawBytesMsg *)allocator.allocate(sizeof(booster_interface__msg__RawBytesMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(booster_interface__msg__RawBytesMsg));
  bool success = booster_interface__msg__RawBytesMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
booster_interface__msg__RawBytesMsg__destroy(booster_interface__msg__RawBytesMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    booster_interface__msg__RawBytesMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
booster_interface__msg__RawBytesMsg__Sequence__init(booster_interface__msg__RawBytesMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__msg__RawBytesMsg * data = NULL;

  if (size) {
    data = (booster_interface__msg__RawBytesMsg *)allocator.zero_allocate(size, sizeof(booster_interface__msg__RawBytesMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = booster_interface__msg__RawBytesMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        booster_interface__msg__RawBytesMsg__fini(&data[i - 1]);
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
booster_interface__msg__RawBytesMsg__Sequence__fini(booster_interface__msg__RawBytesMsg__Sequence * array)
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
      booster_interface__msg__RawBytesMsg__fini(&array->data[i]);
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

booster_interface__msg__RawBytesMsg__Sequence *
booster_interface__msg__RawBytesMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__msg__RawBytesMsg__Sequence * array = (booster_interface__msg__RawBytesMsg__Sequence *)allocator.allocate(sizeof(booster_interface__msg__RawBytesMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = booster_interface__msg__RawBytesMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
booster_interface__msg__RawBytesMsg__Sequence__destroy(booster_interface__msg__RawBytesMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    booster_interface__msg__RawBytesMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
booster_interface__msg__RawBytesMsg__Sequence__are_equal(const booster_interface__msg__RawBytesMsg__Sequence * lhs, const booster_interface__msg__RawBytesMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!booster_interface__msg__RawBytesMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
booster_interface__msg__RawBytesMsg__Sequence__copy(
  const booster_interface__msg__RawBytesMsg__Sequence * input,
  booster_interface__msg__RawBytesMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(booster_interface__msg__RawBytesMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    booster_interface__msg__RawBytesMsg * data =
      (booster_interface__msg__RawBytesMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!booster_interface__msg__RawBytesMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          booster_interface__msg__RawBytesMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!booster_interface__msg__RawBytesMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
