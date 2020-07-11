;; Auto-generated. Do not edit!


(when (boundp 'three_one_msgs::Report)
  (if (not (find-package "THREE_ONE_MSGS"))
    (make-package "THREE_ONE_MSGS"))
  (shadow 'Report (find-package "THREE_ONE_MSGS")))
(unless (find-package "THREE_ONE_MSGS::REPORT")
  (make-package "THREE_ONE_MSGS::REPORT"))

(in-package "ROS")
;;//! \htmlinclude Report.msg.html


(defclass three_one_msgs::Report
  :super ros::object
  :slots (_control _give_back _cylinder_pressure _cylinder_position _vehicle_state _distance _torque _motion _control_mode _operation_mode _counter ))

(defmethod three_one_msgs::Report
  (:init
   (&key
    ((:control __control) (instance three_one_msgs::ReportControlData :init))
    ((:give_back __give_back) (instance three_one_msgs::ReportGiveBack :init))
    ((:cylinder_pressure __cylinder_pressure) (instance three_one_msgs::ReportCylinderPressure :init))
    ((:cylinder_position __cylinder_position) (instance three_one_msgs::ReportCylinderPosition :init))
    ((:vehicle_state __vehicle_state) (instance three_one_msgs::ReportVehicleState :init))
    ((:distance __distance) (instance three_one_msgs::ReportDistance :init))
    ((:torque __torque) (instance three_one_msgs::ReportTorque :init))
    ((:motion __motion) (instance three_one_msgs::ReportMotion :init))
    ((:control_mode __control_mode) 0)
    ((:operation_mode __operation_mode) 0)
    ((:counter __counter) 0)
    )
   (send-super :init)
   (setq _control __control)
   (setq _give_back __give_back)
   (setq _cylinder_pressure __cylinder_pressure)
   (setq _cylinder_position __cylinder_position)
   (setq _vehicle_state __vehicle_state)
   (setq _distance __distance)
   (setq _torque __torque)
   (setq _motion __motion)
   (setq _control_mode (round __control_mode))
   (setq _operation_mode (round __operation_mode))
   (setq _counter (round __counter))
   self)
  (:control
   (&rest __control)
   (if (keywordp (car __control))
       (send* _control __control)
     (progn
       (if __control (setq _control (car __control)))
       _control)))
  (:give_back
   (&rest __give_back)
   (if (keywordp (car __give_back))
       (send* _give_back __give_back)
     (progn
       (if __give_back (setq _give_back (car __give_back)))
       _give_back)))
  (:cylinder_pressure
   (&rest __cylinder_pressure)
   (if (keywordp (car __cylinder_pressure))
       (send* _cylinder_pressure __cylinder_pressure)
     (progn
       (if __cylinder_pressure (setq _cylinder_pressure (car __cylinder_pressure)))
       _cylinder_pressure)))
  (:cylinder_position
   (&rest __cylinder_position)
   (if (keywordp (car __cylinder_position))
       (send* _cylinder_position __cylinder_position)
     (progn
       (if __cylinder_position (setq _cylinder_position (car __cylinder_position)))
       _cylinder_position)))
  (:vehicle_state
   (&rest __vehicle_state)
   (if (keywordp (car __vehicle_state))
       (send* _vehicle_state __vehicle_state)
     (progn
       (if __vehicle_state (setq _vehicle_state (car __vehicle_state)))
       _vehicle_state)))
  (:distance
   (&rest __distance)
   (if (keywordp (car __distance))
       (send* _distance __distance)
     (progn
       (if __distance (setq _distance (car __distance)))
       _distance)))
  (:torque
   (&rest __torque)
   (if (keywordp (car __torque))
       (send* _torque __torque)
     (progn
       (if __torque (setq _torque (car __torque)))
       _torque)))
  (:motion
   (&rest __motion)
   (if (keywordp (car __motion))
       (send* _motion __motion)
     (progn
       (if __motion (setq _motion (car __motion)))
       _motion)))
  (:control_mode
   (&optional __control_mode)
   (if __control_mode (setq _control_mode __control_mode)) _control_mode)
  (:operation_mode
   (&optional __operation_mode)
   (if __operation_mode (setq _operation_mode __operation_mode)) _operation_mode)
  (:counter
   (&optional __counter)
   (if __counter (setq _counter __counter)) _counter)
  (:serialization-length
   ()
   (+
    ;; three_one_msgs/ReportControlData _control
    (send _control :serialization-length)
    ;; three_one_msgs/ReportGiveBack _give_back
    (send _give_back :serialization-length)
    ;; three_one_msgs/ReportCylinderPressure _cylinder_pressure
    (send _cylinder_pressure :serialization-length)
    ;; three_one_msgs/ReportCylinderPosition _cylinder_position
    (send _cylinder_position :serialization-length)
    ;; three_one_msgs/ReportVehicleState _vehicle_state
    (send _vehicle_state :serialization-length)
    ;; three_one_msgs/ReportDistance _distance
    (send _distance :serialization-length)
    ;; three_one_msgs/ReportTorque _torque
    (send _torque :serialization-length)
    ;; three_one_msgs/ReportMotion _motion
    (send _motion :serialization-length)
    ;; uint8 _control_mode
    1
    ;; uint8 _operation_mode
    1
    ;; uint64 _counter
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; three_one_msgs/ReportControlData _control
       (send _control :serialize s)
     ;; three_one_msgs/ReportGiveBack _give_back
       (send _give_back :serialize s)
     ;; three_one_msgs/ReportCylinderPressure _cylinder_pressure
       (send _cylinder_pressure :serialize s)
     ;; three_one_msgs/ReportCylinderPosition _cylinder_position
       (send _cylinder_position :serialize s)
     ;; three_one_msgs/ReportVehicleState _vehicle_state
       (send _vehicle_state :serialize s)
     ;; three_one_msgs/ReportDistance _distance
       (send _distance :serialize s)
     ;; three_one_msgs/ReportTorque _torque
       (send _torque :serialize s)
     ;; three_one_msgs/ReportMotion _motion
       (send _motion :serialize s)
     ;; uint8 _control_mode
       (write-byte _control_mode s)
     ;; uint8 _operation_mode
       (write-byte _operation_mode s)
     ;; uint64 _counter
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _counter (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _counter) (= (length (_counter . bv)) 2)) ;; bignum
              (write-long (ash (elt (_counter . bv) 0) 0) s)
              (write-long (ash (elt (_counter . bv) 1) -1) s))
             ((and (class _counter) (= (length (_counter . bv)) 1)) ;; big1
              (write-long (elt (_counter . bv) 0) s)
              (write-long (if (>= _counter 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _counter s)(write-long (if (>= _counter 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; three_one_msgs/ReportControlData _control
     (send _control :deserialize buf ptr-) (incf ptr- (send _control :serialization-length))
   ;; three_one_msgs/ReportGiveBack _give_back
     (send _give_back :deserialize buf ptr-) (incf ptr- (send _give_back :serialization-length))
   ;; three_one_msgs/ReportCylinderPressure _cylinder_pressure
     (send _cylinder_pressure :deserialize buf ptr-) (incf ptr- (send _cylinder_pressure :serialization-length))
   ;; three_one_msgs/ReportCylinderPosition _cylinder_position
     (send _cylinder_position :deserialize buf ptr-) (incf ptr- (send _cylinder_position :serialization-length))
   ;; three_one_msgs/ReportVehicleState _vehicle_state
     (send _vehicle_state :deserialize buf ptr-) (incf ptr- (send _vehicle_state :serialization-length))
   ;; three_one_msgs/ReportDistance _distance
     (send _distance :deserialize buf ptr-) (incf ptr- (send _distance :serialization-length))
   ;; three_one_msgs/ReportTorque _torque
     (send _torque :deserialize buf ptr-) (incf ptr- (send _torque :serialization-length))
   ;; three_one_msgs/ReportMotion _motion
     (send _motion :deserialize buf ptr-) (incf ptr- (send _motion :serialization-length))
   ;; uint8 _control_mode
     (setq _control_mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _operation_mode
     (setq _operation_mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint64 _counter
     
#+(or :alpha :irix6 :x86_64)
      (setf _counter (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _counter (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(setf (get three_one_msgs::Report :md5sum-) "cb7eb1891ce051b9221ffe7f0ad827d8")
(setf (get three_one_msgs::Report :datatype-) "three_one_msgs/Report")
(setf (get three_one_msgs::Report :definition-)
      "ReportControlData control
ReportGiveBack give_back
ReportCylinderPressure cylinder_pressure
ReportCylinderPosition cylinder_position
ReportVehicleState vehicle_state
ReportDistance distance
ReportTorque torque
ReportMotion motion
uint8 control_mode
uint8 operation_mode
uint64 counter
================================================================================
MSG: three_one_msgs/ReportControlData
float32 curvature
float32 speed
uint16 rpm
uint8 work_mode
uint8 gear
uint8 turn_to
uint8 brake
uint8 park
uint8 cylinder_select
uint8 suspension_select
uint8 vertical_wall_mode
uint8 suspension_work_mode
uint8 suspension_work_mode_detail
uint8 suspension_cylinder_select_mode
uint8 suspension_cylinder_motor_control
uint8 fix_two_chamber_valve
================================================================================
MSG: three_one_msgs/ReportGiveBack
float32 left_wheel_expect_speed
float32 right_wheel_expect_speed
================================================================================
MSG: three_one_msgs/ReportCylinderPressure
uint8 left_one
uint8 left_two
uint8 left_three
uint8 left_four
uint8 right_one
uint8 right_two
uint8 right_three
uint8 right_four
================================================================================
MSG: three_one_msgs/ReportCylinderPosition
uint16 left_one
uint16 left_two
uint16 left_three
uint16 left_four
uint16 right_one
uint16 right_two
uint16 right_three
uint16 right_four
================================================================================
MSG: three_one_msgs/ReportVehicleState
uint8 error_code
uint8 two_chamber_valve
uint8 vertical_wall_status
uint8 entrenchment
uint8 weapon_330
uint8 weapon_28
uint8 vehicle_height
uint8 tailgate_state
uint8 SOC
int8 vehicle_roll
int8 vehicle_pitch
================================================================================
MSG: three_one_msgs/ReportDistance
uint32 mileage
uint32 left_pulse
uint32 right_pulse
float64 left_distance
float64 right_distance
================================================================================
MSG: three_one_msgs/ReportTorque
int16 left
int16 right
================================================================================
MSG: three_one_msgs/ReportMotion
uint8 spin
uint8 park
uint8 current_gear
uint8 left_wheel_rotate
uint8 right_wheel_rotate
uint16 left_motor_rpm
uint16 right_motor_rpm
float32 mechanical_brake
float64 vehicle_speed
float64 left_wheel_speed  # signed
float64 right_wheel_speed  # signed
float32 curvature
")



(provide :three_one_msgs/Report "cb7eb1891ce051b9221ffe7f0ad827d8")


