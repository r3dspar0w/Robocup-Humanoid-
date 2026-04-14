# generated from rosidl_generator_py/resource/_idl.py.em
# with input from booster_interface:msg/FallDownState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FallDownState(type):
    """Metaclass of message 'FallDownState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'IS_READY': 0,
        'IS_FALLING': 1,
        'HAS_FALLEN': 2,
        'IS_GETTING_UP': 3,
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
                'booster_interface.msg.FallDownState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__fall_down_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__fall_down_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__fall_down_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__fall_down_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__fall_down_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'IS_READY': cls.__constants['IS_READY'],
            'IS_FALLING': cls.__constants['IS_FALLING'],
            'HAS_FALLEN': cls.__constants['HAS_FALLEN'],
            'IS_GETTING_UP': cls.__constants['IS_GETTING_UP'],
        }

    @property
    def IS_READY(self):
        """Message constant 'IS_READY'."""
        return Metaclass_FallDownState.__constants['IS_READY']

    @property
    def IS_FALLING(self):
        """Message constant 'IS_FALLING'."""
        return Metaclass_FallDownState.__constants['IS_FALLING']

    @property
    def HAS_FALLEN(self):
        """Message constant 'HAS_FALLEN'."""
        return Metaclass_FallDownState.__constants['HAS_FALLEN']

    @property
    def IS_GETTING_UP(self):
        """Message constant 'IS_GETTING_UP'."""
        return Metaclass_FallDownState.__constants['IS_GETTING_UP']


class FallDownState(metaclass=Metaclass_FallDownState):
    """
    Message class 'FallDownState'.

    Constants:
      IS_READY
      IS_FALLING
      HAS_FALLEN
      IS_GETTING_UP
    """

    __slots__ = [
        '_fall_down_state',
        '_is_recovery_available',
    ]

    _fields_and_field_types = {
        'fall_down_state': 'uint32',
        'is_recovery_available': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.fall_down_state = kwargs.get('fall_down_state', int())
        self.is_recovery_available = kwargs.get('is_recovery_available', bool())

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
        if self.fall_down_state != other.fall_down_state:
            return False
        if self.is_recovery_available != other.is_recovery_available:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def fall_down_state(self):
        """Message field 'fall_down_state'."""
        return self._fall_down_state

    @fall_down_state.setter
    def fall_down_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'fall_down_state' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'fall_down_state' field must be an unsigned integer in [0, 4294967295]"
        self._fall_down_state = value

    @builtins.property
    def is_recovery_available(self):
        """Message field 'is_recovery_available'."""
        return self._is_recovery_available

    @is_recovery_available.setter
    def is_recovery_available(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_recovery_available' field must be of type 'bool'"
        self._is_recovery_available = value
