# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from lanelet_map_msgs/Lanelet.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import lanelet_map_msgs.msg
import geometry_msgs.msg

class Lanelet(genpy.Message):
  _md5sum = "1e01c0132a1b347126bf3583993109da"
  _type = "lanelet_map_msgs/Lanelet"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int32 id
Way left_bound
Way right_bound
Way centerline
Regulatory regulatory_elements

================================================================================
MSG: lanelet_map_msgs/Way
string task_area
int8 is_forward
int8 open_concave_obs_det
int8 open_dynamic_obs_det
int8 open_foggy_det
int8 open_water_det
int8 foggy_area
int8 lawn_area
int8 water_area
int8 wall_area
int8 ditch_area
float64 vel_limit
Node[] points

================================================================================
MSG: lanelet_map_msgs/Node
int32 id
string type
float64 vlimit
geometry_msgs/Point point

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: lanelet_map_msgs/Regulatory
Node[] special_nodes
Way[] special_ways
"""
  __slots__ = ['id','left_bound','right_bound','centerline','regulatory_elements']
  _slot_types = ['int32','lanelet_map_msgs/Way','lanelet_map_msgs/Way','lanelet_map_msgs/Way','lanelet_map_msgs/Regulatory']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       id,left_bound,right_bound,centerline,regulatory_elements

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(Lanelet, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.id is None:
        self.id = 0
      if self.left_bound is None:
        self.left_bound = lanelet_map_msgs.msg.Way()
      if self.right_bound is None:
        self.right_bound = lanelet_map_msgs.msg.Way()
      if self.centerline is None:
        self.centerline = lanelet_map_msgs.msg.Way()
      if self.regulatory_elements is None:
        self.regulatory_elements = lanelet_map_msgs.msg.Regulatory()
    else:
      self.id = 0
      self.left_bound = lanelet_map_msgs.msg.Way()
      self.right_bound = lanelet_map_msgs.msg.Way()
      self.centerline = lanelet_map_msgs.msg.Way()
      self.regulatory_elements = lanelet_map_msgs.msg.Regulatory()

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
      buff.write(_get_struct_i().pack(self.id))
      _x = self.left_bound.task_area
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_10bd().pack(_x.left_bound.is_forward, _x.left_bound.open_concave_obs_det, _x.left_bound.open_dynamic_obs_det, _x.left_bound.open_foggy_det, _x.left_bound.open_water_det, _x.left_bound.foggy_area, _x.left_bound.lawn_area, _x.left_bound.water_area, _x.left_bound.wall_area, _x.left_bound.ditch_area, _x.left_bound.vel_limit))
      length = len(self.left_bound.points)
      buff.write(_struct_I.pack(length))
      for val1 in self.left_bound.points:
        buff.write(_get_struct_i().pack(val1.id))
        _x = val1.type
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        buff.write(_get_struct_d().pack(val1.vlimit))
        _v1 = val1.point
        _x = _v1
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      _x = self.right_bound.task_area
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_10bd().pack(_x.right_bound.is_forward, _x.right_bound.open_concave_obs_det, _x.right_bound.open_dynamic_obs_det, _x.right_bound.open_foggy_det, _x.right_bound.open_water_det, _x.right_bound.foggy_area, _x.right_bound.lawn_area, _x.right_bound.water_area, _x.right_bound.wall_area, _x.right_bound.ditch_area, _x.right_bound.vel_limit))
      length = len(self.right_bound.points)
      buff.write(_struct_I.pack(length))
      for val1 in self.right_bound.points:
        buff.write(_get_struct_i().pack(val1.id))
        _x = val1.type
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        buff.write(_get_struct_d().pack(val1.vlimit))
        _v2 = val1.point
        _x = _v2
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      _x = self.centerline.task_area
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_10bd().pack(_x.centerline.is_forward, _x.centerline.open_concave_obs_det, _x.centerline.open_dynamic_obs_det, _x.centerline.open_foggy_det, _x.centerline.open_water_det, _x.centerline.foggy_area, _x.centerline.lawn_area, _x.centerline.water_area, _x.centerline.wall_area, _x.centerline.ditch_area, _x.centerline.vel_limit))
      length = len(self.centerline.points)
      buff.write(_struct_I.pack(length))
      for val1 in self.centerline.points:
        buff.write(_get_struct_i().pack(val1.id))
        _x = val1.type
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        buff.write(_get_struct_d().pack(val1.vlimit))
        _v3 = val1.point
        _x = _v3
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      length = len(self.regulatory_elements.special_nodes)
      buff.write(_struct_I.pack(length))
      for val1 in self.regulatory_elements.special_nodes:
        buff.write(_get_struct_i().pack(val1.id))
        _x = val1.type
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        buff.write(_get_struct_d().pack(val1.vlimit))
        _v4 = val1.point
        _x = _v4
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      length = len(self.regulatory_elements.special_ways)
      buff.write(_struct_I.pack(length))
      for val1 in self.regulatory_elements.special_ways:
        _x = val1.task_area
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_get_struct_10bd().pack(_x.is_forward, _x.open_concave_obs_det, _x.open_dynamic_obs_det, _x.open_foggy_det, _x.open_water_det, _x.foggy_area, _x.lawn_area, _x.water_area, _x.wall_area, _x.ditch_area, _x.vel_limit))
        length = len(val1.points)
        buff.write(_struct_I.pack(length))
        for val2 in val1.points:
          buff.write(_get_struct_i().pack(val2.id))
          _x = val2.type
          length = len(_x)
          if python3 or type(_x) == unicode:
            _x = _x.encode('utf-8')
            length = len(_x)
          buff.write(struct.pack('<I%ss'%length, length, _x))
          buff.write(_get_struct_d().pack(val2.vlimit))
          _v5 = val2.point
          _x = _v5
          buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.left_bound is None:
        self.left_bound = lanelet_map_msgs.msg.Way()
      if self.right_bound is None:
        self.right_bound = lanelet_map_msgs.msg.Way()
      if self.centerline is None:
        self.centerline = lanelet_map_msgs.msg.Way()
      if self.regulatory_elements is None:
        self.regulatory_elements = lanelet_map_msgs.msg.Regulatory()
      end = 0
      start = end
      end += 4
      (self.id,) = _get_struct_i().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.left_bound.task_area = str[start:end].decode('utf-8')
      else:
        self.left_bound.task_area = str[start:end]
      _x = self
      start = end
      end += 18
      (_x.left_bound.is_forward, _x.left_bound.open_concave_obs_det, _x.left_bound.open_dynamic_obs_det, _x.left_bound.open_foggy_det, _x.left_bound.open_water_det, _x.left_bound.foggy_area, _x.left_bound.lawn_area, _x.left_bound.water_area, _x.left_bound.wall_area, _x.left_bound.ditch_area, _x.left_bound.vel_limit,) = _get_struct_10bd().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.left_bound.points = []
      for i in range(0, length):
        val1 = lanelet_map_msgs.msg.Node()
        start = end
        end += 4
        (val1.id,) = _get_struct_i().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.type = str[start:end].decode('utf-8')
        else:
          val1.type = str[start:end]
        start = end
        end += 8
        (val1.vlimit,) = _get_struct_d().unpack(str[start:end])
        _v6 = val1.point
        _x = _v6
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.left_bound.points.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.right_bound.task_area = str[start:end].decode('utf-8')
      else:
        self.right_bound.task_area = str[start:end]
      _x = self
      start = end
      end += 18
      (_x.right_bound.is_forward, _x.right_bound.open_concave_obs_det, _x.right_bound.open_dynamic_obs_det, _x.right_bound.open_foggy_det, _x.right_bound.open_water_det, _x.right_bound.foggy_area, _x.right_bound.lawn_area, _x.right_bound.water_area, _x.right_bound.wall_area, _x.right_bound.ditch_area, _x.right_bound.vel_limit,) = _get_struct_10bd().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.right_bound.points = []
      for i in range(0, length):
        val1 = lanelet_map_msgs.msg.Node()
        start = end
        end += 4
        (val1.id,) = _get_struct_i().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.type = str[start:end].decode('utf-8')
        else:
          val1.type = str[start:end]
        start = end
        end += 8
        (val1.vlimit,) = _get_struct_d().unpack(str[start:end])
        _v7 = val1.point
        _x = _v7
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.right_bound.points.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.centerline.task_area = str[start:end].decode('utf-8')
      else:
        self.centerline.task_area = str[start:end]
      _x = self
      start = end
      end += 18
      (_x.centerline.is_forward, _x.centerline.open_concave_obs_det, _x.centerline.open_dynamic_obs_det, _x.centerline.open_foggy_det, _x.centerline.open_water_det, _x.centerline.foggy_area, _x.centerline.lawn_area, _x.centerline.water_area, _x.centerline.wall_area, _x.centerline.ditch_area, _x.centerline.vel_limit,) = _get_struct_10bd().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.centerline.points = []
      for i in range(0, length):
        val1 = lanelet_map_msgs.msg.Node()
        start = end
        end += 4
        (val1.id,) = _get_struct_i().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.type = str[start:end].decode('utf-8')
        else:
          val1.type = str[start:end]
        start = end
        end += 8
        (val1.vlimit,) = _get_struct_d().unpack(str[start:end])
        _v8 = val1.point
        _x = _v8
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.centerline.points.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.regulatory_elements.special_nodes = []
      for i in range(0, length):
        val1 = lanelet_map_msgs.msg.Node()
        start = end
        end += 4
        (val1.id,) = _get_struct_i().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.type = str[start:end].decode('utf-8')
        else:
          val1.type = str[start:end]
        start = end
        end += 8
        (val1.vlimit,) = _get_struct_d().unpack(str[start:end])
        _v9 = val1.point
        _x = _v9
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.regulatory_elements.special_nodes.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.regulatory_elements.special_ways = []
      for i in range(0, length):
        val1 = lanelet_map_msgs.msg.Way()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.task_area = str[start:end].decode('utf-8')
        else:
          val1.task_area = str[start:end]
        _x = val1
        start = end
        end += 18
        (_x.is_forward, _x.open_concave_obs_det, _x.open_dynamic_obs_det, _x.open_foggy_det, _x.open_water_det, _x.foggy_area, _x.lawn_area, _x.water_area, _x.wall_area, _x.ditch_area, _x.vel_limit,) = _get_struct_10bd().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.points = []
        for i in range(0, length):
          val2 = lanelet_map_msgs.msg.Node()
          start = end
          end += 4
          (val2.id,) = _get_struct_i().unpack(str[start:end])
          start = end
          end += 4
          (length,) = _struct_I.unpack(str[start:end])
          start = end
          end += length
          if python3:
            val2.type = str[start:end].decode('utf-8')
          else:
            val2.type = str[start:end]
          start = end
          end += 8
          (val2.vlimit,) = _get_struct_d().unpack(str[start:end])
          _v10 = val2.point
          _x = _v10
          start = end
          end += 24
          (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
          val1.points.append(val2)
        self.regulatory_elements.special_ways.append(val1)
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
      buff.write(_get_struct_i().pack(self.id))
      _x = self.left_bound.task_area
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_10bd().pack(_x.left_bound.is_forward, _x.left_bound.open_concave_obs_det, _x.left_bound.open_dynamic_obs_det, _x.left_bound.open_foggy_det, _x.left_bound.open_water_det, _x.left_bound.foggy_area, _x.left_bound.lawn_area, _x.left_bound.water_area, _x.left_bound.wall_area, _x.left_bound.ditch_area, _x.left_bound.vel_limit))
      length = len(self.left_bound.points)
      buff.write(_struct_I.pack(length))
      for val1 in self.left_bound.points:
        buff.write(_get_struct_i().pack(val1.id))
        _x = val1.type
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        buff.write(_get_struct_d().pack(val1.vlimit))
        _v11 = val1.point
        _x = _v11
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      _x = self.right_bound.task_area
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_10bd().pack(_x.right_bound.is_forward, _x.right_bound.open_concave_obs_det, _x.right_bound.open_dynamic_obs_det, _x.right_bound.open_foggy_det, _x.right_bound.open_water_det, _x.right_bound.foggy_area, _x.right_bound.lawn_area, _x.right_bound.water_area, _x.right_bound.wall_area, _x.right_bound.ditch_area, _x.right_bound.vel_limit))
      length = len(self.right_bound.points)
      buff.write(_struct_I.pack(length))
      for val1 in self.right_bound.points:
        buff.write(_get_struct_i().pack(val1.id))
        _x = val1.type
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        buff.write(_get_struct_d().pack(val1.vlimit))
        _v12 = val1.point
        _x = _v12
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      _x = self.centerline.task_area
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_10bd().pack(_x.centerline.is_forward, _x.centerline.open_concave_obs_det, _x.centerline.open_dynamic_obs_det, _x.centerline.open_foggy_det, _x.centerline.open_water_det, _x.centerline.foggy_area, _x.centerline.lawn_area, _x.centerline.water_area, _x.centerline.wall_area, _x.centerline.ditch_area, _x.centerline.vel_limit))
      length = len(self.centerline.points)
      buff.write(_struct_I.pack(length))
      for val1 in self.centerline.points:
        buff.write(_get_struct_i().pack(val1.id))
        _x = val1.type
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        buff.write(_get_struct_d().pack(val1.vlimit))
        _v13 = val1.point
        _x = _v13
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      length = len(self.regulatory_elements.special_nodes)
      buff.write(_struct_I.pack(length))
      for val1 in self.regulatory_elements.special_nodes:
        buff.write(_get_struct_i().pack(val1.id))
        _x = val1.type
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        buff.write(_get_struct_d().pack(val1.vlimit))
        _v14 = val1.point
        _x = _v14
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      length = len(self.regulatory_elements.special_ways)
      buff.write(_struct_I.pack(length))
      for val1 in self.regulatory_elements.special_ways:
        _x = val1.task_area
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_get_struct_10bd().pack(_x.is_forward, _x.open_concave_obs_det, _x.open_dynamic_obs_det, _x.open_foggy_det, _x.open_water_det, _x.foggy_area, _x.lawn_area, _x.water_area, _x.wall_area, _x.ditch_area, _x.vel_limit))
        length = len(val1.points)
        buff.write(_struct_I.pack(length))
        for val2 in val1.points:
          buff.write(_get_struct_i().pack(val2.id))
          _x = val2.type
          length = len(_x)
          if python3 or type(_x) == unicode:
            _x = _x.encode('utf-8')
            length = len(_x)
          buff.write(struct.pack('<I%ss'%length, length, _x))
          buff.write(_get_struct_d().pack(val2.vlimit))
          _v15 = val2.point
          _x = _v15
          buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.left_bound is None:
        self.left_bound = lanelet_map_msgs.msg.Way()
      if self.right_bound is None:
        self.right_bound = lanelet_map_msgs.msg.Way()
      if self.centerline is None:
        self.centerline = lanelet_map_msgs.msg.Way()
      if self.regulatory_elements is None:
        self.regulatory_elements = lanelet_map_msgs.msg.Regulatory()
      end = 0
      start = end
      end += 4
      (self.id,) = _get_struct_i().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.left_bound.task_area = str[start:end].decode('utf-8')
      else:
        self.left_bound.task_area = str[start:end]
      _x = self
      start = end
      end += 18
      (_x.left_bound.is_forward, _x.left_bound.open_concave_obs_det, _x.left_bound.open_dynamic_obs_det, _x.left_bound.open_foggy_det, _x.left_bound.open_water_det, _x.left_bound.foggy_area, _x.left_bound.lawn_area, _x.left_bound.water_area, _x.left_bound.wall_area, _x.left_bound.ditch_area, _x.left_bound.vel_limit,) = _get_struct_10bd().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.left_bound.points = []
      for i in range(0, length):
        val1 = lanelet_map_msgs.msg.Node()
        start = end
        end += 4
        (val1.id,) = _get_struct_i().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.type = str[start:end].decode('utf-8')
        else:
          val1.type = str[start:end]
        start = end
        end += 8
        (val1.vlimit,) = _get_struct_d().unpack(str[start:end])
        _v16 = val1.point
        _x = _v16
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.left_bound.points.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.right_bound.task_area = str[start:end].decode('utf-8')
      else:
        self.right_bound.task_area = str[start:end]
      _x = self
      start = end
      end += 18
      (_x.right_bound.is_forward, _x.right_bound.open_concave_obs_det, _x.right_bound.open_dynamic_obs_det, _x.right_bound.open_foggy_det, _x.right_bound.open_water_det, _x.right_bound.foggy_area, _x.right_bound.lawn_area, _x.right_bound.water_area, _x.right_bound.wall_area, _x.right_bound.ditch_area, _x.right_bound.vel_limit,) = _get_struct_10bd().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.right_bound.points = []
      for i in range(0, length):
        val1 = lanelet_map_msgs.msg.Node()
        start = end
        end += 4
        (val1.id,) = _get_struct_i().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.type = str[start:end].decode('utf-8')
        else:
          val1.type = str[start:end]
        start = end
        end += 8
        (val1.vlimit,) = _get_struct_d().unpack(str[start:end])
        _v17 = val1.point
        _x = _v17
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.right_bound.points.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.centerline.task_area = str[start:end].decode('utf-8')
      else:
        self.centerline.task_area = str[start:end]
      _x = self
      start = end
      end += 18
      (_x.centerline.is_forward, _x.centerline.open_concave_obs_det, _x.centerline.open_dynamic_obs_det, _x.centerline.open_foggy_det, _x.centerline.open_water_det, _x.centerline.foggy_area, _x.centerline.lawn_area, _x.centerline.water_area, _x.centerline.wall_area, _x.centerline.ditch_area, _x.centerline.vel_limit,) = _get_struct_10bd().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.centerline.points = []
      for i in range(0, length):
        val1 = lanelet_map_msgs.msg.Node()
        start = end
        end += 4
        (val1.id,) = _get_struct_i().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.type = str[start:end].decode('utf-8')
        else:
          val1.type = str[start:end]
        start = end
        end += 8
        (val1.vlimit,) = _get_struct_d().unpack(str[start:end])
        _v18 = val1.point
        _x = _v18
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.centerline.points.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.regulatory_elements.special_nodes = []
      for i in range(0, length):
        val1 = lanelet_map_msgs.msg.Node()
        start = end
        end += 4
        (val1.id,) = _get_struct_i().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.type = str[start:end].decode('utf-8')
        else:
          val1.type = str[start:end]
        start = end
        end += 8
        (val1.vlimit,) = _get_struct_d().unpack(str[start:end])
        _v19 = val1.point
        _x = _v19
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.regulatory_elements.special_nodes.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.regulatory_elements.special_ways = []
      for i in range(0, length):
        val1 = lanelet_map_msgs.msg.Way()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.task_area = str[start:end].decode('utf-8')
        else:
          val1.task_area = str[start:end]
        _x = val1
        start = end
        end += 18
        (_x.is_forward, _x.open_concave_obs_det, _x.open_dynamic_obs_det, _x.open_foggy_det, _x.open_water_det, _x.foggy_area, _x.lawn_area, _x.water_area, _x.wall_area, _x.ditch_area, _x.vel_limit,) = _get_struct_10bd().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.points = []
        for i in range(0, length):
          val2 = lanelet_map_msgs.msg.Node()
          start = end
          end += 4
          (val2.id,) = _get_struct_i().unpack(str[start:end])
          start = end
          end += 4
          (length,) = _struct_I.unpack(str[start:end])
          start = end
          end += length
          if python3:
            val2.type = str[start:end].decode('utf-8')
          else:
            val2.type = str[start:end]
          start = end
          end += 8
          (val2.vlimit,) = _get_struct_d().unpack(str[start:end])
          _v20 = val2.point
          _x = _v20
          start = end
          end += 24
          (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
          val1.points.append(val2)
        self.regulatory_elements.special_ways.append(val1)
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
_struct_10bd = None
def _get_struct_10bd():
    global _struct_10bd
    if _struct_10bd is None:
        _struct_10bd = struct.Struct("<10bd")
    return _struct_10bd
_struct_d = None
def _get_struct_d():
    global _struct_d
    if _struct_d is None:
        _struct_d = struct.Struct("<d")
    return _struct_d
_struct_3d = None
def _get_struct_3d():
    global _struct_3d
    if _struct_3d is None:
        _struct_3d = struct.Struct("<3d")
    return _struct_3d
