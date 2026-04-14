# generated from rosidl_generator_py/resource/_idl.py.em
# with input from booster_interface:msg/LowState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LowState(type):
    """Metaclass of message 'LowState'."""

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
                'booster_interface.msg.LowState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__low_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__low_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__low_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__low_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__low_state

            from booster_interface.msg import ImuState
            if ImuState.__class__._TYPE_SUPPORT is None:
                ImuState.__class__.__import_type_support__()

            from booster_interface.msg import MotorState
            if MotorState.__class__._TYPE_SUPPORT is None:
                MotorState.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LowState(metaclass=Metaclass_LowState):
    """Message class 'LowState'."""

    __slots__ = [
        '_imu_state',
        '_motor_state_parallel',
        '_motor_state_serial',
    ]

    _fields_and_field_types = {
        'imu_state': 'booster_interface/ImuState',
        'motor_state_parallel': 'sequence<booster_interface/MotorState>',
        'motor_state_serial': 'sequence<booster_interface/MotorState>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['booster_interface', 'msg'], 'ImuState'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['booster_interface', 'msg'], 'MotorState')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['booster_interface', 'msg'], 'MotorState')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from booster_interface.msg import ImuState
        self.imu_state = kwargs.get('imu_state', ImuState())
        self.motor_state_parallel = kwargs.get('motor_state_parallel', [])
        self.motor_state_serial = kwargs.get('motor_state_serial', [])

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
        if self.imu_state != other.imu_state:
            return False
        if self.motor_state_parallel != other.motor_state_parallel:
            return False
        if self.motor_state_serial != other.motor_state_serial:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def imu_state(self):
        """Message field 'imu_state'."""
        return self._imu_state

    @imu_state.setter
    def imu_state(self, value):
        if __debug__:
            from booster_interface.msg import ImuState
            assert \
                isinstance(value, ImuState), \
                "The 'imu_state' field must be a sub message of type 'ImuState'"
        self._imu_state = value

    @builtins.property
    def motor_state_parallel(self):
        """Message field 'motor_state_parallel'."""
        return self._motor_state_parallel

    @motor_state_parallel.setter
    def motor_state_parallel(self, value):
        if __debug__:
            from booster_interface.msg import MotorState
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
                 all(isinstance(v, MotorState) for v in value) and
                 True), \
                "The 'motor_state_parallel' field must be a set or sequence and each value of type 'MotorState'"
        self._motor_state_parallel = value

    @builtins.property
    def motor_state_serial(self):
        """Message field 'motor_state_serial'."""
        return self._motor_state_serial

    @motor_state_serial.setter
    def motor_state_serial(self, value):
        if __debug__:
            from booster_interface.msg import MotorState
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
                 all(isinstance(v, MotorState) for v in value) and
                 True), \
                "The 'motor_state_serial' field must be a set or sequence and each value of type 'MotorState'"
        self._motor_state_serial = value
