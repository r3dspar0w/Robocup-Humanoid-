# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vision_interface:msg/CalParam.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CalParam(type):
    """Metaclass of message 'CalParam'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('vision_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vision_interface.msg.CalParam')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cal_param
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cal_param
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cal_param
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cal_param
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cal_param

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CalParam(metaclass=Metaclass_CalParam):
    """Message class 'CalParam'."""

    __slots__ = [
        '_pitch_compensation',
        '_yaw_compensation',
        '_z_compensation',
    ]

    _fields_and_field_types = {
        'pitch_compensation': 'float',
        'yaw_compensation': 'float',
        'z_compensation': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.pitch_compensation = kwargs.get('pitch_compensation', float())
        self.yaw_compensation = kwargs.get('yaw_compensation', float())
        self.z_compensation = kwargs.get('z_compensation', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.pitch_compensation != other.pitch_compensation:
            return False
        if self.yaw_compensation != other.yaw_compensation:
            return False
        if self.z_compensation != other.z_compensation:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pitch_compensation(self):
        """Message field 'pitch_compensation'."""
        return self._pitch_compensation

    @pitch_compensation.setter
    def pitch_compensation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pitch_compensation' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pitch_compensation' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pitch_compensation = value

    @builtins.property
    def yaw_compensation(self):
        """Message field 'yaw_compensation'."""
        return self._yaw_compensation

    @yaw_compensation.setter
    def yaw_compensation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw_compensation' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw_compensation' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw_compensation = value

    @builtins.property
    def z_compensation(self):
        """Message field 'z_compensation'."""
        return self._z_compensation

    @z_compensation.setter
    def z_compensation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'z_compensation' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'z_compensation' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._z_compensation = value
