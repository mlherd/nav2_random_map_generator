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

class RMG {
    private:
        // member variables
        int circle_number;
        int square_number;
        int robot_size;
        int pixel_value;
        int thickness;
        int shift;
        LineTypes lineType;
        bool show_map;
        int max_obstacle_radius;
        int min_obstacle_radius;

    public:
        //member functions
        RMG();
        bool checkArea(Map orig, Map temp, Obstacle obs);
        int randomNumberGenerator(int min, int max);
        void generateMap();
};

#endif // map_hpp
