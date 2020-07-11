#!/usr/bin/env python
import matplotlib.pyplot as plt
import os
from math import *

pwd = os.getcwd()

dt = 0.15
x = 0.970077
y = -0.00963135
theta = -0.0215103
v = 4.85069
angle = -0.0697269
control_list = [(-0.14527, 0), (-0.153161, 0), (-0.158636, 0), (-0.162345, 0), (-0.164761, 0), (-0.166232, 0),
                (-0.167008, 0), (-0.167283, 0), (-0.16726, 0), (-0.167134, 0), (-0.167038, 0)]
rviz_point = [(0.970077, -0.00963135), (1.69751, -0.0252812), (2.42379, -0.0692763), (3.14763, -0.143107),
              (3.86768, -0.247724), (4.58247, -0.383664), (5.29054, -0.551135), (5.99041, -0.750092),
              (6.68065, -0.980282), (7.35982, -1.24129), (8.02657, -1.53259), (8.67955, -1.85356)]
initref = [(1.08359, 0.0593344), (1.80932, 0.00723018), (2.53382, -0.0596406), (3.25601, -0.147893),
           (3.97448, -0.262562), (4.68763, -0.406575), (5.394, -0.580771), (6.09134, -0.788132), (6.77745, -1.03009),
           (7.45135, -1.30425), (8.1122, -1.60851), (8.75741, -1.94461)]

### use initial position and solution.x[curvature_range_begin + i] calculate points
calc_point = [(x, y, theta, v)]
# plt.plot([x, x + v * dt * cos(theta + pi / 2.)], [y, y + v * dt * sin(theta + pi / 2.)])
for c in control_list:
    x += v * cos(theta) * dt
    y += v * sin(theta) * dt
    theta += v * c[0] / 2.66 * dt
    v += c[1] * dt
    calc_point.append((x, y, theta, dt))
    # plt.plot([x, x + v * dt * cos(theta + pi / 2.)], [y, y + v * dt * sin(theta + pi / 2.)])

# for i in range(len(x_list) - 1):
#    print sqrt((x_list[i + 1] - x_list[i])**2 + (y_list[i + 1] - y_list[i])**2)

# for i in range(len(rviz_point)):
#    print (rviz_point[i][0] - solve_xy_s[i][0])**2 + (rviz_point[i][1] - solve_xy_s[i][1])**2

plt.scatter([c[0] for c in initref], [c[1] for c in initref],
            color='black', s=10, alpha=0.5, label="initref point")
plt.plot([r[0] for r in initref], [r[1] for r in initref], color='green', label="initref line")
### vehicle origin point
plt.plot(0.0, 0.0, 'xb')
### use control calculate points
plt.scatter([c[0] for c in calc_point], [c[1] for c in calc_point],
            color='red', s=10, alpha=0.5, label="control calculate")
# ### rviz show points
plt.plot([r[0] for r in rviz_point], [r[1] for r in rviz_point], color='blue', label="ipopt solved")
plt.legend()
plt.axis('equal')
plt.grid(True)
plt.show()
