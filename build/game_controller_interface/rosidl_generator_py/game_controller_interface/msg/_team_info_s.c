// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from game_controller_interface:msg/TeamInfo.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "game_controller_interface/msg/detail/team_info__struct.h"
#include "game_controller_interface/msg/detail/team_info__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "game_controller_interface/msg/detail/robot_info__functions.h"
// end nested array functions include
bool game_controller_interface__msg__robot_info__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * game_controller_interface__msg__robot_info__convert_to_py(void * raw_ros_message);
bool game_controller_interface__msg__robot_info__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * game_controller_interface__msg__robot_info__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool game_controller_interface__msg__team_info__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[50];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("game_controller_interface.msg._team_info.TeamInfo", full_classname_dest, 49) == 0);
  }
  game_controller_interface__msg__TeamInfo * ros_message = _ros_message;
  {  // team_number
    PyObject * field = PyObject_GetAttrString(_pymsg, "team_number");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->team_number = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // field_player_colour
    PyObject * field = PyObject_GetAttrString(_pymsg, "field_player_colour");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->field_player_colour = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // score
    PyObject * field = PyObject_GetAttrString(_pymsg, "score");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->score = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // penalty_shot
    PyObject * field = PyObject_GetAttrString(_pymsg, "penalty_shot");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->penalty_shot = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // single_shots
    PyObject * field = PyObject_GetAttrString(_pymsg, "single_shots");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->single_shots = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // coach_sequence
    PyObject * field = PyObject_GetAttrString(_pymsg, "coach_sequence");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->coach_sequence = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // coach_message
    PyObject * field = PyObject_GetAttrString(_pymsg, "coach_message");
    if (!field) {
      return false;
    }
    if (PyObject_CheckBuffer(field)) {
      // Optimization for converting arrays of primitives
      Py_buffer view;
      int rc = PyObject_GetBuffer(field, &view, PyBUF_SIMPLE);
      if (rc < 0) {
        Py_DECREF(field);
        return false;
      }
      Py_ssize_t size = view.len / sizeof(uint8_t);
      if (!rosidl_runtime_c__uint8__Sequence__init(&(ros_message->coach_message), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create uint8__Sequence ros_message");
        PyBuffer_Release(&view);
        Py_DECREF(field);
        return false;
      }
      uint8_t * dest = ros_message->coach_message.data;
      rc = PyBuffer_ToContiguous(dest, &view, view.len, 'C');
      if (rc < 0) {
        PyBuffer_Release(&view);
        Py_DECREF(field);
        return false;
      }
      PyBuffer_Release(&view);
    } else {
      PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'coach_message'");
      if (!seq_field) {
        Py_DECREF(field);
        return false;
      }
      Py_ssize_t size = PySequence_Size(field);
      if (-1 == size) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      if (!rosidl_runtime_c__uint8__Sequence__init(&(ros_message->coach_message), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create uint8__Sequence ros_message");
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      uint8_t * dest = ros_message->coach_message.data;
      for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject * item = PySequence_Fast_GET_ITEM(seq_field, i);
        if (!item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        assert(PyLong_Check(item));
        uint8_t tmp = (uint8_t)PyLong_AsUnsignedLong(item);

        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // coach
    PyObject * field = PyObject_GetAttrString(_pymsg, "coach");
    if (!field) {
      return false;
    }
    if (!game_controller_interface__msg__robot_info__convert_from_py(field, &ros_message->coach)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // players
    PyObject * field = PyObject_GetAttrString(_pymsg, "players");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'players'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!game_controller_interface__msg__RobotInfo__Sequence__init(&(ros_message->players), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create game_controller_interface__msg__RobotInfo__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    game_controller_interface__msg__RobotInfo * dest = ros_message->players.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!game_controller_interface__msg__robot_info__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * game_controller_interface__msg__team_info__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TeamInfo */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("game_controller_interface.msg._team_info");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TeamInfo");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  game_controller_interface__msg__TeamInfo * ros_message = (game_controller_interface__msg__TeamInfo *)raw_ros_message;
  {  // team_number
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->team_number);
    {
      int rc = PyObject_SetAttrString(_pymessage, "team_number", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // field_player_colour
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->field_player_colour);
    {
      int rc = PyObject_SetAttrString(_pymessage, "field_player_colour", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // score
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->score);
    {
      int rc = PyObject_SetAttrString(_pymessage, "score", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // penalty_shot
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->penalty_shot);
    {
      int rc = PyObject_SetAttrString(_pymessage, "penalty_shot", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // single_shots
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->single_shots);
    {
      int rc = PyObject_SetAttrString(_pymessage, "single_shots", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // coach_sequence
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->coach_sequence);
    {
      int rc = PyObject_SetAttrString(_pymessage, "coach_sequence", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // coach_message
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "coach_message");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "array.array") == 0);
    // ensure that itemsize matches the sizeof of the ROS message field
    PyObject * itemsize_attr = PyObject_GetAttrString(field, "itemsize");
    assert(itemsize_attr != NULL);
    size_t itemsize = PyLong_AsSize_t(itemsize_attr);
    Py_DECREF(itemsize_attr);
    if (itemsize != sizeof(uint8_t)) {
      PyErr_SetString(PyExc_RuntimeError, "itemsize doesn't match expectation");
      Py_DECREF(field);
      return NULL;
    }
    // clear the array, poor approach to remove potential default values
    Py_ssize_t length = PyObject_Length(field);
    if (-1 == length) {
      Py_DECREF(field);
      return NULL;
    }
    if (length > 0) {
      PyObject * pop = PyObject_GetAttrString(field, "pop");
      assert(pop != NULL);
      for (Py_ssize_t i = 0; i < length; ++i) {
        PyObject * ret = PyObject_CallFunctionObjArgs(pop, NULL);
        if (!ret) {
          Py_DECREF(pop);
          Py_DECREF(field);
          return NULL;
        }
        Py_DECREF(ret);
      }
      Py_DECREF(pop);
    }
    if (ros_message->coach_message.size > 0) {
      // populating the array.array using the frombytes method
      PyObject * frombytes = PyObject_GetAttrString(field, "frombytes");
      assert(frombytes != NULL);
      uint8_t * src = &(ros_message->coach_message.data[0]);
      PyObject * data = PyBytes_FromStringAndSize((const char *)src, ros_message->coach_message.size * sizeof(uint8_t));
      assert(data != NULL);
      PyObject * ret = PyObject_CallFunctionObjArgs(frombytes, data, NULL);
      Py_DECREF(data);
      Py_DECREF(frombytes);
      if (!ret) {
        Py_DECREF(field);
        return NULL;
      }
      Py_DECREF(ret);
    }
    Py_DECREF(field);
  }
  {  // coach
    PyObject * field = NULL;
    field = game_controller_interface__msg__robot_info__convert_to_py(&ros_message->coach);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "coach", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // players
    PyObject * field = NULL;
    size_t size = ros_message->players.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    game_controller_interface__msg__RobotInfo * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->players.data[i]);
      PyObject * pyitem = game_controller_interface__msg__robot_info__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "players", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
