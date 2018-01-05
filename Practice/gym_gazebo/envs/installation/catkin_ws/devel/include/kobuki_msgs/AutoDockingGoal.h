// Generated by gencpp from file kobuki_msgs/AutoDockingGoal.msg
// DO NOT EDIT!


#ifndef KOBUKI_MSGS_MESSAGE_AUTODOCKINGGOAL_H
#define KOBUKI_MSGS_MESSAGE_AUTODOCKINGGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace kobuki_msgs
{
template <class ContainerAllocator>
struct AutoDockingGoal_
{
  typedef AutoDockingGoal_<ContainerAllocator> Type;

  AutoDockingGoal_()
    {
    }
  AutoDockingGoal_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }






  typedef boost::shared_ptr< ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator> const> ConstPtr;

}; // struct AutoDockingGoal_

typedef ::kobuki_msgs::AutoDockingGoal_<std::allocator<void> > AutoDockingGoal;

typedef boost::shared_ptr< ::kobuki_msgs::AutoDockingGoal > AutoDockingGoalPtr;
typedef boost::shared_ptr< ::kobuki_msgs::AutoDockingGoal const> AutoDockingGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace kobuki_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'kobuki_msgs': ['/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/kobuki_msgs/msg', '/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel/share/kobuki_msgs/msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "kobuki_msgs/AutoDockingGoal";
  }

  static const char* value(const ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#goal\n\
";
  }

  static const char* value(const ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AutoDockingGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::kobuki_msgs::AutoDockingGoal_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // KOBUKI_MSGS_MESSAGE_AUTODOCKINGGOAL_H
