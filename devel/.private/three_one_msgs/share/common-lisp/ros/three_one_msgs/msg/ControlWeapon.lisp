; Auto-generated. Do not edit!


(cl:in-package three_one_msgs-msg)


;//! \htmlinclude ControlWeapon.msg.html

(cl:defclass <ControlWeapon> (roslisp-msg-protocol:ros-message)
  ((priority
    :reader priority
    :initarg :priority
    :type cl:fixnum
    :initform 0)
   (weapon_330
    :reader weapon_330
    :initarg :weapon_330
    :type cl:fixnum
    :initform 0)
   (weapon_28
    :reader weapon_28
    :initarg :weapon_28
    :type cl:fixnum
    :initform 0)
   (weapon_cmd
    :reader weapon_cmd
    :initarg :weapon_cmd
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ControlWeapon (<ControlWeapon>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ControlWeapon>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ControlWeapon)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name three_one_msgs-msg:<ControlWeapon> is deprecated: use three_one_msgs-msg:ControlWeapon instead.")))

(cl:ensure-generic-function 'priority-val :lambda-list '(m))
(cl:defmethod priority-val ((m <ControlWeapon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:priority-val is deprecated.  Use three_one_msgs-msg:priority instead.")
  (priority m))

(cl:ensure-generic-function 'weapon_330-val :lambda-list '(m))
(cl:defmethod weapon_330-val ((m <ControlWeapon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:weapon_330-val is deprecated.  Use three_one_msgs-msg:weapon_330 instead.")
  (weapon_330 m))

(cl:ensure-generic-function 'weapon_28-val :lambda-list '(m))
(cl:defmethod weapon_28-val ((m <ControlWeapon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:weapon_28-val is deprecated.  Use three_one_msgs-msg:weapon_28 instead.")
  (weapon_28 m))

(cl:ensure-generic-function 'weapon_cmd-val :lambda-list '(m))
(cl:defmethod weapon_cmd-val ((m <ControlWeapon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:weapon_cmd-val is deprecated.  Use three_one_msgs-msg:weapon_cmd instead.")
  (weapon_cmd m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ControlWeapon>) ostream)
  "Serializes a message object of type '<ControlWeapon>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'priority)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'weapon_330)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'weapon_28)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'weapon_cmd)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ControlWeapon>) istream)
  "Deserializes a message object of type '<ControlWeapon>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'priority)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'weapon_330)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'weapon_28)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'weapon_cmd)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ControlWeapon>)))
  "Returns string type for a message object of type '<ControlWeapon>"
  "three_one_msgs/ControlWeapon")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ControlWeapon)))
  "Returns string type for a message object of type 'ControlWeapon"
  "three_one_msgs/ControlWeapon")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ControlWeapon>)))
  "Returns md5sum for a message object of type '<ControlWeapon>"
  "4cc1e4ec0b5615d8df21778e6fab18ae")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ControlWeapon)))
  "Returns md5sum for a message object of type 'ControlWeapon"
  "4cc1e4ec0b5615d8df21778e6fab18ae")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ControlWeapon>)))
  "Returns full string definition for message of type '<ControlWeapon>"
  (cl:format cl:nil "uint8 priority~%uint8 weapon_330~%uint8 weapon_28~%uint8 weapon_cmd~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ControlWeapon)))
  "Returns full string definition for message of type 'ControlWeapon"
  (cl:format cl:nil "uint8 priority~%uint8 weapon_330~%uint8 weapon_28~%uint8 weapon_cmd~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ControlWeapon>))
  (cl:+ 0
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ControlWeapon>))
  "Converts a ROS message object to a list"
  (cl:list 'ControlWeapon
    (cl:cons ':priority (priority msg))
    (cl:cons ':weapon_330 (weapon_330 msg))
    (cl:cons ':weapon_28 (weapon_28 msg))
    (cl:cons ':weapon_cmd (weapon_cmd msg))
))
