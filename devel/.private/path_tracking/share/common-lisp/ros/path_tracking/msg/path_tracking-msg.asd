
(cl:in-package :asdf)

(defsystem "path_tracking-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :anm_msgs-msg
               :control_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ModelParameter" :depends-on ("_package_ModelParameter"))
    (:file "_package_ModelParameter" :depends-on ("_package"))
    (:file "observer" :depends-on ("_package_observer"))
    (:file "_package_observer" :depends-on ("_package"))
  ))