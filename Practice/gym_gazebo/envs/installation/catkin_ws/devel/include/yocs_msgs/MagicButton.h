// Generated by gencpp from file yocs_msgs/MagicButton.msg
// DO NOT EDIT!


#ifndef YOCS_MSGS_MESSAGE_MAGICBUTTON_H
#define YOCS_MSGS_MESSAGE_MAGICBUTTON_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace yocs_msgs
{
template <class ContainerAllocator>
struct MagicButton_
{
  typedef MagicButton_<ContainerAllocator> Type;

  MagicButton_()
    : header()
    , pressed(false)  {
    }
  MagicButton_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , pressed(false)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint8_t _pressed_type;
  _pressed_type pressed;




  typedef boost::shared_ptr< ::yocs_msgs::MagicButton_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::yocs_msgs::MagicButton_<ContainerAllocator> const> ConstPtr;

}; // struct MagicButton_

typedef ::yocs_msgs::MagicButton_<std::allocator<void> > MagicButton;

typedef boost::shared_ptr< ::yocs_msgs::MagicButton > MagicButtonPtr;
typedef boost::shared_ptr< ::yocs_msgs::MagicButton const> MagicButtonConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::yocs_msgs::MagicButton_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::yocs_msgs::MagicButton_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace yocs_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'yocs_msgs': ['/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/yocs_msgs/msg', '/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel/share/yocs_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::yocs_msgs::MagicButton_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::yocs_msgs::MagicButton_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::yocs_msgs::MagicButton_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::yocs_msgs::MagicButton_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::yocs_msgs::MagicButton_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::yocs_msgs::MagicButton_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::yocs_msgs::MagicButton_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bfc1e2424321b1d3dcc226b473f78588";
  }

  static const char* value(const ::yocs_msgs::MagicButton_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbfc1e2424321b1d3ULL;
  static const uint64_t static_value2 = 0xdcc226b473f78588ULL;
};

template<class ContainerAllocator>
struct DataType< ::yocs_msgs::MagicButton_<ContainerAllocator> >
{
  static const char* value()
  {
    return "yocs_msgs/MagicButton";
  }

  static const char* value(const ::yocs_msgs::MagicButton_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::yocs_msgs::MagicButton_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Used to send status and timestamp of a magic button press (typically\n\
# from a joystick). Used in yocs_joyop.\n\
\n\
std_msgs/Header header\n\
bool pressed\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::yocs_msgs::MagicButton_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::yocs_msgs::MagicButton_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.pressed);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MagicButton_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::yocs_msgs::MagicButton_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::yocs_msgs::MagicButton_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "pressed: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.pressed);
  }
};

} // namespace message_operations
} // namespace ros

#endif // YOCS_MSGS_MESSAGE_MAGICBUTTON_H
