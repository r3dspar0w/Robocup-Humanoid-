// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from game_controller_interface:msg/RobotInfo.idl
// generated code does not contain a copyright notice
#include "game_controller_interface/msg/detail/robot_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
game_controller_interface__msg__RobotInfo__init(game_controller_interface__msg__RobotInfo * msg)
{
  if (!msg) {
    return false;
  }
  // penalty
  // secs_till_unpenalised
  // number_of_warnings
  // yellow_card_count
  // red_card_count
  // goal_keeper
  return true;
}

void
game_controller_interface__msg__RobotInfo__fini(game_controller_interface__msg__RobotInfo * msg)
{
  if (!msg) {
    return;
  }
  // penalty
  // secs_till_unpenalised
  // number_of_warnings
  // yellow_card_count
  // red_card_count
  // goal_keeper
}

bool
game_controller_interface__msg__RobotInfo__are_equal(const game_controller_interface__msg__RobotInfo * lhs, const game_controller_interface__msg__RobotInfo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // penalty
  if (lhs->penalty != rhs->penalty) {
    return false;
  }
  // secs_till_unpenalised
  if (lhs->secs_till_unpenalised != rhs->secs_till_unpenalised) {
    return false;
  }
  // number_of_warnings
  if (lhs->number_of_warnings != rhs->number_of_warnings) {
    return false;
  }
  // yellow_card_count
  if (lhs->yellow_card_count != rhs->yellow_card_count) {
    return false;
  }
  // red_card_count
  if (lhs->red_card_count != rhs->red_card_count) {
    return false;
  }
  // goal_keeper
  if (lhs->goal_keeper != rhs->goal_keeper) {
    return false;
  }
  return true;
}

bool
game_controller_interface__msg__RobotInfo__copy(
  const game_controller_interface__msg__RobotInfo * input,
  game_controller_interface__msg__RobotInfo * output)
{
  if (!input || !output) {
    return false;
  }
  // penalty
  output->penalty = input->penalty;
  // secs_till_unpenalised
  output->secs_till_unpenalised = input->secs_till_unpenalised;
  // number_of_warnings
  output->number_of_warnings = input->number_of_warnings;
  // yellow_card_count
  output->yellow_card_count = input->yellow_card_count;
  // red_card_count
  output->red_card_count = input->red_card_count;
  // goal_keeper
  output->goal_keeper = input->goal_keeper;
  return true;
}

game_controller_interface__msg__RobotInfo *
game_controller_interface__msg__RobotInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  game_controller_interface__msg__RobotInfo * msg = (game_controller_interface__msg__RobotInfo *)allocator.allocate(sizeof(game_controller_interface__msg__RobotInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(game_controller_interface__msg__RobotInfo));
  bool success = game_controller_interface__msg__RobotInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
game_controller_interface__msg__RobotInfo__destroy(game_controller_interface__msg__RobotInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    game_controller_interface__msg__RobotInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
game_controller_interface__msg__RobotInfo__Sequence__init(game_controller_interface__msg__RobotInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  game_controller_interface__msg__RobotInfo * data = NULL;

  if (size) {
    data = (game_controller_interface__msg__RobotInfo *)allocator.zero_allocate(size, sizeof(game_controller_interface__msg__RobotInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = game_controller_interface__msg__RobotInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        game_controller_interface__msg__RobotInfo__fini(&data[i - 1]);
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
game_controller_interface__msg__RobotInfo__Sequence__fini(game_controller_interface__msg__RobotInfo__Sequence * array)
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
      game_controller_interface__msg__RobotInfo__fini(&array->data[i]);
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

game_controller_interface__msg__RobotInfo__Sequence *
game_controller_interface__msg__RobotInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  game_controller_interface__msg__RobotInfo__Sequence * array = (game_controller_interface__msg__RobotInfo__Sequence *)allocator.allocate(sizeof(game_controller_interface__msg__RobotInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = game_controller_interface__msg__RobotInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
game_controller_interface__msg__RobotInfo__Sequence__destroy(game_controller_interface__msg__RobotInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    game_controller_interface__msg__RobotInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
game_controller_interface__msg__RobotInfo__Sequence__are_equal(const game_controller_interface__msg__RobotInfo__Sequence * lhs, const game_controller_interface__msg__RobotInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!game_controller_interface__msg__RobotInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
game_controller_interface__msg__RobotInfo__Sequence__copy(
  const game_controller_interface__msg__RobotInfo__Sequence * input,
  game_controller_interface__msg__RobotInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(game_controller_interface__msg__RobotInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    game_controller_interface__msg__RobotInfo * data =
      (game_controller_interface__msg__RobotInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!game_controller_interface__msg__RobotInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          game_controller_interface__msg__RobotInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!game_controller_interface__msg__RobotInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
