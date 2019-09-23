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

#include "../include/square.hpp"

using namespace cv;

Square::Square() {
    Square::size = 1;
    Square::min_size = 0;
    Square::max_size = 1;
    
    // Set the frame for the obstacle
    Square::setFrameSize(Point (Square::size + Square::border + Square::infilation, 
        Square::size +  Square::border + Square::infilation));
    
    // Draw square in the obstacle frame
    Rect r = Rect(Square::border, Square::border, Square::size , Square::size);
    rectangle(Square::frame, r, Square::pixel_value, Square::thickness, Square::lineType, Square::shift);
}

Square::Square(int size, int max, int min){
    Square::size = size;
    Square::max_size = max;
    Square::min_size = min;
    
    // Set the frame for the obstacle
    Square::setFrameSize(Point (Square::size + Square::border + Square::infilation, 
        Square::size +  Square::border + Square::infilation));
    
    // Draw square in the obstacle frame
    Rect r = Rect(Square::border, Square::border, Square::size , Square::size);
    rectangle(Square::frame, r, Square::pixel_value, Square::thickness, Square::lineType, Square::shift);
}

void
Square::setMaxSize(int size_max) {
    Square::max_size = size_max;
}

void
Square::setMinSize(int size_min) {
    Square::min_size = size_min;
}

void
Square::setSize(int size) {
    Square::size = size;
    
    Square::setFrameSize(Point (Square::size + Square::border + Square::infilation, Square::size +  Square::border + Square::infilation));
    
    // Draw Square
    Rect r = Rect(Square::border, Square::border, Square::size + Square::infilation , Square::size + Square::infilation);
    rectangle(Square::frame, r, Square::pixel_value, Square::thickness, Square::lineType, Square::shift);
}
