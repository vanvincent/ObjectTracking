/* Auto-generated by genmsg_cpp for file /home/jfasola/fuerte_workspace/sandbox/colortrack_ros/srv/GetDirection.srv */
#ifndef COLORTRACK_ROS_SERVICE_GETDIRECTION_H
#define COLORTRACK_ROS_SERVICE_GETDIRECTION_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "ros/service_traits.h"




namespace colortrack_ros
{
template <class ContainerAllocator>
struct GetDirectionRequest_ {
  typedef GetDirectionRequest_<ContainerAllocator> Type;

  GetDirectionRequest_()
  : color()
  {
  }

  GetDirectionRequest_(const ContainerAllocator& _alloc)
  : color(_alloc)
  {
  }

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _color_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  color;


  typedef boost::shared_ptr< ::colortrack_ros::GetDirectionRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::colortrack_ros::GetDirectionRequest_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct GetDirectionRequest
typedef  ::colortrack_ros::GetDirectionRequest_<std::allocator<void> > GetDirectionRequest;

typedef boost::shared_ptr< ::colortrack_ros::GetDirectionRequest> GetDirectionRequestPtr;
typedef boost::shared_ptr< ::colortrack_ros::GetDirectionRequest const> GetDirectionRequestConstPtr;


template <class ContainerAllocator>
struct GetDirectionResponse_ {
  typedef GetDirectionResponse_<ContainerAllocator> Type;

  GetDirectionResponse_()
  : left_distance(0.0)
  , front_distance(0.0)
  {
  }

  GetDirectionResponse_(const ContainerAllocator& _alloc)
  : left_distance(0.0)
  , front_distance(0.0)
  {
  }

  typedef float _left_distance_type;
  float left_distance;

  typedef float _front_distance_type;
  float front_distance;


  typedef boost::shared_ptr< ::colortrack_ros::GetDirectionResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::colortrack_ros::GetDirectionResponse_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct GetDirectionResponse
typedef  ::colortrack_ros::GetDirectionResponse_<std::allocator<void> > GetDirectionResponse;

typedef boost::shared_ptr< ::colortrack_ros::GetDirectionResponse> GetDirectionResponsePtr;
typedef boost::shared_ptr< ::colortrack_ros::GetDirectionResponse const> GetDirectionResponseConstPtr;

struct GetDirection
{

typedef GetDirectionRequest Request;
typedef GetDirectionResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct GetDirection
} // namespace colortrack_ros

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::colortrack_ros::GetDirectionRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::colortrack_ros::GetDirectionRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::colortrack_ros::GetDirectionRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "89e44dcab627a2c43a70ae1100695caa";
  }

  static const char* value(const  ::colortrack_ros::GetDirectionRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x89e44dcab627a2c4ULL;
  static const uint64_t static_value2 = 0x3a70ae1100695caaULL;
};

template<class ContainerAllocator>
struct DataType< ::colortrack_ros::GetDirectionRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "colortrack_ros/GetDirectionRequest";
  }

  static const char* value(const  ::colortrack_ros::GetDirectionRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::colortrack_ros::GetDirectionRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "string color\n\
\n\
";
  }

  static const char* value(const  ::colortrack_ros::GetDirectionRequest_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::colortrack_ros::GetDirectionResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::colortrack_ros::GetDirectionResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::colortrack_ros::GetDirectionResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "dcea709c91c145aa7022915bcff78b5d";
  }

  static const char* value(const  ::colortrack_ros::GetDirectionResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xdcea709c91c145aaULL;
  static const uint64_t static_value2 = 0x7022915bcff78b5dULL;
};

template<class ContainerAllocator>
struct DataType< ::colortrack_ros::GetDirectionResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "colortrack_ros/GetDirectionResponse";
  }

  static const char* value(const  ::colortrack_ros::GetDirectionResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::colortrack_ros::GetDirectionResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "float32 left_distance\n\
float32 front_distance\n\
\n\
\n\
";
  }

  static const char* value(const  ::colortrack_ros::GetDirectionResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::colortrack_ros::GetDirectionResponse_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::colortrack_ros::GetDirectionRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.color);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct GetDirectionRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::colortrack_ros::GetDirectionResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.left_distance);
    stream.next(m.front_distance);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct GetDirectionResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<colortrack_ros::GetDirection> {
  static const char* value() 
  {
    return "122806e889d9e6a9d8604fae5a0ab895";
  }

  static const char* value(const colortrack_ros::GetDirection&) { return value(); } 
};

template<>
struct DataType<colortrack_ros::GetDirection> {
  static const char* value() 
  {
    return "colortrack_ros/GetDirection";
  }

  static const char* value(const colortrack_ros::GetDirection&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<colortrack_ros::GetDirectionRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "122806e889d9e6a9d8604fae5a0ab895";
  }

  static const char* value(const colortrack_ros::GetDirectionRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<colortrack_ros::GetDirectionRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "colortrack_ros/GetDirection";
  }

  static const char* value(const colortrack_ros::GetDirectionRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<colortrack_ros::GetDirectionResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "122806e889d9e6a9d8604fae5a0ab895";
  }

  static const char* value(const colortrack_ros::GetDirectionResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<colortrack_ros::GetDirectionResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "colortrack_ros/GetDirection";
  }

  static const char* value(const colortrack_ros::GetDirectionResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // COLORTRACK_ROS_SERVICE_GETDIRECTION_H
