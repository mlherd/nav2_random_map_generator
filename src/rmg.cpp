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
    original_map.setMapSize(Point(513, 513));

    // create a temp map and clone the original map
    Map temp_map;
    temp_map.cloneMap(original_map.getMap());

    // infilate obstacle size by robot radius to create enough room between obstacles
    auto adjusted_radius {0};

    // set params for the random obstacle place algorithm
    bool location_search {true};
    auto circle_number_counter {0};
    auto square_number_counter {0};

    for (int i=0; i < RMG::circle_number + RMG::square_number; i++) {
        Circle c;
        Square s;
        //cout << i;

        // Create an obstacle image (map)
        if (circle_number_counter <= RMG::circle_number){
            c.setMinRadius(5);
            c.setMaxRadius(20);
            c.setRadius(RMG::randomNumberGenerator(c.min_radius, c.max_radius));
        }
        else if (square_number_counter <= RMG::square_number){
            s.setMinSize(5);
            s.setMaxSize(20);
            s.setSize(RMG::randomNumberGenerator(s.min_size, s.max_size));
        }

        location_search = true;
        auto try_counter = 0;

        while(location_search) {
            if (try_counter == 100) {
                location_search = false;
            }
            temp_map.cloneMap(original_map.getMap());

            // randomly pick a location for the new obstacle
            Point obstacle_location =  Point(
                RMG::randomNumberGenerator(0, original_map.getMap().cols),
                RMG::randomNumberGenerator(0, original_map.getMap().rows));

            if (circle_number_counter <= RMG::circle_number){
                auto adjusted_radius = c.radius + c.infilation/2;

                // Draw the same cirle in temp_map
                circle(temp_map.map, obstacle_location, adjusted_radius, 
                    c.pixel_value, c.thickness, c.lineType, c.shift);

                // check if there is enough room for the obstacle at the location
                if (RMG::checkArea(original_map, temp_map, c)){
                    circle(original_map.map, obstacle_location, c.radius,  
                        c.pixel_value, c.thickness, c.lineType, c.shift);
                    location_search = false;
                    circle_number_counter = circle_number_counter + 1;
                }
            }

            else if (square_number_counter <= RMG::square_number){
                auto adjusted_size = s.size + s.infilation;
                
                // Draw square in temp_map
                Rect r = Rect(obstacle_location.x, obstacle_location.y, adjusted_size , adjusted_size);
                rectangle(temp_map.map, r, s.pixel_value, s.thickness, s.lineType, s.shift);
                
                if (RMG::checkArea(original_map, temp_map, s)){
                    r = Rect(obstacle_location.x, obstacle_location.y, s.size , s.size);
                    rectangle(original_map.map, r, s.pixel_value, s.thickness, s.lineType, s.shift);
                    location_search = false;
                    square_number_counter = square_number_counter + 1;
                }
            }
            try_counter = try_counter + 1;
        }
    }
    original_map.save(); // saves as a grayscale 8 bit .png image
    original_map.saveAsGazeboMap();
    original_map.saveAsPGM();
}
