// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from game_controller_interface:msg/GameControlData.idl
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
#include "game_controller_interface/msg/detail/game_control_data__struct.h"
#include "game_controller_interface/msg/detail/game_control_data__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "game_controller_interface/msg/detail/team_info__functions.h"
// end nested array functions include
bool game_controller_interface__msg__team_info__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * game_controller_interface__msg__team_info__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool game_controller_interface__msg__game_control_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[65];
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
    assert(strncmp("game_controller_interface.msg._game_control_data.GameControlData", full_classname_dest, 64) == 0);
  }
  game_controller_interface__msg__GameControlData * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_UINT8);
      Py_ssize_t size = 4;
      uint8_t * dest = ros_message->header;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint8_t tmp = *(npy_uint8 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // version
    PyObject * field = PyObject_GetAttrString(_pymsg, "version");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->version = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // packet_number
    PyObject * field = PyObject_GetAttrString(_pymsg, "packet_number");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->packet_number = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // players_per_team
    PyObject * field = PyObject_GetAttrString(_pymsg, "players_per_team");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->players_per_team = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // game_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "game_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->game_type = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // state
    PyObject * field = PyObject_GetAttrString(_pymsg, "state");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->state = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // first_half
    PyObject * field = PyObject_GetAttrString(_pymsg, "first_half");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->first_half = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // kick_off_team
    PyObject * field = PyObject_GetAttrString(_pymsg, "kick_off_team");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->kick_off_team = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // secondary_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "secondary_state");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->secondary_state = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // secondary_state_info
    PyObject * field = PyObject_GetAttrString(_pymsg, "secondary_state_info");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_UINT8);
      Py_ssize_t size = 4;
      uint8_t * dest = ros_message->secondary_state_info;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint8_t tmp = *(npy_uint8 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // drop_in_team
    PyObject * field = PyObject_GetAttrString(_pymsg, "drop_in_team");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->drop_in_team = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // drop_in_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "drop_in_time");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->drop_in_time = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // secs_remaining
    PyObject * field = PyObject_GetAttrString(_pymsg, "secs_remaining");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->secs_remaining = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // secondary_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "secondary_time");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->secondary_time = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // teams
    PyObject * field = PyObject_GetAttrString(_pymsg, "teams");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'teams'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = 2;
    game_controller_interface__msg__TeamInfo * dest = ros_message->teams;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!game_controller_interface__msg__team_info__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
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
PyObject * game_controller_interface__msg__game_control_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GameControlData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("game_controller_interface.msg._game_control_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GameControlData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  game_controller_interface__msg__GameControlData * ros_message = (game_controller_interface__msg__GameControlData *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "header");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_UINT8);
    assert(sizeof(npy_uint8) == sizeof(uint8_t));
    npy_uint8 * dst = (npy_uint8 *)PyArray_GETPTR1(seq_field, 0);
    uint8_t * src = &(ros_message->header[0]);
    memcpy(dst, src, 4 * sizeof(uint8_t));
    Py_DECREF(field);
  }
  {  // version
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->version);
    {
      int rc = PyObject_SetAttrString(_pymessage, "version", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // packet_number
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->packet_number);
    {
      int rc = PyObject_SetAttrString(_pymessage, "packet_number", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // players_per_team
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->players_per_team);
    {
      int rc = PyObject_SetAttrString(_pymessage, "players_per_team", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // game_type
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->game_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "game_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // state
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->state);
    {
      int rc = PyObject_SetAttrString(_pymessage, "state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // first_half
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->first_half);
    {
      int rc = PyObject_SetAttrString(_pymessage, "first_half", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // kick_off_team
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->kick_off_team);
    {
      int rc = PyObject_SetAttrString(_pymessage, "kick_off_team", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // secondary_state
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->secondary_state);
    {
      int rc = PyObject_SetAttrString(_pymessage, "secondary_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // secondary_state_info
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "secondary_state_info");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_UINT8);
    assert(sizeof(npy_uint8) == sizeof(uint8_t));
    npy_uint8 * dst = (npy_uint8 *)PyArray_GETPTR1(seq_field, 0);
    uint8_t * src = &(ros_message->secondary_state_info[0]);
    memcpy(dst, src, 4 * sizeof(uint8_t));
    Py_DECREF(field);
  }
  {  // drop_in_team
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->drop_in_team);
    {
      int rc = PyObject_SetAttrString(_pymessage, "drop_in_team", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // drop_in_time
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->drop_in_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "drop_in_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // secs_remaining
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->secs_remaining);
    {
      int rc = PyObject_SetAttrString(_pymessage, "secs_remaining", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // secondary_time
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->secondary_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "secondary_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // teams
    PyObject * field = NULL;
    size_t size = 2;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    game_controller_interface__msg__TeamInfo * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->teams[i]);
      PyObject * pyitem = game_controller_interface__msg__team_info__convert_to_py(item);
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
      int rc = PyObject_SetAttrString(_pymessage, "teams", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
