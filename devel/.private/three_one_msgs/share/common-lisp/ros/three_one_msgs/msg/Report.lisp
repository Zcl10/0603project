; Auto-generated. Do not edit!


(cl:in-package three_one_msgs-msg)


;//! \htmlinclude Report.msg.html

(cl:defclass <Report> (roslisp-msg-protocol:ros-message)
  ((control
    :reader control
    :initarg :control
    :type three_one_msgs-msg:ReportControlData
    :initform (cl:make-instance 'three_one_msgs-msg:ReportControlData))
   (give_back
    :reader give_back
    :initarg :give_back
    :type three_one_msgs-msg:ReportGiveBack
    :initform (cl:make-instance 'three_one_msgs-msg:ReportGiveBack))
   (cylinder_pressure
    :reader cylinder_pressure
    :initarg :cylinder_pressure
    :type three_one_msgs-msg:ReportCylinderPressure
    :initform (cl:make-instance 'three_one_msgs-msg:ReportCylinderPressure))
   (cylinder_position
    :reader cylinder_position
    :initarg :cylinder_position
    :type three_one_msgs-msg:ReportCylinderPosition
    :initform (cl:make-instance 'three_one_msgs-msg:ReportCylinderPosition))
   (vehicle_state
    :reader vehicle_state
    :initarg :vehicle_state
    :type three_one_msgs-msg:ReportVehicleState
    :initform (cl:make-instance 'three_one_msgs-msg:ReportVehicleState))
   (distance
    :reader distance
    :initarg :distance
    :type three_one_msgs-msg:ReportDistance
    :initform (cl:make-instance 'three_one_msgs-msg:ReportDistance))
   (torque
    :reader torque
    :initarg :torque
    :type three_one_msgs-msg:ReportTorque
    :initform (cl:make-instance 'three_one_msgs-msg:ReportTorque))
   (motion
    :reader motion
    :initarg :motion
    :type three_one_msgs-msg:ReportMotion
    :initform (cl:make-instance 'three_one_msgs-msg:ReportMotion))
   (control_mode
    :reader control_mode
    :initarg :control_mode
    :type cl:fixnum
    :initform 0)
   (operation_mode
    :reader operation_mode
    :initarg :operation_mode
    :type cl:fixnum
    :initform 0)
   (counter
    :reader counter
    :initarg :counter
    :type cl:integer
    :initform 0))
)

(cl:defclass Report (<Report>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Report>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Report)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name three_one_msgs-msg:<Report> is deprecated: use three_one_msgs-msg:Report instead.")))

(cl:ensure-generic-function 'control-val :lambda-list '(m))
(cl:defmethod control-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:control-val is deprecated.  Use three_one_msgs-msg:control instead.")
  (control m))

(cl:ensure-generic-function 'give_back-val :lambda-list '(m))
(cl:defmethod give_back-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:give_back-val is deprecated.  Use three_one_msgs-msg:give_back instead.")
  (give_back m))

(cl:ensure-generic-function 'cylinder_pressure-val :lambda-list '(m))
(cl:defmethod cylinder_pressure-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:cylinder_pressure-val is deprecated.  Use three_one_msgs-msg:cylinder_pressure instead.")
  (cylinder_pressure m))

(cl:ensure-generic-function 'cylinder_position-val :lambda-list '(m))
(cl:defmethod cylinder_position-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:cylinder_position-val is deprecated.  Use three_one_msgs-msg:cylinder_position instead.")
  (cylinder_position m))

(cl:ensure-generic-function 'vehicle_state-val :lambda-list '(m))
(cl:defmethod vehicle_state-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:vehicle_state-val is deprecated.  Use three_one_msgs-msg:vehicle_state instead.")
  (vehicle_state m))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:distance-val is deprecated.  Use three_one_msgs-msg:distance instead.")
  (distance m))

(cl:ensure-generic-function 'torque-val :lambda-list '(m))
(cl:defmethod torque-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:torque-val is deprecated.  Use three_one_msgs-msg:torque instead.")
  (torque m))

(cl:ensure-generic-function 'motion-val :lambda-list '(m))
(cl:defmethod motion-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:motion-val is deprecated.  Use three_one_msgs-msg:motion instead.")
  (motion m))

(cl:ensure-generic-function 'control_mode-val :lambda-list '(m))
(cl:defmethod control_mode-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:control_mode-val is deprecated.  Use three_one_msgs-msg:control_mode instead.")
  (control_mode m))

(cl:ensure-generic-function 'operation_mode-val :lambda-list '(m))
(cl:defmethod operation_mode-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:operation_mode-val is deprecated.  Use three_one_msgs-msg:operation_mode instead.")
  (operation_mode m))

(cl:ensure-generic-function 'counter-val :lambda-list '(m))
(cl:defmethod counter-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:counter-val is deprecated.  Use three_one_msgs-msg:counter instead.")
  (counter m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Report>) ostream)
  "Serializes a message object of type '<Report>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'control) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'give_back) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'cylinder_pressure) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'cylinder_position) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'vehicle_state) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'distance) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'torque) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'motion) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'control_mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'operation_mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'counter)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'counter)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'counter)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'counter)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'counter)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'counter)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'counter)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'counter)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Report>) istream)
  "Deserializes a message object of type '<Report>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'control) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'give_back) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'cylinder_pressure) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'cylinder_position) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'vehicle_state) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'distance) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'torque) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'motion) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'control_mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'operation_mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'counter)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'counter)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'counter)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'counter)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'counter)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'counter)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'counter)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'counter)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Report>)))
  "Returns string type for a message object of type '<Report>"
  "three_one_msgs/Report")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Report)))
  "Returns string type for a message object of type 'Report"
  "three_one_msgs/Report")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Report>)))
  "Returns md5sum for a message object of type '<Report>"
  "cb7eb1891ce051b9221ffe7f0ad827d8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Report)))
  "Returns md5sum for a message object of type 'Report"
  "cb7eb1891ce051b9221ffe7f0ad827d8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Report>)))
  "Returns full string definition for message of type '<Report>"
  (cl:format cl:nil "ReportControlData control~%ReportGiveBack give_back~%ReportCylinderPressure cylinder_pressure~%ReportCylinderPosition cylinder_position~%ReportVehicleState vehicle_state~%ReportDistance distance~%ReportTorque torque~%ReportMotion motion~%uint8 control_mode~%uint8 operation_mode~%uint64 counter~%================================================================================~%MSG: three_one_msgs/ReportControlData~%float32 curvature~%float32 speed~%uint16 rpm~%uint8 work_mode~%uint8 gear~%uint8 turn_to~%uint8 brake~%uint8 park~%uint8 cylinder_select~%uint8 suspension_select~%uint8 vertical_wall_mode~%uint8 suspension_work_mode~%uint8 suspension_work_mode_detail~%uint8 suspension_cylinder_select_mode~%uint8 suspension_cylinder_motor_control~%uint8 fix_two_chamber_valve~%================================================================================~%MSG: three_one_msgs/ReportGiveBack~%float32 left_wheel_expect_speed~%float32 right_wheel_expect_speed~%================================================================================~%MSG: three_one_msgs/ReportCylinderPressure~%uint8 left_one~%uint8 left_two~%uint8 left_three~%uint8 left_four~%uint8 right_one~%uint8 right_two~%uint8 right_three~%uint8 right_four~%================================================================================~%MSG: three_one_msgs/ReportCylinderPosition~%uint16 left_one~%uint16 left_two~%uint16 left_three~%uint16 left_four~%uint16 right_one~%uint16 right_two~%uint16 right_three~%uint16 right_four~%================================================================================~%MSG: three_one_msgs/ReportVehicleState~%uint8 error_code~%uint8 two_chamber_valve~%uint8 vertical_wall_status~%uint8 entrenchment~%uint8 weapon_330~%uint8 weapon_28~%uint8 vehicle_height~%uint8 tailgate_state~%uint8 SOC~%int8 vehicle_roll~%int8 vehicle_pitch~%================================================================================~%MSG: three_one_msgs/ReportDistance~%uint32 mileage~%uint32 left_pulse~%uint32 right_pulse~%float64 left_distance~%float64 right_distance~%================================================================================~%MSG: three_one_msgs/ReportTorque~%int16 left~%int16 right~%================================================================================~%MSG: three_one_msgs/ReportMotion~%uint8 spin~%uint8 park~%uint8 current_gear~%uint8 left_wheel_rotate~%uint8 right_wheel_rotate~%uint16 left_motor_rpm~%uint16 right_motor_rpm~%float32 mechanical_brake~%float64 vehicle_speed~%float64 left_wheel_speed  # signed~%float64 right_wheel_speed  # signed~%float32 curvature~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Report)))
  "Returns full string definition for message of type 'Report"
  (cl:format cl:nil "ReportControlData control~%ReportGiveBack give_back~%ReportCylinderPressure cylinder_pressure~%ReportCylinderPosition cylinder_position~%ReportVehicleState vehicle_state~%ReportDistance distance~%ReportTorque torque~%ReportMotion motion~%uint8 control_mode~%uint8 operation_mode~%uint64 counter~%================================================================================~%MSG: three_one_msgs/ReportControlData~%float32 curvature~%float32 speed~%uint16 rpm~%uint8 work_mode~%uint8 gear~%uint8 turn_to~%uint8 brake~%uint8 park~%uint8 cylinder_select~%uint8 suspension_select~%uint8 vertical_wall_mode~%uint8 suspension_work_mode~%uint8 suspension_work_mode_detail~%uint8 suspension_cylinder_select_mode~%uint8 suspension_cylinder_motor_control~%uint8 fix_two_chamber_valve~%================================================================================~%MSG: three_one_msgs/ReportGiveBack~%float32 left_wheel_expect_speed~%float32 right_wheel_expect_speed~%================================================================================~%MSG: three_one_msgs/ReportCylinderPressure~%uint8 left_one~%uint8 left_two~%uint8 left_three~%uint8 left_four~%uint8 right_one~%uint8 right_two~%uint8 right_three~%uint8 right_four~%================================================================================~%MSG: three_one_msgs/ReportCylinderPosition~%uint16 left_one~%uint16 left_two~%uint16 left_three~%uint16 left_four~%uint16 right_one~%uint16 right_two~%uint16 right_three~%uint16 right_four~%================================================================================~%MSG: three_one_msgs/ReportVehicleState~%uint8 error_code~%uint8 two_chamber_valve~%uint8 vertical_wall_status~%uint8 entrenchment~%uint8 weapon_330~%uint8 weapon_28~%uint8 vehicle_height~%uint8 tailgate_state~%uint8 SOC~%int8 vehicle_roll~%int8 vehicle_pitch~%================================================================================~%MSG: three_one_msgs/ReportDistance~%uint32 mileage~%uint32 left_pulse~%uint32 right_pulse~%float64 left_distance~%float64 right_distance~%================================================================================~%MSG: three_one_msgs/ReportTorque~%int16 left~%int16 right~%================================================================================~%MSG: three_one_msgs/ReportMotion~%uint8 spin~%uint8 park~%uint8 current_gear~%uint8 left_wheel_rotate~%uint8 right_wheel_rotate~%uint16 left_motor_rpm~%uint16 right_motor_rpm~%float32 mechanical_brake~%float64 vehicle_speed~%float64 left_wheel_speed  # signed~%float64 right_wheel_speed  # signed~%float32 curvature~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Report>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'control))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'give_back))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'cylinder_pressure))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'cylinder_position))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'vehicle_state))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'distance))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'torque))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'motion))
     1
     1
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Report>))
  "Converts a ROS message object to a list"
  (cl:list 'Report
    (cl:cons ':control (control msg))
    (cl:cons ':give_back (give_back msg))
    (cl:cons ':cylinder_pressure (cylinder_pressure msg))
    (cl:cons ':cylinder_position (cylinder_position msg))
    (cl:cons ':vehicle_state (vehicle_state msg))
    (cl:cons ':distance (distance msg))
    (cl:cons ':torque (torque msg))
    (cl:cons ':motion (motion msg))
    (cl:cons ':control_mode (control_mode msg))
    (cl:cons ':operation_mode (operation_mode msg))
    (cl:cons ':counter (counter msg))
))
