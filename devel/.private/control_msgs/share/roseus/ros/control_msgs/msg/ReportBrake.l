;; Auto-generated. Do not edit!


(when (boundp 'control_msgs::ReportBrake)
  (if (not (find-package "CONTROL_MSGS"))
    (make-package "CONTROL_MSGS"))
  (shadow 'ReportBrake (find-package "CONTROL_MSGS")))
(unless (find-package "CONTROL_MSGS::REPORTBRAKE")
  (make-package "CONTROL_MSGS::REPORTBRAKE"))

(in-package "ROS")
;;//! \htmlinclude ReportBrake.msg.html


(defclass control_msgs::ReportBrake
  :super ros::object
  :slots (_left_pressure_back _right_pressure_back _auto_park_state _auto_brake_enable _system_hot_warn _system_error_code _left_pressure_set _right_pressure_set _brake_pedal ))

(defmethod control_msgs::ReportBrake
  (:init
   (&key
    ((:left_pressure_back __left_pressure_back) 0.0)
    ((:right_pressure_back __right_pressure_back) 0.0)
    ((:auto_park_state __auto_park_state) 0)
    ((:auto_brake_enable __auto_brake_enable) 0)
    ((:system_hot_warn __system_hot_warn) 0)
    ((:system_error_code __system_error_code) 0)
    ((:left_pressure_set __left_pressure_set) 0.0)
    ((:right_pressure_set __right_pressure_set) 0.0)
    ((:brake_pedal __brake_pedal) 0.0)
    )
   (send-super :init)
   (setq _left_pressure_back (float __left_pressure_back))
   (setq _right_pressure_back (float __right_pressure_back))
   (setq _auto_park_state (round __auto_park_state))
   (setq _auto_brake_enable (round __auto_brake_enable))
   (setq _system_hot_warn (round __system_hot_warn))
   (setq _system_error_code (round __system_error_code))
   (setq _left_pressure_set (float __left_pressure_set))
   (setq _right_pressure_set (float __right_pressure_set))
   (setq _brake_pedal (float __brake_pedal))
   self)
  (:left_pressure_back
   (&optional __left_pressure_back)
   (if __left_pressure_back (setq _left_pressure_back __left_pressure_back)) _left_pressure_back)
  (:right_pressure_back
   (&optional __right_pressure_back)
   (if __right_pressure_back (setq _right_pressure_back __right_pressure_back)) _right_pressure_back)
  (:auto_park_state
   (&optional __auto_park_state)
   (if __auto_park_state (setq _auto_park_state __auto_park_state)) _auto_park_state)
  (:auto_brake_enable
   (&optional __auto_brake_enable)
   (if __auto_brake_enable (setq _auto_brake_enable __auto_brake_enable)) _auto_brake_enable)
  (:system_hot_warn
   (&optional __system_hot_warn)
   (if __system_hot_warn (setq _system_hot_warn __system_hot_warn)) _system_hot_warn)
  (:system_error_code
   (&optional __system_error_code)
   (if __system_error_code (setq _system_error_code __system_error_code)) _system_error_code)
  (:left_pressure_set
   (&optional __left_pressure_set)
   (if __left_pressure_set (setq _left_pressure_set __left_pressure_set)) _left_pressure_set)
  (:right_pressure_set
   (&optional __right_pressure_set)
   (if __right_pressure_set (setq _right_pressure_set __right_pressure_set)) _right_pressure_set)
  (:brake_pedal
   (&optional __brake_pedal)
   (if __brake_pedal (setq _brake_pedal __brake_pedal)) _brake_pedal)
  (:serialization-length
   ()
   (+
    ;; float64 _left_pressure_back
    8
    ;; float64 _right_pressure_back
    8
    ;; uint8 _auto_park_state
    1
    ;; uint8 _auto_brake_enable
    1
    ;; uint8 _system_hot_warn
    1
    ;; uint8 _system_error_code
    1
    ;; float64 _left_pressure_set
    8
    ;; float64 _right_pressure_set
    8
    ;; float32 _brake_pedal
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _left_pressure_back
       (sys::poke _left_pressure_back (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _right_pressure_back
       (sys::poke _right_pressure_back (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; uint8 _auto_park_state
       (write-byte _auto_park_state s)
     ;; uint8 _auto_brake_enable
       (write-byte _auto_brake_enable s)
     ;; uint8 _system_hot_warn
       (write-byte _system_hot_warn s)
     ;; uint8 _system_error_code
       (write-byte _system_error_code s)
     ;; float64 _left_pressure_set
       (sys::poke _left_pressure_set (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _right_pressure_set
       (sys::poke _right_pressure_set (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float32 _brake_pedal
       (sys::poke _brake_pedal (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _left_pressure_back
     (setq _left_pressure_back (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _right_pressure_back
     (setq _right_pressure_back (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; uint8 _auto_park_state
     (setq _auto_park_state (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _auto_brake_enable
     (setq _auto_brake_enable (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _system_hot_warn
     (setq _system_hot_warn (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _system_error_code
     (setq _system_error_code (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _left_pressure_set
     (setq _left_pressure_set (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _right_pressure_set
     (setq _right_pressure_set (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float32 _brake_pedal
     (setq _brake_pedal (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get control_msgs::ReportBrake :md5sum-) "c8b58fe12b43fe4b1c2d9a5950b7da37")
(setf (get control_msgs::ReportBrake :datatype-) "control_msgs/ReportBrake")
(setf (get control_msgs::ReportBrake :definition-)
      "float64 left_pressure_back
float64 right_pressure_back
uint8 auto_park_state
uint8 auto_brake_enable
uint8 system_hot_warn
uint8 system_error_code
float64 left_pressure_set
float64 right_pressure_set
float32 brake_pedal

")



(provide :control_msgs/ReportBrake "c8b58fe12b43fe4b1c2d9a5950b7da37")


