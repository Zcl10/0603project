# *********************************************************
#
# File autogenerated for the ros_vcu package
# by the rosparam_handler package.
# Please do not edit.
#
# *********************************************************
import rospy

param_description = [{'constant': False, 'description': 'lock of params', 'pytype': 'bool', 'max': None, 'is_vector': False, 'edit_method': '""', 'name': 'params_lock', 'min': None, 'default': True, 'level': 0, 'is_map': False, 'configurable': True, 'global_scope': False, 'type': 'bool'}]

defaults = {}

for param in param_description:
    defaults[param['name']] = param['default']


class ecu_communicationParameters(dict):
    def __init__(self):
        super(self.__class__, self).__init__(defaults)
        self.from_param_server()

    __getattr__ = dict.__getitem__
    __setattr__ = dict.__setitem__

    def from_param_server(self):
        """
        Reads and initializes parameters with values from parameter server.
        Called automatically at initialization.
        """
        for k, v in self.iteritems():
            config = next((item for item in param_description if item["name"] == k), None)
            if config['constant']:
                self.test_const_param(k)
                continue

            self[k] = self.get_param(k, config)


    def to_param_server(self):
        """
        Sets parameters with current values on the parameter server.
        """
        for param_name, param_value in self.iteritems():
            config = next((item for item in param_description if item["name"] == param_name), None)
            if not config['constant']:
                full_name = "/" + param_name if config['global_scope'] else "~" + param_name
                rospy.set_param(full_name, param_value)
               
    def from_config(self, config):
        """
        Reads parameter from a dynamic_reconfigure config file.
        Should be called in the callback of dynamic_reconfigure.
        :param config: config object from dynamic reconfigure
        """
        for k, v in config.iteritems():
            # handle reserved name groups
            if k == "groups":
                continue
            if not k in self:
                raise TypeError("Element {} of config is not part of parameters.".format(k))
            self[k] = v

    @staticmethod
    def test_const_param(param_name):
        if rospy.has_param("~" + param_name):
            rospy.logwarn(
                "Parameter {} was set on the parameter server even though it was defined to be constant.".format(
                    param_name))

    @staticmethod
    def get_param(param_name, config):
        def get_type(type_string):
            if type_string == 'std::string':
                return str
            elif type_string == 'int':
                return int
            elif type_string == 'bool':
                return bool
            elif type_string == 'float' or type_string == 'double':
                return float
            else:
                raise ValueError()

        full_name = "/" + param_name if config['global_scope'] else "~" + param_name
        try:
            val = rospy.get_param(full_name)
        except KeyError:
            if config['default'] is None:
                raise KeyError("Parameter {} is neither set on the parameter server nor "
                               "has it a default value".format(param_description))
            rospy.loginfo("Parameter {} is not yet set. Setting default value".format(param_name))
            rospy.set_param(full_name, config['default'])
            val = config['default']

        # test whether type is correct
        try:
            if config['is_vector']:
                val = list(val)
                config_type = config['type']
                val_type = get_type(config_type[config_type.find("<")+1:config_type.find(">")])
                val = [ val_type(v) for v in val ]
            elif config['is_map']:
                val = dict(val)
                config_type = config['type']
                key_type = get_type(config_type[config_type.find("<")+1:config_type.find(",")])
                val_type = get_type(config_type[config_type.find(",")+1:config_type.find(">")])
                val = { key_type(key): val_type(v) for key, v in val.items() }
            else:
                val = get_type(config['type'])(val)
        except ValueError:
            rospy.logerr(
                "Parameter {} is set, but has a different type. Using default value instead.".format(param_name))
            val = config['default']
        # test bounds
        if config['min'] is not None:
            if config['is_vector']:
                if min(val) < config['min']:
                    rospy.logwarn(
                        "Some values in {} for {} are smaller than minimal allowed value. "
                        "Correcting them to min={}".format(val, param_name, config['min']))
                    val = [ v if v > config['min'] else config['min'] for v in val ]
            elif config['is_map']:
                if min(val.values()) < config['min']:
                    rospy.logwarn(
                        "Some values in {} for {} are smaller than minimal allowed value. "
                        "Correcting them to min={}".format(val, param_name, config['min']))
                    val = { k: (v if v > config['min'] else config['min']) for k, v in val.items() }
            elif val < config['min']:
                rospy.logwarn(
                    "Value of {} for {} is smaller than minimal allowed value. "
                    "Correcting value to min={}".format(val, param_name, config['min']))
                val = config['min']

        if config['max'] is not None:
            if config['is_vector']:
                if max(val) > config['max']:
                    rospy.logwarn(
                        "Some values in {} for {} are greater than maximal allowed value. "
                        "Correcting them to max={}".format(val, param_name, config['max']))
                    val = [ v if v < config['max'] else config['max'] for v in val ]
            elif config['is_map']:
                if max(val.values()) > config['max']:
                    rospy.logwarn(
                        "Some values in {} for {} are greater than maximal allowed value. "
                        "Correcting them to max={}".format(val, param_name, config['max']))
                    val = { k: (v if v < config['max'] else config['max']) for k, v in val.items() }
            elif val > config['max']:
                rospy.logwarn(
                    "Value of {} for {} is greater than maximal allowed value. "
                    "Correcting value to max={}".format(val, param_name, config['max']))
                val = config['max']
        return val

