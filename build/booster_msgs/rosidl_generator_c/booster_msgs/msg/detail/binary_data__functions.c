// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from booster_msgs:msg/BinaryData.idl
// generated code does not contain a copyright notice
#include "booster_msgs/msg/detail/binary_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
booster_msgs__msg__BinaryData__init(booster_msgs__msg__BinaryData * msg)
{
  if (!msg) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->data, 0)) {
    booster_msgs__msg__BinaryData__fini(msg);
    return false;
  }
  return true;
}

void
booster_msgs__msg__BinaryData__fini(booster_msgs__msg__BinaryData * msg)
{
  if (!msg) {
    return;
  }
  // data
  rosidl_runtime_c__uint8__Sequence__fini(&msg->data);
}

bool
booster_msgs__msg__BinaryData__are_equal(const booster_msgs__msg__BinaryData * lhs, const booster_msgs__msg__BinaryData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
booster_msgs__msg__BinaryData__copy(
  const booster_msgs__msg__BinaryData * input,
  booster_msgs__msg__BinaryData * output)
{
  if (!input || !output) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

booster_msgs__msg__BinaryData *
booster_msgs__msg__BinaryData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_msgs__msg__BinaryData * msg = (booster_msgs__msg__BinaryData *)allocator.allocate(sizeof(booster_msgs__msg__BinaryData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(booster_msgs__msg__BinaryData));
  bool success = booster_msgs__msg__BinaryData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
booster_msgs__msg__BinaryData__destroy(booster_msgs__msg__BinaryData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    booster_msgs__msg__BinaryData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
booster_msgs__msg__BinaryData__Sequence__init(booster_msgs__msg__BinaryData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_msgs__msg__BinaryData * data = NULL;

  if (size) {
    data = (booster_msgs__msg__BinaryData *)allocator.zero_allocate(size, sizeof(booster_msgs__msg__BinaryData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = booster_msgs__msg__BinaryData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        booster_msgs__msg__BinaryData__fini(&data[i - 1]);
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
booster_msgs__msg__BinaryData__Sequence__fini(booster_msgs__msg__BinaryData__Sequence * array)
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
      booster_msgs__msg__BinaryData__fini(&array->data[i]);
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

booster_msgs__msg__BinaryData__Sequence *
booster_msgs__msg__BinaryData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_msgs__msg__BinaryData__Sequence * array = (booster_msgs__msg__BinaryData__Sequence *)allocator.allocate(sizeof(booster_msgs__msg__BinaryData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = booster_msgs__msg__BinaryData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
booster_msgs__msg__BinaryData__Sequence__destroy(booster_msgs__msg__BinaryData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    booster_msgs__msg__BinaryData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
booster_msgs__msg__BinaryData__Sequence__are_equal(const booster_msgs__msg__BinaryData__Sequence * lhs, const booster_msgs__msg__BinaryData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!booster_msgs__msg__BinaryData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
booster_msgs__msg__BinaryData__Sequence__copy(
  const booster_msgs__msg__BinaryData__Sequence * input,
  booster_msgs__msg__BinaryData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(booster_msgs__msg__BinaryData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    booster_msgs__msg__BinaryData * data =
      (booster_msgs__msg__BinaryData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!booster_msgs__msg__BinaryData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          booster_msgs__msg__BinaryData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!booster_msgs__msg__BinaryData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
