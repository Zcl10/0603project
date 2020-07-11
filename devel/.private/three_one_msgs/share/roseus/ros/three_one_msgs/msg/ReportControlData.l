;; Auto-generated. Do not edit!


(when (boundp 'three_one_msgs::ReportControlData)
  (if (not (find-package "THREE_ONE_MSGS"))
    (make-package "THREE_ONE_MSGS"))
  (shadow 'ReportControlData (find-package "THREE_ONE_MSGS")))
(unless (find-package "THREE_ONE_MSGS::REPORTCONTROLDATA")
  (make-package "THREE_ONE_MSGS::REPORTCONTROLDATA"))

(in-package "ROS")
;;//! \htmlinclude ReportControlData.msg.html


(defclass three_one_msgs::ReportControlData
  :super ros::object
  :slots (_curvature _speed _rpm _work_mode _gear _turn_to _brake _park _cylinder_select _suspension_select _vertical_wall_mode _suspension_work_mode _suspension_work_mode_detail _suspension_cylinder_select_mode _suspension_cylinder_motor_control _fix_two_chamber_valve ))

(defmethod three_one_msgs::ReportControlData
  (:init
   (&key
    ((:curvature __curvature) 0.0)
    ((:speed __speed) 0.0)
    ((:rpm __rpm) 0)
    ((:work_mode __work_mode) 0)
    ((:gear __gear) 0)
    ((:turn_to __turn_to) 0)
    ((:brake __brake) 0)
    ((:park __park) 0)
    ((:cylinder_select __cylinder_select) 0)
    ((:suspension_select __suspension_select) 0)
    ((:vertical_wall_mode __vertical_wall_mode) 0)
    ((:suspension_work_mode __suspension_work_mode) 0)
    ((:suspension_work_mode_detail __suspension_work_mode_detail) 0)
    ((:suspension_cylinder_select_mode __suspension_cylinder_select_mode) 0)
    ((:suspension_cylinder_motor_control __suspension_cylinder_motor_control) 0)
    ((:fix_two_chamber_valve __fix_two_chamber_valve) 0)
    )
   (send-super :init)
   (setq _curvature (float __curvature))
   (setq _speed (float __speed))
   (setq _rpm (round __rpm))
   (setq _work_mode (round __work_mode))
   (setq _gear (round __gear))
   (setq _turn_to (round __turn_to))
   (setq _brake (round __brake))
   (setq _park (round __park))
   (setq _cylinder_select (round __cylinder_select))
   (setq _suspension_select (round __suspension_select))
   (setq _vertical_wall_mode (round __vertical_wall_mode))
   (setq _suspension_work_mode (round __suspension_work_mode))
   (setq _suspension_work_mode_detail (round __suspension_work_mode_detail))
   (setq _suspension_cylinder_select_mode (round __suspension_cylinder_select_mode))
   (setq _suspension_cylinder_motor_control (round __suspension_cylinder_motor_control))
   (setq _fix_two_chamber_valve (round __fix_two_chamber_valve))
   self)
  (:curvature
   (&optional __curvature)
   (if __curvature (setq _curvature __curvature)) _curvature)
  (:speed
   (&optional __speed)
   (if __speed (setq _speed __speed)) _speed)
  (:rpm
   (&optional __rpm)
   (if __rpm (setq _rpm __rpm)) _rpm)
  (:work_mode
   (&optional __work_mode)
   (if __work_mode (setq _work_mode __work_mode)) _work_mode)
  (:gear
   (&optional __gear)
   (if __gear (setq _gear __gear)) _gear)
  (:turn_to
   (&optional __turn_to)
   (if __turn_to (setq _turn_to __turn_to)) _turn_to)
  (:brake
   (&optional __brake)
   (if __brake (setq _brake __brake)) _brake)
  (:park
   (&optional __park)
   (if __park (setq _park __park)) _park)
  (:cylinder_select
   (&optional __cylinder_select)
   (if __cylinder_select (setq _cylinder_select __cylinder_select)) _cylinder_select)
  (:suspension_select
   (&optional __suspension_select)
   (if __suspension_select (setq _suspension_select __suspension_select)) _suspension_select)
  (:vertical_wall_mode
   (&optional __vertical_wall_mode)
   (if __vertical_wall_mode (setq _vertical_wall_mode __vertical_wall_mode)) _vertical_wall_mode)
  (:suspension_work_mode
   (&optional __suspension_work_mode)
   (if __suspension_work_mode (setq _suspension_work_mode __suspension_work_mode)) _suspension_work_mode)
  (:suspension_work_mode_detail
   (&optional __suspension_work_mode_detail)
   (if __suspension_work_mode_detail (setq _suspension_work_mode_detail __suspension_work_mode_detail)) _suspension_work_mode_detail)
  (:suspension_cylinder_select_mode
   (&optional __suspension_cylinder_select_mode)
   (if __suspension_cylinder_select_mode (setq _suspension_cylinder_select_mode __suspension_cylinder_select_mode)) _suspension_cylinder_select_mode)
  (:suspension_cylinder_motor_control
   (&optional __suspension_cylinder_motor_control)
   (if __suspension_cylinder_motor_control (setq _suspension_cylinder_motor_control __suspension_cylinder_motor_control)) _suspension_cylinder_motor_control)
  (:fix_two_chamber_valve
   (&optional __fix_two_chamber_valve)
   (if __fix_two_chamber_valve (setq _fix_two_chamber_valve __fix_two_chamber_valve)) _fix_two_chamber_valve)
  (:serialization-length
   ()
   (+
    ;; float32 _curvature
    4
    ;; float32 _speed
    4
    ;; uint16 _rpm
    2
    ;; uint8 _work_mode
    1
    ;; uint8 _gear
    1
    ;; uint8 _turn_to
    1
    ;; uint8 _brake
    1
    ;; uint8 _park
    1
    ;; uint8 _cylinder_select
    1
    ;; uint8 _suspension_select
    1
    ;; uint8 _vertical_wall_mode
    1
    ;; uint8 _suspension_work_mode
    1
    ;; uint8 _suspension_work_mode_detail
    1
    ;; uint8 _suspension_cylinder_select_mode
    1
    ;; uint8 _suspension_cylinder_motor_control
    1
    ;; uint8 _fix_two_chamber_valve
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _curvature
       (sys::poke _curvature (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _speed
       (sys::poke _speed (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint16 _rpm
       (write-word _rpm s)
     ;; uint8 _work_mode
       (write-byte _work_mode s)
     ;; uint8 _gear
       (write-byte _gear s)
     ;; uint8 _turn_to
       (write-byte _turn_to s)
     ;; uint8 _brake
       (write-byte _brake s)
     ;; uint8 _park
       (write-byte _park s)
     ;; uint8 _cylinder_select
       (write-byte _cylinder_select s)
     ;; uint8 _suspension_select
       (write-byte _suspension_select s)
     ;; uint8 _vertical_wall_mode
       (write-byte _vertical_wall_mode s)
     ;; uint8 _suspension_work_mode
       (write-byte _suspension_work_mode s)
     ;; uint8 _suspension_work_mode_detail
       (write-byte _suspension_work_mode_detail s)
     ;; uint8 _suspension_cylinder_select_mode
       (write-byte _suspension_cylinder_select_mode s)
     ;; uint8 _suspension_cylinder_motor_control
       (write-byte _suspension_cylinder_motor_control s)
     ;; uint8 _fix_two_chamber_valve
       (write-byte _fix_two_chamber_valve s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _curvature
     (setq _curvature (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _speed
     (setq _speed (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint16 _rpm
     (setq _rpm (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _work_mode
     (setq _work_mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _gear
     (setq _gear (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _turn_to
     (setq _turn_to (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _brake
     (setq _brake (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _park
     (setq _park (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _cylinder_select
     (setq _cylinder_select (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _suspension_select
     (setq _suspension_select (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _vertical_wall_mode
     (setq _vertical_wall_mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _suspension_work_mode
     (setq _suspension_work_mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _suspension_work_mode_detail
     (setq _suspension_work_mode_detail (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _suspension_cylinder_select_mode
     (setq _suspension_cylinder_select_mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _suspension_cylinder_motor_control
     (setq _suspension_cylinder_motor_control (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _fix_two_chamber_valve
     (setq _fix_two_chamber_valve (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get three_one_msgs::ReportControlData :md5sum-) "a6b97385db9e76f4dfa530144bb3765f")
(setf (get three_one_msgs::ReportControlData :datatype-) "three_one_msgs/ReportControlData")
(setf (get three_one_msgs::ReportControlData :definition-)
      "float32 curvature
float32 speed
uint16 rpm
uint8 work_mode
uint8 gear
uint8 turn_to
uint8 brake
uint8 park
uint8 cylinder_select
uint8 suspension_select
uint8 vertical_wall_mode
uint8 suspension_work_mode
uint8 suspension_work_mode_detail
uint8 suspension_cylinder_select_mode
uint8 suspension_cylinder_motor_control
uint8 fix_two_chamber_valve
")



(provide :three_one_msgs/ReportControlData "a6b97385db9e76f4dfa530144bb3765f")


