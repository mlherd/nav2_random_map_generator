# Navigation 2 Random Map Generator 

This tool creates randomly generated maps and world models that can be used by Navigation 2 and Gazebo. It uses a small portion of the [HouseExpo](https://arxiv.org/abs/1903.09845) data set. It is a set of 2D empty hand-drawn indoor layout images. The empty maps are located in the maps directory. The random map generator randomly places obstacles in grayscale maps. The maps must be in .png format. Currently, adding circles, squares, and ramps are supported. Size, shape, type, and distance between obstacles can be configured by the user. Gazebo heightmap is used to create a Gazebo world model of a randomly generated map. The random_world directory can be copied in .gazebo/model directory to be used with Gazebo. The generated map size must be 2^n+1 x 2^n+1. Otherwise, it will not work with Gazebo. World model size in Gazebo is scaled to 20-meter x 20-meter.

## Documentation

- [How it works](#how-it-works)
- [Build and Run Instrunctions](#build-and-run-instructions)
- [Examples](#examples)
- [Videos](#videos)

## How It Works
![enter image description here](https://github.com/mlherd/nav2_random_map_generator/blob/master/doc/img/rmg.PNG?raw=true)

## Build and Run Instructions

### Tested System

- Ubuntu 18.04.03 Bionic Beaver
- Gazebo 9

### 1 - Install the Dependencies:

	sudo apt-get update
    sudo apt-get upgrade

- Install OpenCV

		sudo apt-get  update
		sudo apt-get  upgrade
		sudo apt-get  install libopencv-dev
		
#### Build
 
```
cd nav2_random_map_generator

make
```

or

```
cd src

g++ circle.cpp main.cpp map.cpp obstacle.cpp ramp.cpp rmg.cpp square.cpp -o random-map `pkg-config --cflags --libs opencv`
```
### 2 - Run the Program
	
    ./map_generator <Map Id> <Number_of_Circles> <Number_of_Squares> <Robot_Size (px*0.03898)> <Map_Size(x)> <Map_Size(y)> <Min_Circle_Radius> <Max_Circle_Radius> <Min Square_Size> <Max_Circle_Radius> <Add Ramp> <Show_Map>
	
Example:

    ./map_generator 10 200 200 5 513 513 5 10 5 10 1 1

### 3 - Help Menu

	./map_generator h

## Examples

### Randomly Generated Map Example

![enter image description here](https://github.com/mlherd/nav2_random_map_generator/blob/master/doc/img/random_map.png?raw=true)

### Randomly Generated Gazebo World Example

![enter image description here](https://github.com/mlherd/nav2_random_map_generator/blob/master/doc/img/gazebo.png?raw=true)

### Randomly Generated Map, Navigation 2, Turtlebot 3, and Rviz

![enter image description here](https://github.com/mlherd/nav2_random_map_generator/blob/master/doc/img/rviz.png?raw=true)

### Adding Ramps to the Map

![enter image description here](https://github.com/mlherd/nav2_random_map_generator/blob/master/doc/img/ramp.png?raw=true)

## Videos

[Ramdom Map TB3 Test Video](https://drive.google.com/file/d/1v9ZD_BBVTWFIhG86w5fbsWIV2ZU6xtcS/view?usp=sharing)

[Ramdom Map Ramp Test Video](https://drive.google.com/file/d/1pfmojJDchdqk0-fnMwMe8CWzGxXcXovb/view?usp=sharing)
