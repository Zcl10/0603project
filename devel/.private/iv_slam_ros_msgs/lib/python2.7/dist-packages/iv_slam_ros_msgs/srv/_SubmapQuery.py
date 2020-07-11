# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from iv_slam_ros_msgs/SubmapQueryRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class SubmapQueryRequest(genpy.Message):
  _md5sum = "5fc429a478a6d73822616720a31a2158"
  _type = "iv_slam_ros_msgs/SubmapQueryRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """
int32 trajectory_id
int32 submap_index
"""
  __slots__ = ['trajectory_id','submap_index']
  _slot_types = ['int32','int32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       trajectory_id,submap_index

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(SubmapQueryRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.trajectory_id is None:
        self.trajectory_id = 0
      if self.submap_index is None:
        self.submap_index = 0
    else:
      self.trajectory_id = 0
      self.submap_index = 0

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
      buff.write(_get_struct_2i().pack(_x.trajectory_id, _x.submap_index))
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
      end += 8
      (_x.trajectory_id, _x.submap_index,) = _get_struct_2i().unpack(str[start:end])
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
      buff.write(_get_struct_2i().pack(_x.trajectory_id, _x.submap_index))
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
      end += 8
      (_x.trajectory_id, _x.submap_index,) = _get_struct_2i().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2i = None
def _get_struct_2i():
    global _struct_2i
    if _struct_2i is None:
        _struct_2i = struct.Struct("<2i")
    return _struct_2i
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from iv_slam_ros_msgs/SubmapQueryResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg

class SubmapQueryResponse(genpy.Message):
  _md5sum = "d714bb0d07bc98995c3ddaa9d96d2db4"
  _type = "iv_slam_ros_msgs/SubmapQueryResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int32 submap_version
uint8[] cells
int32 width
int32 height
float64 resolution
geometry_msgs/Pose slice_pose
string error_message


================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w
"""
  __slots__ = ['submap_version','cells','width','height','resolution','slice_pose','error_message']
  _slot_types = ['int32','uint8[]','int32','int32','float64','geometry_msgs/Pose','string']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       submap_version,cells,width,height,resolution,slice_pose,error_message

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(SubmapQueryResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.submap_version is None:
        self.submap_version = 0
      if self.cells is None:
        self.cells = b''
      if self.width is None:
        self.width = 0
      if self.height is None:
        self.height = 0
      if self.resolution is None:
        self.resolution = 0.
      if self.slice_pose is None:
        self.slice_pose = geometry_msgs.msg.Pose()
      if self.error_message is None:
        self.error_message = ''
    else:
      self.submap_version = 0
      self.cells = b''
      self.width = 0
      self.height = 0
      self.resolution = 0.
      self.slice_pose = geometry_msgs.msg.Pose()
      self.error_message = ''

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
      buff.write(_get_struct_i().pack(self.submap_version))
      _x = self.cells
      length = len(_x)
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_2i8d().pack(_x.width, _x.height, _x.resolution, _x.slice_pose.position.x, _x.slice_pose.position.y, _x.slice_pose.position.z, _x.slice_pose.orientation.x, _x.slice_pose.orientation.y, _x.slice_pose.orientation.z, _x.slice_pose.orientation.w))
      _x = self.error_message
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.slice_pose is None:
        self.slice_pose = geometry_msgs.msg.Pose()
      end = 0
      start = end
      end += 4
      (self.submap_version,) = _get_struct_i().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.cells = str[start:end]
      _x = self
      start = end
      end += 72
      (_x.width, _x.height, _x.resolution, _x.slice_pose.position.x, _x.slice_pose.position.y, _x.slice_pose.position.z, _x.slice_pose.orientation.x, _x.slice_pose.orientation.y, _x.slice_pose.orientation.z, _x.slice_pose.orientation.w,) = _get_struct_2i8d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.error_message = str[start:end].decode('utf-8')
      else:
        self.error_message = str[start:end]
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
      buff.write(_get_struct_i().pack(self.submap_version))
      _x = self.cells
      length = len(_x)
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_2i8d().pack(_x.width, _x.height, _x.resolution, _x.slice_pose.position.x, _x.slice_pose.position.y, _x.slice_pose.position.z, _x.slice_pose.orientation.x, _x.slice_pose.orientation.y, _x.slice_pose.orientation.z, _x.slice_pose.orientation.w))
      _x = self.error_message
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.slice_pose is None:
        self.slice_pose = geometry_msgs.msg.Pose()
      end = 0
      start = end
      end += 4
      (self.submap_version,) = _get_struct_i().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.cells = str[start:end]
      _x = self
      start = end
      end += 72
      (_x.width, _x.height, _x.resolution, _x.slice_pose.position.x, _x.slice_pose.position.y, _x.slice_pose.position.z, _x.slice_pose.orientation.x, _x.slice_pose.orientation.y, _x.slice_pose.orientation.z, _x.slice_pose.orientation.w,) = _get_struct_2i8d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.error_message = str[start:end].decode('utf-8')
      else:
        self.error_message = str[start:end]
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_i = None
def _get_struct_i():
    global _struct_i
    if _struct_i is None:
        _struct_i = struct.Struct("<i")
    return _struct_i
_struct_2i8d = None
def _get_struct_2i8d():
    global _struct_2i8d
    if _struct_2i8d is None:
        _struct_2i8d = struct.Struct("<2i8d")
    return _struct_2i8d
class SubmapQuery(object):
  _type          = 'iv_slam_ros_msgs/SubmapQuery'
  _md5sum = 'cb8ebfdb2c22b8f1b896e7143a82ac87'
  _request_class  = SubmapQueryRequest
  _response_class = SubmapQueryResponse
