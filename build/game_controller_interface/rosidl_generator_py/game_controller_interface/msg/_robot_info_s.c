// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from game_controller_interface:msg/RobotInfo.idl
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
#include "game_controller_interface/msg/detail/robot_info__struct.h"
#include "game_controller_interface/msg/detail/robot_info__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool game_controller_interface__msg__robot_info__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[52];
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
    assert(strncmp("game_controller_interface.msg._robot_info.RobotInfo", full_classname_dest, 51) == 0);
  }
  game_controller_interface__msg__RobotInfo * ros_message = _ros_message;
  {  // penalty
    PyObject * field = PyObject_GetAttrString(_pymsg, "penalty");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->penalty = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // secs_till_unpenalised
    PyObject * field = PyObject_GetAttrString(_pymsg, "secs_till_unpenalised");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->secs_till_unpenalised = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // number_of_warnings
    PyObject * field = PyObject_GetAttrString(_pymsg, "number_of_warnings");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->number_of_warnings = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // yellow_card_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "yellow_card_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->yellow_card_count = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // red_card_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "red_card_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->red_card_count = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // goal_keeper
    PyObject * field = PyObject_GetAttrString(_pymsg, "goal_keeper");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->goal_keeper = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * game_controller_interface__msg__robot_info__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RobotInfo */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("game_controller_interface.msg._robot_info");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RobotInfo");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  game_controller_interface__msg__RobotInfo * ros_message = (game_controller_interface__msg__RobotInfo *)raw_ros_message;
  {  // penalty
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->penalty);
    {
      int rc = PyObject_SetAttrString(_pymessage, "penalty", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // secs_till_unpenalised
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->secs_till_unpenalised);
    {
      int rc = PyObject_SetAttrString(_pymessage, "secs_till_unpenalised", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // number_of_warnings
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->number_of_warnings);
    {
      int rc = PyObject_SetAttrString(_pymessage, "number_of_warnings", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yellow_card_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->yellow_card_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yellow_card_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // red_card_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->red_card_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "red_card_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // goal_keeper
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->goal_keeper ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "goal_keeper", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
