## Navigation 2 Random Map Generator 

This tool is for random map generation. It uses a small portion of the HouseExpo data set. It can randomly place obtacles in maps. Currently, adding circles, sqaures, and ramps are supported. Size, shape, type, and distance between obtacles are configured by user. Gazebo hightmap is used to create Gazebo world model of a randomly generated map. The random_world directory can be copied in .gazebo/model directory to be used with Gazebo. 

### Build and Run Instructions

### Tested Operating System

- Ubuntu 18.04.03 Bionic Beaver

### 1 - Install the Dependencies:

	sudo apt-get update
    sudo apt-get upgrade

- Install OpenCV

		sudo apt-get  update
		sudo apt-get  upgrade
		sudo apt-get  install libopencv-dev

### 2 - Run the Program
	
    ./map_generator <Map Id> <Number_of_Circles> <Number_of_Squares> <Robot_Size (px*0.03898)> <Map_Size(x)> <Map_Size(y)> <Min_Circle_Radius> <Max_Circle_Radius> <Min Square_Size> <Max_Circle_Radius> <Add Ramp> <Show_Map>
	
Example:

    ./map_generator 10 200 200 5 513 513 5 10 5 10 1 1

### 3 - Help Menu

	./map_generator h

## Randomly Generated Map Example

![enter image description here](https://github.com/mlherd/nav2_random_map_generator/blob/master/doc/img/random_map.png?raw=true)

## Randomly Generated Gazebo World Example

![enter image description here](https://github.com/mlherd/nav2_random_map_generator/blob/master/doc/img/gazebo.png?raw=true)

## Randomly Generated Map, Navigation 2, Turtlebot 3, and Rviz

![enter image description here](https://github.com/mlherd/nav2_random_map_generator/blob/master/doc/img/rviz.png?raw=true)

## Adding Ramps to the Map

![enter image description here](https://github.com/mlherd/nav2_random_map_generator/blob/master/doc/img/ramp.png?raw=true)


## Videos

[Ramdom Map TB3 Test Video](https://drive.google.com/file/d/1v9ZD_BBVTWFIhG86w5fbsWIV2ZU6xtcS/view?usp=sharing)

[Ramdom Map Ramp Test Video](https://drive.google.com/file/d/1pfmojJDchdqk0-fnMwMe8CWzGxXcXovb/view?usp=sharing)
