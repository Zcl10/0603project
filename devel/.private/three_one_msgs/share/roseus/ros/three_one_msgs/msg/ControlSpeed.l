;; Auto-generated. Do not edit!


(when (boundp 'three_one_msgs::ControlSpeed)
  (if (not (find-package "THREE_ONE_MSGS"))
    (make-package "THREE_ONE_MSGS"))
  (shadow 'ControlSpeed (find-package "THREE_ONE_MSGS")))
(unless (find-package "THREE_ONE_MSGS::CONTROLSPEED")
  (make-package "THREE_ONE_MSGS::CONTROLSPEED"))

(in-package "ROS")
;;//! \htmlinclude ControlSpeed.msg.html


(defclass three_one_msgs::ControlSpeed
  :super ros::object
  :slots (_priority _halt _gear _speed ))

(defmethod three_one_msgs::ControlSpeed
  (:init
   (&key
    ((:priority __priority) 0)
    ((:halt __halt) 0)
    ((:gear __gear) 0)
    ((:speed __speed) 0.0)
    )
   (send-super :init)
   (setq _priority (round __priority))
   (setq _halt (round __halt))
   (setq _gear (round __gear))
   (setq _speed (float __speed))
   self)
  (:priority
   (&optional __priority)
   (if __priority (setq _priority __priority)) _priority)
  (:halt
   (&optional __halt)
   (if __halt (setq _halt __halt)) _halt)
  (:gear
   (&optional __gear)
   (if __gear (setq _gear __gear)) _gear)
  (:speed
   (&optional __speed)
   (if __speed (setq _speed __speed)) _speed)
  (:serialization-length
   ()
   (+
    ;; uint8 _priority
    1
    ;; uint8 _halt
    1
    ;; uint8 _gear
    1
    ;; float32 _speed
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _priority
       (write-byte _priority s)
     ;; uint8 _halt
       (write-byte _halt s)
     ;; uint8 _gear
       (write-byte _gear s)
     ;; float32 _speed
       (sys::poke _speed (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _priority
     (setq _priority (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _halt
     (setq _halt (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _gear
     (setq _gear (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float32 _speed
     (setq _speed (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get three_one_msgs::ControlSpeed :md5sum-) "cd90b94757225a2c977b45e86b71ada1")
(setf (get three_one_msgs::ControlSpeed :datatype-) "three_one_msgs/ControlSpeed")
(setf (get three_one_msgs::ControlSpeed :definition-)
      "uint8 priority
uint8 halt
uint8 gear
float32 speed
")



(provide :three_one_msgs/ControlSpeed "cd90b94757225a2c977b45e86b71ada1")


