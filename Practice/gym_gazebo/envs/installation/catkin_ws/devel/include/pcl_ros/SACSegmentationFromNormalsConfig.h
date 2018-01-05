//#line 2 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
// 
// File autogenerated for the pcl_ros package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

#ifndef __pcl_ros__SACSEGMENTATIONFROMNORMALSCONFIG_H__
#define __pcl_ros__SACSEGMENTATIONFROMNORMALSCONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace pcl_ros
{
  class SACSegmentationFromNormalsConfigStatics;
  
  class SACSegmentationFromNormalsConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l, 
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      
      virtual void clamp(SACSegmentationFromNormalsConfig &config, const SACSegmentationFromNormalsConfig &max, const SACSegmentationFromNormalsConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const SACSegmentationFromNormalsConfig &config1, const SACSegmentationFromNormalsConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, SACSegmentationFromNormalsConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const SACSegmentationFromNormalsConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, SACSegmentationFromNormalsConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const SACSegmentationFromNormalsConfig &config) const = 0;
      virtual void getValue(const SACSegmentationFromNormalsConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level, 
          std::string a_description, std::string a_edit_method, T SACSegmentationFromNormalsConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T (SACSegmentationFromNormalsConfig::* field);

      virtual void clamp(SACSegmentationFromNormalsConfig &config, const SACSegmentationFromNormalsConfig &max, const SACSegmentationFromNormalsConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const SACSegmentationFromNormalsConfig &config1, const SACSegmentationFromNormalsConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, SACSegmentationFromNormalsConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const SACSegmentationFromNormalsConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, SACSegmentationFromNormalsConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const SACSegmentationFromNormalsConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const SACSegmentationFromNormalsConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, SACSegmentationFromNormalsConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    template<class T, class PT>
    class GroupDescription : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, SACSegmentationFromNormalsConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<SACSegmentationFromNormalsConfig::AbstractGroupDescriptionConstPtr> groups;
    };
    
class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(SACSegmentationFromNormalsConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("normal_distance_weight"==(*_i)->name){normal_distance_weight = boost::any_cast<double>(val);}
        if("max_iterations"==(*_i)->name){max_iterations = boost::any_cast<int>(val);}
        if("probability"==(*_i)->name){probability = boost::any_cast<double>(val);}
        if("distance_threshold"==(*_i)->name){distance_threshold = boost::any_cast<double>(val);}
        if("optimize_coefficients"==(*_i)->name){optimize_coefficients = boost::any_cast<bool>(val);}
        if("radius_min"==(*_i)->name){radius_min = boost::any_cast<double>(val);}
        if("radius_max"==(*_i)->name){radius_max = boost::any_cast<double>(val);}
        if("eps_angle"==(*_i)->name){eps_angle = boost::any_cast<double>(val);}
        if("min_inliers"==(*_i)->name){min_inliers = boost::any_cast<int>(val);}
        if("input_frame"==(*_i)->name){input_frame = boost::any_cast<std::string>(val);}
        if("output_frame"==(*_i)->name){output_frame = boost::any_cast<std::string>(val);}
      }
    }

    double normal_distance_weight;
int max_iterations;
double probability;
double distance_threshold;
bool optimize_coefficients;
double radius_min;
double radius_max;
double eps_angle;
int min_inliers;
std::string input_frame;
std::string output_frame;

    bool state;
    std::string name;

    
}groups;



//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double normal_distance_weight;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int max_iterations;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double probability;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double distance_threshold;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool optimize_coefficients;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double radius_min;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double radius_max;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double eps_angle;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int min_inliers;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      std::string input_frame;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      std::string output_frame;
//#line 218 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("SACSegmentationFromNormalsConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const SACSegmentationFromNormalsConfig &__max__ = __getMax__();
      const SACSegmentationFromNormalsConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const SACSegmentationFromNormalsConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const SACSegmentationFromNormalsConfig &__getDefault__();
    static const SACSegmentationFromNormalsConfig &__getMax__();
    static const SACSegmentationFromNormalsConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();
    
  private:
    static const SACSegmentationFromNormalsConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void SACSegmentationFromNormalsConfig::ParamDescription<std::string>::clamp(SACSegmentationFromNormalsConfig &config, const SACSegmentationFromNormalsConfig &max, const SACSegmentationFromNormalsConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class SACSegmentationFromNormalsConfigStatics
  {
    friend class SACSegmentationFromNormalsConfig;
    
    SACSegmentationFromNormalsConfigStatics()
    {
SACSegmentationFromNormalsConfig::GroupDescription<SACSegmentationFromNormalsConfig::DEFAULT, SACSegmentationFromNormalsConfig> Default("Default", "", 0, 0, true, &SACSegmentationFromNormalsConfig::groups);
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.normal_distance_weight = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.normal_distance_weight = 1.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.normal_distance_weight = 0.1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<double>("normal_distance_weight", "double", 0, "The relative weight (between 0 and 1) to give to the angular distance (0 to pi/2) between point normals and the plane normal.", "", &SACSegmentationFromNormalsConfig::normal_distance_weight)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<double>("normal_distance_weight", "double", 0, "The relative weight (between 0 and 1) to give to the angular distance (0 to pi/2) between point normals and the plane normal.", "", &SACSegmentationFromNormalsConfig::normal_distance_weight)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.max_iterations = 0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.max_iterations = 100000;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.max_iterations = 50;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<int>("max_iterations", "int", 0, "The maximum number of iterations the algorithm will run for", "", &SACSegmentationFromNormalsConfig::max_iterations)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<int>("max_iterations", "int", 0, "The maximum number of iterations the algorithm will run for", "", &SACSegmentationFromNormalsConfig::max_iterations)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.probability = 0.5;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.probability = 0.99;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.probability = 0.99;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<double>("probability", "double", 0, "The desired probability of choosing at least one sample free from outliers", "", &SACSegmentationFromNormalsConfig::probability)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<double>("probability", "double", 0, "The desired probability of choosing at least one sample free from outliers", "", &SACSegmentationFromNormalsConfig::probability)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.distance_threshold = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.distance_threshold = 1.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.distance_threshold = 0.02;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<double>("distance_threshold", "double", 0, "The distance to model threshold", "", &SACSegmentationFromNormalsConfig::distance_threshold)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<double>("distance_threshold", "double", 0, "The distance to model threshold", "", &SACSegmentationFromNormalsConfig::distance_threshold)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.optimize_coefficients = 0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.optimize_coefficients = 1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.optimize_coefficients = 1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<bool>("optimize_coefficients", "bool", 0, "Model coefficient refinement", "", &SACSegmentationFromNormalsConfig::optimize_coefficients)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<bool>("optimize_coefficients", "bool", 0, "Model coefficient refinement", "", &SACSegmentationFromNormalsConfig::optimize_coefficients)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.radius_min = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.radius_min = 1.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.radius_min = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<double>("radius_min", "double", 0, "The minimum allowed model radius (where applicable)", "", &SACSegmentationFromNormalsConfig::radius_min)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<double>("radius_min", "double", 0, "The minimum allowed model radius (where applicable)", "", &SACSegmentationFromNormalsConfig::radius_min)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.radius_max = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.radius_max = 1.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.radius_max = 0.05;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<double>("radius_max", "double", 0, "The maximum allowed model radius (where applicable)", "", &SACSegmentationFromNormalsConfig::radius_max)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<double>("radius_max", "double", 0, "The maximum allowed model radius (where applicable)", "", &SACSegmentationFromNormalsConfig::radius_max)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.eps_angle = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.eps_angle = 1.5707;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.eps_angle = 0.17;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<double>("eps_angle", "double", 0, "The maximum allowed difference between the model normal and the given axis in radians.", "", &SACSegmentationFromNormalsConfig::eps_angle)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<double>("eps_angle", "double", 0, "The maximum allowed difference between the model normal and the given axis in radians.", "", &SACSegmentationFromNormalsConfig::eps_angle)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.min_inliers = 0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.min_inliers = 100000;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.min_inliers = 0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<int>("min_inliers", "int", 0, "The minimum number of inliers a model must have in order to be considered valid.", "", &SACSegmentationFromNormalsConfig::min_inliers)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<int>("min_inliers", "int", 0, "The minimum number of inliers a model must have in order to be considered valid.", "", &SACSegmentationFromNormalsConfig::min_inliers)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.input_frame = "";
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.input_frame = "";
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.input_frame = "";
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<std::string>("input_frame", "str", 0, "The input TF frame the data should be transformed into, if input.header.frame_id is different.", "", &SACSegmentationFromNormalsConfig::input_frame)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<std::string>("input_frame", "str", 0, "The input TF frame the data should be transformed into, if input.header.frame_id is different.", "", &SACSegmentationFromNormalsConfig::input_frame)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.output_frame = "";
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.output_frame = "";
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.output_frame = "";
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<std::string>("output_frame", "str", 0, "The output TF frame the data should be transformed into, if input.header.frame_id is different.", "", &SACSegmentationFromNormalsConfig::output_frame)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr(new SACSegmentationFromNormalsConfig::ParamDescription<std::string>("output_frame", "str", 0, "The output TF frame the data should be transformed into, if input.header.frame_id is different.", "", &SACSegmentationFromNormalsConfig::output_frame)));
//#line 246 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 246 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(SACSegmentationFromNormalsConfig::AbstractGroupDescriptionConstPtr(new SACSegmentationFromNormalsConfig::GroupDescription<SACSegmentationFromNormalsConfig::DEFAULT, SACSegmentationFromNormalsConfig>(Default)));
//#line 356 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<SACSegmentationFromNormalsConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__); 
    }
    std::vector<SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<SACSegmentationFromNormalsConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    SACSegmentationFromNormalsConfig __max__;
    SACSegmentationFromNormalsConfig __min__;
    SACSegmentationFromNormalsConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const SACSegmentationFromNormalsConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static SACSegmentationFromNormalsConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &SACSegmentationFromNormalsConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const SACSegmentationFromNormalsConfig &SACSegmentationFromNormalsConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const SACSegmentationFromNormalsConfig &SACSegmentationFromNormalsConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const SACSegmentationFromNormalsConfig &SACSegmentationFromNormalsConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<SACSegmentationFromNormalsConfig::AbstractParamDescriptionConstPtr> &SACSegmentationFromNormalsConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<SACSegmentationFromNormalsConfig::AbstractGroupDescriptionConstPtr> &SACSegmentationFromNormalsConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const SACSegmentationFromNormalsConfigStatics *SACSegmentationFromNormalsConfig::__get_statics__()
  {
    const static SACSegmentationFromNormalsConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = SACSegmentationFromNormalsConfigStatics::get_instance();
    
    return statics;
  }


}

#endif // __SACSEGMENTATIONFROMNORMALSRECONFIGURATOR_H__
