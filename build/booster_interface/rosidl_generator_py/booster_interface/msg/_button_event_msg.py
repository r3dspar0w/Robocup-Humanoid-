# generated from rosidl_generator_py/resource/_idl.py.em
# with input from booster_interface:msg/ButtonEventMsg.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ButtonEventMsg(type):
    """Metaclass of message 'ButtonEventMsg'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'PRESS_DOWN': 0,
        'PRESS_UP': 1,
        'SINGLE_CLICK': 0,
        'DOUBLE_CLICK': 1,
        'TRIPLE_CLICK': 0,
        'LONG_PRESS_START': 1,
        'LONG_PRESS_HOLD': 0,
        'LONG_PRESS_END': 1,
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
                'booster_interface.msg.ButtonEventMsg')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__button_event_msg
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__button_event_msg
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__button_event_msg
            cls._TYPE_SUPPORT = module.type_support_msg__msg__button_event_msg
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__button_event_msg

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'PRESS_DOWN': cls.__constants['PRESS_DOWN'],
            'PRESS_UP': cls.__constants['PRESS_UP'],
            'SINGLE_CLICK': cls.__constants['SINGLE_CLICK'],
            'DOUBLE_CLICK': cls.__constants['DOUBLE_CLICK'],
            'TRIPLE_CLICK': cls.__constants['TRIPLE_CLICK'],
            'LONG_PRESS_START': cls.__constants['LONG_PRESS_START'],
            'LONG_PRESS_HOLD': cls.__constants['LONG_PRESS_HOLD'],
            'LONG_PRESS_END': cls.__constants['LONG_PRESS_END'],
        }

    @property
    def PRESS_DOWN(self):
        """Message constant 'PRESS_DOWN'."""
        return Metaclass_ButtonEventMsg.__constants['PRESS_DOWN']

    @property
    def PRESS_UP(self):
        """Message constant 'PRESS_UP'."""
        return Metaclass_ButtonEventMsg.__constants['PRESS_UP']

    @property
    def SINGLE_CLICK(self):
        """Message constant 'SINGLE_CLICK'."""
        return Metaclass_ButtonEventMsg.__constants['SINGLE_CLICK']

    @property
    def DOUBLE_CLICK(self):
        """Message constant 'DOUBLE_CLICK'."""
        return Metaclass_ButtonEventMsg.__constants['DOUBLE_CLICK']

    @property
    def TRIPLE_CLICK(self):
        """Message constant 'TRIPLE_CLICK'."""
        return Metaclass_ButtonEventMsg.__constants['TRIPLE_CLICK']

    @property
    def LONG_PRESS_START(self):
        """Message constant 'LONG_PRESS_START'."""
        return Metaclass_ButtonEventMsg.__constants['LONG_PRESS_START']

    @property
    def LONG_PRESS_HOLD(self):
        """Message constant 'LONG_PRESS_HOLD'."""
        return Metaclass_ButtonEventMsg.__constants['LONG_PRESS_HOLD']

    @property
    def LONG_PRESS_END(self):
        """Message constant 'LONG_PRESS_END'."""
        return Metaclass_ButtonEventMsg.__constants['LONG_PRESS_END']


class ButtonEventMsg(metaclass=Metaclass_ButtonEventMsg):
    """
    Message class 'ButtonEventMsg'.

    Constants:
      PRESS_DOWN
      PRESS_UP
      SINGLE_CLICK
      DOUBLE_CLICK
      TRIPLE_CLICK
      LONG_PRESS_START
      LONG_PRESS_HOLD
      LONG_PRESS_END
    """

    __slots__ = [
        '_event',
        '_button',
    ]

    _fields_and_field_types = {
        'event': 'int8',
        'button': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.event = kwargs.get('event', int())
        self.button = kwargs.get('button', int())

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
        if self.event != other.event:
            return False
        if self.button != other.button:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def event(self):
        """Message field 'event'."""
        return self._event

    @event.setter
    def event(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'event' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'event' field must be an integer in [-128, 127]"
        self._event = value

    @builtins.property
    def button(self):
        """Message field 'button'."""
        return self._button

    @button.setter
    def button(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'button' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'button' field must be an integer in [-2147483648, 2147483647]"
        self._button = value
