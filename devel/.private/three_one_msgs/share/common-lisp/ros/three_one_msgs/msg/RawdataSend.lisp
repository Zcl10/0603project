; Auto-generated. Do not edit!


(cl:in-package three_one_msgs-msg)


;//! \htmlinclude RawdataSend.msg.html

(cl:defclass <RawdataSend> (roslisp-msg-protocol:ros-message)
  ((ros_time
    :reader ros_time
    :initarg :ros_time
    :type cl:float
    :initform 0.0)
   (data
    :reader data
    :initarg :data
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0)))
)

(cl:defclass RawdataSend (<RawdataSend>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RawdataSend>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RawdataSend)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name three_one_msgs-msg:<RawdataSend> is deprecated: use three_one_msgs-msg:RawdataSend instead.")))

(cl:ensure-generic-function 'ros_time-val :lambda-list '(m))
(cl:defmethod ros_time-val ((m <RawdataSend>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:ros_time-val is deprecated.  Use three_one_msgs-msg:ros_time instead.")
  (ros_time m))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <RawdataSend>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:data-val is deprecated.  Use three_one_msgs-msg:data instead.")
  (data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RawdataSend>) ostream)
  "Serializes a message object of type '<RawdataSend>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ros_time))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'data))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'data))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RawdataSend>) istream)
  "Deserializes a message object of type '<RawdataSend>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ros_time) (roslisp-utils:decode-double-float-bits bits)))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'data) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'data)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RawdataSend>)))
  "Returns string type for a message object of type '<RawdataSend>"
  "three_one_msgs/RawdataSend")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RawdataSend)))
  "Returns string type for a message object of type 'RawdataSend"
  "three_one_msgs/RawdataSend")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RawdataSend>)))
  "Returns md5sum for a message object of type '<RawdataSend>"
  "a34d701bf319ec12f678fa7cb20e57e3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RawdataSend)))
  "Returns md5sum for a message object of type 'RawdataSend"
  "a34d701bf319ec12f678fa7cb20e57e3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RawdataSend>)))
  "Returns full string definition for message of type '<RawdataSend>"
  (cl:format cl:nil "float64 ros_time~%uint8[] data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RawdataSend)))
  "Returns full string definition for message of type 'RawdataSend"
  (cl:format cl:nil "float64 ros_time~%uint8[] data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RawdataSend>))
  (cl:+ 0
     8
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'data) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RawdataSend>))
  "Converts a ROS message object to a list"
  (cl:list 'RawdataSend
    (cl:cons ':ros_time (ros_time msg))
    (cl:cons ':data (data msg))
))
