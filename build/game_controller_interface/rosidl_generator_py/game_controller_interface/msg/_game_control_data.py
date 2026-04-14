# generated from rosidl_generator_py/resource/_idl.py.em
# with input from game_controller_interface:msg/GameControlData.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'header'
# Member 'secondary_state_info'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GameControlData(type):
    """Metaclass of message 'GameControlData'."""

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
                'game_controller_interface.msg.GameControlData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__game_control_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__game_control_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__game_control_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__game_control_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__game_control_data

            from game_controller_interface.msg import TeamInfo
            if TeamInfo.__class__._TYPE_SUPPORT is None:
                TeamInfo.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GameControlData(metaclass=Metaclass_GameControlData):
    """Message class 'GameControlData'."""

    __slots__ = [
        '_header',
        '_version',
        '_packet_number',
        '_players_per_team',
        '_game_type',
        '_state',
        '_first_half',
        '_kick_off_team',
        '_secondary_state',
        '_secondary_state_info',
        '_drop_in_team',
        '_drop_in_time',
        '_secs_remaining',
        '_secondary_time',
        '_teams',
    ]

    _fields_and_field_types = {
        'header': 'uint8[4]',
        'version': 'uint16',
        'packet_number': 'uint8',
        'players_per_team': 'uint8',
        'game_type': 'uint8',
        'state': 'uint8',
        'first_half': 'uint8',
        'kick_off_team': 'uint8',
        'secondary_state': 'uint8',
        'secondary_state_info': 'uint8[4]',
        'drop_in_team': 'uint8',
        'drop_in_time': 'uint16',
        'secs_remaining': 'uint16',
        'secondary_time': 'uint16',
        'teams': 'game_controller_interface/TeamInfo[2]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 4),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 4),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.NamespacedType(['game_controller_interface', 'msg'], 'TeamInfo'), 2),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        if 'header' not in kwargs:
            self.header = numpy.zeros(4, dtype=numpy.uint8)
        else:
            self.header = numpy.array(kwargs.get('header'), dtype=numpy.uint8)
            assert self.header.shape == (4, )
        self.version = kwargs.get('version', int())
        self.packet_number = kwargs.get('packet_number', int())
        self.players_per_team = kwargs.get('players_per_team', int())
        self.game_type = kwargs.get('game_type', int())
        self.state = kwargs.get('state', int())
        self.first_half = kwargs.get('first_half', int())
        self.kick_off_team = kwargs.get('kick_off_team', int())
        self.secondary_state = kwargs.get('secondary_state', int())
        if 'secondary_state_info' not in kwargs:
            self.secondary_state_info = numpy.zeros(4, dtype=numpy.uint8)
        else:
            self.secondary_state_info = numpy.array(kwargs.get('secondary_state_info'), dtype=numpy.uint8)
            assert self.secondary_state_info.shape == (4, )
        self.drop_in_team = kwargs.get('drop_in_team', int())
        self.drop_in_time = kwargs.get('drop_in_time', int())
        self.secs_remaining = kwargs.get('secs_remaining', int())
        self.secondary_time = kwargs.get('secondary_time', int())
        from game_controller_interface.msg import TeamInfo
        self.teams = kwargs.get(
            'teams',
            [TeamInfo() for x in range(2)]
        )

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
        if all(self.header != other.header):
            return False
        if self.version != other.version:
            return False
        if self.packet_number != other.packet_number:
            return False
        if self.players_per_team != other.players_per_team:
            return False
        if self.game_type != other.game_type:
            return False
        if self.state != other.state:
            return False
        if self.first_half != other.first_half:
            return False
        if self.kick_off_team != other.kick_off_team:
            return False
        if self.secondary_state != other.secondary_state:
            return False
        if all(self.secondary_state_info != other.secondary_state_info):
            return False
        if self.drop_in_team != other.drop_in_team:
            return False
        if self.drop_in_time != other.drop_in_time:
            return False
        if self.secs_remaining != other.secs_remaining:
            return False
        if self.secondary_time != other.secondary_time:
            return False
        if self.teams != other.teams:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'header' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 4, \
                "The 'header' numpy.ndarray() must have a size of 4"
            self._header = value
            return
        if __debug__:
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
                 len(value) == 4 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'header' field must be a set or sequence with length 4 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._header = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def version(self):
        """Message field 'version'."""
        return self._version

    @version.setter
    def version(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'version' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'version' field must be an unsigned integer in [0, 65535]"
        self._version = value

    @builtins.property
    def packet_number(self):
        """Message field 'packet_number'."""
        return self._packet_number

    @packet_number.setter
    def packet_number(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'packet_number' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'packet_number' field must be an unsigned integer in [0, 255]"
        self._packet_number = value

    @builtins.property
    def players_per_team(self):
        """Message field 'players_per_team'."""
        return self._players_per_team

    @players_per_team.setter
    def players_per_team(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'players_per_team' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'players_per_team' field must be an unsigned integer in [0, 255]"
        self._players_per_team = value

    @builtins.property
    def game_type(self):
        """Message field 'game_type'."""
        return self._game_type

    @game_type.setter
    def game_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'game_type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'game_type' field must be an unsigned integer in [0, 255]"
        self._game_type = value

    @builtins.property
    def state(self):
        """Message field 'state'."""
        return self._state

    @state.setter
    def state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'state' field must be an unsigned integer in [0, 255]"
        self._state = value

    @builtins.property
    def first_half(self):
        """Message field 'first_half'."""
        return self._first_half

    @first_half.setter
    def first_half(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'first_half' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'first_half' field must be an unsigned integer in [0, 255]"
        self._first_half = value

    @builtins.property
    def kick_off_team(self):
        """Message field 'kick_off_team'."""
        return self._kick_off_team

    @kick_off_team.setter
    def kick_off_team(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'kick_off_team' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'kick_off_team' field must be an unsigned integer in [0, 255]"
        self._kick_off_team = value

    @builtins.property
    def secondary_state(self):
        """Message field 'secondary_state'."""
        return self._secondary_state

    @secondary_state.setter
    def secondary_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'secondary_state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'secondary_state' field must be an unsigned integer in [0, 255]"
        self._secondary_state = value

    @builtins.property
    def secondary_state_info(self):
        """Message field 'secondary_state_info'."""
        return self._secondary_state_info

    @secondary_state_info.setter
    def secondary_state_info(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'secondary_state_info' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 4, \
                "The 'secondary_state_info' numpy.ndarray() must have a size of 4"
            self._secondary_state_info = value
            return
        if __debug__:
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
                 len(value) == 4 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'secondary_state_info' field must be a set or sequence with length 4 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._secondary_state_info = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def drop_in_team(self):
        """Message field 'drop_in_team'."""
        return self._drop_in_team

    @drop_in_team.setter
    def drop_in_team(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'drop_in_team' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'drop_in_team' field must be an unsigned integer in [0, 255]"
        self._drop_in_team = value

    @builtins.property
    def drop_in_time(self):
        """Message field 'drop_in_time'."""
        return self._drop_in_time

    @drop_in_time.setter
    def drop_in_time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'drop_in_time' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'drop_in_time' field must be an unsigned integer in [0, 65535]"
        self._drop_in_time = value

    @builtins.property
    def secs_remaining(self):
        """Message field 'secs_remaining'."""
        return self._secs_remaining

    @secs_remaining.setter
    def secs_remaining(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'secs_remaining' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'secs_remaining' field must be an unsigned integer in [0, 65535]"
        self._secs_remaining = value

    @builtins.property
    def secondary_time(self):
        """Message field 'secondary_time'."""
        return self._secondary_time

    @secondary_time.setter
    def secondary_time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'secondary_time' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'secondary_time' field must be an unsigned integer in [0, 65535]"
        self._secondary_time = value

    @builtins.property
    def teams(self):
        """Message field 'teams'."""
        return self._teams

    @teams.setter
    def teams(self, value):
        if __debug__:
            from game_controller_interface.msg import TeamInfo
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
                 len(value) == 2 and
                 all(isinstance(v, TeamInfo) for v in value) and
                 True), \
                "The 'teams' field must be a set or sequence with length 2 and each value of type 'TeamInfo'"
        self._teams = value
