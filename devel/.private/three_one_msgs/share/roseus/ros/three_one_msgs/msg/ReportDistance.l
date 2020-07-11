;; Auto-generated. Do not edit!


(when (boundp 'three_one_msgs::ReportDistance)
  (if (not (find-package "THREE_ONE_MSGS"))
    (make-package "THREE_ONE_MSGS"))
  (shadow 'ReportDistance (find-package "THREE_ONE_MSGS")))
(unless (find-package "THREE_ONE_MSGS::REPORTDISTANCE")
  (make-package "THREE_ONE_MSGS::REPORTDISTANCE"))

(in-package "ROS")
;;//! \htmlinclude ReportDistance.msg.html


(defclass three_one_msgs::ReportDistance
  :super ros::object
  :slots (_mileage _left_pulse _right_pulse _left_distance _right_distance ))

(defmethod three_one_msgs::ReportDistance
  (:init
   (&key
    ((:mileage __mileage) 0)
    ((:left_pulse __left_pulse) 0)
    ((:right_pulse __right_pulse) 0)
    ((:left_distance __left_distance) 0.0)
    ((:right_distance __right_distance) 0.0)
    )
   (send-super :init)
   (setq _mileage (round __mileage))
   (setq _left_pulse (round __left_pulse))
   (setq _right_pulse (round __right_pulse))
   (setq _left_distance (float __left_distance))
   (setq _right_distance (float __right_distance))
   self)
  (:mileage
   (&optional __mileage)
   (if __mileage (setq _mileage __mileage)) _mileage)
  (:left_pulse
   (&optional __left_pulse)
   (if __left_pulse (setq _left_pulse __left_pulse)) _left_pulse)
  (:right_pulse
   (&optional __right_pulse)
   (if __right_pulse (setq _right_pulse __right_pulse)) _right_pulse)
  (:left_distance
   (&optional __left_distance)
   (if __left_distance (setq _left_distance __left_distance)) _left_distance)
  (:right_distance
   (&optional __right_distance)
   (if __right_distance (setq _right_distance __right_distance)) _right_distance)
  (:serialization-length
   ()
   (+
    ;; uint32 _mileage
    4
    ;; uint32 _left_pulse
    4
    ;; uint32 _right_pulse
    4
    ;; float64 _left_distance
    8
    ;; float64 _right_distance
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _mileage
       (write-long _mileage s)
     ;; uint32 _left_pulse
       (write-long _left_pulse s)
     ;; uint32 _right_pulse
       (write-long _right_pulse s)
     ;; float64 _left_distance
       (sys::poke _left_distance (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _right_distance
       (sys::poke _right_distance (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _mileage
     (setq _mileage (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _left_pulse
     (setq _left_pulse (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _right_pulse
     (setq _right_pulse (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _left_distance
     (setq _left_distance (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _right_distance
     (setq _right_distance (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get three_one_msgs::ReportDistance :md5sum-) "11d828c6b9eb85d8fbb317377ee4beba")
(setf (get three_one_msgs::ReportDistance :datatype-) "three_one_msgs/ReportDistance")
(setf (get three_one_msgs::ReportDistance :definition-)
      "uint32 mileage
uint32 left_pulse
uint32 right_pulse
float64 left_distance
float64 right_distance
")



(provide :three_one_msgs/ReportDistance "11d828c6b9eb85d8fbb317377ee4beba")


