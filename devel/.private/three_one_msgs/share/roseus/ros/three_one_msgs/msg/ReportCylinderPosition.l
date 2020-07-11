;; Auto-generated. Do not edit!


(when (boundp 'three_one_msgs::ReportCylinderPosition)
  (if (not (find-package "THREE_ONE_MSGS"))
    (make-package "THREE_ONE_MSGS"))
  (shadow 'ReportCylinderPosition (find-package "THREE_ONE_MSGS")))
(unless (find-package "THREE_ONE_MSGS::REPORTCYLINDERPOSITION")
  (make-package "THREE_ONE_MSGS::REPORTCYLINDERPOSITION"))

(in-package "ROS")
;;//! \htmlinclude ReportCylinderPosition.msg.html


(defclass three_one_msgs::ReportCylinderPosition
  :super ros::object
  :slots (_left_one _left_two _left_three _left_four _right_one _right_two _right_three _right_four ))

(defmethod three_one_msgs::ReportCylinderPosition
  (:init
   (&key
    ((:left_one __left_one) 0)
    ((:left_two __left_two) 0)
    ((:left_three __left_three) 0)
    ((:left_four __left_four) 0)
    ((:right_one __right_one) 0)
    ((:right_two __right_two) 0)
    ((:right_three __right_three) 0)
    ((:right_four __right_four) 0)
    )
   (send-super :init)
   (setq _left_one (round __left_one))
   (setq _left_two (round __left_two))
   (setq _left_three (round __left_three))
   (setq _left_four (round __left_four))
   (setq _right_one (round __right_one))
   (setq _right_two (round __right_two))
   (setq _right_three (round __right_three))
   (setq _right_four (round __right_four))
   self)
  (:left_one
   (&optional __left_one)
   (if __left_one (setq _left_one __left_one)) _left_one)
  (:left_two
   (&optional __left_two)
   (if __left_two (setq _left_two __left_two)) _left_two)
  (:left_three
   (&optional __left_three)
   (if __left_three (setq _left_three __left_three)) _left_three)
  (:left_four
   (&optional __left_four)
   (if __left_four (setq _left_four __left_four)) _left_four)
  (:right_one
   (&optional __right_one)
   (if __right_one (setq _right_one __right_one)) _right_one)
  (:right_two
   (&optional __right_two)
   (if __right_two (setq _right_two __right_two)) _right_two)
  (:right_three
   (&optional __right_three)
   (if __right_three (setq _right_three __right_three)) _right_three)
  (:right_four
   (&optional __right_four)
   (if __right_four (setq _right_four __right_four)) _right_four)
  (:serialization-length
   ()
   (+
    ;; uint16 _left_one
    2
    ;; uint16 _left_two
    2
    ;; uint16 _left_three
    2
    ;; uint16 _left_four
    2
    ;; uint16 _right_one
    2
    ;; uint16 _right_two
    2
    ;; uint16 _right_three
    2
    ;; uint16 _right_four
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16 _left_one
       (write-word _left_one s)
     ;; uint16 _left_two
       (write-word _left_two s)
     ;; uint16 _left_three
       (write-word _left_three s)
     ;; uint16 _left_four
       (write-word _left_four s)
     ;; uint16 _right_one
       (write-word _right_one s)
     ;; uint16 _right_two
       (write-word _right_two s)
     ;; uint16 _right_three
       (write-word _right_three s)
     ;; uint16 _right_four
       (write-word _right_four s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16 _left_one
     (setq _left_one (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _left_two
     (setq _left_two (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _left_three
     (setq _left_three (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _left_four
     (setq _left_four (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _right_one
     (setq _right_one (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _right_two
     (setq _right_two (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _right_three
     (setq _right_three (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _right_four
     (setq _right_four (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get three_one_msgs::ReportCylinderPosition :md5sum-) "10a79bbfdcab9d59df66b73e79bbb8ac")
(setf (get three_one_msgs::ReportCylinderPosition :datatype-) "three_one_msgs/ReportCylinderPosition")
(setf (get three_one_msgs::ReportCylinderPosition :definition-)
      "uint16 left_one
uint16 left_two
uint16 left_three
uint16 left_four
uint16 right_one
uint16 right_two
uint16 right_three
uint16 right_four
")



(provide :three_one_msgs/ReportCylinderPosition "10a79bbfdcab9d59df66b73e79bbb8ac")


