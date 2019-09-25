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

#ifndef rmg_hpp
#define rmg_hpp
#include <opencv2/opencv.hpp>
#include "map.hpp"
#include "obstacle.hpp"

using namespace cv;
using namespace std;

class RMG {
    private:
        // member variables
        int circle_number;
        int square_number;
        int robot_size;
        int map_id;
        int map_x;
        int map_y;
        int show_map;
        int min_circle_r;
        int max_circle_r;
        int min_square_size;
        int max_square_size;
        int add_ramp;

    public:
        //member functions
        RMG();
        RMG(int map_id,
            int num_circles,
            int num_squares,
            int robot_size,
            int map_size_x,
            int map_size_y,      
            int min_circle_r,
            int max_circle_r,
            int min_square_size,
            int max_square_size,
            int add_ramp,
            int show_map);
        
        bool checkArea(Map orig, Map temp, Obstacle obs);
        int randomNumberGenerator(int min, int max);
        void generateMap();
};

#endif // map_hpp
