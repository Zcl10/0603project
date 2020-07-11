#!/usr/bin/env python
# -*- coding:utf-8 -*-

import os
import shutil
import rospy
import rosbag
import datetime
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import datetime

def bag_analysis(file, bagfiles_path):
    os.chdir(bagfiles_path)
    file_name = os.path.splitext(file)[0]
    if not os.path.exists(file_name):
        print ('I am handling a bagfile slowly, not stuck, please waiting ...')
        bag = rosbag.Bag(file)
        os.mkdir(file_name)
        analysis_path = os.path.join(bagfiles_path, file_name)
        os.chdir(analysis_path)

        # observer topic
        time_obs = []
        lateral_error = []
        heading_error = []
        time_cost = []
        ecu_speed = []

        # gpsdata topic
        time_gps = []
        latitude = []
        longitude = []
        altitude = []
        heading = []
        roll = []
        pitch = []

        #insvelocity
        time_ins = []
        linear_velocity_x = []
        linear_velocity_y = []
        angular_velocity_z = []

        for topic, msg, t in bag.read_messages():
            if topic == "/gpsdata":
                time_gps.append(t.secs + t.nsecs*pow(10,-9))
                latitude.append(msg.gps.latitude)
                longitude.append(msg.gps.longitude)
                altitude.append(msg.gps.altitude)
                heading.append(msg.heading)
                roll.append(msg.roll)
                pitch.append(msg.pitch)

        # gpsdata topic
        gps_init_time = time_gps[0]
        for i in range(0,len(time_gps)):
            time_gps[i] -= gps_init_time
        raw_data = {'time_gps': time_gps,
        'latitude': latitude,
        'longitude': longitude,
        'altitude': altitude,
        'heading': heading,
        'roll': roll,
        'pitch': pitch}
        data_frame = pd.DataFrame(data=raw_data)
        print('writing to csv file ...')
        data_frame.to_csv('gpsdata.csv')

    else:
        print ('the dir \'' + file_name + '\' already exists, do nothing with the bagfile')
        pass
    return

def bag_read():
    script_path = os.getcwd()
    bagfiles_path = script_path; # os.path.join(script_path, 'bagfiles')
    os.chdir(bagfiles_path)
    for root, dirs, files in os.walk(bagfiles_path):
        for file in files:
            if os.path.splitext(file)[1] == '.bag':
                bag_analysis(file, bagfiles_path)
    return

if __name__ == '__main__':
    bag_read()
