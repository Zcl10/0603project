# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from three_one_msgs/ReportDistance.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class ReportDistance(genpy.Message):
  _md5sum = "11d828c6b9eb85d8fbb317377ee4beba"
  _type = "three_one_msgs/ReportDistance"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """uint32 mileage
uint32 left_pulse
uint32 right_pulse
float64 left_distance
float64 right_distance"""
  __slots__ = ['mileage','left_pulse','right_pulse','left_distance','right_distance']
  _slot_types = ['uint32','uint32','uint32','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       mileage,left_pulse,right_pulse,left_distance,right_distance

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(ReportDistance, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.mileage is None:
        self.mileage = 0
      if self.left_pulse is None:
        self.left_pulse = 0
      if self.right_pulse is None:
        self.right_pulse = 0
      if self.left_distance is None:
        self.left_distance = 0.
      if self.right_distance is None:
        self.right_distance = 0.
    else:
      self.mileage = 0
      self.left_pulse = 0
      self.right_pulse = 0
      self.left_distance = 0.
      self.right_distance = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_3I2d().pack(_x.mileage, _x.left_pulse, _x.right_pulse, _x.left_distance, _x.right_distance))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 28
      (_x.mileage, _x.left_pulse, _x.right_pulse, _x.left_distance, _x.right_distance,) = _get_struct_3I2d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3I2d().pack(_x.mileage, _x.left_pulse, _x.right_pulse, _x.left_distance, _x.right_distance))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 28
      (_x.mileage, _x.left_pulse, _x.right_pulse, _x.left_distance, _x.right_distance,) = _get_struct_3I2d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3I2d = None
def _get_struct_3I2d():
    global _struct_3I2d
    if _struct_3I2d is None:
        _struct_3I2d = struct.Struct("<3I2d")
    return _struct_3I2d
