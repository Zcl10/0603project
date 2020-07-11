;; Auto-generated. Do not edit!


(when (boundp 'three_one_msgs::ReportGiveBack)
  (if (not (find-package "THREE_ONE_MSGS"))
    (make-package "THREE_ONE_MSGS"))
  (shadow 'ReportGiveBack (find-package "THREE_ONE_MSGS")))
(unless (find-package "THREE_ONE_MSGS::REPORTGIVEBACK")
  (make-package "THREE_ONE_MSGS::REPORTGIVEBACK"))

(in-package "ROS")
;;//! \htmlinclude ReportGiveBack.msg.html


(defclass three_one_msgs::ReportGiveBack
  :super ros::object
  :slots (_left_wheel_expect_speed _right_wheel_expect_speed ))

(defmethod three_one_msgs::ReportGiveBack
  (:init
   (&key
    ((:left_wheel_expect_speed __left_wheel_expect_speed) 0.0)
    ((:right_wheel_expect_speed __right_wheel_expect_speed) 0.0)
    )
   (send-super :init)
   (setq _left_wheel_expect_speed (float __left_wheel_expect_speed))
   (setq _right_wheel_expect_speed (float __right_wheel_expect_speed))
   self)
  (:left_wheel_expect_speed
   (&optional __left_wheel_expect_speed)
   (if __left_wheel_expect_speed (setq _left_wheel_expect_speed __left_wheel_expect_speed)) _left_wheel_expect_speed)
  (:right_wheel_expect_speed
   (&optional __right_wheel_expect_speed)
   (if __right_wheel_expect_speed (setq _right_wheel_expect_speed __right_wheel_expect_speed)) _right_wheel_expect_speed)
  (:serialization-length
   ()
   (+
    ;; float32 _left_wheel_expect_speed
    4
    ;; float32 _right_wheel_expect_speed
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _left_wheel_expect_speed
       (sys::poke _left_wheel_expect_speed (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _right_wheel_expect_speed
       (sys::poke _right_wheel_expect_speed (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _left_wheel_expect_speed
     (setq _left_wheel_expect_speed (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _right_wheel_expect_speed
     (setq _right_wheel_expect_speed (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get three_one_msgs::ReportGiveBack :md5sum-) "a412fdf7ba4df281362ad0892df1c4a0")
(setf (get three_one_msgs::ReportGiveBack :datatype-) "three_one_msgs/ReportGiveBack")
(setf (get three_one_msgs::ReportGiveBack :definition-)
      "float32 left_wheel_expect_speed
float32 right_wheel_expect_speed
")



(provide :three_one_msgs/ReportGiveBack "a412fdf7ba4df281362ad0892df1c4a0")


