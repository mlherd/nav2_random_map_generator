## Navigation 2 Map Editor

## 1 - Install the Dependencies:

- Install git

		sudo apt-get install git

- Install OpenCV

		sudo apt-get  update
		sudo apt-get  upgrade
		sudo apt-get  install libopencv-dev

## 2-  Clone the Project Repository

    git clone https://github.com/mlherd/nav2_random_map.git

## 3 - Build the Source Code

    cd nav2_random_map/src
    g++ main.cpp map.cpp rmg.cpp circle.cpp obstacle.cpp -o map_editor `pkg-config --cflags --libs opencv`

## 4- Run the Program
	
    cd nav2_random_map/src
    ./map_editor

	


