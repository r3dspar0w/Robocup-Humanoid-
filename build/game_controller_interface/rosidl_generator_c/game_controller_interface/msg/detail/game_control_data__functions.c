// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from game_controller_interface:msg/GameControlData.idl
// generated code does not contain a copyright notice
#include "game_controller_interface/msg/detail/game_control_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `teams`
#include "game_controller_interface/msg/detail/team_info__functions.h"

bool
game_controller_interface__msg__GameControlData__init(game_controller_interface__msg__GameControlData * msg)
{
  if (!msg) {
    return false;
  }
  // header
  // version
  // packet_number
  // players_per_team
  // game_type
  // state
  // first_half
  // kick_off_team
  // secondary_state
  // secondary_state_info
  // drop_in_team
  // drop_in_time
  // secs_remaining
  // secondary_time
  // teams
  for (size_t i = 0; i < 2; ++i) {
    if (!game_controller_interface__msg__TeamInfo__init(&msg->teams[i])) {
      game_controller_interface__msg__GameControlData__fini(msg);
      return false;
    }
  }
  return true;
}

void
game_controller_interface__msg__GameControlData__fini(game_controller_interface__msg__GameControlData * msg)
{
  if (!msg) {
    return;
  }
  // header
  // version
  // packet_number
  // players_per_team
  // game_type
  // state
  // first_half
  // kick_off_team
  // secondary_state
  // secondary_state_info
  // drop_in_team
  // drop_in_time
  // secs_remaining
  // secondary_time
  // teams
  for (size_t i = 0; i < 2; ++i) {
    game_controller_interface__msg__TeamInfo__fini(&msg->teams[i]);
  }
}

bool
game_controller_interface__msg__GameControlData__are_equal(const game_controller_interface__msg__GameControlData * lhs, const game_controller_interface__msg__GameControlData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->header[i] != rhs->header[i]) {
      return false;
    }
  }
  // version
  if (lhs->version != rhs->version) {
    return false;
  }
  // packet_number
  if (lhs->packet_number != rhs->packet_number) {
    return false;
  }
  // players_per_team
  if (lhs->players_per_team != rhs->players_per_team) {
    return false;
  }
  // game_type
  if (lhs->game_type != rhs->game_type) {
    return false;
  }
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  // first_half
  if (lhs->first_half != rhs->first_half) {
    return false;
  }
  // kick_off_team
  if (lhs->kick_off_team != rhs->kick_off_team) {
    return false;
  }
  // secondary_state
  if (lhs->secondary_state != rhs->secondary_state) {
    return false;
  }
  // secondary_state_info
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->secondary_state_info[i] != rhs->secondary_state_info[i]) {
      return false;
    }
  }
  // drop_in_team
  if (lhs->drop_in_team != rhs->drop_in_team) {
    return false;
  }
  // drop_in_time
  if (lhs->drop_in_time != rhs->drop_in_time) {
    return false;
  }
  // secs_remaining
  if (lhs->secs_remaining != rhs->secs_remaining) {
    return false;
  }
  // secondary_time
  if (lhs->secondary_time != rhs->secondary_time) {
    return false;
  }
  // teams
  for (size_t i = 0; i < 2; ++i) {
    if (!game_controller_interface__msg__TeamInfo__are_equal(
        &(lhs->teams[i]), &(rhs->teams[i])))
    {
      return false;
    }
  }
  return true;
}

bool
game_controller_interface__msg__GameControlData__copy(
  const game_controller_interface__msg__GameControlData * input,
  game_controller_interface__msg__GameControlData * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  for (size_t i = 0; i < 4; ++i) {
    output->header[i] = input->header[i];
  }
  // version
  output->version = input->version;
  // packet_number
  output->packet_number = input->packet_number;
  // players_per_team
  output->players_per_team = input->players_per_team;
  // game_type
  output->game_type = input->game_type;
  // state
  output->state = input->state;
  // first_half
  output->first_half = input->first_half;
  // kick_off_team
  output->kick_off_team = input->kick_off_team;
  // secondary_state
  output->secondary_state = input->secondary_state;
  // secondary_state_info
  for (size_t i = 0; i < 4; ++i) {
    output->secondary_state_info[i] = input->secondary_state_info[i];
  }
  // drop_in_team
  output->drop_in_team = input->drop_in_team;
  // drop_in_time
  output->drop_in_time = input->drop_in_time;
  // secs_remaining
  output->secs_remaining = input->secs_remaining;
  // secondary_time
  output->secondary_time = input->secondary_time;
  // teams
  for (size_t i = 0; i < 2; ++i) {
    if (!game_controller_interface__msg__TeamInfo__copy(
        &(input->teams[i]), &(output->teams[i])))
    {
      return false;
    }
  }
  return true;
}

game_controller_interface__msg__GameControlData *
game_controller_interface__msg__GameControlData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  game_controller_interface__msg__GameControlData * msg = (game_controller_interface__msg__GameControlData *)allocator.allocate(sizeof(game_controller_interface__msg__GameControlData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(game_controller_interface__msg__GameControlData));
  bool success = game_controller_interface__msg__GameControlData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
game_controller_interface__msg__GameControlData__destroy(game_controller_interface__msg__GameControlData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    game_controller_interface__msg__GameControlData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
game_controller_interface__msg__GameControlData__Sequence__init(game_controller_interface__msg__GameControlData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  game_controller_interface__msg__GameControlData * data = NULL;

  if (size) {
    data = (game_controller_interface__msg__GameControlData *)allocator.zero_allocate(size, sizeof(game_controller_interface__msg__GameControlData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = game_controller_interface__msg__GameControlData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        game_controller_interface__msg__GameControlData__fini(&data[i - 1]);
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
game_controller_interface__msg__GameControlData__Sequence__fini(game_controller_interface__msg__GameControlData__Sequence * array)
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
      game_controller_interface__msg__GameControlData__fini(&array->data[i]);
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

game_controller_interface__msg__GameControlData__Sequence *
game_controller_interface__msg__GameControlData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  game_controller_interface__msg__GameControlData__Sequence * array = (game_controller_interface__msg__GameControlData__Sequence *)allocator.allocate(sizeof(game_controller_interface__msg__GameControlData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = game_controller_interface__msg__GameControlData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
game_controller_interface__msg__GameControlData__Sequence__destroy(game_controller_interface__msg__GameControlData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    game_controller_interface__msg__GameControlData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
game_controller_interface__msg__GameControlData__Sequence__are_equal(const game_controller_interface__msg__GameControlData__Sequence * lhs, const game_controller_interface__msg__GameControlData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!game_controller_interface__msg__GameControlData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
game_controller_interface__msg__GameControlData__Sequence__copy(
  const game_controller_interface__msg__GameControlData__Sequence * input,
  game_controller_interface__msg__GameControlData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(game_controller_interface__msg__GameControlData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    game_controller_interface__msg__GameControlData * data =
      (game_controller_interface__msg__GameControlData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!game_controller_interface__msg__GameControlData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          game_controller_interface__msg__GameControlData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!game_controller_interface__msg__GameControlData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
