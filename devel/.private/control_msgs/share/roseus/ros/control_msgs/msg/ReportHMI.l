;; Auto-generated. Do not edit!


(when (boundp 'control_msgs::ReportHMI)
  (if (not (find-package "CONTROL_MSGS"))
    (make-package "CONTROL_MSGS"))
  (shadow 'ReportHMI (find-package "CONTROL_MSGS")))
(unless (find-package "CONTROL_MSGS::REPORTHMI")
  (make-package "CONTROL_MSGS::REPORTHMI"))

(in-package "ROS")
;;//! \htmlinclude ReportHMI.msg.html


(defclass control_msgs::ReportHMI
  :super ros::object
  :slots (_manual_estop _is_human_brake ))

(defmethod control_msgs::ReportHMI
  (:init
   (&key
    ((:manual_estop __manual_estop) 0)
    ((:is_human_brake __is_human_brake) 0)
    )
   (send-super :init)
   (setq _manual_estop (round __manual_estop))
   (setq _is_human_brake (round __is_human_brake))
   self)
  (:manual_estop
   (&optional __manual_estop)
   (if __manual_estop (setq _manual_estop __manual_estop)) _manual_estop)
  (:is_human_brake
   (&optional __is_human_brake)
   (if __is_human_brake (setq _is_human_brake __is_human_brake)) _is_human_brake)
  (:serialization-length
   ()
   (+
    ;; uint8 _manual_estop
    1
    ;; uint8 _is_human_brake
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _manual_estop
       (write-byte _manual_estop s)
     ;; uint8 _is_human_brake
       (write-byte _is_human_brake s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _manual_estop
     (setq _manual_estop (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _is_human_brake
     (setq _is_human_brake (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get control_msgs::ReportHMI :md5sum-) "f19a467eddf6f2a1b5c81ed415355fbf")
(setf (get control_msgs::ReportHMI :datatype-) "control_msgs/ReportHMI")
(setf (get control_msgs::ReportHMI :definition-)
      "uint8 manual_estop
uint8 is_human_brake 

")



(provide :control_msgs/ReportHMI "f19a467eddf6f2a1b5c81ed415355fbf")


