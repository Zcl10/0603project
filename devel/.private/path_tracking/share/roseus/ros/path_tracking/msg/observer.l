;; Auto-generated. Do not edit!


(when (boundp 'path_tracking::observer)
  (if (not (find-package "PATH_TRACKING"))
    (make-package "PATH_TRACKING"))
  (shadow 'observer (find-package "PATH_TRACKING")))
(unless (find-package "PATH_TRACKING::OBSERVER")
  (make-package "PATH_TRACKING::OBSERVER"))

(in-package "ROS")
;;//! \htmlinclude observer.msg.html
(if (not (find-package "ANM_MSGS"))
  (ros::roseus-add-msgs "anm_msgs"))
(if (not (find-package "CONTROL_MSGS"))
  (ros::roseus-add-msgs "control_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass path_tracking::observer
  :super ros::object
  :slots (_header _vehicle_state _ecu_report _speed_cmd _steer_cmd _lateral_error _heading_error _time_cost ))

(defmethod path_tracking::observer
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:vehicle_state __vehicle_state) (instance anm_msgs::VehicleState :init))
    ((:ecu_report __ecu_report) (instance control_msgs::Report :init))
    ((:speed_cmd __speed_cmd) 0.0)
    ((:steer_cmd __steer_cmd) 0.0)
    ((:lateral_error __lateral_error) 0.0)
    ((:heading_error __heading_error) 0.0)
    ((:time_cost __time_cost) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _vehicle_state __vehicle_state)
   (setq _ecu_report __ecu_report)
   (setq _speed_cmd (float __speed_cmd))
   (setq _steer_cmd (float __steer_cmd))
   (setq _lateral_error (float __lateral_error))
   (setq _heading_error (float __heading_error))
   (setq _time_cost (float __time_cost))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:vehicle_state
   (&rest __vehicle_state)
   (if (keywordp (car __vehicle_state))
       (send* _vehicle_state __vehicle_state)
     (progn
       (if __vehicle_state (setq _vehicle_state (car __vehicle_state)))
       _vehicle_state)))
  (:ecu_report
   (&rest __ecu_report)
   (if (keywordp (car __ecu_report))
       (send* _ecu_report __ecu_report)
     (progn
       (if __ecu_report (setq _ecu_report (car __ecu_report)))
       _ecu_report)))
  (:speed_cmd
   (&optional __speed_cmd)
   (if __speed_cmd (setq _speed_cmd __speed_cmd)) _speed_cmd)
  (:steer_cmd
   (&optional __steer_cmd)
   (if __steer_cmd (setq _steer_cmd __steer_cmd)) _steer_cmd)
  (:lateral_error
   (&optional __lateral_error)
   (if __lateral_error (setq _lateral_error __lateral_error)) _lateral_error)
  (:heading_error
   (&optional __heading_error)
   (if __heading_error (setq _heading_error __heading_error)) _heading_error)
  (:time_cost
   (&optional __time_cost)
   (if __time_cost (setq _time_cost __time_cost)) _time_cost)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; anm_msgs/VehicleState _vehicle_state
    (send _vehicle_state :serialization-length)
    ;; control_msgs/Report _ecu_report
    (send _ecu_report :serialization-length)
    ;; float64 _speed_cmd
    8
    ;; float64 _steer_cmd
    8
    ;; float64 _lateral_error
    8
    ;; float64 _heading_error
    8
    ;; float64 _time_cost
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; anm_msgs/VehicleState _vehicle_state
       (send _vehicle_state :serialize s)
     ;; control_msgs/Report _ecu_report
       (send _ecu_report :serialize s)
     ;; float64 _speed_cmd
       (sys::poke _speed_cmd (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _steer_cmd
       (sys::poke _steer_cmd (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _lateral_error
       (sys::poke _lateral_error (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _heading_error
       (sys::poke _heading_error (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _time_cost
       (sys::poke _time_cost (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; anm_msgs/VehicleState _vehicle_state
     (send _vehicle_state :deserialize buf ptr-) (incf ptr- (send _vehicle_state :serialization-length))
   ;; control_msgs/Report _ecu_report
     (send _ecu_report :deserialize buf ptr-) (incf ptr- (send _ecu_report :serialization-length))
   ;; float64 _speed_cmd
     (setq _speed_cmd (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _steer_cmd
     (setq _steer_cmd (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _lateral_error
     (setq _lateral_error (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _heading_error
     (setq _heading_error (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _time_cost
     (setq _time_cost (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get path_tracking::observer :md5sum-) "5f683c55d076db2e680be51e6dee7354")
(setf (get path_tracking::observer :datatype-) "path_tracking/observer")
(setf (get path_tracking::observer :definition-)
      "Header header

anm_msgs/VehicleState vehicle_state
control_msgs/Report ecu_report
float64 speed_cmd
float64 steer_cmd
float64 lateral_error
float64 heading_error
float64 time_cost

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: anm_msgs/VehicleState
# This message describes the complete vehicle state
# orientation = orientation of the vehicle using euler angles

Header header
string child_frame_id

geometry_msgs/Point position
geometry_msgs/Vector3 orientation
geometry_msgs/Twist velocity
geometry_msgs/Twist acceleration

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
================================================================================
MSG: geometry_msgs/Twist
# This expresses velocity in free space broken into its linear and angular parts.
Vector3  linear
Vector3  angular

================================================================================
MSG: control_msgs/Report
Header header
ReportControl control

ReportControl vcu_torque_brake

ReportMotion motion
ReportBrake brake
ReportThrottle throttle
ReportWheel wheel
ReportHMI manual
ReportVehicleWorkMode vehicle_work_mode 

================================================================================
MSG: control_msgs/ReportControl
ControlSpeed Speed
ControlSteer Steer
ControlMode ordermode


================================================================================
MSG: control_msgs/ControlSpeed
Header header
uint8 priority
uint8 gear
float64 speed
float64 acc
float64 torque
float64 brake

================================================================================
MSG: control_msgs/ControlSteer
Header header
uint8 priority
float64 steer


================================================================================
MSG: control_msgs/ControlMode
Header header
uint8 RainyLight



================================================================================
MSG: control_msgs/ReportMotion
uint8 drive_mode
float64 steer
uint8 gear
float64 velocity



================================================================================
MSG: control_msgs/ReportBrake
float64 left_pressure_back
float64 right_pressure_back
uint8 auto_park_state
uint8 auto_brake_enable
uint8 system_hot_warn
uint8 system_error_code
float64 left_pressure_set
float64 right_pressure_set
float32 brake_pedal

================================================================================
MSG: control_msgs/ReportThrottle
float32 throttle_opening
float32 throttle_pedal

================================================================================
MSG: control_msgs/ReportWheel
float32 front_left
float32 front_right
float32 rear_left
float32 rear_right
uint8 statusfl
uint8 statusfr
uint8 statusrl
uint8 statusrr

================================================================================
MSG: control_msgs/ReportHMI
uint8 manual_estop
uint8 is_human_brake 

================================================================================
MSG: control_msgs/ReportVehicleWorkMode
uint8 work_mode



")



(provide :path_tracking/observer "5f683c55d076db2e680be51e6dee7354")


