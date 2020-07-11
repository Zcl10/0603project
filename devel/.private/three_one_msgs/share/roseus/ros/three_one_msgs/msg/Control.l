;; Auto-generated. Do not edit!


(when (boundp 'three_one_msgs::Control)
  (if (not (find-package "THREE_ONE_MSGS"))
    (make-package "THREE_ONE_MSGS"))
  (shadow 'Control (find-package "THREE_ONE_MSGS")))
(unless (find-package "THREE_ONE_MSGS::CONTROL")
  (make-package "THREE_ONE_MSGS::CONTROL"))

(in-package "ROS")
;;//! \htmlinclude Control.msg.html


(defclass three_one_msgs::Control
  :super ros::object
  :slots (_priority _speed _steer _suspension _weapon ))

(defmethod three_one_msgs::Control
  (:init
   (&key
    ((:priority __priority) 0)
    ((:speed __speed) (instance three_one_msgs::ControlSpeed :init))
    ((:steer __steer) (instance three_one_msgs::ControlSteer :init))
    ((:suspension __suspension) (instance three_one_msgs::ControlSuspension :init))
    ((:weapon __weapon) (instance three_one_msgs::ControlWeapon :init))
    )
   (send-super :init)
   (setq _priority (round __priority))
   (setq _speed __speed)
   (setq _steer __steer)
   (setq _suspension __suspension)
   (setq _weapon __weapon)
   self)
  (:priority
   (&optional __priority)
   (if __priority (setq _priority __priority)) _priority)
  (:speed
   (&rest __speed)
   (if (keywordp (car __speed))
       (send* _speed __speed)
     (progn
       (if __speed (setq _speed (car __speed)))
       _speed)))
  (:steer
   (&rest __steer)
   (if (keywordp (car __steer))
       (send* _steer __steer)
     (progn
       (if __steer (setq _steer (car __steer)))
       _steer)))
  (:suspension
   (&rest __suspension)
   (if (keywordp (car __suspension))
       (send* _suspension __suspension)
     (progn
       (if __suspension (setq _suspension (car __suspension)))
       _suspension)))
  (:weapon
   (&rest __weapon)
   (if (keywordp (car __weapon))
       (send* _weapon __weapon)
     (progn
       (if __weapon (setq _weapon (car __weapon)))
       _weapon)))
  (:serialization-length
   ()
   (+
    ;; uint8 _priority
    1
    ;; three_one_msgs/ControlSpeed _speed
    (send _speed :serialization-length)
    ;; three_one_msgs/ControlSteer _steer
    (send _steer :serialization-length)
    ;; three_one_msgs/ControlSuspension _suspension
    (send _suspension :serialization-length)
    ;; three_one_msgs/ControlWeapon _weapon
    (send _weapon :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _priority
       (write-byte _priority s)
     ;; three_one_msgs/ControlSpeed _speed
       (send _speed :serialize s)
     ;; three_one_msgs/ControlSteer _steer
       (send _steer :serialize s)
     ;; three_one_msgs/ControlSuspension _suspension
       (send _suspension :serialize s)
     ;; three_one_msgs/ControlWeapon _weapon
       (send _weapon :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _priority
     (setq _priority (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; three_one_msgs/ControlSpeed _speed
     (send _speed :deserialize buf ptr-) (incf ptr- (send _speed :serialization-length))
   ;; three_one_msgs/ControlSteer _steer
     (send _steer :deserialize buf ptr-) (incf ptr- (send _steer :serialization-length))
   ;; three_one_msgs/ControlSuspension _suspension
     (send _suspension :deserialize buf ptr-) (incf ptr- (send _suspension :serialization-length))
   ;; three_one_msgs/ControlWeapon _weapon
     (send _weapon :deserialize buf ptr-) (incf ptr- (send _weapon :serialization-length))
   ;;
   self)
  )

(setf (get three_one_msgs::Control :md5sum-) "d0ddf03a8d19a85e773b681a9262d15c")
(setf (get three_one_msgs::Control :datatype-) "three_one_msgs/Control")
(setf (get three_one_msgs::Control :definition-)
      "uint8 priority
ControlSpeed speed
ControlSteer steer
ControlSuspension suspension
ControlWeapon weapon
================================================================================
MSG: three_one_msgs/ControlSpeed
uint8 priority
uint8 halt
uint8 gear
float32 speed
================================================================================
MSG: three_one_msgs/ControlSteer
uint8 priority
float64 curvature
================================================================================
MSG: three_one_msgs/ControlSuspension
uint8 priority
uint8 cylinder_select
uint8 suspension_select
uint8 suspension_work_mode
uint8 suspension_work_mode_detail
uint8 suspension_cylinder_select_mode
uint8 suspension_cylinder_motor_control
uint8 vertical_wall_mode
uint8 fix_two_chamber_valve
uint8 entrenchment
================================================================================
MSG: three_one_msgs/ControlWeapon
uint8 priority
uint8 weapon_330
uint8 weapon_28
uint8 weapon_cmd

")



(provide :three_one_msgs/Control "d0ddf03a8d19a85e773b681a9262d15c")


