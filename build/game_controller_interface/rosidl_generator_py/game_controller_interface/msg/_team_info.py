# generated from rosidl_generator_py/resource/_idl.py.em
# with input from game_controller_interface:msg/TeamInfo.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'coach_message'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TeamInfo(type):
    """Metaclass of message 'TeamInfo'."""

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
                'game_controller_interface.msg.TeamInfo')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__team_info
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__team_info
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__team_info
            cls._TYPE_SUPPORT = module.type_support_msg__msg__team_info
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__team_info

            from game_controller_interface.msg import RobotInfo
            if RobotInfo.__class__._TYPE_SUPPORT is None:
                RobotInfo.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TeamInfo(metaclass=Metaclass_TeamInfo):
    """Message class 'TeamInfo'."""

    __slots__ = [
        '_team_number',
        '_field_player_colour',
        '_score',
        '_penalty_shot',
        '_single_shots',
        '_coach_sequence',
        '_coach_message',
        '_coach',
        '_players',
    ]

    _fields_and_field_types = {
        'team_number': 'uint8',
        'field_player_colour': 'uint8',
        'score': 'uint8',
        'penalty_shot': 'uint8',
        'single_shots': 'uint16',
        'coach_sequence': 'uint8',
        'coach_message': 'sequence<uint8>',
        'coach': 'game_controller_interface/RobotInfo',
        'players': 'sequence<game_controller_interface/RobotInfo>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['game_controller_interface', 'msg'], 'RobotInfo'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['game_controller_interface', 'msg'], 'RobotInfo')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.team_number = kwargs.get('team_number', int())
        self.field_player_colour = kwargs.get('field_player_colour', int())
        self.score = kwargs.get('score', int())
        self.penalty_shot = kwargs.get('penalty_shot', int())
        self.single_shots = kwargs.get('single_shots', int())
        self.coach_sequence = kwargs.get('coach_sequence', int())
        self.coach_message = array.array('B', kwargs.get('coach_message', []))
        from game_controller_interface.msg import RobotInfo
        self.coach = kwargs.get('coach', RobotInfo())
        self.players = kwargs.get('players', [])

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
        if self.team_number != other.team_number:
            return False
        if self.field_player_colour != other.field_player_colour:
            return False
        if self.score != other.score:
            return False
        if self.penalty_shot != other.penalty_shot:
            return False
        if self.single_shots != other.single_shots:
            return False
        if self.coach_sequence != other.coach_sequence:
            return False
        if self.coach_message != other.coach_message:
            return False
        if self.coach != other.coach:
            return False
        if self.players != other.players:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def team_number(self):
        """Message field 'team_number'."""
        return self._team_number

    @team_number.setter
    def team_number(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'team_number' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'team_number' field must be an unsigned integer in [0, 255]"
        self._team_number = value

    @builtins.property
    def field_player_colour(self):
        """Message field 'field_player_colour'."""
        return self._field_player_colour

    @field_player_colour.setter
    def field_player_colour(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'field_player_colour' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'field_player_colour' field must be an unsigned integer in [0, 255]"
        self._field_player_colour = value

    @builtins.property
    def score(self):
        """Message field 'score'."""
        return self._score

    @score.setter
    def score(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'score' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'score' field must be an unsigned integer in [0, 255]"
        self._score = value

    @builtins.property
    def penalty_shot(self):
        """Message field 'penalty_shot'."""
        return self._penalty_shot

    @penalty_shot.setter
    def penalty_shot(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'penalty_shot' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'penalty_shot' field must be an unsigned integer in [0, 255]"
        self._penalty_shot = value

    @builtins.property
    def single_shots(self):
        """Message field 'single_shots'."""
        return self._single_shots

    @single_shots.setter
    def single_shots(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'single_shots' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'single_shots' field must be an unsigned integer in [0, 65535]"
        self._single_shots = value

    @builtins.property
    def coach_sequence(self):
        """Message field 'coach_sequence'."""
        return self._coach_sequence

    @coach_sequence.setter
    def coach_sequence(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'coach_sequence' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'coach_sequence' field must be an unsigned integer in [0, 255]"
        self._coach_sequence = value

    @builtins.property
    def coach_message(self):
        """Message field 'coach_message'."""
        return self._coach_message

    @coach_message.setter
    def coach_message(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'coach_message' array.array() must have the type code of 'B'"
            self._coach_message = value
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
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'coach_message' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._coach_message = array.array('B', value)

    @builtins.property
    def coach(self):
        """Message field 'coach'."""
        return self._coach

    @coach.setter
    def coach(self, value):
        if __debug__:
            from game_controller_interface.msg import RobotInfo
            assert \
                isinstance(value, RobotInfo), \
                "The 'coach' field must be a sub message of type 'RobotInfo'"
        self._coach = value

    @builtins.property
    def players(self):
        """Message field 'players'."""
        return self._players

    @players.setter
    def players(self, value):
        if __debug__:
            from game_controller_interface.msg import RobotInfo
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
                 all(isinstance(v, RobotInfo) for v in value) and
                 True), \
                "The 'players' field must be a set or sequence and each value of type 'RobotInfo'"
        self._players = value
