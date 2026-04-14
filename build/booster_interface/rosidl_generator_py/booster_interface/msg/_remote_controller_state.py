# generated from rosidl_generator_py/resource/_idl.py.em
# with input from booster_interface:msg/RemoteControllerState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RemoteControllerState(type):
    """Metaclass of message 'RemoteControllerState'."""

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
                'booster_interface.msg.RemoteControllerState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__remote_controller_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__remote_controller_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__remote_controller_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__remote_controller_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__remote_controller_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RemoteControllerState(metaclass=Metaclass_RemoteControllerState):
    """Message class 'RemoteControllerState'."""

    __slots__ = [
        '_event',
        '_lx',
        '_ly',
        '_rx',
        '_ry',
        '_a',
        '_b',
        '_x',
        '_y',
        '_lb',
        '_rb',
        '_lt',
        '_rt',
        '_ls',
        '_rs',
        '_back',
        '_start',
        '_hat_c',
        '_hat_u',
        '_hat_d',
        '_hat_l',
        '_hat_r',
        '_hat_lu',
        '_hat_ld',
        '_hat_ru',
        '_hat_rd',
        '_hat_pos',
    ]

    _fields_and_field_types = {
        'event': 'uint32',
        'lx': 'float',
        'ly': 'float',
        'rx': 'float',
        'ry': 'float',
        'a': 'boolean',
        'b': 'boolean',
        'x': 'boolean',
        'y': 'boolean',
        'lb': 'boolean',
        'rb': 'boolean',
        'lt': 'boolean',
        'rt': 'boolean',
        'ls': 'boolean',
        'rs': 'boolean',
        'back': 'boolean',
        'start': 'boolean',
        'hat_c': 'boolean',
        'hat_u': 'boolean',
        'hat_d': 'boolean',
        'hat_l': 'boolean',
        'hat_r': 'boolean',
        'hat_lu': 'boolean',
        'hat_ld': 'boolean',
        'hat_ru': 'boolean',
        'hat_rd': 'boolean',
        'hat_pos': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.event = kwargs.get('event', int())
        self.lx = kwargs.get('lx', float())
        self.ly = kwargs.get('ly', float())
        self.rx = kwargs.get('rx', float())
        self.ry = kwargs.get('ry', float())
        self.a = kwargs.get('a', bool())
        self.b = kwargs.get('b', bool())
        self.x = kwargs.get('x', bool())
        self.y = kwargs.get('y', bool())
        self.lb = kwargs.get('lb', bool())
        self.rb = kwargs.get('rb', bool())
        self.lt = kwargs.get('lt', bool())
        self.rt = kwargs.get('rt', bool())
        self.ls = kwargs.get('ls', bool())
        self.rs = kwargs.get('rs', bool())
        self.back = kwargs.get('back', bool())
        self.start = kwargs.get('start', bool())
        self.hat_c = kwargs.get('hat_c', bool())
        self.hat_u = kwargs.get('hat_u', bool())
        self.hat_d = kwargs.get('hat_d', bool())
        self.hat_l = kwargs.get('hat_l', bool())
        self.hat_r = kwargs.get('hat_r', bool())
        self.hat_lu = kwargs.get('hat_lu', bool())
        self.hat_ld = kwargs.get('hat_ld', bool())
        self.hat_ru = kwargs.get('hat_ru', bool())
        self.hat_rd = kwargs.get('hat_rd', bool())
        self.hat_pos = kwargs.get('hat_pos', int())

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
        if self.lx != other.lx:
            return False
        if self.ly != other.ly:
            return False
        if self.rx != other.rx:
            return False
        if self.ry != other.ry:
            return False
        if self.a != other.a:
            return False
        if self.b != other.b:
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.lb != other.lb:
            return False
        if self.rb != other.rb:
            return False
        if self.lt != other.lt:
            return False
        if self.rt != other.rt:
            return False
        if self.ls != other.ls:
            return False
        if self.rs != other.rs:
            return False
        if self.back != other.back:
            return False
        if self.start != other.start:
            return False
        if self.hat_c != other.hat_c:
            return False
        if self.hat_u != other.hat_u:
            return False
        if self.hat_d != other.hat_d:
            return False
        if self.hat_l != other.hat_l:
            return False
        if self.hat_r != other.hat_r:
            return False
        if self.hat_lu != other.hat_lu:
            return False
        if self.hat_ld != other.hat_ld:
            return False
        if self.hat_ru != other.hat_ru:
            return False
        if self.hat_rd != other.hat_rd:
            return False
        if self.hat_pos != other.hat_pos:
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
            assert value >= 0 and value < 4294967296, \
                "The 'event' field must be an unsigned integer in [0, 4294967295]"
        self._event = value

    @builtins.property
    def lx(self):
        """Message field 'lx'."""
        return self._lx

    @lx.setter
    def lx(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'lx' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'lx' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._lx = value

    @builtins.property
    def ly(self):
        """Message field 'ly'."""
        return self._ly

    @ly.setter
    def ly(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ly' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'ly' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._ly = value

    @builtins.property
    def rx(self):
        """Message field 'rx'."""
        return self._rx

    @rx.setter
    def rx(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rx' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'rx' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._rx = value

    @builtins.property
    def ry(self):
        """Message field 'ry'."""
        return self._ry

    @ry.setter
    def ry(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ry' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'ry' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._ry = value

    @builtins.property
    def a(self):
        """Message field 'a'."""
        return self._a

    @a.setter
    def a(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'a' field must be of type 'bool'"
        self._a = value

    @builtins.property
    def b(self):
        """Message field 'b'."""
        return self._b

    @b.setter
    def b(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'b' field must be of type 'bool'"
        self._b = value

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'x' field must be of type 'bool'"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'y' field must be of type 'bool'"
        self._y = value

    @builtins.property
    def lb(self):
        """Message field 'lb'."""
        return self._lb

    @lb.setter
    def lb(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'lb' field must be of type 'bool'"
        self._lb = value

    @builtins.property
    def rb(self):
        """Message field 'rb'."""
        return self._rb

    @rb.setter
    def rb(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'rb' field must be of type 'bool'"
        self._rb = value

    @builtins.property
    def lt(self):
        """Message field 'lt'."""
        return self._lt

    @lt.setter
    def lt(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'lt' field must be of type 'bool'"
        self._lt = value

    @builtins.property
    def rt(self):
        """Message field 'rt'."""
        return self._rt

    @rt.setter
    def rt(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'rt' field must be of type 'bool'"
        self._rt = value

    @builtins.property
    def ls(self):
        """Message field 'ls'."""
        return self._ls

    @ls.setter
    def ls(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'ls' field must be of type 'bool'"
        self._ls = value

    @builtins.property
    def rs(self):
        """Message field 'rs'."""
        return self._rs

    @rs.setter
    def rs(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'rs' field must be of type 'bool'"
        self._rs = value

    @builtins.property
    def back(self):
        """Message field 'back'."""
        return self._back

    @back.setter
    def back(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'back' field must be of type 'bool'"
        self._back = value

    @builtins.property
    def start(self):
        """Message field 'start'."""
        return self._start

    @start.setter
    def start(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'start' field must be of type 'bool'"
        self._start = value

    @builtins.property
    def hat_c(self):
        """Message field 'hat_c'."""
        return self._hat_c

    @hat_c.setter
    def hat_c(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'hat_c' field must be of type 'bool'"
        self._hat_c = value

    @builtins.property
    def hat_u(self):
        """Message field 'hat_u'."""
        return self._hat_u

    @hat_u.setter
    def hat_u(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'hat_u' field must be of type 'bool'"
        self._hat_u = value

    @builtins.property
    def hat_d(self):
        """Message field 'hat_d'."""
        return self._hat_d

    @hat_d.setter
    def hat_d(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'hat_d' field must be of type 'bool'"
        self._hat_d = value

    @builtins.property
    def hat_l(self):
        """Message field 'hat_l'."""
        return self._hat_l

    @hat_l.setter
    def hat_l(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'hat_l' field must be of type 'bool'"
        self._hat_l = value

    @builtins.property
    def hat_r(self):
        """Message field 'hat_r'."""
        return self._hat_r

    @hat_r.setter
    def hat_r(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'hat_r' field must be of type 'bool'"
        self._hat_r = value

    @builtins.property
    def hat_lu(self):
        """Message field 'hat_lu'."""
        return self._hat_lu

    @hat_lu.setter
    def hat_lu(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'hat_lu' field must be of type 'bool'"
        self._hat_lu = value

    @builtins.property
    def hat_ld(self):
        """Message field 'hat_ld'."""
        return self._hat_ld

    @hat_ld.setter
    def hat_ld(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'hat_ld' field must be of type 'bool'"
        self._hat_ld = value

    @builtins.property
    def hat_ru(self):
        """Message field 'hat_ru'."""
        return self._hat_ru

    @hat_ru.setter
    def hat_ru(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'hat_ru' field must be of type 'bool'"
        self._hat_ru = value

    @builtins.property
    def hat_rd(self):
        """Message field 'hat_rd'."""
        return self._hat_rd

    @hat_rd.setter
    def hat_rd(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'hat_rd' field must be of type 'bool'"
        self._hat_rd = value

    @builtins.property
    def hat_pos(self):
        """Message field 'hat_pos'."""
        return self._hat_pos

    @hat_pos.setter
    def hat_pos(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'hat_pos' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'hat_pos' field must be an unsigned integer in [0, 255]"
        self._hat_pos = value
