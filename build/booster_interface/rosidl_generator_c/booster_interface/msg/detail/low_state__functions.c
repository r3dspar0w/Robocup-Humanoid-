// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from booster_interface:msg/LowState.idl
// generated code does not contain a copyright notice
#include "booster_interface/msg/detail/low_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `imu_state`
#include "booster_interface/msg/detail/imu_state__functions.h"
// Member `motor_state_parallel`
// Member `motor_state_serial`
#include "booster_interface/msg/detail/motor_state__functions.h"

bool
booster_interface__msg__LowState__init(booster_interface__msg__LowState * msg)
{
  if (!msg) {
    return false;
  }
  // imu_state
  if (!booster_interface__msg__ImuState__init(&msg->imu_state)) {
    booster_interface__msg__LowState__fini(msg);
    return false;
  }
  // motor_state_parallel
  if (!booster_interface__msg__MotorState__Sequence__init(&msg->motor_state_parallel, 0)) {
    booster_interface__msg__LowState__fini(msg);
    return false;
  }
  // motor_state_serial
  if (!booster_interface__msg__MotorState__Sequence__init(&msg->motor_state_serial, 0)) {
    booster_interface__msg__LowState__fini(msg);
    return false;
  }
  return true;
}

void
booster_interface__msg__LowState__fini(booster_interface__msg__LowState * msg)
{
  if (!msg) {
    return;
  }
  // imu_state
  booster_interface__msg__ImuState__fini(&msg->imu_state);
  // motor_state_parallel
  booster_interface__msg__MotorState__Sequence__fini(&msg->motor_state_parallel);
  // motor_state_serial
  booster_interface__msg__MotorState__Sequence__fini(&msg->motor_state_serial);
}

bool
booster_interface__msg__LowState__are_equal(const booster_interface__msg__LowState * lhs, const booster_interface__msg__LowState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // imu_state
  if (!booster_interface__msg__ImuState__are_equal(
      &(lhs->imu_state), &(rhs->imu_state)))
  {
    return false;
  }
  // motor_state_parallel
  if (!booster_interface__msg__MotorState__Sequence__are_equal(
      &(lhs->motor_state_parallel), &(rhs->motor_state_parallel)))
  {
    return false;
  }
  // motor_state_serial
  if (!booster_interface__msg__MotorState__Sequence__are_equal(
      &(lhs->motor_state_serial), &(rhs->motor_state_serial)))
  {
    return false;
  }
  return true;
}

bool
booster_interface__msg__LowState__copy(
  const booster_interface__msg__LowState * input,
  booster_interface__msg__LowState * output)
{
  if (!input || !output) {
    return false;
  }
  // imu_state
  if (!booster_interface__msg__ImuState__copy(
      &(input->imu_state), &(output->imu_state)))
  {
    return false;
  }
  // motor_state_parallel
  if (!booster_interface__msg__MotorState__Sequence__copy(
      &(input->motor_state_parallel), &(output->motor_state_parallel)))
  {
    return false;
  }
  // motor_state_serial
  if (!booster_interface__msg__MotorState__Sequence__copy(
      &(input->motor_state_serial), &(output->motor_state_serial)))
  {
    return false;
  }
  return true;
}

booster_interface__msg__LowState *
booster_interface__msg__LowState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__msg__LowState * msg = (booster_interface__msg__LowState *)allocator.allocate(sizeof(booster_interface__msg__LowState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(booster_interface__msg__LowState));
  bool success = booster_interface__msg__LowState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
booster_interface__msg__LowState__destroy(booster_interface__msg__LowState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    booster_interface__msg__LowState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
booster_interface__msg__LowState__Sequence__init(booster_interface__msg__LowState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__msg__LowState * data = NULL;

  if (size) {
    data = (booster_interface__msg__LowState *)allocator.zero_allocate(size, sizeof(booster_interface__msg__LowState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = booster_interface__msg__LowState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        booster_interface__msg__LowState__fini(&data[i - 1]);
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
booster_interface__msg__LowState__Sequence__fini(booster_interface__msg__LowState__Sequence * array)
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
      booster_interface__msg__LowState__fini(&array->data[i]);
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

booster_interface__msg__LowState__Sequence *
booster_interface__msg__LowState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__msg__LowState__Sequence * array = (booster_interface__msg__LowState__Sequence *)allocator.allocate(sizeof(booster_interface__msg__LowState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = booster_interface__msg__LowState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
booster_interface__msg__LowState__Sequence__destroy(booster_interface__msg__LowState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    booster_interface__msg__LowState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
booster_interface__msg__LowState__Sequence__are_equal(const booster_interface__msg__LowState__Sequence * lhs, const booster_interface__msg__LowState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!booster_interface__msg__LowState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
booster_interface__msg__LowState__Sequence__copy(
  const booster_interface__msg__LowState__Sequence * input,
  booster_interface__msg__LowState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(booster_interface__msg__LowState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    booster_interface__msg__LowState * data =
      (booster_interface__msg__LowState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!booster_interface__msg__LowState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          booster_interface__msg__LowState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!booster_interface__msg__LowState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
