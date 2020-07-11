//#line 2 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
//
// File autogenerated for the path_smoothing package
// by the dynamic_reconfigure package.
// Please do not edit.
//
// ********************************************************/

#ifndef __path_smoothing__SMOOTHING_DEMOCONFIG_H__
#define __path_smoothing__SMOOTHING_DEMOCONFIG_H__

#if __cplusplus >= 201103L
#define DYNAMIC_RECONFIGURE_FINAL final
#else
#define DYNAMIC_RECONFIGURE_FINAL
#endif

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace path_smoothing
{
  class smoothing_demoConfigStatics;

  class smoothing_demoConfig
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

      virtual void clamp(smoothing_demoConfig &config, const smoothing_demoConfig &max, const smoothing_demoConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const smoothing_demoConfig &config1, const smoothing_demoConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, smoothing_demoConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const smoothing_demoConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, smoothing_demoConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const smoothing_demoConfig &config) const = 0;
      virtual void getValue(const smoothing_demoConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template <class T>
    class ParamDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level,
          std::string a_description, std::string a_edit_method, T smoothing_demoConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T (smoothing_demoConfig::* field);

      virtual void clamp(smoothing_demoConfig &config, const smoothing_demoConfig &max, const smoothing_demoConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;

        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const smoothing_demoConfig &config1, const smoothing_demoConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, smoothing_demoConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const smoothing_demoConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, smoothing_demoConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const smoothing_demoConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const smoothing_demoConfig &config, boost::any &val) const
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
      virtual void updateParams(boost::any &cfg, smoothing_demoConfig &top) const= 0;
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

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template<class T, class PT>
    class GroupDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractGroupDescription
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

      virtual void updateParams(boost::any &cfg, smoothing_demoConfig &top) const
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
      std::vector<smoothing_demoConfig::AbstractGroupDescriptionConstPtr> groups;
    };

class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(smoothing_demoConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("cg_heading_term_coe"==(*_i)->name){cg_heading_term_coe = boost::any_cast<double>(val);}
        if("cg_curvature_term_coe"==(*_i)->name){cg_curvature_term_coe = boost::any_cast<double>(val);}
        if("cg_obstacle_term_coe"==(*_i)->name){cg_obstacle_term_coe = boost::any_cast<double>(val);}
        if("gp_obs_sigma"==(*_i)->name){gp_obs_sigma = boost::any_cast<double>(val);}
        if("gp_vehicle_dynamic_sigma"==(*_i)->name){gp_vehicle_dynamic_sigma = boost::any_cast<double>(val);}
        if("gp_dt"==(*_i)->name){gp_dt = boost::any_cast<double>(val);}
        if("distance_threshold"==(*_i)->name){distance_threshold = boost::any_cast<double>(val);}
        if("cg_solver_type"==(*_i)->name){cg_solver_type = boost::any_cast<int>(val);}
      }
    }

    double cg_heading_term_coe;
double cg_curvature_term_coe;
double cg_obstacle_term_coe;
double gp_obs_sigma;
double gp_vehicle_dynamic_sigma;
double gp_dt;
double distance_threshold;
int cg_solver_type;

    bool state;
    std::string name;

    
}groups;



//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double cg_heading_term_coe;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double cg_curvature_term_coe;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double cg_obstacle_term_coe;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double gp_obs_sigma;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double gp_vehicle_dynamic_sigma;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double gp_dt;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double distance_threshold;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int cg_solver_type;
//#line 228 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

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
        ROS_ERROR("smoothing_demoConfig::__fromMessage__ called with an unexpected parameter.");
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
      const smoothing_demoConfig &__max__ = __getMax__();
      const smoothing_demoConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const smoothing_demoConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }

    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const smoothing_demoConfig &__getDefault__();
    static const smoothing_demoConfig &__getMax__();
    static const smoothing_demoConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();

  private:
    static const smoothing_demoConfigStatics *__get_statics__();
  };

  template <> // Max and min are ignored for strings.
  inline void smoothing_demoConfig::ParamDescription<std::string>::clamp(smoothing_demoConfig &config, const smoothing_demoConfig &max, const smoothing_demoConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class smoothing_demoConfigStatics
  {
    friend class smoothing_demoConfig;

    smoothing_demoConfigStatics()
    {
smoothing_demoConfig::GroupDescription<smoothing_demoConfig::DEFAULT, smoothing_demoConfig> Default("Default", "", 0, 0, true, &smoothing_demoConfig::groups);
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.cg_heading_term_coe = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.cg_heading_term_coe = 10.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.cg_heading_term_coe = 1.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(smoothing_demoConfig::AbstractParamDescriptionConstPtr(new smoothing_demoConfig::ParamDescription<double>("cg_heading_term_coe", "double", 0, "cg method coe", "", &smoothing_demoConfig::cg_heading_term_coe)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(smoothing_demoConfig::AbstractParamDescriptionConstPtr(new smoothing_demoConfig::ParamDescription<double>("cg_heading_term_coe", "double", 0, "cg method coe", "", &smoothing_demoConfig::cg_heading_term_coe)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.cg_curvature_term_coe = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.cg_curvature_term_coe = 5.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.cg_curvature_term_coe = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(smoothing_demoConfig::AbstractParamDescriptionConstPtr(new smoothing_demoConfig::ParamDescription<double>("cg_curvature_term_coe", "double", 0, "cg method coe", "", &smoothing_demoConfig::cg_curvature_term_coe)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(smoothing_demoConfig::AbstractParamDescriptionConstPtr(new smoothing_demoConfig::ParamDescription<double>("cg_curvature_term_coe", "double", 0, "cg method coe", "", &smoothing_demoConfig::cg_curvature_term_coe)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.cg_obstacle_term_coe = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.cg_obstacle_term_coe = 5.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.cg_obstacle_term_coe = 2.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(smoothing_demoConfig::AbstractParamDescriptionConstPtr(new smoothing_demoConfig::ParamDescription<double>("cg_obstacle_term_coe", "double", 0, "cg method coe", "", &smoothing_demoConfig::cg_obstacle_term_coe)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(smoothing_demoConfig::AbstractParamDescriptionConstPtr(new smoothing_demoConfig::ParamDescription<double>("cg_obstacle_term_coe", "double", 0, "cg method coe", "", &smoothing_demoConfig::cg_obstacle_term_coe)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.gp_obs_sigma = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.gp_obs_sigma = 1.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.gp_obs_sigma = 0.03;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(smoothing_demoConfig::AbstractParamDescriptionConstPtr(new smoothing_demoConfig::ParamDescription<double>("gp_obs_sigma", "double", 0, "gp method coe", "", &smoothing_demoConfig::gp_obs_sigma)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(smoothing_demoConfig::AbstractParamDescriptionConstPtr(new smoothing_demoConfig::ParamDescription<double>("gp_obs_sigma", "double", 0, "gp method coe", "", &smoothing_demoConfig::gp_obs_sigma)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.gp_vehicle_dynamic_sigma = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.gp_vehicle_dynamic_sigma = 1.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.gp_vehicle_dynamic_sigma = 0.02;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(smoothing_demoConfig::AbstractParamDescriptionConstPtr(new smoothing_demoConfig::ParamDescription<double>("gp_vehicle_dynamic_sigma", "double", 0, "gp method coe", "", &smoothing_demoConfig::gp_vehicle_dynamic_sigma)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(smoothing_demoConfig::AbstractParamDescriptionConstPtr(new smoothing_demoConfig::ParamDescription<double>("gp_vehicle_dynamic_sigma", "double", 0, "gp method coe", "", &smoothing_demoConfig::gp_vehicle_dynamic_sigma)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.gp_dt = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.gp_dt = 5.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.gp_dt = 0.4;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(smoothing_demoConfig::AbstractParamDescriptionConstPtr(new smoothing_demoConfig::ParamDescription<double>("gp_dt", "double", 0, "gp method coe", "", &smoothing_demoConfig::gp_dt)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(smoothing_demoConfig::AbstractParamDescriptionConstPtr(new smoothing_demoConfig::ParamDescription<double>("gp_dt", "double", 0, "gp method coe", "", &smoothing_demoConfig::gp_dt)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.distance_threshold = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.distance_threshold = 5.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.distance_threshold = 2.5;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(smoothing_demoConfig::AbstractParamDescriptionConstPtr(new smoothing_demoConfig::ParamDescription<double>("distance_threshold", "double", 0, "gp method coe", "", &smoothing_demoConfig::distance_threshold)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(smoothing_demoConfig::AbstractParamDescriptionConstPtr(new smoothing_demoConfig::ParamDescription<double>("distance_threshold", "double", 0, "gp method coe", "", &smoothing_demoConfig::distance_threshold)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.cg_solver_type = -2147483648;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.cg_solver_type = 2147483647;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.cg_solver_type = 1;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(smoothing_demoConfig::AbstractParamDescriptionConstPtr(new smoothing_demoConfig::ParamDescription<int>("cg_solver_type", "int", 0, "solver enum", "{'enum_description': 'solver enum', 'enum': [{'srcline': 15, 'description': '', 'srcfile': '/home/bit2/0603_project/tang_ws/devel/.private/path_smoothing/share/path_smoothing/cfg/smoothing_demo.cfg', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'Ceres'}, {'srcline': 16, 'description': '', 'srcfile': '/home/bit2/0603_project/tang_ws/devel/.private/path_smoothing/share/path_smoothing/cfg/smoothing_demo.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'Self'}, {'srcline': 17, 'description': '', 'srcfile': '/home/bit2/0603_project/tang_ws/devel/.private/path_smoothing/share/path_smoothing/cfg/smoothing_demo.cfg', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'ddd'}, {'srcline': 18, 'description': '', 'srcfile': '/home/bit2/0603_project/tang_ws/devel/.private/path_smoothing/share/path_smoothing/cfg/smoothing_demo.cfg', 'cconsttype': 'const int', 'value': 3, 'ctype': 'int', 'type': 'int', 'name': 'ggg'}]}", &smoothing_demoConfig::cg_solver_type)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(smoothing_demoConfig::AbstractParamDescriptionConstPtr(new smoothing_demoConfig::ParamDescription<int>("cg_solver_type", "int", 0, "solver enum", "{'enum_description': 'solver enum', 'enum': [{'srcline': 15, 'description': '', 'srcfile': '/home/bit2/0603_project/tang_ws/devel/.private/path_smoothing/share/path_smoothing/cfg/smoothing_demo.cfg', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'Ceres'}, {'srcline': 16, 'description': '', 'srcfile': '/home/bit2/0603_project/tang_ws/devel/.private/path_smoothing/share/path_smoothing/cfg/smoothing_demo.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'Self'}, {'srcline': 17, 'description': '', 'srcfile': '/home/bit2/0603_project/tang_ws/devel/.private/path_smoothing/share/path_smoothing/cfg/smoothing_demo.cfg', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'ddd'}, {'srcline': 18, 'description': '', 'srcfile': '/home/bit2/0603_project/tang_ws/devel/.private/path_smoothing/share/path_smoothing/cfg/smoothing_demo.cfg', 'cconsttype': 'const int', 'value': 3, 'ctype': 'int', 'type': 'int', 'name': 'ggg'}]}", &smoothing_demoConfig::cg_solver_type)));
//#line 245 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 245 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(smoothing_demoConfig::AbstractGroupDescriptionConstPtr(new smoothing_demoConfig::GroupDescription<smoothing_demoConfig::DEFAULT, smoothing_demoConfig>(Default)));
//#line 366 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<smoothing_demoConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__);
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__);
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__);
    }
    std::vector<smoothing_demoConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<smoothing_demoConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    smoothing_demoConfig __max__;
    smoothing_demoConfig __min__;
    smoothing_demoConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const smoothing_demoConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static smoothing_demoConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &smoothing_demoConfig::__getDescriptionMessage__()
  {
    return __get_statics__()->__description_message__;
  }

  inline const smoothing_demoConfig &smoothing_demoConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }

  inline const smoothing_demoConfig &smoothing_demoConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }

  inline const smoothing_demoConfig &smoothing_demoConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }

  inline const std::vector<smoothing_demoConfig::AbstractParamDescriptionConstPtr> &smoothing_demoConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<smoothing_demoConfig::AbstractGroupDescriptionConstPtr> &smoothing_demoConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const smoothing_demoConfigStatics *smoothing_demoConfig::__get_statics__()
  {
    const static smoothing_demoConfigStatics *statics;

    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = smoothing_demoConfigStatics::get_instance();

    return statics;
  }

//#line 15 "/home/bit2/0603_project/tang_ws/devel/.private/path_smoothing/share/path_smoothing/cfg/smoothing_demo.cfg"
      const int smoothing_demo_Ceres = 0;
//#line 16 "/home/bit2/0603_project/tang_ws/devel/.private/path_smoothing/share/path_smoothing/cfg/smoothing_demo.cfg"
      const int smoothing_demo_Self = 1;
//#line 17 "/home/bit2/0603_project/tang_ws/devel/.private/path_smoothing/share/path_smoothing/cfg/smoothing_demo.cfg"
      const int smoothing_demo_ddd = 2;
//#line 18 "/home/bit2/0603_project/tang_ws/devel/.private/path_smoothing/share/path_smoothing/cfg/smoothing_demo.cfg"
      const int smoothing_demo_ggg = 3;
}

#undef DYNAMIC_RECONFIGURE_FINAL

#endif // __SMOOTHING_DEMORECONFIGURATOR_H__
