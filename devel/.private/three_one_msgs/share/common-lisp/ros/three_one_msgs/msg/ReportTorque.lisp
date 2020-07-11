; Auto-generated. Do not edit!


(cl:in-package three_one_msgs-msg)


;//! \htmlinclude ReportTorque.msg.html

(cl:defclass <ReportTorque> (roslisp-msg-protocol:ros-message)
  ((left
    :reader left
    :initarg :left
    :type cl:fixnum
    :initform 0)
   (right
    :reader right
    :initarg :right
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ReportTorque (<ReportTorque>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReportTorque>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReportTorque)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name three_one_msgs-msg:<ReportTorque> is deprecated: use three_one_msgs-msg:ReportTorque instead.")))

(cl:ensure-generic-function 'left-val :lambda-list '(m))
(cl:defmethod left-val ((m <ReportTorque>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:left-val is deprecated.  Use three_one_msgs-msg:left instead.")
  (left m))

(cl:ensure-generic-function 'right-val :lambda-list '(m))
(cl:defmethod right-val ((m <ReportTorque>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:right-val is deprecated.  Use three_one_msgs-msg:right instead.")
  (right m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReportTorque>) ostream)
  "Serializes a message object of type '<ReportTorque>"
  (cl:let* ((signed (cl:slot-value msg 'left)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'right)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReportTorque>) istream)
  "Deserializes a message object of type '<ReportTorque>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'left) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'right) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReportTorque>)))
  "Returns string type for a message object of type '<ReportTorque>"
  "three_one_msgs/ReportTorque")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReportTorque)))
  "Returns string type for a message object of type 'ReportTorque"
  "three_one_msgs/ReportTorque")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReportTorque>)))
  "Returns md5sum for a message object of type '<ReportTorque>"
  "09d1b2323a1aeae9343e81809a820b60")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReportTorque)))
  "Returns md5sum for a message object of type 'ReportTorque"
  "09d1b2323a1aeae9343e81809a820b60")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReportTorque>)))
  "Returns full string definition for message of type '<ReportTorque>"
  (cl:format cl:nil "int16 left~%int16 right~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReportTorque)))
  "Returns full string definition for message of type 'ReportTorque"
  (cl:format cl:nil "int16 left~%int16 right~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReportTorque>))
  (cl:+ 0
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReportTorque>))
  "Converts a ROS message object to a list"
  (cl:list 'ReportTorque
    (cl:cons ':left (left msg))
    (cl:cons ':right (right msg))
))
