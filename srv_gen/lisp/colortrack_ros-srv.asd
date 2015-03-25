
(cl:in-package :asdf)

(defsystem "colortrack_ros-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "GetDirection" :depends-on ("_package_GetDirection"))
    (:file "_package_GetDirection" :depends-on ("_package"))
  ))