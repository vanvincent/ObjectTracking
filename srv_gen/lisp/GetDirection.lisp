; Auto-generated. Do not edit!


(cl:in-package colortrack_ros-srv)


;//! \htmlinclude GetDirection-request.msg.html

(cl:defclass <GetDirection-request> (roslisp-msg-protocol:ros-message)
  ((color
    :reader color
    :initarg :color
    :type cl:string
    :initform ""))
)

(cl:defclass GetDirection-request (<GetDirection-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetDirection-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetDirection-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name colortrack_ros-srv:<GetDirection-request> is deprecated: use colortrack_ros-srv:GetDirection-request instead.")))

(cl:ensure-generic-function 'color-val :lambda-list '(m))
(cl:defmethod color-val ((m <GetDirection-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader colortrack_ros-srv:color-val is deprecated.  Use colortrack_ros-srv:color instead.")
  (color m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetDirection-request>) ostream)
  "Serializes a message object of type '<GetDirection-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'color))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'color))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetDirection-request>) istream)
  "Deserializes a message object of type '<GetDirection-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'color) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'color) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetDirection-request>)))
  "Returns string type for a service object of type '<GetDirection-request>"
  "colortrack_ros/GetDirectionRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetDirection-request)))
  "Returns string type for a service object of type 'GetDirection-request"
  "colortrack_ros/GetDirectionRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetDirection-request>)))
  "Returns md5sum for a message object of type '<GetDirection-request>"
  "122806e889d9e6a9d8604fae5a0ab895")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetDirection-request)))
  "Returns md5sum for a message object of type 'GetDirection-request"
  "122806e889d9e6a9d8604fae5a0ab895")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetDirection-request>)))
  "Returns full string definition for message of type '<GetDirection-request>"
  (cl:format cl:nil "string color~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetDirection-request)))
  "Returns full string definition for message of type 'GetDirection-request"
  (cl:format cl:nil "string color~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetDirection-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'color))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetDirection-request>))
  "Converts a ROS message object to a list"
  (cl:list 'GetDirection-request
    (cl:cons ':color (color msg))
))
;//! \htmlinclude GetDirection-response.msg.html

(cl:defclass <GetDirection-response> (roslisp-msg-protocol:ros-message)
  ((left_distance
    :reader left_distance
    :initarg :left_distance
    :type cl:float
    :initform 0.0)
   (front_distance
    :reader front_distance
    :initarg :front_distance
    :type cl:float
    :initform 0.0))
)

(cl:defclass GetDirection-response (<GetDirection-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetDirection-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetDirection-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name colortrack_ros-srv:<GetDirection-response> is deprecated: use colortrack_ros-srv:GetDirection-response instead.")))

(cl:ensure-generic-function 'left_distance-val :lambda-list '(m))
(cl:defmethod left_distance-val ((m <GetDirection-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader colortrack_ros-srv:left_distance-val is deprecated.  Use colortrack_ros-srv:left_distance instead.")
  (left_distance m))

(cl:ensure-generic-function 'front_distance-val :lambda-list '(m))
(cl:defmethod front_distance-val ((m <GetDirection-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader colortrack_ros-srv:front_distance-val is deprecated.  Use colortrack_ros-srv:front_distance instead.")
  (front_distance m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetDirection-response>) ostream)
  "Serializes a message object of type '<GetDirection-response>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'left_distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'front_distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetDirection-response>) istream)
  "Deserializes a message object of type '<GetDirection-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_distance) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'front_distance) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetDirection-response>)))
  "Returns string type for a service object of type '<GetDirection-response>"
  "colortrack_ros/GetDirectionResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetDirection-response)))
  "Returns string type for a service object of type 'GetDirection-response"
  "colortrack_ros/GetDirectionResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetDirection-response>)))
  "Returns md5sum for a message object of type '<GetDirection-response>"
  "122806e889d9e6a9d8604fae5a0ab895")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetDirection-response)))
  "Returns md5sum for a message object of type 'GetDirection-response"
  "122806e889d9e6a9d8604fae5a0ab895")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetDirection-response>)))
  "Returns full string definition for message of type '<GetDirection-response>"
  (cl:format cl:nil "float32 left_distance~%float32 front_distance~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetDirection-response)))
  "Returns full string definition for message of type 'GetDirection-response"
  (cl:format cl:nil "float32 left_distance~%float32 front_distance~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetDirection-response>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetDirection-response>))
  "Converts a ROS message object to a list"
  (cl:list 'GetDirection-response
    (cl:cons ':left_distance (left_distance msg))
    (cl:cons ':front_distance (front_distance msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'GetDirection)))
  'GetDirection-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'GetDirection)))
  'GetDirection-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetDirection)))
  "Returns string type for a service object of type '<GetDirection>"
  "colortrack_ros/GetDirection")