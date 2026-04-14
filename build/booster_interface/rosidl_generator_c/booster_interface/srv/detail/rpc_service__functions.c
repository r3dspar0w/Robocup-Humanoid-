// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from booster_interface:srv/RpcService.idl
// generated code does not contain a copyright notice
#include "booster_interface/srv/detail/rpc_service__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `msg`
#include "booster_interface/msg/detail/booster_api_req_msg__functions.h"

bool
booster_interface__srv__RpcService_Request__init(booster_interface__srv__RpcService_Request * msg)
{
  if (!msg) {
    return false;
  }
  // msg
  if (!booster_interface__msg__BoosterApiReqMsg__init(&msg->msg)) {
    booster_interface__srv__RpcService_Request__fini(msg);
    return false;
  }
  return true;
}

void
booster_interface__srv__RpcService_Request__fini(booster_interface__srv__RpcService_Request * msg)
{
  if (!msg) {
    return;
  }
  // msg
  booster_interface__msg__BoosterApiReqMsg__fini(&msg->msg);
}

bool
booster_interface__srv__RpcService_Request__are_equal(const booster_interface__srv__RpcService_Request * lhs, const booster_interface__srv__RpcService_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // msg
  if (!booster_interface__msg__BoosterApiReqMsg__are_equal(
      &(lhs->msg), &(rhs->msg)))
  {
    return false;
  }
  return true;
}

bool
booster_interface__srv__RpcService_Request__copy(
  const booster_interface__srv__RpcService_Request * input,
  booster_interface__srv__RpcService_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // msg
  if (!booster_interface__msg__BoosterApiReqMsg__copy(
      &(input->msg), &(output->msg)))
  {
    return false;
  }
  return true;
}

booster_interface__srv__RpcService_Request *
booster_interface__srv__RpcService_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__srv__RpcService_Request * msg = (booster_interface__srv__RpcService_Request *)allocator.allocate(sizeof(booster_interface__srv__RpcService_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(booster_interface__srv__RpcService_Request));
  bool success = booster_interface__srv__RpcService_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
booster_interface__srv__RpcService_Request__destroy(booster_interface__srv__RpcService_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    booster_interface__srv__RpcService_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
booster_interface__srv__RpcService_Request__Sequence__init(booster_interface__srv__RpcService_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__srv__RpcService_Request * data = NULL;

  if (size) {
    data = (booster_interface__srv__RpcService_Request *)allocator.zero_allocate(size, sizeof(booster_interface__srv__RpcService_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = booster_interface__srv__RpcService_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        booster_interface__srv__RpcService_Request__fini(&data[i - 1]);
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
booster_interface__srv__RpcService_Request__Sequence__fini(booster_interface__srv__RpcService_Request__Sequence * array)
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
      booster_interface__srv__RpcService_Request__fini(&array->data[i]);
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

booster_interface__srv__RpcService_Request__Sequence *
booster_interface__srv__RpcService_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__srv__RpcService_Request__Sequence * array = (booster_interface__srv__RpcService_Request__Sequence *)allocator.allocate(sizeof(booster_interface__srv__RpcService_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = booster_interface__srv__RpcService_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
booster_interface__srv__RpcService_Request__Sequence__destroy(booster_interface__srv__RpcService_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    booster_interface__srv__RpcService_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
booster_interface__srv__RpcService_Request__Sequence__are_equal(const booster_interface__srv__RpcService_Request__Sequence * lhs, const booster_interface__srv__RpcService_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!booster_interface__srv__RpcService_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
booster_interface__srv__RpcService_Request__Sequence__copy(
  const booster_interface__srv__RpcService_Request__Sequence * input,
  booster_interface__srv__RpcService_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(booster_interface__srv__RpcService_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    booster_interface__srv__RpcService_Request * data =
      (booster_interface__srv__RpcService_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!booster_interface__srv__RpcService_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          booster_interface__srv__RpcService_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!booster_interface__srv__RpcService_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `msg`
#include "booster_interface/msg/detail/booster_api_resp_msg__functions.h"

bool
booster_interface__srv__RpcService_Response__init(booster_interface__srv__RpcService_Response * msg)
{
  if (!msg) {
    return false;
  }
  // msg
  if (!booster_interface__msg__BoosterApiRespMsg__init(&msg->msg)) {
    booster_interface__srv__RpcService_Response__fini(msg);
    return false;
  }
  return true;
}

void
booster_interface__srv__RpcService_Response__fini(booster_interface__srv__RpcService_Response * msg)
{
  if (!msg) {
    return;
  }
  // msg
  booster_interface__msg__BoosterApiRespMsg__fini(&msg->msg);
}

bool
booster_interface__srv__RpcService_Response__are_equal(const booster_interface__srv__RpcService_Response * lhs, const booster_interface__srv__RpcService_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // msg
  if (!booster_interface__msg__BoosterApiRespMsg__are_equal(
      &(lhs->msg), &(rhs->msg)))
  {
    return false;
  }
  return true;
}

bool
booster_interface__srv__RpcService_Response__copy(
  const booster_interface__srv__RpcService_Response * input,
  booster_interface__srv__RpcService_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // msg
  if (!booster_interface__msg__BoosterApiRespMsg__copy(
      &(input->msg), &(output->msg)))
  {
    return false;
  }
  return true;
}

booster_interface__srv__RpcService_Response *
booster_interface__srv__RpcService_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__srv__RpcService_Response * msg = (booster_interface__srv__RpcService_Response *)allocator.allocate(sizeof(booster_interface__srv__RpcService_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(booster_interface__srv__RpcService_Response));
  bool success = booster_interface__srv__RpcService_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
booster_interface__srv__RpcService_Response__destroy(booster_interface__srv__RpcService_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    booster_interface__srv__RpcService_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
booster_interface__srv__RpcService_Response__Sequence__init(booster_interface__srv__RpcService_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__srv__RpcService_Response * data = NULL;

  if (size) {
    data = (booster_interface__srv__RpcService_Response *)allocator.zero_allocate(size, sizeof(booster_interface__srv__RpcService_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = booster_interface__srv__RpcService_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        booster_interface__srv__RpcService_Response__fini(&data[i - 1]);
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
booster_interface__srv__RpcService_Response__Sequence__fini(booster_interface__srv__RpcService_Response__Sequence * array)
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
      booster_interface__srv__RpcService_Response__fini(&array->data[i]);
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

booster_interface__srv__RpcService_Response__Sequence *
booster_interface__srv__RpcService_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__srv__RpcService_Response__Sequence * array = (booster_interface__srv__RpcService_Response__Sequence *)allocator.allocate(sizeof(booster_interface__srv__RpcService_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = booster_interface__srv__RpcService_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
booster_interface__srv__RpcService_Response__Sequence__destroy(booster_interface__srv__RpcService_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    booster_interface__srv__RpcService_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
booster_interface__srv__RpcService_Response__Sequence__are_equal(const booster_interface__srv__RpcService_Response__Sequence * lhs, const booster_interface__srv__RpcService_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!booster_interface__srv__RpcService_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
booster_interface__srv__RpcService_Response__Sequence__copy(
  const booster_interface__srv__RpcService_Response__Sequence * input,
  booster_interface__srv__RpcService_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(booster_interface__srv__RpcService_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    booster_interface__srv__RpcService_Response * data =
      (booster_interface__srv__RpcService_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!booster_interface__srv__RpcService_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          booster_interface__srv__RpcService_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!booster_interface__srv__RpcService_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
