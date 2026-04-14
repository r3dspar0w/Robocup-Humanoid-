// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from game_controller_interface:msg/TeamInfo.idl
// generated code does not contain a copyright notice
#include "game_controller_interface/msg/detail/team_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `coach_message`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `coach`
// Member `players`
#include "game_controller_interface/msg/detail/robot_info__functions.h"

bool
game_controller_interface__msg__TeamInfo__init(game_controller_interface__msg__TeamInfo * msg)
{
  if (!msg) {
    return false;
  }
  // team_number
  // field_player_colour
  // score
  // penalty_shot
  // single_shots
  // coach_sequence
  // coach_message
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->coach_message, 0)) {
    game_controller_interface__msg__TeamInfo__fini(msg);
    return false;
  }
  // coach
  if (!game_controller_interface__msg__RobotInfo__init(&msg->coach)) {
    game_controller_interface__msg__TeamInfo__fini(msg);
    return false;
  }
  // players
  if (!game_controller_interface__msg__RobotInfo__Sequence__init(&msg->players, 0)) {
    game_controller_interface__msg__TeamInfo__fini(msg);
    return false;
  }
  return true;
}

void
game_controller_interface__msg__TeamInfo__fini(game_controller_interface__msg__TeamInfo * msg)
{
  if (!msg) {
    return;
  }
  // team_number
  // field_player_colour
  // score
  // penalty_shot
  // single_shots
  // coach_sequence
  // coach_message
  rosidl_runtime_c__uint8__Sequence__fini(&msg->coach_message);
  // coach
  game_controller_interface__msg__RobotInfo__fini(&msg->coach);
  // players
  game_controller_interface__msg__RobotInfo__Sequence__fini(&msg->players);
}

bool
game_controller_interface__msg__TeamInfo__are_equal(const game_controller_interface__msg__TeamInfo * lhs, const game_controller_interface__msg__TeamInfo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // team_number
  if (lhs->team_number != rhs->team_number) {
    return false;
  }
  // field_player_colour
  if (lhs->field_player_colour != rhs->field_player_colour) {
    return false;
  }
  // score
  if (lhs->score != rhs->score) {
    return false;
  }
  // penalty_shot
  if (lhs->penalty_shot != rhs->penalty_shot) {
    return false;
  }
  // single_shots
  if (lhs->single_shots != rhs->single_shots) {
    return false;
  }
  // coach_sequence
  if (lhs->coach_sequence != rhs->coach_sequence) {
    return false;
  }
  // coach_message
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->coach_message), &(rhs->coach_message)))
  {
    return false;
  }
  // coach
  if (!game_controller_interface__msg__RobotInfo__are_equal(
      &(lhs->coach), &(rhs->coach)))
  {
    return false;
  }
  // players
  if (!game_controller_interface__msg__RobotInfo__Sequence__are_equal(
      &(lhs->players), &(rhs->players)))
  {
    return false;
  }
  return true;
}

bool
game_controller_interface__msg__TeamInfo__copy(
  const game_controller_interface__msg__TeamInfo * input,
  game_controller_interface__msg__TeamInfo * output)
{
  if (!input || !output) {
    return false;
  }
  // team_number
  output->team_number = input->team_number;
  // field_player_colour
  output->field_player_colour = input->field_player_colour;
  // score
  output->score = input->score;
  // penalty_shot
  output->penalty_shot = input->penalty_shot;
  // single_shots
  output->single_shots = input->single_shots;
  // coach_sequence
  output->coach_sequence = input->coach_sequence;
  // coach_message
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->coach_message), &(output->coach_message)))
  {
    return false;
  }
  // coach
  if (!game_controller_interface__msg__RobotInfo__copy(
      &(input->coach), &(output->coach)))
  {
    return false;
  }
  // players
  if (!game_controller_interface__msg__RobotInfo__Sequence__copy(
      &(input->players), &(output->players)))
  {
    return false;
  }
  return true;
}

game_controller_interface__msg__TeamInfo *
game_controller_interface__msg__TeamInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  game_controller_interface__msg__TeamInfo * msg = (game_controller_interface__msg__TeamInfo *)allocator.allocate(sizeof(game_controller_interface__msg__TeamInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(game_controller_interface__msg__TeamInfo));
  bool success = game_controller_interface__msg__TeamInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
game_controller_interface__msg__TeamInfo__destroy(game_controller_interface__msg__TeamInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    game_controller_interface__msg__TeamInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
game_controller_interface__msg__TeamInfo__Sequence__init(game_controller_interface__msg__TeamInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  game_controller_interface__msg__TeamInfo * data = NULL;

  if (size) {
    data = (game_controller_interface__msg__TeamInfo *)allocator.zero_allocate(size, sizeof(game_controller_interface__msg__TeamInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = game_controller_interface__msg__TeamInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        game_controller_interface__msg__TeamInfo__fini(&data[i - 1]);
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
game_controller_interface__msg__TeamInfo__Sequence__fini(game_controller_interface__msg__TeamInfo__Sequence * array)
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
      game_controller_interface__msg__TeamInfo__fini(&array->data[i]);
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

game_controller_interface__msg__TeamInfo__Sequence *
game_controller_interface__msg__TeamInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  game_controller_interface__msg__TeamInfo__Sequence * array = (game_controller_interface__msg__TeamInfo__Sequence *)allocator.allocate(sizeof(game_controller_interface__msg__TeamInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = game_controller_interface__msg__TeamInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
game_controller_interface__msg__TeamInfo__Sequence__destroy(game_controller_interface__msg__TeamInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    game_controller_interface__msg__TeamInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
game_controller_interface__msg__TeamInfo__Sequence__are_equal(const game_controller_interface__msg__TeamInfo__Sequence * lhs, const game_controller_interface__msg__TeamInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!game_controller_interface__msg__TeamInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
game_controller_interface__msg__TeamInfo__Sequence__copy(
  const game_controller_interface__msg__TeamInfo__Sequence * input,
  game_controller_interface__msg__TeamInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(game_controller_interface__msg__TeamInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    game_controller_interface__msg__TeamInfo * data =
      (game_controller_interface__msg__TeamInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!game_controller_interface__msg__TeamInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          game_controller_interface__msg__TeamInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!game_controller_interface__msg__TeamInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
