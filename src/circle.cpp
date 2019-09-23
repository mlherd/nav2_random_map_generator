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

#include "../include/circle.hpp"

using namespace cv;

Circle::Circle() {
    Circle::radius = 1;
    Circle::max_radius = 1;
    Circle::min_radius = 0;

    // Set the obstacle frame size
    Circle::setFrameSize(Point (2*Circle::radius + Circle::border + Circle::infilation, 
        2*Circle::radius +  Circle::border + Circle::infilation));
    
    // Draw square in the obstacle frame
    circle(Circle::frame, Circle::getObstacleCenter(), 
            Circle::radius + Circle::infilation/2, Circle::pixel_value, 
                Circle::thickness, Circle::lineType, Circle::shift);
}

Circle::Circle(int r, int max, int min){
    Circle::radius = r;
    Circle::max_radius = max;
    Circle::min_radius = min;
    
    // Set the obstacle frame size
    Circle::setFrameSize(Point (2*Circle::radius + Circle::border + Circle::infilation, 
        2*Circle::radius +  Circle::border + Circle::infilation));
    
    // Draw square in the obstacle frame
    circle(Circle::frame, Circle::getObstacleCenter(), 
            Circle::radius + Circle::infilation/2, Circle::pixel_value, 
                Circle::thickness, Circle::lineType, Circle::shift);
}

void
Circle::setMaxRadius(int r_max) {
    Circle::max_radius = r_max;
}

void
Circle::setMinRadius(int r_min) {
    Circle::min_radius = r_min;
}

void
Circle::setRadius(int r) {
    Circle::radius = r;
    Circle::setFrameSize(Point (2*Circle::radius + Circle::border + Circle::infilation, 2*Circle::radius +  Circle::border + Circle::infilation));
    //
    circle(Circle::frame, Circle::getObstacleCenter(), 
        Circle::radius + Circle::infilation/2, Circle::pixel_value, Circle::thickness, Circle::lineType, Circle::shift);
}
