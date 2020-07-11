## Benchmark Design

1. obstacles numbers (namely, density)
Empty map with obstacles information makes a test map, we don't even need a 
as the quality of iamges are low.
* density ~10%
* density ~20% 
* density ~30% 

2. random states (csv files) 
* 1000000

3. run several times with the same random map and the same random state, get the following results  
**Runtime**
* maximum time 
* average time
* minimum time

4. 4cirlces and 6 circle methods 
* time 
* circle access times


## Data consists of three parts
* obstacles data in a csv file
    x, y theta with a radius 3 meters 
    
* map data 
    origin in the mid, width and length, right hand frame 

* state data in a csv file 
    generated randomly in a number of 1000 000.
    
    
## Benchmark file format
* obstacle_number:   int 
* obstacle_density:  double 
* obstacle_file:  random_obstacles*.csv
* random_states_num: int
* random_states_file: random_states*.csv 
* normal_times: int 
* improved_time: int 

