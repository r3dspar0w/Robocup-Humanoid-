# generated from rosidl_generator_py/resource/_idl.py.em
# with input from game_controller_interface:msg/RobotInfo.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotInfo(type):
    """Metaclass of message 'RobotInfo'."""

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
            module = import_type_support('game_controller_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'game_controller_interface.msg.RobotInfo')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_info
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_info
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_info
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_info
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_info

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotInfo(metaclass=Metaclass_RobotInfo):
    """Message class 'RobotInfo'."""

    __slots__ = [
        '_penalty',
        '_secs_till_unpenalised',
        '_number_of_warnings',
        '_yellow_card_count',
        '_red_card_count',
        '_goal_keeper',
    ]

    _fields_and_field_types = {
        'penalty': 'uint8',
        'secs_till_unpenalised': 'uint8',
        'number_of_warnings': 'uint8',
        'yellow_card_count': 'uint8',
        'red_card_count': 'uint8',
        'goal_keeper': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.penalty = kwargs.get('penalty', int())
        self.secs_till_unpenalised = kwargs.get('secs_till_unpenalised', int())
        self.number_of_warnings = kwargs.get('number_of_warnings', int())
        self.yellow_card_count = kwargs.get('yellow_card_count', int())
        self.red_card_count = kwargs.get('red_card_count', int())
        self.goal_keeper = kwargs.get('goal_keeper', bool())

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
        if self.penalty != other.penalty:
            return False
        if self.secs_till_unpenalised != other.secs_till_unpenalised:
            return False
        if self.number_of_warnings != other.number_of_warnings:
            return False
        if self.yellow_card_count != other.yellow_card_count:
            return False
        if self.red_card_count != other.red_card_count:
            return False
        if self.goal_keeper != other.goal_keeper:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def penalty(self):
        """Message field 'penalty'."""
        return self._penalty

    @penalty.setter
    def penalty(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'penalty' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'penalty' field must be an unsigned integer in [0, 255]"
        self._penalty = value

    @builtins.property
    def secs_till_unpenalised(self):
        """Message field 'secs_till_unpenalised'."""
        return self._secs_till_unpenalised

    @secs_till_unpenalised.setter
    def secs_till_unpenalised(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'secs_till_unpenalised' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'secs_till_unpenalised' field must be an unsigned integer in [0, 255]"
        self._secs_till_unpenalised = value

    @builtins.property
    def number_of_warnings(self):
        """Message field 'number_of_warnings'."""
        return self._number_of_warnings

    @number_of_warnings.setter
    def number_of_warnings(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'number_of_warnings' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'number_of_warnings' field must be an unsigned integer in [0, 255]"
        self._number_of_warnings = value

    @builtins.property
    def yellow_card_count(self):
        """Message field 'yellow_card_count'."""
        return self._yellow_card_count

    @yellow_card_count.setter
    def yellow_card_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'yellow_card_count' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'yellow_card_count' field must be an unsigned integer in [0, 255]"
        self._yellow_card_count = value

    @builtins.property
    def red_card_count(self):
        """Message field 'red_card_count'."""
        return self._red_card_count

    @red_card_count.setter
    def red_card_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'red_card_count' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'red_card_count' field must be an unsigned integer in [0, 255]"
        self._red_card_count = value

    @builtins.property
    def goal_keeper(self):
        """Message field 'goal_keeper'."""
        return self._goal_keeper

    @goal_keeper.setter
    def goal_keeper(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'goal_keeper' field must be of type 'bool'"
        self._goal_keeper = value
