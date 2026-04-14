# generated from rosidl_generator_py/resource/_idl.py.em
# with input from booster_interface:msg/HandCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_HandCommand(type):
    """Metaclass of message 'HandCommand'."""

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
            module = import_type_support('booster_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'booster_interface.msg.HandCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__hand_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__hand_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__hand_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__hand_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__hand_command

            from booster_interface.msg import HandParam
            if HandParam.__class__._TYPE_SUPPORT is None:
                HandParam.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HandCommand(metaclass=Metaclass_HandCommand):
    """Message class 'HandCommand'."""

    __slots__ = [
        '_hand_param',
        '_force_mode',
        '_hand_index',
        '_hand_type',
    ]

    _fields_and_field_types = {
        'hand_param': 'sequence<booster_interface/HandParam>',
        'force_mode': 'int32',
        'hand_index': 'int32',
        'hand_type': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['booster_interface', 'msg'], 'HandParam')),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.hand_param = kwargs.get('hand_param', [])
        self.force_mode = kwargs.get('force_mode', int())
        self.hand_index = kwargs.get('hand_index', int())
        self.hand_type = kwargs.get('hand_type', int())

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
        if self.hand_param != other.hand_param:
            return False
        if self.force_mode != other.force_mode:
            return False
        if self.hand_index != other.hand_index:
            return False
        if self.hand_type != other.hand_type:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def hand_param(self):
        """Message field 'hand_param'."""
        return self._hand_param

    @hand_param.setter
    def hand_param(self, value):
        if __debug__:
            from booster_interface.msg import HandParam
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, HandParam) for v in value) and
                 True), \
                "The 'hand_param' field must be a set or sequence and each value of type 'HandParam'"
        self._hand_param = value

    @builtins.property
    def force_mode(self):
        """Message field 'force_mode'."""
        return self._force_mode

    @force_mode.setter
    def force_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'force_mode' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'force_mode' field must be an integer in [-2147483648, 2147483647]"
        self._force_mode = value

    @builtins.property
    def hand_index(self):
        """Message field 'hand_index'."""
        return self._hand_index

    @hand_index.setter
    def hand_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'hand_index' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'hand_index' field must be an integer in [-2147483648, 2147483647]"
        self._hand_index = value

    @builtins.property
    def hand_type(self):
        """Message field 'hand_type'."""
        return self._hand_type

    @hand_type.setter
    def hand_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'hand_type' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'hand_type' field must be an integer in [-2147483648, 2147483647]"
        self._hand_type = value
