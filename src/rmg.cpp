// Copyright (c) 2018 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <random>
#include "../include/map.hpp"
#include "../include/rmg.hpp"
#include "../include/circle.hpp"
#include "../include/square.hpp"
#include "../include/obstacle.hpp"

using namespace cv;
using namespace std;

// Random Map Generator Consructor
RMG::RMG() {
    RMG::circle_number = 50;
    RMG::square_number = 50;
    RMG::show_map = false;
}

RMG::RMG(int map_id, int num_circles, int num_squares, int robot_size, int map_size_x,
         int map_size_y, int min_circle_r, int max_circle_r, int min_square_size,
         int max_square_size, int show_map) {
    
    RMG::circle_number = num_circles;
    RMG::square_number = num_squares;
    RMG::map_x = map_size_x;
    RMG::map_y = map_size_y;
    RMG::robot_size = robot_size;
    RMG::min_circle_r = min_circle_r;
    RMG::max_circle_r = max_circle_r;
    RMG::min_square_size = min_square_size;
    RMG::max_square_size = max_square_size;
    
    if (show_map == 1) {
        RMG::show_map = true;
    }
    else {
        RMG::show_map = false;
    }
}

// Random number generator
int 
RMG::randomNumberGenerator(int min, int max) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> range(min, max);
    return range(generator);
}

// Check if the new obstacle can be places at the location
bool 
RMG::checkArea(Map orig, Map temp, Obstacle obs) {
    if ( orig.getBlackPixelNumber() + obs.getBlackPixelNumber() == temp.getBlackPixelNumber()){
        return true;
    }
    return false;
}

// Generates a random map
void 
RMG::generateMap() { 
    // load a map (room) from the /maps directory
    // room_id = 0 radomly picked room
    Map original_map;
    original_map.loadMap();
    original_map.setMapSize(Point(RMG::map_x, RMG::map_y));

    // create a temp map and clone the original map
    Map temp_map;
    temp_map.cloneMap(original_map.getMap());

    // infilate obstacle size by robot radius to create enough room between obstacles
    auto adjusted_radius {0};

    // set params for the random obstacle place algorithm
    bool location_search {true};
    auto circle_number_counter {0};
    auto square_number_counter {0};

    auto termination_counter {0};
    
    while (((circle_number_counter + square_number_counter) != (RMG::square_number + RMG::circle_number))) {
        Circle c;
        Square s;

        c.infilation = RMG::robot_size;
        s.infilation = RMG::robot_size;

        temp_map.cloneMap(original_map.getMap());

        // randomly pick a location for the new obstacle
        Point obstacle_location =  Point(
            RMG::randomNumberGenerator(0, original_map.getMap().cols),
            RMG::randomNumberGenerator(0, original_map.getMap().rows));

        // Create a circle obstacle image (map)
        if (circle_number_counter != RMG::circle_number){
            c.setMinRadius(RMG::min_circle_r);
            c.setMaxRadius(RMG::max_circle_r);
            c.setRadius(RMG::randomNumberGenerator(c.min_radius, c.max_radius));

            auto adjusted_radius = c.radius + c.infilation/2;

            // Draw the same cirle in temp_map
            circle(temp_map.map, obstacle_location, adjusted_radius, 
                c.pixel_value, c.thickness, c.lineType, c.shift);

            // Check if there is enough room for the obstacle at the location
            if (RMG::checkArea(original_map, temp_map, c)){
                circle(original_map.map, obstacle_location, c.radius,  
                    c.pixel_value, c.thickness, c.lineType, c.shift);
                circle_number_counter = circle_number_counter + 1;
            }
        }
        
        // Create a square obstacle image (map)
        if (square_number_counter != RMG::square_number){
            s.setMinSize(RMG::min_square_size);
            s.setMaxSize(RMG::max_square_size);
            s.setSize(RMG::randomNumberGenerator(s.min_size, s.max_size));

            auto adjusted_size = s.size + s.infilation;
            
            // Draw square in temp_map
            Rect r = Rect(obstacle_location.x, obstacle_location.y, adjusted_size , adjusted_size);
            rectangle(temp_map.map, r, s.pixel_value, s.thickness, s.lineType, s.shift);
            
            // Check if there is enough room for the obstacle at the location
            if (RMG::checkArea(original_map, temp_map, s)){
                r = Rect(obstacle_location.x, obstacle_location.y, s.size , s.size);
                rectangle(original_map.map, r, s.pixel_value, s.thickness, s.lineType, s.shift);
                square_number_counter = square_number_counter + 1;
            }
        }
        if (termination_counter == (100 * RMG::square_number + RMG::circle_number)){
            cout << "There is not enough room in the map for all the obstacles" << endl;
            break;
        }
        termination_counter = termination_counter + 1;
    }

    cout << circle_number_counter << " circles added to the map" << endl << square_number_counter << " squares added to the map" << endl;

    original_map.save(); // saves as a grayscale 8 bit .png image
    original_map.saveAsGazeboMap(); // saves as a grayscale (inverted colors) 8 bit .png image
    original_map.saveAsPGM(); // saves the map for map server
    
    if (show_map) {
        original_map.show();
    }
}
