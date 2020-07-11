;; Auto-generated. Do not edit!


(when (boundp 'control_msgs::ReportThrottle)
  (if (not (find-package "CONTROL_MSGS"))
    (make-package "CONTROL_MSGS"))
  (shadow 'ReportThrottle (find-package "CONTROL_MSGS")))
(unless (find-package "CONTROL_MSGS::REPORTTHROTTLE")
  (make-package "CONTROL_MSGS::REPORTTHROTTLE"))

(in-package "ROS")
;;//! \htmlinclude ReportThrottle.msg.html


(defclass control_msgs::ReportThrottle
  :super ros::object
  :slots (_throttle_opening _throttle_pedal ))

(defmethod control_msgs::ReportThrottle
  (:init
   (&key
    ((:throttle_opening __throttle_opening) 0.0)
    ((:throttle_pedal __throttle_pedal) 0.0)
    )
   (send-super :init)
   (setq _throttle_opening (float __throttle_opening))
   (setq _throttle_pedal (float __throttle_pedal))
   self)
  (:throttle_opening
   (&optional __throttle_opening)
   (if __throttle_opening (setq _throttle_opening __throttle_opening)) _throttle_opening)
  (:throttle_pedal
   (&optional __throttle_pedal)
   (if __throttle_pedal (setq _throttle_pedal __throttle_pedal)) _throttle_pedal)
  (:serialization-length
   ()
   (+
    ;; float32 _throttle_opening
    4
    ;; float32 _throttle_pedal
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _throttle_opening
       (sys::poke _throttle_opening (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _throttle_pedal
       (sys::poke _throttle_pedal (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _throttle_opening
     (setq _throttle_opening (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _throttle_pedal
     (setq _throttle_pedal (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get control_msgs::ReportThrottle :md5sum-) "3fec449e5f78595bef42751bd36df7c4")
(setf (get control_msgs::ReportThrottle :datatype-) "control_msgs/ReportThrottle")
(setf (get control_msgs::ReportThrottle :definition-)
      "float32 throttle_opening
float32 throttle_pedal

")



(provide :control_msgs/ReportThrottle "3fec449e5f78595bef42751bd36df7c4")


