// Generated by gencpp from file create_node/SetTurtlebotModeResponse.msg
// DO NOT EDIT!


#ifndef CREATE_NODE_MESSAGE_SETTURTLEBOTMODERESPONSE_H
#define CREATE_NODE_MESSAGE_SETTURTLEBOTMODERESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace create_node
{
template <class ContainerAllocator>
struct SetTurtlebotModeResponse_
{
  typedef SetTurtlebotModeResponse_<ContainerAllocator> Type;

  SetTurtlebotModeResponse_()
    : valid_mode(false)  {
    }
  SetTurtlebotModeResponse_(const ContainerAllocator& _alloc)
    : valid_mode(false)  {
  (void)_alloc;
    }



   typedef uint8_t _valid_mode_type;
  _valid_mode_type valid_mode;




  typedef boost::shared_ptr< ::create_node::SetTurtlebotModeResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::create_node::SetTurtlebotModeResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SetTurtlebotModeResponse_

typedef ::create_node::SetTurtlebotModeResponse_<std::allocator<void> > SetTurtlebotModeResponse;

typedef boost::shared_ptr< ::create_node::SetTurtlebotModeResponse > SetTurtlebotModeResponsePtr;
typedef boost::shared_ptr< ::create_node::SetTurtlebotModeResponse const> SetTurtlebotModeResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::create_node::SetTurtlebotModeResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::create_node::SetTurtlebotModeResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace create_node

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'create_node': ['/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/msg'], 'diagnostic_msgs': ['/opt/ros/kinetic/share/diagnostic_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::create_node::SetTurtlebotModeResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::create_node::SetTurtlebotModeResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::create_node::SetTurtlebotModeResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::create_node::SetTurtlebotModeResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::create_node::SetTurtlebotModeResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::create_node::SetTurtlebotModeResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::create_node::SetTurtlebotModeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ef9db56bf4a60ce42049595d58c32b54";
  }

  static const char* value(const ::create_node::SetTurtlebotModeResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xef9db56bf4a60ce4ULL;
  static const uint64_t static_value2 = 0x2049595d58c32b54ULL;
};

template<class ContainerAllocator>
struct DataType< ::create_node::SetTurtlebotModeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "create_node/SetTurtlebotModeResponse";
  }

  static const char* value(const ::create_node::SetTurtlebotModeResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::create_node::SetTurtlebotModeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool valid_mode\n\
";
  }

  static const char* value(const ::create_node::SetTurtlebotModeResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::create_node::SetTurtlebotModeResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.valid_mode);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetTurtlebotModeResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::create_node::SetTurtlebotModeResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::create_node::SetTurtlebotModeResponse_<ContainerAllocator>& v)
  {
    s << indent << "valid_mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.valid_mode);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CREATE_NODE_MESSAGE_SETTURTLEBOTMODERESPONSE_H
