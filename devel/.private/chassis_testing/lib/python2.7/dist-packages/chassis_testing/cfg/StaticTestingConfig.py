## *********************************************************
##
## File autogenerated for the chassis_testing package
## by the dynamic_reconfigure package.
## Please do not edit.
##
## ********************************************************/

from dynamic_reconfigure.encoding import extract_params

inf = float('inf')

config_description = {'upper': 'DEFAULT', 'lower': 'groups', 'srcline': 245, 'name': 'Default', 'parent': 0, 'srcfile': '/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'cstate': 'true', 'parentname': 'Default', 'class': 'DEFAULT', 'field': 'default', 'state': True, 'parentclass': '', 'groups': [], 'parameters': [{'srcline': 290, 'description': 'Gear', 'max': 4, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'gear', 'edit_method': "{'enum_description': 'An enum to gear', 'enum': [{'srcline': 7, 'description': 'Invalid gear', 'srcfile': '/home/bit2/0603_project/tang_ws/src/control/chassis_testing/config/StaticTesting.cfg', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'Invalid'}, {'srcline': 8, 'description': 'P gear', 'srcfile': '/home/bit2/0603_project/tang_ws/src/control/chassis_testing/config/StaticTesting.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'P'}, {'srcline': 9, 'description': 'R gear', 'srcfile': '/home/bit2/0603_project/tang_ws/src/control/chassis_testing/config/StaticTesting.cfg', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'R'}, {'srcline': 10, 'description': 'N gear', 'srcfile': '/home/bit2/0603_project/tang_ws/src/control/chassis_testing/config/StaticTesting.cfg', 'cconsttype': 'const int', 'value': 3, 'ctype': 'int', 'type': 'int', 'name': 'N'}, {'srcline': 11, 'description': 'D gear', 'srcfile': '/home/bit2/0603_project/tang_ws/src/control/chassis_testing/config/StaticTesting.cfg', 'cconsttype': 'const int', 'value': 4, 'ctype': 'int', 'type': 'int', 'name': 'D'}]}", 'default': 0, 'level': 4, 'min': 1, 'type': 'int'}, {'srcline': 290, 'description': 'Target torque', 'max': 1800.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'target_torque', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 290, 'description': 'brake', 'max': 20.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'halt', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 290, 'description': 'Steer degree', 'max': 20, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'steer_degree', 'edit_method': '', 'default': 0, 'level': 0, 'min': -20, 'type': 'int'}], 'type': '', 'id': 0}

min = {}
max = {}
defaults = {}
level = {}
type = {}
all_level = 0

#def extract_params(config):
#    params = []
#    params.extend(config['parameters'])
#    for group in config['groups']:
#        params.extend(extract_params(group))
#    return params

for param in extract_params(config_description):
    min[param['name']] = param['min']
    max[param['name']] = param['max']
    defaults[param['name']] = param['default']
    level[param['name']] = param['level']
    type[param['name']] = param['type']
    all_level = all_level | param['level']

StaticTesting_Invalid = 0
StaticTesting_P = 1
StaticTesting_R = 2
StaticTesting_N = 3
StaticTesting_D = 4
