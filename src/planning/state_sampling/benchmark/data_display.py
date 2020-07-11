#!/usr/bin/env python
import yaml
import numpy as np
import pandas as pd
import matplotlib.patches as patches
import matplotlib as mpl


import matplotlib.pyplot as plt

fig, ax = plt.subplots()

font_size = 30
# read the random obstacles
obs_df = pd.read_csv("data8_100/random_obstacles.csv", sep = ";")
# read the random states
state_df = pd.read_csv("data0_50/random_states0.csv", sep = ";")
# map information
map_length = 80
map_width = 80
# display length and width
display_length = map_length + 6
display_width = map_width + 6

with open('data0_50/benchmark.yaml') as fp:
    config = yaml.load(fp)

with open('car_geometry.yaml') as car_fp:
    car = yaml.load(car_fp)

for solve_time in config["f_solving_time"]:
    print solve_time["improved"]

obs_x_array = obs_df["x"]
obs_y_array = obs_df["y"]
obs_r_array = obs_df["r"]

state_x_array = state_df["x"]
state_y_array = state_df["y"]
state_t_array = state_df["t"]

for x, y, r in zip(obs_x_array, obs_y_array, obs_r_array):
    obs = plt.Circle((x, y), r, color = 'black', fill=True)
    ax.add_artist(obs)

ax.add_patch(
    patches.Rectangle(
        (-display_length/2, -display_width/2),
        display_length,
        display_width,
        color = 'black',
        fill=False,
        linewidth = 3,
        zorder=10),
)

car_length = car['c_footprint'][1]['x'] - car['c_footprint'][0]['x']
car_width = car['c_footprint'][3]['y'] - car['c_footprint'][0]['y']
print ("car length:", car_length)
print ("car width:", car_width)

#for x, y, t in zip(state_x_array, state_y_array, state_t_array):
for i in range(0, 1500):
    car_footprint = patches.Rectangle((car["c_footprint"][0]['x'], car["c_footprint"][0]["y"]),
                                   car_length,
                                   car_width,
                                   color = np.random.rand(3,1),
                                   alpha=0.3,
                                   fill=True,
                                   linewidth=1,
                                   zorder=11)
    x = state_x_array[i]
    y = state_y_array[i]
    t = state_t_array[i]
    # se2 transformation
    t2=mpl.transforms.Affine2D().rotate(t).translate(x, y) + ax.transData
    car_footprint.set_transform(t2)
    ax.add_patch(car_footprint)

plt.axis("equal")
plt.ylim(-display_length/2 - 1, display_length/2+1)
plt.xlim(-45, 45)
#plt.tick_params(top='off', bottom='off', left='off', right='off', labelleft='off', labelbottom='off')
plt.tight_layout()

plt.tick_params(axis='y', which='major', labelsize=font_size)
plt.tick_params(axis='x', which='major', labelsize=font_size)
ax.legend()
plt.show()






