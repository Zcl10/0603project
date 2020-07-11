#!/usr/bin/env python
"""
python simulator
author zhyg
"""
import math
import matplotlib.pyplot as plt
import numpy as np
import rospy
import sys
from anm_msgs.msg import VehicleState
from plan2control_msgs.msg import Traj_Node
from plan2control_msgs.msg import Trajectory
from std_msgs.msg import Float32

publish_node = True  # False #
show_animation = True
mode = 'rectangle'  # 'rectangle' # 'single' # 'round' # 'laneChange' # 'sin'
traj_points = []


class Point2D:
    def __init__(self, x, y, yaw=0.0):
        self.x = x
        self.y = y
        self.yaw = yaw

    def calcSubPoints(self, c):
        self.left = Point2D(self.x - 1. / c, self.y)
        self.right = Point2D(self.x + 1. / c, self.y)
        self.upper = Point2D(self.x, self.y + 1. / c)
        self.bottom = Point2D(self.x, self.y - 1. / c)
        self.s1 = Point2D(self.x + 1. / c, self.y + 1. / c)
        self.s2 = Point2D(self.x - 1. / c, self.y + 1. / c)
        self.s3 = Point2D(self.x - 1. / c, self.y - 1. / c)
        self.s4 = Point2D(self.x + 1. / c, self.y - 1. / c)


class NormalVector:
    def __init__(self, x, y):
        d = math.sqrt(float(x) ** 2 + float(y) ** 2)
        self.x = x / d
        self.y = y / d


def sgn(x):
    if x > 0: return 1
    if x < 0: return -1
    return 0


def dotProduct(v1, v2):
    return v1.x * v2.x + v1.y * v2.y


def crossProduct(v1, v2):
    return v1.x * v2.y - v2.x * v1.y


def normalizeAngle(x):
    return math.fmod((x + math.pi), 2 * math.pi) - math.pi


def singlePath(start, end, c):
    """
    input:
        sx x position of start point [m]
        sy y position of start point [m]
        syaw yaw angle of start point [rad]
        ex x position of end point [m]
        ey y position of end point [m]
        eyaw yaw angle of end point [rad]
        c curvature [1/m]

    output:
        px
        py
        pyaw
    """
    assert c > 0
    sx, sy, syaw = start.x, start.y, normalizeAngle(start.yaw)
    ex, ey, eyaw = end.x, end.y, normalizeAngle(end.yaw)
    if sx == ex or sy == ey:
        print 'Generate Path Failed'
        sys.exit(0)
    vector_s = NormalVector(math.cos(syaw), math.sin(syaw))
    vector_s2e = NormalVector(ex - sx, ey - sy)
    vector_e = NormalVector(math.cos(eyaw), math.sin(eyaw))
    r1 = crossProduct(vector_s, vector_s2e)
    r2 = crossProduct(vector_s2e, vector_e)
    if r1 * r2 <= 0:
        print 'Generate Path Failed'
        sys.exit(0)
    if abs(math.cos(syaw)) < 0.0001:
        mx = sx
        my = ey - math.tan(eyaw) * (ex - sx)
    elif abs(math.cos(eyaw)) < 0.0001:
        mx = ex
        my = sy + math.tan(syaw) * (ex - sx)
    else:
        mx = ((ey - sy) - (math.tan(eyaw) * ex - math.tan(syaw) * sx)) / (math.tan(syaw) - math.tan(eyaw))
        my = math.tan(syaw) * (mx - sx) + sy

    vector_1 = NormalVector(sx - mx, sy - my)
    vector_2 = NormalVector(ex - mx, ey - my)
    vector_3 = NormalVector(vector_1.x + vector_2.x, vector_1.y + vector_2.y)

    theta = math.acos(dotProduct(vector_1, vector_2)) / 2

    l = 1.0 / (c * math.sin(theta))

    ox = mx + l * vector_3.x
    oy = my + l * vector_3.y

    d = 1.0 / (c * math.tan(theta))

    px = mx + d * vector_1.x
    py = my + d * vector_1.y

    qx = mx + d * vector_2.x
    qy = my + d * vector_2.y

    s1 = math.sqrt((px - sx) ** 2 + (py - sy) ** 2)
    s2 = (math.pi - 2 * theta) / c
    s3 = math.sqrt((ex - qx) ** 2 + (ey - qy) ** 2)
    total_s = s1 + s2 + s3
    ss_theta = [math.atan2(py - oy, px - ox) + sgn(-crossProduct(vector_1, vector_2)) * ss * c for ss in
                np.arange(0, s2, 0.5)]

    path1 = [(sx - ss * vector_1.x, sy - ss * vector_1.y) for ss in np.arange(0, s1, 0.5)]
    path2 = [(ox + math.cos(the) / c, oy + math.sin(the) / c) for the in ss_theta]
    path3 = [(qx + ss * vector_2.x, qy + ss * vector_2.y) for ss in np.arange(0, s3, 0.5)]

    return path1 + path2 + path3, total_s


def rectanglePath(length, width, center, c):
    assert c > 0
    assert 2. / c < length and 2. / c < width
    upper = Point2D(center.x, center.y + width / 2., math.radians(180))
    bottom = Point2D(center.x, center.y - width / 2., 0)
    left = Point2D(center.x - length / 2., center.y, math.radians(-90))
    right = Point2D(center.x + length / 2., center.y, math.radians(90))

    path1, s1 = singlePath(right, upper, c)
    path2, s2 = singlePath(upper, left, c)
    path3, s3 = singlePath(left, bottom, c)
    path4, s4 = singlePath(bottom, right, c)

    return path1 + path2 + path3 + path4, s1 + s2 + s3 + s4


def roundPath(center, c):
    assert c > 0
    total_s = 2. * math.pi / c
    n = int(total_s / 0.5)
    path = [(center.x + math.cos(2. * math.pi * i / n) / c, center.y + math.sin(2. * math.pi * i / n) / c) for i in
            range(n)]
    return path, total_s


def laneChange(s, d):
    total_s = s
    n = int(s + 1);
    path = [(i / 2., d * int(2 * i / n)) for i in range(int(s + 1))]
    return path, total_s


def sinPath(x0, x1, A=1., omega=1., phi=0.):
    path = [(x, A * math.sin(omega * x + phi)) for x in np.arange(x0, x1, 0.2)]
    return path, 0.


def plot_arrow(point, length=1.0, width=0.5, fc="r", ec="k"):
    """
    Plot arrow
    """
    x, y, yaw = point.x, point.y, point.yaw
    if not isinstance(x, float):
        for (ix, iy, iyaw) in zip(x, y, yaw):
            plot_arrow(ix, iy, iyaw)
    else:
        plt.arrow(x, y, length * math.cos(yaw), length * math.sin(yaw),
                  fc=fc, ec=ec, head_width=width, head_length=width)
        plt.plot(x, y)


class PathPublish():
    kappa_cmd = 0.0
    angular_speed = 0.0
    speed = 0.0
    acceleration = 0.0

    dt = 0.1

    last_steer_msg_time = 0.0
    last_speed_msg_time = 0.0
    last_acceleration_msg_time = 0.0

    def __init__(self, path, init_pose):
        self.path = path
        self.veh_x, self.veh_y, self.heading = init_pose.x, init_pose.y, init_pose.yaw
        traj_points.append((self.veh_x, self.veh_y, self.heading, 0.))
        rospy.Subscriber('cmd_str', Float32, self.steerCallback)
        rospy.Subscriber('cmd_vel', Float32, self.speedCallback)
        rospy.Subscriber('cmd_acc', Float32, self.accelerationCallback)
        self.traj_topic = rospy.get_param('/python_sim/traj_topic')
        self.state_pub = rospy.Publisher('vehicle_state', VehicleState, queue_size=1)
        self.path_pub = rospy.Publisher(self.traj_topic, Trajectory, queue_size=1)
        rospy.Timer(rospy.Duration(0.1), self.globalPathPosition, oneshot=False)

    def globalPathPosition(self, event):
        if self.messageReceived():
            delta_s = self.speed * self.dt + self.acceleration * self.dt ** 2 / 2.0
            self.veh_x += delta_s * math.cos(self.heading + self.angular_speed * self.dt / 2.0)
            self.veh_y += delta_s * math.sin(self.heading + self.angular_speed * self.dt / 2.0)
            self.heading = normalizeAngle(self.heading + self.angular_speed * self.dt)
            self.speed += self.acceleration * self.dt
            # x = np.random.normal(1. / 2, 1. / 6)
            x = 1.0
            self.angular_speed = (1 - x) * self.angular_speed + x * self.speed * self.kappa_cmd + np.random.normal(0.,
                                                                                                                   0.1)
            if delta_s > 0.01:
                traj_points.append((self.veh_x, self.veh_y, self.heading, self.speed))

        msg = VehicleState()
        msg.header.stamp.secs = rospy.get_rostime().secs
        msg.header.stamp.nsecs = rospy.get_rostime().nsecs
        msg.header.frame_id = 'VehicleState'
        msg.position.x = self.veh_x
        msg.position.y = self.veh_y
        msg.position.z = 0.0
        msg.orientation.z = self.heading
        msg.velocity.linear.x = self.speed
        msg.velocity.angular.z = self.angular_speed
        msg.acceleration.linear.x = self.acceleration
        self.state_pub.publish(msg)

        msg = Trajectory()
        msg.header.stamp.secs = rospy.get_rostime().secs
        msg.header.stamp.nsecs = rospy.get_rostime().nsecs
        msg.header.frame_id = 'base_link'
        for i in range(len(self.path)):
            path_node = Traj_Node()
            path_node.id = i
            path_node.forward = True
            path_node.position.x = self.path[i][0]
            path_node.position.y = self.path[i][1]
            msg.points.append(path_node)
        self.path_pub.publish(msg)

    def steerCallback(self, data):
        self.kappa_cmd = data.data
        self.last_steer_msg_time = rospy.get_time()

    def speedCallback(self, data):
        self.speed = data.data
        self.last_speed_msg_time = rospy.get_time()

    def accelerationCallback(self, msg):
        # self.acceleration = msg.data
        self.last_acceleration_msg_time = rospy.get_time()

    def messageReceived(self):
        result = True
        now_time = rospy.get_time()
        result &= now_time - self.last_steer_msg_time < 0.2
        result &= now_time - self.last_speed_msg_time < 0.2
        result &= now_time - self.last_acceleration_msg_time < 0.2
        return result


if __name__ == '__main__':

    curvature = 0.2

    if mode == 'single':
        start = Point2D(0.0, -10.0, math.radians(90.0))
        end = Point2D(30.0, 15.0, math.radians(0.0))
        path, total_s = singlePath(start, end, curvature)
        init_veh_pos = Point2D(1.0, -10., math.radians(90.0))
    elif mode == 'rectangle':
        path, total_s = rectanglePath(50, 36, Point2D(3, 5), curvature)
        init_veh_pos = Point2D(30.0, 5.0, math.radians(90.0))
    elif mode == 'round':
        path, total_s = roundPath(Point2D(3, 5), curvature)
        init_veh_pos = Point2D(10.0, 5.5, math.radians(90.0))
    elif mode == 'laneChange':
        path, total_s = laneChange(200., 0.)
        init_veh_pos = Point2D(0., -10., math.radians(0.))
    elif mode == 'sin':
        path, total_s = sinPath(0., 20.)
        init_veh_pos = Point2D(0., 0., math.radians(0.))

    print 'point number is', len(path)
    print 'total length is', total_s, 'meters'

    if publish_node:
        rospy.init_node('pathplot', anonymous=True)
        try:
            PathPublish(path, init_veh_pos)
        except rospy.ROSInterruptException:
            pass
        rospy.spin()
    if show_animation:
        plt.plot([p[0] for p in path], [p[1] for p in path], linestyle='--', color='pink')
        plt.scatter([p[0] for p in traj_points], [p[1] for p in traj_points],
                    c=[p[3] for p in traj_points], s=10, alpha=0.5)
        if mode == 'single':
            plot_arrow(start)
            plot_arrow(end)
        plt.legend(['refer', 'act'])
        plot_arrow(init_veh_pos)
        plt.grid(True)
        plt.axis("equal")
        plt.show()
