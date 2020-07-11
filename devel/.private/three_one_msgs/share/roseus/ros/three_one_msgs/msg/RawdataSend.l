;; Auto-generated. Do not edit!


(when (boundp 'three_one_msgs::RawdataSend)
  (if (not (find-package "THREE_ONE_MSGS"))
    (make-package "THREE_ONE_MSGS"))
  (shadow 'RawdataSend (find-package "THREE_ONE_MSGS")))
(unless (find-package "THREE_ONE_MSGS::RAWDATASEND")
  (make-package "THREE_ONE_MSGS::RAWDATASEND"))

(in-package "ROS")
;;//! \htmlinclude RawdataSend.msg.html


(defclass three_one_msgs::RawdataSend
  :super ros::object
  :slots (_ros_time _data ))

(defmethod three_one_msgs::RawdataSend
  (:init
   (&key
    ((:ros_time __ros_time) 0.0)
    ((:data __data) (make-array 0 :initial-element 0 :element-type :char))
    )
   (send-super :init)
   (setq _ros_time (float __ros_time))
   (setq _data __data)
   self)
  (:ros_time
   (&optional __ros_time)
   (if __ros_time (setq _ros_time __ros_time)) _ros_time)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:serialization-length
   ()
   (+
    ;; float64 _ros_time
    8
    ;; uint8[] _data
    (* 1    (length _data)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _ros_time
       (sys::poke _ros_time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; uint8[] _data
     (write-long (length _data) s)
     (princ _data s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _ros_time
     (setq _ros_time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; uint8[] _data
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _data (make-array n :element-type :char))
     (replace _data buf :start2 ptr-) (incf ptr- n))
   ;;
   self)
  )

(setf (get three_one_msgs::RawdataSend :md5sum-) "a34d701bf319ec12f678fa7cb20e57e3")
(setf (get three_one_msgs::RawdataSend :datatype-) "three_one_msgs/RawdataSend")
(setf (get three_one_msgs::RawdataSend :definition-)
      "float64 ros_time
uint8[] data
")



(provide :three_one_msgs/RawdataSend "a34d701bf319ec12f678fa7cb20e57e3")


