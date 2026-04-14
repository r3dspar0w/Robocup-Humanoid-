// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from booster_interface:msg/RemoteControllerState.idl
// generated code does not contain a copyright notice
#include "booster_interface/msg/detail/remote_controller_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
booster_interface__msg__RemoteControllerState__init(booster_interface__msg__RemoteControllerState * msg)
{
  if (!msg) {
    return false;
  }
  // event
  // lx
  // ly
  // rx
  // ry
  // a
  // b
  // x
  // y
  // lb
  // rb
  // lt
  // rt
  // ls
  // rs
  // back
  // start
  // hat_c
  // hat_u
  // hat_d
  // hat_l
  // hat_r
  // hat_lu
  // hat_ld
  // hat_ru
  // hat_rd
  // hat_pos
  return true;
}

void
booster_interface__msg__RemoteControllerState__fini(booster_interface__msg__RemoteControllerState * msg)
{
  if (!msg) {
    return;
  }
  // event
  // lx
  // ly
  // rx
  // ry
  // a
  // b
  // x
  // y
  // lb
  // rb
  // lt
  // rt
  // ls
  // rs
  // back
  // start
  // hat_c
  // hat_u
  // hat_d
  // hat_l
  // hat_r
  // hat_lu
  // hat_ld
  // hat_ru
  // hat_rd
  // hat_pos
}

bool
booster_interface__msg__RemoteControllerState__are_equal(const booster_interface__msg__RemoteControllerState * lhs, const booster_interface__msg__RemoteControllerState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // event
  if (lhs->event != rhs->event) {
    return false;
  }
  // lx
  if (lhs->lx != rhs->lx) {
    return false;
  }
  // ly
  if (lhs->ly != rhs->ly) {
    return false;
  }
  // rx
  if (lhs->rx != rhs->rx) {
    return false;
  }
  // ry
  if (lhs->ry != rhs->ry) {
    return false;
  }
  // a
  if (lhs->a != rhs->a) {
    return false;
  }
  // b
  if (lhs->b != rhs->b) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // lb
  if (lhs->lb != rhs->lb) {
    return false;
  }
  // rb
  if (lhs->rb != rhs->rb) {
    return false;
  }
  // lt
  if (lhs->lt != rhs->lt) {
    return false;
  }
  // rt
  if (lhs->rt != rhs->rt) {
    return false;
  }
  // ls
  if (lhs->ls != rhs->ls) {
    return false;
  }
  // rs
  if (lhs->rs != rhs->rs) {
    return false;
  }
  // back
  if (lhs->back != rhs->back) {
    return false;
  }
  // start
  if (lhs->start != rhs->start) {
    return false;
  }
  // hat_c
  if (lhs->hat_c != rhs->hat_c) {
    return false;
  }
  // hat_u
  if (lhs->hat_u != rhs->hat_u) {
    return false;
  }
  // hat_d
  if (lhs->hat_d != rhs->hat_d) {
    return false;
  }
  // hat_l
  if (lhs->hat_l != rhs->hat_l) {
    return false;
  }
  // hat_r
  if (lhs->hat_r != rhs->hat_r) {
    return false;
  }
  // hat_lu
  if (lhs->hat_lu != rhs->hat_lu) {
    return false;
  }
  // hat_ld
  if (lhs->hat_ld != rhs->hat_ld) {
    return false;
  }
  // hat_ru
  if (lhs->hat_ru != rhs->hat_ru) {
    return false;
  }
  // hat_rd
  if (lhs->hat_rd != rhs->hat_rd) {
    return false;
  }
  // hat_pos
  if (lhs->hat_pos != rhs->hat_pos) {
    return false;
  }
  return true;
}

bool
booster_interface__msg__RemoteControllerState__copy(
  const booster_interface__msg__RemoteControllerState * input,
  booster_interface__msg__RemoteControllerState * output)
{
  if (!input || !output) {
    return false;
  }
  // event
  output->event = input->event;
  // lx
  output->lx = input->lx;
  // ly
  output->ly = input->ly;
  // rx
  output->rx = input->rx;
  // ry
  output->ry = input->ry;
  // a
  output->a = input->a;
  // b
  output->b = input->b;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // lb
  output->lb = input->lb;
  // rb
  output->rb = input->rb;
  // lt
  output->lt = input->lt;
  // rt
  output->rt = input->rt;
  // ls
  output->ls = input->ls;
  // rs
  output->rs = input->rs;
  // back
  output->back = input->back;
  // start
  output->start = input->start;
  // hat_c
  output->hat_c = input->hat_c;
  // hat_u
  output->hat_u = input->hat_u;
  // hat_d
  output->hat_d = input->hat_d;
  // hat_l
  output->hat_l = input->hat_l;
  // hat_r
  output->hat_r = input->hat_r;
  // hat_lu
  output->hat_lu = input->hat_lu;
  // hat_ld
  output->hat_ld = input->hat_ld;
  // hat_ru
  output->hat_ru = input->hat_ru;
  // hat_rd
  output->hat_rd = input->hat_rd;
  // hat_pos
  output->hat_pos = input->hat_pos;
  return true;
}

booster_interface__msg__RemoteControllerState *
booster_interface__msg__RemoteControllerState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__msg__RemoteControllerState * msg = (booster_interface__msg__RemoteControllerState *)allocator.allocate(sizeof(booster_interface__msg__RemoteControllerState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(booster_interface__msg__RemoteControllerState));
  bool success = booster_interface__msg__RemoteControllerState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
booster_interface__msg__RemoteControllerState__destroy(booster_interface__msg__RemoteControllerState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    booster_interface__msg__RemoteControllerState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
booster_interface__msg__RemoteControllerState__Sequence__init(booster_interface__msg__RemoteControllerState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__msg__RemoteControllerState * data = NULL;

  if (size) {
    data = (booster_interface__msg__RemoteControllerState *)allocator.zero_allocate(size, sizeof(booster_interface__msg__RemoteControllerState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = booster_interface__msg__RemoteControllerState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        booster_interface__msg__RemoteControllerState__fini(&data[i - 1]);
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
booster_interface__msg__RemoteControllerState__Sequence__fini(booster_interface__msg__RemoteControllerState__Sequence * array)
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
      booster_interface__msg__RemoteControllerState__fini(&array->data[i]);
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

booster_interface__msg__RemoteControllerState__Sequence *
booster_interface__msg__RemoteControllerState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  booster_interface__msg__RemoteControllerState__Sequence * array = (booster_interface__msg__RemoteControllerState__Sequence *)allocator.allocate(sizeof(booster_interface__msg__RemoteControllerState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = booster_interface__msg__RemoteControllerState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
booster_interface__msg__RemoteControllerState__Sequence__destroy(booster_interface__msg__RemoteControllerState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    booster_interface__msg__RemoteControllerState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
booster_interface__msg__RemoteControllerState__Sequence__are_equal(const booster_interface__msg__RemoteControllerState__Sequence * lhs, const booster_interface__msg__RemoteControllerState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!booster_interface__msg__RemoteControllerState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
booster_interface__msg__RemoteControllerState__Sequence__copy(
  const booster_interface__msg__RemoteControllerState__Sequence * input,
  booster_interface__msg__RemoteControllerState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(booster_interface__msg__RemoteControllerState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    booster_interface__msg__RemoteControllerState * data =
      (booster_interface__msg__RemoteControllerState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!booster_interface__msg__RemoteControllerState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          booster_interface__msg__RemoteControllerState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!booster_interface__msg__RemoteControllerState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
