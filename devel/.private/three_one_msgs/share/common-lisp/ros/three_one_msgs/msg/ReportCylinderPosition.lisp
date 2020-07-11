; Auto-generated. Do not edit!


(cl:in-package three_one_msgs-msg)


;//! \htmlinclude ReportCylinderPosition.msg.html

(cl:defclass <ReportCylinderPosition> (roslisp-msg-protocol:ros-message)
  ((left_one
    :reader left_one
    :initarg :left_one
    :type cl:fixnum
    :initform 0)
   (left_two
    :reader left_two
    :initarg :left_two
    :type cl:fixnum
    :initform 0)
   (left_three
    :reader left_three
    :initarg :left_three
    :type cl:fixnum
    :initform 0)
   (left_four
    :reader left_four
    :initarg :left_four
    :type cl:fixnum
    :initform 0)
   (right_one
    :reader right_one
    :initarg :right_one
    :type cl:fixnum
    :initform 0)
   (right_two
    :reader right_two
    :initarg :right_two
    :type cl:fixnum
    :initform 0)
   (right_three
    :reader right_three
    :initarg :right_three
    :type cl:fixnum
    :initform 0)
   (right_four
    :reader right_four
    :initarg :right_four
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ReportCylinderPosition (<ReportCylinderPosition>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReportCylinderPosition>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReportCylinderPosition)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name three_one_msgs-msg:<ReportCylinderPosition> is deprecated: use three_one_msgs-msg:ReportCylinderPosition instead.")))

(cl:ensure-generic-function 'left_one-val :lambda-list '(m))
(cl:defmethod left_one-val ((m <ReportCylinderPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:left_one-val is deprecated.  Use three_one_msgs-msg:left_one instead.")
  (left_one m))

(cl:ensure-generic-function 'left_two-val :lambda-list '(m))
(cl:defmethod left_two-val ((m <ReportCylinderPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:left_two-val is deprecated.  Use three_one_msgs-msg:left_two instead.")
  (left_two m))

(cl:ensure-generic-function 'left_three-val :lambda-list '(m))
(cl:defmethod left_three-val ((m <ReportCylinderPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:left_three-val is deprecated.  Use three_one_msgs-msg:left_three instead.")
  (left_three m))

(cl:ensure-generic-function 'left_four-val :lambda-list '(m))
(cl:defmethod left_four-val ((m <ReportCylinderPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:left_four-val is deprecated.  Use three_one_msgs-msg:left_four instead.")
  (left_four m))

(cl:ensure-generic-function 'right_one-val :lambda-list '(m))
(cl:defmethod right_one-val ((m <ReportCylinderPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:right_one-val is deprecated.  Use three_one_msgs-msg:right_one instead.")
  (right_one m))

(cl:ensure-generic-function 'right_two-val :lambda-list '(m))
(cl:defmethod right_two-val ((m <ReportCylinderPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:right_two-val is deprecated.  Use three_one_msgs-msg:right_two instead.")
  (right_two m))

(cl:ensure-generic-function 'right_three-val :lambda-list '(m))
(cl:defmethod right_three-val ((m <ReportCylinderPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:right_three-val is deprecated.  Use three_one_msgs-msg:right_three instead.")
  (right_three m))

(cl:ensure-generic-function 'right_four-val :lambda-list '(m))
(cl:defmethod right_four-val ((m <ReportCylinderPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:right_four-val is deprecated.  Use three_one_msgs-msg:right_four instead.")
  (right_four m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReportCylinderPosition>) ostream)
  "Serializes a message object of type '<ReportCylinderPosition>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_one)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'left_one)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_two)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'left_two)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_three)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'left_three)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_four)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'left_four)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_one)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'right_one)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_two)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'right_two)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_three)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'right_three)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_four)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'right_four)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReportCylinderPosition>) istream)
  "Deserializes a message object of type '<ReportCylinderPosition>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_one)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'left_one)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_two)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'left_two)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_three)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'left_three)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_four)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'left_four)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_one)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'right_one)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_two)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'right_two)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_three)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'right_three)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_four)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'right_four)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReportCylinderPosition>)))
  "Returns string type for a message object of type '<ReportCylinderPosition>"
  "three_one_msgs/ReportCylinderPosition")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReportCylinderPosition)))
  "Returns string type for a message object of type 'ReportCylinderPosition"
  "three_one_msgs/ReportCylinderPosition")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReportCylinderPosition>)))
  "Returns md5sum for a message object of type '<ReportCylinderPosition>"
  "10a79bbfdcab9d59df66b73e79bbb8ac")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReportCylinderPosition)))
  "Returns md5sum for a message object of type 'ReportCylinderPosition"
  "10a79bbfdcab9d59df66b73e79bbb8ac")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReportCylinderPosition>)))
  "Returns full string definition for message of type '<ReportCylinderPosition>"
  (cl:format cl:nil "uint16 left_one~%uint16 left_two~%uint16 left_three~%uint16 left_four~%uint16 right_one~%uint16 right_two~%uint16 right_three~%uint16 right_four~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReportCylinderPosition)))
  "Returns full string definition for message of type 'ReportCylinderPosition"
  (cl:format cl:nil "uint16 left_one~%uint16 left_two~%uint16 left_three~%uint16 left_four~%uint16 right_one~%uint16 right_two~%uint16 right_three~%uint16 right_four~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReportCylinderPosition>))
  (cl:+ 0
     2
     2
     2
     2
     2
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReportCylinderPosition>))
  "Converts a ROS message object to a list"
  (cl:list 'ReportCylinderPosition
    (cl:cons ':left_one (left_one msg))
    (cl:cons ':left_two (left_two msg))
    (cl:cons ':left_three (left_three msg))
    (cl:cons ':left_four (left_four msg))
    (cl:cons ':right_one (right_one msg))
    (cl:cons ':right_two (right_two msg))
    (cl:cons ':right_three (right_three msg))
    (cl:cons ':right_four (right_four msg))
))
