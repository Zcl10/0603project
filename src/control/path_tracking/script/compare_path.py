#!/usr/bin/env python

import matplotlib.pyplot as plt
import os
import pandas as pd
import rospy
from math import *
from plan2control_msgs.msg import Trajectory
from sensor_driver_msgs.msg import GpswithHeading, InsVelocity
from three_one_msgs.msg import Report

read_csv = True

ref_path_local = []
ref_path_global = []

gps_position = []
time_record = []

ins_control_list = []
ins_cal_position = []

des_control_list = []
ctrl_cal_position = []


def positionGPStoMeters(longitude, latitude, e0=47400., n0=4316000.):
    WGS84_ECCENTRICITY = 0.0818192  # e=0.0818192
    WGS84_EQUATORIAL_RADIUS = 6378.137  # a=6378.137
    k0 = 0.9996

    Zone = (longitude // 6) + 1
    lonBase = Zone * 6 - 3

    vPhi = (1 / sqrt(1 - pow(WGS84_ECCENTRICITY * sin(latitude * pi / 180.0), 2)))
    A = ((longitude - lonBase) * pi / 180.0 * cos(latitude * pi / 180.0))
    sPhi = ((1 - pow(WGS84_ECCENTRICITY, 2) / 4.0 - 3 * pow(WGS84_ECCENTRICITY, 4) / 64.0 - 5 * pow(WGS84_ECCENTRICITY,
                                                                                                    6) / 256.0) * latitude * pi / 180.0 - (
                    3 * pow(WGS84_ECCENTRICITY, 2) / 8.0 + 3 * pow(WGS84_ECCENTRICITY, 4) / 32.0 + 45 * pow(
                WGS84_ECCENTRICITY, 6) / 1024.0) * sin(2 * latitude * pi / 180.0) + (
                    15 * pow(WGS84_ECCENTRICITY, 4) / 256.0 + 45 * pow(WGS84_ECCENTRICITY, 6) / 256.0) * sin(
        4 * latitude * pi / 180.0) - (35 * pow(WGS84_ECCENTRICITY, 6) / 3072.0) * sin(6 * latitude * pi / 180.0))
    T = (pow(tan(latitude * pi / 180.0), 2))
    C = ((pow(WGS84_ECCENTRICITY, 2) / (1 - pow(WGS84_ECCENTRICITY, 2))) * pow(cos(latitude * pi / 180.0), 2))
    tmp_x = ((k0 * WGS84_EQUATORIAL_RADIUS * vPhi * (
            A + (1 - T + C) * pow(A, 3) / 6.0 + (5 - 18 * T + pow(T, 2)) * pow(A, 5) / 120.0)) * 1000 - e0)
    tmp_y = ((k0 * WGS84_EQUATORIAL_RADIUS * (sPhi + vPhi * tan(latitude * pi / 180.0) * (
            pow(A, 2) / 2 + (5 - T + 9 * C + 4 * C * C) * pow(A, 4) / 24.0 + (61 - 58 * T + T * T) * pow(A,
                                                                                                         6) / 720.0))) * 1000 - n0)
    return tmp_x, tmp_y


def normallizeAngle(theta):
    if theta > pi:
        return (theta - 2 * pi)
    elif theta <= -pi:
        return theta + 2 * pi
    return theta


class Interpreter():
    path_receive, gps_receive, ins_receive, control_receive = False, False, False, False
    gps_time, ins_time, ecu_time = 0., 0., 0.
    east, north, gps_heading = float('inf'), float('inf'), 0.
    ins_vx, ins_vy, ins_wz = 0., 0., 0.
    cmd_speed, cmd_curvature = 0., 0.

    def __init__(self):
        rospy.Subscriber('global_path/traj_plan', Trajectory, self.referpathCallback)
        rospy.Subscriber('gpsdata', GpswithHeading, self.gpsCallback)
        rospy.Subscriber('insvelocity', InsVelocity, self.insvelocityCallback)
        rospy.Subscriber('ecudatareport', Report, self.ecuCallback)
        rospy.Timer(rospy.Duration(0.1), self.timerCallback, oneshot=False)

    def timerCallback(self, event):
        self.saveData(rospy.get_time())
        return

    def saveData(self, t):

        self.exceedTimeCheck()

        if self.gps_receive:
            gps_position.append((self.east, self.north, self.gps_heading))
            time_record.append(t)
            rospy.loginfo("gps receive")
        else:
            rospy.logwarn("can't receive gps")

        if self.ins_receive:
            ins_control_list.append((self.ins_vx, self.ins_wz))
            rospy.loginfo("ins receive")
        else:
            rospy.logwarn("can't receive ins")

        if self.control_receive:
            des_control_list.append((self.cmd_speed, self.cmd_speed * self.cmd_curvature))
            rospy.loginfo("ecudata receive")
        else:
            rospy.logwarn("can't receive ecu")

    def exceedTimeCheck(self):
        time = rospy.get_time()
        self.gps_receive &= (time - self.gps_time < 0.2)
        self.ins_receive &= (time - self.ins_time < 0.2)
        self.control_receive &= (time - self.ecu_time < 0.2)

    def referpathCallback(self, msg):
        if not self.path_receive:
            global ref_path_local
            ref_path_local = [(p.position.x, p.position.y) for p in msg.points]
        self.path_receive = True

    def gpsCallback(self, msg):
        self.gps_time = rospy.get_time()
        gps_msg_time = msg.header.stamp.secs + msg.header.stamp.secs / 10 ** 9
        self.east, self.north = positionGPStoMeters(msg.gps.longitude, msg.gps.latitude)
        self.gps_heading = (msg.heading + 90.) * pi / 180.
        self.gps_heading -= 2 * pi if self.gps_heading > pi else 0.
        self.gps_receive = True

        # self.saveData(gps_msg_time)

    def insvelocityCallback(self, msg):
        self.ins_time = rospy.get_time()
        self.ins_wz = msg.angular_velocity.z
        self.ins_vx = msg.linear_velocity.y
        self.ins_vy = -msg.linear_velocity.x
        self.ins_receive = True

    def ecuCallback(self, msg):
        self.ecu_time = rospy.get_time()
        self.cmd_speed = msg.control.speed
        self.cmd_curvature = (-2 * msg.control.turn_to + 1) * (msg.control.curvature / 2.651)
        self.control_receive = True


def trajPlot():
    if len(gps_position) == 0:
        return
    ins_cal_position.append(gps_position[0])
    ctrl_cal_position.append(gps_position[0])

    n = min(len(gps_position), len(time_record), len(ins_control_list), len(des_control_list)) - 1

    for i in range(n):
        if i % 100 == 0:
            ins_cal_position.append(gps_position[i])
            ctrl_cal_position.append(gps_position[i])
            continue

        dt = time_record[i] if read_csv else time_record[i + 1] - time_record[i]

        x = ins_cal_position[i][0] + ins_control_list[i][0] * cos(ins_cal_position[i][2]) * dt
        y = ins_cal_position[i][1] + ins_control_list[i][0] * sin(ins_cal_position[i][2]) * dt
        theta = ins_cal_position[i][2] + ins_control_list[i][1] * dt
        ins_cal_position.append((x, y, theta))

        x = ctrl_cal_position[i][0] + des_control_list[i][0] * cos(ctrl_cal_position[i][2]) * dt
        y = ctrl_cal_position[i][1] + des_control_list[i][0] * sin(ctrl_cal_position[i][2]) * dt
        theta = ctrl_cal_position[i][2] + des_control_list[i][1] * dt
        ctrl_cal_position.append((x, y, theta))

    gps0 = gps_position[0]
    for p in ref_path_local:
        x = p[0] * cos(gps0[2]) - p[1] * sin(gps0[2]) + gps0[0]
        y = p[0] * sin(gps0[2]) + p[1] * cos(gps0[2]) + gps0[1]
        ref_path_global.append((x, y))

    plt.plot([p[0] for p in gps_position], [p[1] for p in gps_position], label="gps output", c='black')
    plt.scatter([p[0] for p in ins_cal_position], [p[1] for p in ins_cal_position], label="ins calculate", s=10,
                alpha=0.5)
    plt.scatter([p[0] for p in ctrl_cal_position], [p[1] for p in ctrl_cal_position], label="control calculate", s=10,
                alpha=0.5)
    plt.plot([p[0] for p in ref_path_global], [p[1] for p in ref_path_global], label="refer path")
    plt.legend()
    plt.axis('equal')
    plt.grid(True)
    plt.show()


if __name__ == '__main__':

    if read_csv:
        pwd = os.getcwd()
        data = pd.read_csv(pwd + "/regression/datasets_global.csv")
        gps_position = zip(data["1X"], data["2Y"], data["3Theta"])
        des_control_list = zip(data["6v_cmd"], data["7w_cmd"])
        ins_control_list = zip(data["8v_act"], data["9w_act"])
        time_record = data["dt"]
    else:
        rospy.init_node('interpreter', anonymous=True)
        try:
            Interpreter()
        except rospy.ROSInterruptException:
            pass
        rospy.spin()

    trajPlot()
