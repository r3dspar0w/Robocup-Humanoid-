// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from booster_msgs:msg/RpcRespMsg.idl
// generated code does not contain a copyright notice
#include "booster_msgs/msg/detail/rpc_resp_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `uuid`
// Member `header`
// Member `body`
#include "rosidl_runtime_c/string_functions.h"

bool
booster_msgs__msg__RpcRespMsg__init(booster_msgs__msg__RpcRespMsg * msg)
{
  if (!msg) {
    return false;
  }
  // uuid
  if (!rosidl_runtime_c__String__init(&msg->uuid)) {
    booster_msgs__msg__RpcRespMsg__fini(msg);
    return false;
  }
  // header
  if (!rosidl_runtime_c__String__init(&msg->header)) {
    booster_msgs__msg__RpcRespMsg__fini(msg);
    return false;
  }
  // body
  if (!rosidl_runtime_c__String__init(&msg->body)) {
    booster_msgs__msg__RpcRespMsg__fini(msg);
    return false;
  }
  return true;
}

void
booster_msgs__msg__RpcRespMsg__fini(booster_msgs__msg__RpcRespMsg * msg)
{
  if (!msg) {
    return;
  }
  // uuid
  rosidl_runtime_c__String__fini(&msg->uuid);
  // header
  rosidl_runtime_c__String__fini(&msg->header);
  // body
  rosidl_runtime_c__String__fini(&msg->body);
}

bool
booster_msgs__msg__RpcRespMsg__are_equal(const booster_msgs__msg__RpcRespMsg * lhs, const booster_msgs__msg__RpcRespMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // uuid
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->uuid), &(rhs->uuid)))
  {
    return false;
  }
  // header
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // body
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->body), &(rhs->body)))
  {
    return false;
  }
  return true;
}

bool
booster_msgs__msg__RpcRespMsg__copy(
  const booster_msgs__msg__RpcRespMsg * input,
  booster_msgs__msg__RpcRespMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // uuid
  if (!rosidl_runtime_c__String__copy(
      &(input->uuid), &(output->uuid)))
  {
    return false;
  }
  // header
  if (!rosidl_runtime_c__String__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // body
  if (!rosidl_runtime_c__String__copy(
      &(input->body), &(output->body)))
  {
    return false;
  }
  return true;
}

booster_msgs__msg__RpcRespMsg *
booster_msgs__msg__RpcRespMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_msgs__msg__RpcRespMsg * msg = (booster_msgs__msg__RpcRespMsg *)allocator.allocate(sizeof(booster_msgs__msg__RpcRespMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(booster_msgs__msg__RpcRespMsg));
  bool success = booster_msgs__msg__RpcRespMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
booster_msgs__msg__RpcRespMsg__destroy(booster_msgs__msg__RpcRespMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    booster_msgs__msg__RpcRespMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
booster_msgs__msg__RpcRespMsg__Sequence__init(booster_msgs__msg__RpcRespMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_msgs__msg__RpcRespMsg * data = NULL;

  if (size) {
    data = (booster_msgs__msg__RpcRespMsg *)allocator.zero_allocate(size, sizeof(booster_msgs__msg__RpcRespMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = booster_msgs__msg__RpcRespMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        booster_msgs__msg__RpcRespMsg__fini(&data[i - 1]);
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
booster_msgs__msg__RpcRespMsg__Sequence__fini(booster_msgs__msg__RpcRespMsg__Sequence * array)
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
      booster_msgs__msg__RpcRespMsg__fini(&array->data[i]);
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

booster_msgs__msg__RpcRespMsg__Sequence *
booster_msgs__msg__RpcRespMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_msgs__msg__RpcRespMsg__Sequence * array = (booster_msgs__msg__RpcRespMsg__Sequence *)allocator.allocate(sizeof(booster_msgs__msg__RpcRespMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = booster_msgs__msg__RpcRespMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
booster_msgs__msg__RpcRespMsg__Sequence__destroy(booster_msgs__msg__RpcRespMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    booster_msgs__msg__RpcRespMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
booster_msgs__msg__RpcRespMsg__Sequence__are_equal(const booster_msgs__msg__RpcRespMsg__Sequence * lhs, const booster_msgs__msg__RpcRespMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!booster_msgs__msg__RpcRespMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
booster_msgs__msg__RpcRespMsg__Sequence__copy(
  const booster_msgs__msg__RpcRespMsg__Sequence * input,
  booster_msgs__msg__RpcRespMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(booster_msgs__msg__RpcRespMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    booster_msgs__msg__RpcRespMsg * data =
      (booster_msgs__msg__RpcRespMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!booster_msgs__msg__RpcRespMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          booster_msgs__msg__RpcRespMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!booster_msgs__msg__RpcRespMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
