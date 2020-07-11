;; Auto-generated. Do not edit!


(when (boundp 'control_msgs::ReportVehicleWorkMode)
  (if (not (find-package "CONTROL_MSGS"))
    (make-package "CONTROL_MSGS"))
  (shadow 'ReportVehicleWorkMode (find-package "CONTROL_MSGS")))
(unless (find-package "CONTROL_MSGS::REPORTVEHICLEWORKMODE")
  (make-package "CONTROL_MSGS::REPORTVEHICLEWORKMODE"))

(in-package "ROS")
;;//! \htmlinclude ReportVehicleWorkMode.msg.html


(defclass control_msgs::ReportVehicleWorkMode
  :super ros::object
  :slots (_work_mode ))

(defmethod control_msgs::ReportVehicleWorkMode
  (:init
   (&key
    ((:work_mode __work_mode) 0)
    )
   (send-super :init)
   (setq _work_mode (round __work_mode))
   self)
  (:work_mode
   (&optional __work_mode)
   (if __work_mode (setq _work_mode __work_mode)) _work_mode)
  (:serialization-length
   ()
   (+
    ;; uint8 _work_mode
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _work_mode
       (write-byte _work_mode s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _work_mode
     (setq _work_mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get control_msgs::ReportVehicleWorkMode :md5sum-) "fcfe851405844897c8730da81110283d")
(setf (get control_msgs::ReportVehicleWorkMode :datatype-) "control_msgs/ReportVehicleWorkMode")
(setf (get control_msgs::ReportVehicleWorkMode :definition-)
      "uint8 work_mode



")



(provide :control_msgs/ReportVehicleWorkMode "fcfe851405844897c8730da81110283d")


