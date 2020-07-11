
(cl:in-package :asdf)

(defsystem "movobsplan_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "Movobspath" :depends-on ("_package_Movobspath"))
    (:file "_package_Movobspath" :depends-on ("_package"))
    (:file "Movobspeed" :depends-on ("_package_Movobspeed"))
    (:file "_package_Movobspeed" :depends-on ("_package"))
    (:file "Movobspoint" :depends-on ("_package_Movobspoint"))
    (:file "_package_Movobspoint" :depends-on ("_package"))
    (:file "Movobspoints" :depends-on ("_package_Movobspoints"))
    (:file "_package_Movobspoints" :depends-on ("_package"))
  ))