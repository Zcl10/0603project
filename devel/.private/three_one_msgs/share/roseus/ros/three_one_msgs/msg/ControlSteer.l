;; Auto-generated. Do not edit!


(when (boundp 'three_one_msgs::ControlSteer)
  (if (not (find-package "THREE_ONE_MSGS"))
    (make-package "THREE_ONE_MSGS"))
  (shadow 'ControlSteer (find-package "THREE_ONE_MSGS")))
(unless (find-package "THREE_ONE_MSGS::CONTROLSTEER")
  (make-package "THREE_ONE_MSGS::CONTROLSTEER"))

(in-package "ROS")
;;//! \htmlinclude ControlSteer.msg.html


(defclass three_one_msgs::ControlSteer
  :super ros::object
  :slots (_priority _curvature ))

(defmethod three_one_msgs::ControlSteer
  (:init
   (&key
    ((:priority __priority) 0)
    ((:curvature __curvature) 0.0)
    )
   (send-super :init)
   (setq _priority (round __priority))
   (setq _curvature (float __curvature))
   self)
  (:priority
   (&optional __priority)
   (if __priority (setq _priority __priority)) _priority)
  (:curvature
   (&optional __curvature)
   (if __curvature (setq _curvature __curvature)) _curvature)
  (:serialization-length
   ()
   (+
    ;; uint8 _priority
    1
    ;; float64 _curvature
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _priority
       (write-byte _priority s)
     ;; float64 _curvature
       (sys::poke _curvature (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _priority
     (setq _priority (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _curvature
     (setq _curvature (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get three_one_msgs::ControlSteer :md5sum-) "dfb9884ac74fdee49105f987268ecda4")
(setf (get three_one_msgs::ControlSteer :datatype-) "three_one_msgs/ControlSteer")
(setf (get three_one_msgs::ControlSteer :definition-)
      "uint8 priority
float64 curvature
")



(provide :three_one_msgs/ControlSteer "dfb9884ac74fdee49105f987268ecda4")


