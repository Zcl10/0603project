;; Auto-generated. Do not edit!


(when (boundp 'three_one_msgs::ReportMotion)
  (if (not (find-package "THREE_ONE_MSGS"))
    (make-package "THREE_ONE_MSGS"))
  (shadow 'ReportMotion (find-package "THREE_ONE_MSGS")))
(unless (find-package "THREE_ONE_MSGS::REPORTMOTION")
  (make-package "THREE_ONE_MSGS::REPORTMOTION"))

(in-package "ROS")
;;//! \htmlinclude ReportMotion.msg.html


(defclass three_one_msgs::ReportMotion
  :super ros::object
  :slots (_spin _park _current_gear _left_wheel_rotate _right_wheel_rotate _left_motor_rpm _right_motor_rpm _mechanical_brake _vehicle_speed _left_wheel_speed _right_wheel_speed _curvature ))

(defmethod three_one_msgs::ReportMotion
  (:init
   (&key
    ((:spin __spin) 0)
    ((:park __park) 0)
    ((:current_gear __current_gear) 0)
    ((:left_wheel_rotate __left_wheel_rotate) 0)
    ((:right_wheel_rotate __right_wheel_rotate) 0)
    ((:left_motor_rpm __left_motor_rpm) 0)
    ((:right_motor_rpm __right_motor_rpm) 0)
    ((:mechanical_brake __mechanical_brake) 0.0)
    ((:vehicle_speed __vehicle_speed) 0.0)
    ((:left_wheel_speed __left_wheel_speed) 0.0)
    ((:right_wheel_speed __right_wheel_speed) 0.0)
    ((:curvature __curvature) 0.0)
    )
   (send-super :init)
   (setq _spin (round __spin))
   (setq _park (round __park))
   (setq _current_gear (round __current_gear))
   (setq _left_wheel_rotate (round __left_wheel_rotate))
   (setq _right_wheel_rotate (round __right_wheel_rotate))
   (setq _left_motor_rpm (round __left_motor_rpm))
   (setq _right_motor_rpm (round __right_motor_rpm))
   (setq _mechanical_brake (float __mechanical_brake))
   (setq _vehicle_speed (float __vehicle_speed))
   (setq _left_wheel_speed (float __left_wheel_speed))
   (setq _right_wheel_speed (float __right_wheel_speed))
   (setq _curvature (float __curvature))
   self)
  (:spin
   (&optional __spin)
   (if __spin (setq _spin __spin)) _spin)
  (:park
   (&optional __park)
   (if __park (setq _park __park)) _park)
  (:current_gear
   (&optional __current_gear)
   (if __current_gear (setq _current_gear __current_gear)) _current_gear)
  (:left_wheel_rotate
   (&optional __left_wheel_rotate)
   (if __left_wheel_rotate (setq _left_wheel_rotate __left_wheel_rotate)) _left_wheel_rotate)
  (:right_wheel_rotate
   (&optional __right_wheel_rotate)
   (if __right_wheel_rotate (setq _right_wheel_rotate __right_wheel_rotate)) _right_wheel_rotate)
  (:left_motor_rpm
   (&optional __left_motor_rpm)
   (if __left_motor_rpm (setq _left_motor_rpm __left_motor_rpm)) _left_motor_rpm)
  (:right_motor_rpm
   (&optional __right_motor_rpm)
   (if __right_motor_rpm (setq _right_motor_rpm __right_motor_rpm)) _right_motor_rpm)
  (:mechanical_brake
   (&optional __mechanical_brake)
   (if __mechanical_brake (setq _mechanical_brake __mechanical_brake)) _mechanical_brake)
  (:vehicle_speed
   (&optional __vehicle_speed)
   (if __vehicle_speed (setq _vehicle_speed __vehicle_speed)) _vehicle_speed)
  (:left_wheel_speed
   (&optional __left_wheel_speed)
   (if __left_wheel_speed (setq _left_wheel_speed __left_wheel_speed)) _left_wheel_speed)
  (:right_wheel_speed
   (&optional __right_wheel_speed)
   (if __right_wheel_speed (setq _right_wheel_speed __right_wheel_speed)) _right_wheel_speed)
  (:curvature
   (&optional __curvature)
   (if __curvature (setq _curvature __curvature)) _curvature)
  (:serialization-length
   ()
   (+
    ;; uint8 _spin
    1
    ;; uint8 _park
    1
    ;; uint8 _current_gear
    1
    ;; uint8 _left_wheel_rotate
    1
    ;; uint8 _right_wheel_rotate
    1
    ;; uint16 _left_motor_rpm
    2
    ;; uint16 _right_motor_rpm
    2
    ;; float32 _mechanical_brake
    4
    ;; float64 _vehicle_speed
    8
    ;; float64 _left_wheel_speed
    8
    ;; float64 _right_wheel_speed
    8
    ;; float32 _curvature
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _spin
       (write-byte _spin s)
     ;; uint8 _park
       (write-byte _park s)
     ;; uint8 _current_gear
       (write-byte _current_gear s)
     ;; uint8 _left_wheel_rotate
       (write-byte _left_wheel_rotate s)
     ;; uint8 _right_wheel_rotate
       (write-byte _right_wheel_rotate s)
     ;; uint16 _left_motor_rpm
       (write-word _left_motor_rpm s)
     ;; uint16 _right_motor_rpm
       (write-word _right_motor_rpm s)
     ;; float32 _mechanical_brake
       (sys::poke _mechanical_brake (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float64 _vehicle_speed
       (sys::poke _vehicle_speed (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _left_wheel_speed
       (sys::poke _left_wheel_speed (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _right_wheel_speed
       (sys::poke _right_wheel_speed (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float32 _curvature
       (sys::poke _curvature (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _spin
     (setq _spin (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _park
     (setq _park (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _current_gear
     (setq _current_gear (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _left_wheel_rotate
     (setq _left_wheel_rotate (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _right_wheel_rotate
     (setq _right_wheel_rotate (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint16 _left_motor_rpm
     (setq _left_motor_rpm (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _right_motor_rpm
     (setq _right_motor_rpm (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; float32 _mechanical_brake
     (setq _mechanical_brake (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float64 _vehicle_speed
     (setq _vehicle_speed (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _left_wheel_speed
     (setq _left_wheel_speed (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _right_wheel_speed
     (setq _right_wheel_speed (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float32 _curvature
     (setq _curvature (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get three_one_msgs::ReportMotion :md5sum-) "60fe6a6e7ba2e99db01da0cfbfd1bb49")
(setf (get three_one_msgs::ReportMotion :datatype-) "three_one_msgs/ReportMotion")
(setf (get three_one_msgs::ReportMotion :definition-)
      "uint8 spin
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



(provide :three_one_msgs/ReportMotion "60fe6a6e7ba2e99db01da0cfbfd1bb49")


