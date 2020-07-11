; Auto-generated. Do not edit!


(cl:in-package vertical_wall_grid-msg)


;//! \htmlinclude vertical_wall_grid.msg.html

(cl:defclass <vertical_wall_grid> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (detected
    :reader detected
    :initarg :detected
    :type cl:boolean
    :initform cl:nil)
   (dis
    :reader dis
    :initarg :dis
    :type cl:float
    :initform 0.0)
   (angle
    :reader angle
    :initarg :angle
    :type cl:float
    :initform 0.0)
   (height
    :reader height
    :initarg :height
    :type cl:float
    :initform 0.0)
   (center
    :reader center
    :initarg :center
    :type (cl:vector cl:float)
   :initform (cl:make-array 2 :element-type 'cl:float :initial-element 0.0))
   (vertical
    :reader vertical
    :initarg :vertical
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass vertical_wall_grid (<vertical_wall_grid>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <vertical_wall_grid>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'vertical_wall_grid)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name vertical_wall_grid-msg:<vertical_wall_grid> is deprecated: use vertical_wall_grid-msg:vertical_wall_grid instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <vertical_wall_grid>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader vertical_wall_grid-msg:header-val is deprecated.  Use vertical_wall_grid-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'detected-val :lambda-list '(m))
(cl:defmethod detected-val ((m <vertical_wall_grid>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader vertical_wall_grid-msg:detected-val is deprecated.  Use vertical_wall_grid-msg:detected instead.")
  (detected m))

(cl:ensure-generic-function 'dis-val :lambda-list '(m))
(cl:defmethod dis-val ((m <vertical_wall_grid>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader vertical_wall_grid-msg:dis-val is deprecated.  Use vertical_wall_grid-msg:dis instead.")
  (dis m))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <vertical_wall_grid>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader vertical_wall_grid-msg:angle-val is deprecated.  Use vertical_wall_grid-msg:angle instead.")
  (angle m))

(cl:ensure-generic-function 'height-val :lambda-list '(m))
(cl:defmethod height-val ((m <vertical_wall_grid>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader vertical_wall_grid-msg:height-val is deprecated.  Use vertical_wall_grid-msg:height instead.")
  (height m))

(cl:ensure-generic-function 'center-val :lambda-list '(m))
(cl:defmethod center-val ((m <vertical_wall_grid>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader vertical_wall_grid-msg:center-val is deprecated.  Use vertical_wall_grid-msg:center instead.")
  (center m))

(cl:ensure-generic-function 'vertical-val :lambda-list '(m))
(cl:defmethod vertical-val ((m <vertical_wall_grid>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader vertical_wall_grid-msg:vertical-val is deprecated.  Use vertical_wall_grid-msg:vertical instead.")
  (vertical m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <vertical_wall_grid>) ostream)
  "Serializes a message object of type '<vertical_wall_grid>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'detected) 1 0)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'dis))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'height))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'center))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'vertical) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <vertical_wall_grid>) istream)
  "Deserializes a message object of type '<vertical_wall_grid>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:slot-value msg 'detected) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'dis) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'angle) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'height) (roslisp-utils:decode-single-float-bits bits)))
  (cl:setf (cl:slot-value msg 'center) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'center)))
    (cl:dotimes (i 2)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
    (cl:setf (cl:slot-value msg 'vertical) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<vertical_wall_grid>)))
  "Returns string type for a message object of type '<vertical_wall_grid>"
  "vertical_wall_grid/vertical_wall_grid")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'vertical_wall_grid)))
  "Returns string type for a message object of type 'vertical_wall_grid"
  "vertical_wall_grid/vertical_wall_grid")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<vertical_wall_grid>)))
  "Returns md5sum for a message object of type '<vertical_wall_grid>"
  "f060965c53a68944b55190b69cd4980c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'vertical_wall_grid)))
  "Returns md5sum for a message object of type 'vertical_wall_grid"
  "f060965c53a68944b55190b69cd4980c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<vertical_wall_grid>)))
  "Returns full string definition for message of type '<vertical_wall_grid>"
  (cl:format cl:nil "std_msgs/Header header~%bool detected~%float32 dis~%float32 angle~%float32 height~%float32[2] center~%bool vertical~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'vertical_wall_grid)))
  "Returns full string definition for message of type 'vertical_wall_grid"
  (cl:format cl:nil "std_msgs/Header header~%bool detected~%float32 dis~%float32 angle~%float32 height~%float32[2] center~%bool vertical~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <vertical_wall_grid>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     4
     4
     4
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'center) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <vertical_wall_grid>))
  "Converts a ROS message object to a list"
  (cl:list 'vertical_wall_grid
    (cl:cons ':header (header msg))
    (cl:cons ':detected (detected msg))
    (cl:cons ':dis (dis msg))
    (cl:cons ':angle (angle msg))
    (cl:cons ':height (height msg))
    (cl:cons ':center (center msg))
    (cl:cons ':vertical (vertical msg))
))
