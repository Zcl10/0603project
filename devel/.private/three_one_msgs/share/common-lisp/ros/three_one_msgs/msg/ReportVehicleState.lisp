; Auto-generated. Do not edit!


(cl:in-package three_one_msgs-msg)


;//! \htmlinclude ReportVehicleState.msg.html

(cl:defclass <ReportVehicleState> (roslisp-msg-protocol:ros-message)
  ((error_code
    :reader error_code
    :initarg :error_code
    :type cl:fixnum
    :initform 0)
   (two_chamber_valve
    :reader two_chamber_valve
    :initarg :two_chamber_valve
    :type cl:fixnum
    :initform 0)
   (vertical_wall_status
    :reader vertical_wall_status
    :initarg :vertical_wall_status
    :type cl:fixnum
    :initform 0)
   (entrenchment
    :reader entrenchment
    :initarg :entrenchment
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
   (vehicle_height
    :reader vehicle_height
    :initarg :vehicle_height
    :type cl:fixnum
    :initform 0)
   (tailgate_state
    :reader tailgate_state
    :initarg :tailgate_state
    :type cl:fixnum
    :initform 0)
   (SOC
    :reader SOC
    :initarg :SOC
    :type cl:fixnum
    :initform 0)
   (vehicle_roll
    :reader vehicle_roll
    :initarg :vehicle_roll
    :type cl:fixnum
    :initform 0)
   (vehicle_pitch
    :reader vehicle_pitch
    :initarg :vehicle_pitch
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ReportVehicleState (<ReportVehicleState>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReportVehicleState>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReportVehicleState)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name three_one_msgs-msg:<ReportVehicleState> is deprecated: use three_one_msgs-msg:ReportVehicleState instead.")))

(cl:ensure-generic-function 'error_code-val :lambda-list '(m))
(cl:defmethod error_code-val ((m <ReportVehicleState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:error_code-val is deprecated.  Use three_one_msgs-msg:error_code instead.")
  (error_code m))

(cl:ensure-generic-function 'two_chamber_valve-val :lambda-list '(m))
(cl:defmethod two_chamber_valve-val ((m <ReportVehicleState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:two_chamber_valve-val is deprecated.  Use three_one_msgs-msg:two_chamber_valve instead.")
  (two_chamber_valve m))

(cl:ensure-generic-function 'vertical_wall_status-val :lambda-list '(m))
(cl:defmethod vertical_wall_status-val ((m <ReportVehicleState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:vertical_wall_status-val is deprecated.  Use three_one_msgs-msg:vertical_wall_status instead.")
  (vertical_wall_status m))

(cl:ensure-generic-function 'entrenchment-val :lambda-list '(m))
(cl:defmethod entrenchment-val ((m <ReportVehicleState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:entrenchment-val is deprecated.  Use three_one_msgs-msg:entrenchment instead.")
  (entrenchment m))

(cl:ensure-generic-function 'weapon_330-val :lambda-list '(m))
(cl:defmethod weapon_330-val ((m <ReportVehicleState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:weapon_330-val is deprecated.  Use three_one_msgs-msg:weapon_330 instead.")
  (weapon_330 m))

(cl:ensure-generic-function 'weapon_28-val :lambda-list '(m))
(cl:defmethod weapon_28-val ((m <ReportVehicleState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:weapon_28-val is deprecated.  Use three_one_msgs-msg:weapon_28 instead.")
  (weapon_28 m))

(cl:ensure-generic-function 'vehicle_height-val :lambda-list '(m))
(cl:defmethod vehicle_height-val ((m <ReportVehicleState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:vehicle_height-val is deprecated.  Use three_one_msgs-msg:vehicle_height instead.")
  (vehicle_height m))

(cl:ensure-generic-function 'tailgate_state-val :lambda-list '(m))
(cl:defmethod tailgate_state-val ((m <ReportVehicleState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:tailgate_state-val is deprecated.  Use three_one_msgs-msg:tailgate_state instead.")
  (tailgate_state m))

(cl:ensure-generic-function 'SOC-val :lambda-list '(m))
(cl:defmethod SOC-val ((m <ReportVehicleState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:SOC-val is deprecated.  Use three_one_msgs-msg:SOC instead.")
  (SOC m))

(cl:ensure-generic-function 'vehicle_roll-val :lambda-list '(m))
(cl:defmethod vehicle_roll-val ((m <ReportVehicleState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:vehicle_roll-val is deprecated.  Use three_one_msgs-msg:vehicle_roll instead.")
  (vehicle_roll m))

(cl:ensure-generic-function 'vehicle_pitch-val :lambda-list '(m))
(cl:defmethod vehicle_pitch-val ((m <ReportVehicleState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:vehicle_pitch-val is deprecated.  Use three_one_msgs-msg:vehicle_pitch instead.")
  (vehicle_pitch m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReportVehicleState>) ostream)
  "Serializes a message object of type '<ReportVehicleState>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'error_code)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'two_chamber_valve)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vertical_wall_status)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'entrenchment)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'weapon_330)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'weapon_28)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vehicle_height)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tailgate_state)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'SOC)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'vehicle_roll)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'vehicle_pitch)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReportVehicleState>) istream)
  "Deserializes a message object of type '<ReportVehicleState>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'error_code)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'two_chamber_valve)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vertical_wall_status)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'entrenchment)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'weapon_330)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'weapon_28)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vehicle_height)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tailgate_state)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'SOC)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'vehicle_roll) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'vehicle_pitch) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReportVehicleState>)))
  "Returns string type for a message object of type '<ReportVehicleState>"
  "three_one_msgs/ReportVehicleState")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReportVehicleState)))
  "Returns string type for a message object of type 'ReportVehicleState"
  "three_one_msgs/ReportVehicleState")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReportVehicleState>)))
  "Returns md5sum for a message object of type '<ReportVehicleState>"
  "038961e65ff3db9742a20c76bdc20ca1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReportVehicleState)))
  "Returns md5sum for a message object of type 'ReportVehicleState"
  "038961e65ff3db9742a20c76bdc20ca1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReportVehicleState>)))
  "Returns full string definition for message of type '<ReportVehicleState>"
  (cl:format cl:nil "uint8 error_code~%uint8 two_chamber_valve~%uint8 vertical_wall_status~%uint8 entrenchment~%uint8 weapon_330~%uint8 weapon_28~%uint8 vehicle_height~%uint8 tailgate_state~%uint8 SOC~%int8 vehicle_roll~%int8 vehicle_pitch~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReportVehicleState)))
  "Returns full string definition for message of type 'ReportVehicleState"
  (cl:format cl:nil "uint8 error_code~%uint8 two_chamber_valve~%uint8 vertical_wall_status~%uint8 entrenchment~%uint8 weapon_330~%uint8 weapon_28~%uint8 vehicle_height~%uint8 tailgate_state~%uint8 SOC~%int8 vehicle_roll~%int8 vehicle_pitch~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReportVehicleState>))
  (cl:+ 0
     1
     1
     1
     1
     1
     1
     1
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReportVehicleState>))
  "Converts a ROS message object to a list"
  (cl:list 'ReportVehicleState
    (cl:cons ':error_code (error_code msg))
    (cl:cons ':two_chamber_valve (two_chamber_valve msg))
    (cl:cons ':vertical_wall_status (vertical_wall_status msg))
    (cl:cons ':entrenchment (entrenchment msg))
    (cl:cons ':weapon_330 (weapon_330 msg))
    (cl:cons ':weapon_28 (weapon_28 msg))
    (cl:cons ':vehicle_height (vehicle_height msg))
    (cl:cons ':tailgate_state (tailgate_state msg))
    (cl:cons ':SOC (SOC msg))
    (cl:cons ':vehicle_roll (vehicle_roll msg))
    (cl:cons ':vehicle_pitch (vehicle_pitch msg))
))
