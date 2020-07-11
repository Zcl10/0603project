; Auto-generated. Do not edit!


(cl:in-package three_one_msgs-msg)


;//! \htmlinclude ReportGiveBack.msg.html

(cl:defclass <ReportGiveBack> (roslisp-msg-protocol:ros-message)
  ((left_wheel_expect_speed
    :reader left_wheel_expect_speed
    :initarg :left_wheel_expect_speed
    :type cl:float
    :initform 0.0)
   (right_wheel_expect_speed
    :reader right_wheel_expect_speed
    :initarg :right_wheel_expect_speed
    :type cl:float
    :initform 0.0))
)

(cl:defclass ReportGiveBack (<ReportGiveBack>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReportGiveBack>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReportGiveBack)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name three_one_msgs-msg:<ReportGiveBack> is deprecated: use three_one_msgs-msg:ReportGiveBack instead.")))

(cl:ensure-generic-function 'left_wheel_expect_speed-val :lambda-list '(m))
(cl:defmethod left_wheel_expect_speed-val ((m <ReportGiveBack>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:left_wheel_expect_speed-val is deprecated.  Use three_one_msgs-msg:left_wheel_expect_speed instead.")
  (left_wheel_expect_speed m))

(cl:ensure-generic-function 'right_wheel_expect_speed-val :lambda-list '(m))
(cl:defmethod right_wheel_expect_speed-val ((m <ReportGiveBack>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:right_wheel_expect_speed-val is deprecated.  Use three_one_msgs-msg:right_wheel_expect_speed instead.")
  (right_wheel_expect_speed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReportGiveBack>) ostream)
  "Serializes a message object of type '<ReportGiveBack>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'left_wheel_expect_speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'right_wheel_expect_speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReportGiveBack>) istream)
  "Deserializes a message object of type '<ReportGiveBack>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_wheel_expect_speed) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_wheel_expect_speed) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReportGiveBack>)))
  "Returns string type for a message object of type '<ReportGiveBack>"
  "three_one_msgs/ReportGiveBack")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReportGiveBack)))
  "Returns string type for a message object of type 'ReportGiveBack"
  "three_one_msgs/ReportGiveBack")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReportGiveBack>)))
  "Returns md5sum for a message object of type '<ReportGiveBack>"
  "a412fdf7ba4df281362ad0892df1c4a0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReportGiveBack)))
  "Returns md5sum for a message object of type 'ReportGiveBack"
  "a412fdf7ba4df281362ad0892df1c4a0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReportGiveBack>)))
  "Returns full string definition for message of type '<ReportGiveBack>"
  (cl:format cl:nil "float32 left_wheel_expect_speed~%float32 right_wheel_expect_speed~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReportGiveBack)))
  "Returns full string definition for message of type 'ReportGiveBack"
  (cl:format cl:nil "float32 left_wheel_expect_speed~%float32 right_wheel_expect_speed~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReportGiveBack>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReportGiveBack>))
  "Converts a ROS message object to a list"
  (cl:list 'ReportGiveBack
    (cl:cons ':left_wheel_expect_speed (left_wheel_expect_speed msg))
    (cl:cons ':right_wheel_expect_speed (right_wheel_expect_speed msg))
))
