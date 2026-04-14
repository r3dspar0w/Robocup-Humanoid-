// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vision_interface:msg/CalParam.idl
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
#include "vision_interface/msg/detail/cal_param__struct.h"
#include "vision_interface/msg/detail/cal_param__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool vision_interface__msg__cal_param__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[41];
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
    assert(strncmp("vision_interface.msg._cal_param.CalParam", full_classname_dest, 40) == 0);
  }
  vision_interface__msg__CalParam * ros_message = _ros_message;
  {  // pitch_compensation
    PyObject * field = PyObject_GetAttrString(_pymsg, "pitch_compensation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pitch_compensation = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // yaw_compensation
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw_compensation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw_compensation = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // z_compensation
    PyObject * field = PyObject_GetAttrString(_pymsg, "z_compensation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->z_compensation = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vision_interface__msg__cal_param__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CalParam */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vision_interface.msg._cal_param");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CalParam");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vision_interface__msg__CalParam * ros_message = (vision_interface__msg__CalParam *)raw_ros_message;
  {  // pitch_compensation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pitch_compensation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pitch_compensation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw_compensation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw_compensation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw_compensation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // z_compensation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->z_compensation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "z_compensation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
