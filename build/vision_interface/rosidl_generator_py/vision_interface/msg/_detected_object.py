# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vision_interface:msg/DetectedObject.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'target_uv'
# Member 'received_pos'
# Member 'position'
# Member 'position_projection'
# Member 'position_cam'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DetectedObject(type):
    """Metaclass of message 'DetectedObject'."""

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
                'vision_interface.msg.DetectedObject')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__detected_object
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__detected_object
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__detected_object
            cls._TYPE_SUPPORT = module.type_support_msg__msg__detected_object
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__detected_object

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DetectedObject(metaclass=Metaclass_DetectedObject):
    """Message class 'DetectedObject'."""

    __slots__ = [
        '_label',
        '_color',
        '_confidence',
        '_xmin',
        '_ymin',
        '_xmax',
        '_ymax',
        '_target_uv',
        '_received_pos',
        '_position',
        '_position_projection',
        '_position_cam',
        '_position_confidence',
    ]

    _fields_and_field_types = {
        'label': 'string',
        'color': 'string',
        'confidence': 'double',
        'xmin': 'int64',
        'ymin': 'int64',
        'xmax': 'int64',
        'ymax': 'int64',
        'target_uv': 'sequence<float>',
        'received_pos': 'sequence<float>',
        'position': 'sequence<float>',
        'position_projection': 'sequence<float>',
        'position_cam': 'sequence<float>',
        'position_confidence': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.label = kwargs.get('label', str())
        self.color = kwargs.get('color', str())
        self.confidence = kwargs.get('confidence', float())
        self.xmin = kwargs.get('xmin', int())
        self.ymin = kwargs.get('ymin', int())
        self.xmax = kwargs.get('xmax', int())
        self.ymax = kwargs.get('ymax', int())
        self.target_uv = array.array('f', kwargs.get('target_uv', []))
        self.received_pos = array.array('f', kwargs.get('received_pos', []))
        self.position = array.array('f', kwargs.get('position', []))
        self.position_projection = array.array('f', kwargs.get('position_projection', []))
        self.position_cam = array.array('f', kwargs.get('position_cam', []))
        self.position_confidence = kwargs.get('position_confidence', int())

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
        if self.label != other.label:
            return False
        if self.color != other.color:
            return False
        if self.confidence != other.confidence:
            return False
        if self.xmin != other.xmin:
            return False
        if self.ymin != other.ymin:
            return False
        if self.xmax != other.xmax:
            return False
        if self.ymax != other.ymax:
            return False
        if self.target_uv != other.target_uv:
            return False
        if self.received_pos != other.received_pos:
            return False
        if self.position != other.position:
            return False
        if self.position_projection != other.position_projection:
            return False
        if self.position_cam != other.position_cam:
            return False
        if self.position_confidence != other.position_confidence:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def label(self):
        """Message field 'label'."""
        return self._label

    @label.setter
    def label(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'label' field must be of type 'str'"
        self._label = value

    @builtins.property
    def color(self):
        """Message field 'color'."""
        return self._color

    @color.setter
    def color(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'color' field must be of type 'str'"
        self._color = value

    @builtins.property
    def confidence(self):
        """Message field 'confidence'."""
        return self._confidence

    @confidence.setter
    def confidence(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'confidence' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'confidence' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._confidence = value

    @builtins.property
    def xmin(self):
        """Message field 'xmin'."""
        return self._xmin

    @xmin.setter
    def xmin(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'xmin' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'xmin' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._xmin = value

    @builtins.property
    def ymin(self):
        """Message field 'ymin'."""
        return self._ymin

    @ymin.setter
    def ymin(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ymin' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'ymin' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._ymin = value

    @builtins.property
    def xmax(self):
        """Message field 'xmax'."""
        return self._xmax

    @xmax.setter
    def xmax(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'xmax' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'xmax' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._xmax = value

    @builtins.property
    def ymax(self):
        """Message field 'ymax'."""
        return self._ymax

    @ymax.setter
    def ymax(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ymax' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'ymax' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._ymax = value

    @builtins.property
    def target_uv(self):
        """Message field 'target_uv'."""
        return self._target_uv

    @target_uv.setter
    def target_uv(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'target_uv' array.array() must have the type code of 'f'"
            self._target_uv = value
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
                "The 'target_uv' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._target_uv = array.array('f', value)

    @builtins.property
    def received_pos(self):
        """Message field 'received_pos'."""
        return self._received_pos

    @received_pos.setter
    def received_pos(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'received_pos' array.array() must have the type code of 'f'"
            self._received_pos = value
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
                "The 'received_pos' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._received_pos = array.array('f', value)

    @builtins.property
    def position(self):
        """Message field 'position'."""
        return self._position

    @position.setter
    def position(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'position' array.array() must have the type code of 'f'"
            self._position = value
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
                "The 'position' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._position = array.array('f', value)

    @builtins.property
    def position_projection(self):
        """Message field 'position_projection'."""
        return self._position_projection

    @position_projection.setter
    def position_projection(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'position_projection' array.array() must have the type code of 'f'"
            self._position_projection = value
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
                "The 'position_projection' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._position_projection = array.array('f', value)

    @builtins.property
    def position_cam(self):
        """Message field 'position_cam'."""
        return self._position_cam

    @position_cam.setter
    def position_cam(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'position_cam' array.array() must have the type code of 'f'"
            self._position_cam = value
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
                "The 'position_cam' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._position_cam = array.array('f', value)

    @builtins.property
    def position_confidence(self):
        """Message field 'position_confidence'."""
        return self._position_confidence

    @position_confidence.setter
    def position_confidence(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'position_confidence' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'position_confidence' field must be an integer in [-2147483648, 2147483647]"
        self._position_confidence = value
