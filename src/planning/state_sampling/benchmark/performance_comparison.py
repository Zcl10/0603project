#!/usr/bin/env python
import yaml
import numpy as np
import pandas as pd
import matplotlib.patches as patches
import matplotlib as mpl
import statistics


import matplotlib.pyplot as plt



font_size = 25
title_size = 30
floating_size = 20

## this file is to generate comparison of 2 different methods
with open('data0_50/benchmark.yaml') as fp1:
    benchmark1 = yaml.load(fp1)
with open('data3_80/benchmark.yaml') as fp2:
    benchmark2 = yaml.load(fp2)
with open('data8_100/benchmark.yaml') as fp3:
    benchmark3 = yaml.load(fp3)


data = []
data.append(benchmark1)
data.append(benchmark2)
data.append(benchmark3)

draw_data_improved_mean=()
draw_data_normal_mean=()

draw_data_improved_error_l=()
draw_data_improved_error_u=()
draw_data_improved_error=()

draw_data_normal_error_l=()
draw_data_normal_error_u=()
draw_data_normal_error=()
density_vector=[]
for i in range(0, 3):
    improved_time = []
    normal_time = []
    benchmark = data[i]
    for time in benchmark["f_solving_time"]:
        improved_t = time['improved']
        normal_t = time['normal']
        improved_time.append(improved_t)
        normal_time.append(normal_t)
    density_vector.append(benchmark["b_obstacle_density"])
    ##  extract the max min and mean
    ## improved

    mean_time_improved = statistics.mean(improved_time)
    min_time_improved = mean_time_improved - min(improved_time)
    max_time_improved = max(improved_time) - mean_time_improved
    ## normal

    mean_time_normal = statistics.mean(normal_time)
    min_time_normal = mean_time_normal - min(normal_time)
    max_time_normal = max(normal_time) - mean_time_normal
    ##
    #improved_error = (min_time_improved, max_time_normal)
    #normal_error = (min_time_normal, max_time_normal)

    draw_data_improved_error_l +=(min_time_improved,)
    draw_data_improved_error_u +=(max_time_improved,)
    draw_data_improved_error += ([min_time_improved, max_time_improved],)

    draw_data_normal_error_l +=(min_time_normal,)
    draw_data_normal_error_u +=(max_time_normal,)
    draw_data_normal_error += ([min_time_normal, max_time_normal],)

    draw_data_normal_mean +=(mean_time_normal,)
    draw_data_improved_mean += (mean_time_improved,)

N = 3
improved_means = draw_data_improved_mean
ind = np.arange(N)  # the x locations for the groups
width = 0.35       # the width of the bars

print ("improved_l:", draw_data_improved_error_l)
print ("improved_u:", draw_data_improved_error_u)
print ("normal_l:", draw_data_normal_error_l)
print ("normal_u:", draw_data_normal_error_u)
print ("Density:", density_vector)
## figure drawing
fig, ax = plt.subplots()

rects1 = ax.bar(ind, improved_means, width,
                capsize = 20,  color='green',
                alpha = 0.5,
                ecolor = 'black',
                error_kw=dict(lw=2, capsize=40, capthick=2),
                yerr=[draw_data_improved_error_l,draw_data_improved_error_u])

norm_means = draw_data_normal_mean
rects2 = ax.bar(ind + width, norm_means, width,
                alpha = 0.8,
                ecolor = 'black',
                error_kw=dict(lw=2,capsize=40,capthick=2),
                color='blue', yerr=[draw_data_normal_error_l,draw_data_normal_error_u])

# add some text for labels, title and axes ticks
ax.set_ylabel('Runtime/s', fontsize = font_size)
ax.set_title('Runtimes for 1000000 Random Collision Checking', fontsize = title_size)
ax.set_xticks(ind + width / 2)
##
obstacles =['50 obstacles','80 obstacles','100 obstacles']
ax.set_xticklabels((obstacles[0], obstacles[1], obstacles[2]), fontsize = font_size)

## test
percent_of_goal = ["Obstacle Density={:.2f}%".format(100*percent) for percent in density_vector]

maximum = max(norm_means)
for i in range(0, 3):
    #temp = [norm_means[i], improved_means[i]]
    #maximum = max(temp)
    ax.text(i+width/2, 3.8,percent_of_goal[i], horizontalalignment ='center',fontsize=floating_size)

ax.legend((rects1[0], rects2[0]), ('The Proposed Two Phase Routine', 'Single Phase Routine'), fontsize = font_size)

def autolabel(rects):
    """
    Attach a text label above each bar displaying its height
    """
    for rect in rects:
        height = rect.get_height()
        ax.text(rect.get_x() + rect.get_width()/2., 1.05*height,
                '%d' % int(height),
                ha='center', va='bottom')
plt.tick_params(axis='y', which='major', labelsize=font_size)

autolabel(rects1)
autolabel(rects2)
plt.ylim(0, 5.5)

plt.show()