# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vision_interface:msg/Detections.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'radar_x'
# Member 'radar_y'
# Member 'corner_pos'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Detections(type):
    """Metaclass of message 'Detections'."""

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
                'vision_interface.msg.Detections')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__detections
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__detections
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__detections
            cls._TYPE_SUPPORT = module.type_support_msg__msg__detections
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__detections

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

            from vision_interface.msg import DetectedObject
            if DetectedObject.__class__._TYPE_SUPPORT is None:
                DetectedObject.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Detections(metaclass=Metaclass_Detections):
    """Message class 'Detections'."""

    __slots__ = [
        '_header',
        '_detected_objects',
        '_radar_x',
        '_radar_y',
        '_corner_pos',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'detected_objects': 'sequence<vision_interface/DetectedObject>',
        'radar_x': 'sequence<float>',
        'radar_y': 'sequence<float>',
        'corner_pos': 'sequence<float>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vision_interface', 'msg'], 'DetectedObject')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.detected_objects = kwargs.get('detected_objects', [])
        self.radar_x = array.array('f', kwargs.get('radar_x', []))
        self.radar_y = array.array('f', kwargs.get('radar_y', []))
        self.corner_pos = array.array('f', kwargs.get('corner_pos', []))

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
        if self.header != other.header:
            return False
        if self.detected_objects != other.detected_objects:
            return False
        if self.radar_x != other.radar_x:
            return False
        if self.radar_y != other.radar_y:
            return False
        if self.corner_pos != other.corner_pos:
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
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def detected_objects(self):
        """Message field 'detected_objects'."""
        return self._detected_objects

    @detected_objects.setter
    def detected_objects(self, value):
        if __debug__:
            from vision_interface.msg import DetectedObject
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
                 all(isinstance(v, DetectedObject) for v in value) and
                 True), \
                "The 'detected_objects' field must be a set or sequence and each value of type 'DetectedObject'"
        self._detected_objects = value

    @builtins.property
    def radar_x(self):
        """Message field 'radar_x'."""
        return self._radar_x

    @radar_x.setter
    def radar_x(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'radar_x' array.array() must have the type code of 'f'"
            self._radar_x = value
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'radar_x' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._radar_x = array.array('f', value)

    @builtins.property
    def radar_y(self):
        """Message field 'radar_y'."""
        return self._radar_y

    @radar_y.setter
    def radar_y(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'radar_y' array.array() must have the type code of 'f'"
            self._radar_y = value
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'radar_y' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._radar_y = array.array('f', value)

    @builtins.property
    def corner_pos(self):
        """Message field 'corner_pos'."""
        return self._corner_pos

    @corner_pos.setter
    def corner_pos(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'corner_pos' array.array() must have the type code of 'f'"
            self._corner_pos = value
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'corner_pos' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._corner_pos = array.array('f', value)
