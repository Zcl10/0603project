; Auto-generated. Do not edit!


(cl:in-package three_one_msgs-msg)


;//! \htmlinclude ReportCylinderPressure.msg.html

(cl:defclass <ReportCylinderPressure> (roslisp-msg-protocol:ros-message)
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

(cl:defclass ReportCylinderPressure (<ReportCylinderPressure>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReportCylinderPressure>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReportCylinderPressure)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name three_one_msgs-msg:<ReportCylinderPressure> is deprecated: use three_one_msgs-msg:ReportCylinderPressure instead.")))

(cl:ensure-generic-function 'left_one-val :lambda-list '(m))
(cl:defmethod left_one-val ((m <ReportCylinderPressure>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:left_one-val is deprecated.  Use three_one_msgs-msg:left_one instead.")
  (left_one m))

(cl:ensure-generic-function 'left_two-val :lambda-list '(m))
(cl:defmethod left_two-val ((m <ReportCylinderPressure>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:left_two-val is deprecated.  Use three_one_msgs-msg:left_two instead.")
  (left_two m))

(cl:ensure-generic-function 'left_three-val :lambda-list '(m))
(cl:defmethod left_three-val ((m <ReportCylinderPressure>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:left_three-val is deprecated.  Use three_one_msgs-msg:left_three instead.")
  (left_three m))

(cl:ensure-generic-function 'left_four-val :lambda-list '(m))
(cl:defmethod left_four-val ((m <ReportCylinderPressure>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:left_four-val is deprecated.  Use three_one_msgs-msg:left_four instead.")
  (left_four m))

(cl:ensure-generic-function 'right_one-val :lambda-list '(m))
(cl:defmethod right_one-val ((m <ReportCylinderPressure>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:right_one-val is deprecated.  Use three_one_msgs-msg:right_one instead.")
  (right_one m))

(cl:ensure-generic-function 'right_two-val :lambda-list '(m))
(cl:defmethod right_two-val ((m <ReportCylinderPressure>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:right_two-val is deprecated.  Use three_one_msgs-msg:right_two instead.")
  (right_two m))

(cl:ensure-generic-function 'right_three-val :lambda-list '(m))
(cl:defmethod right_three-val ((m <ReportCylinderPressure>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:right_three-val is deprecated.  Use three_one_msgs-msg:right_three instead.")
  (right_three m))

(cl:ensure-generic-function 'right_four-val :lambda-list '(m))
(cl:defmethod right_four-val ((m <ReportCylinderPressure>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:right_four-val is deprecated.  Use three_one_msgs-msg:right_four instead.")
  (right_four m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReportCylinderPressure>) ostream)
  "Serializes a message object of type '<ReportCylinderPressure>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_one)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_two)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_three)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_four)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_one)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_two)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_three)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_four)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReportCylinderPressure>) istream)
  "Deserializes a message object of type '<ReportCylinderPressure>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_one)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_two)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_three)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_four)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_one)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_two)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_three)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_four)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReportCylinderPressure>)))
  "Returns string type for a message object of type '<ReportCylinderPressure>"
  "three_one_msgs/ReportCylinderPressure")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReportCylinderPressure)))
  "Returns string type for a message object of type 'ReportCylinderPressure"
  "three_one_msgs/ReportCylinderPressure")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReportCylinderPressure>)))
  "Returns md5sum for a message object of type '<ReportCylinderPressure>"
  "e261355aeec2b4d716939018ae20229e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReportCylinderPressure)))
  "Returns md5sum for a message object of type 'ReportCylinderPressure"
  "e261355aeec2b4d716939018ae20229e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReportCylinderPressure>)))
  "Returns full string definition for message of type '<ReportCylinderPressure>"
  (cl:format cl:nil "uint8 left_one~%uint8 left_two~%uint8 left_three~%uint8 left_four~%uint8 right_one~%uint8 right_two~%uint8 right_three~%uint8 right_four~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReportCylinderPressure)))
  "Returns full string definition for message of type 'ReportCylinderPressure"
  (cl:format cl:nil "uint8 left_one~%uint8 left_two~%uint8 left_three~%uint8 left_four~%uint8 right_one~%uint8 right_two~%uint8 right_three~%uint8 right_four~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReportCylinderPressure>))
  (cl:+ 0
     1
     1
     1
     1
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReportCylinderPressure>))
  "Converts a ROS message object to a list"
  (cl:list 'ReportCylinderPressure
    (cl:cons ':left_one (left_one msg))
    (cl:cons ':left_two (left_two msg))
    (cl:cons ':left_three (left_three msg))
    (cl:cons ':left_four (left_four msg))
    (cl:cons ':right_one (right_one msg))
    (cl:cons ':right_two (right_two msg))
    (cl:cons ':right_three (right_three msg))
    (cl:cons ':right_four (right_four msg))
))
