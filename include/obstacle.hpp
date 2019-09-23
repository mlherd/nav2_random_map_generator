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

#ifndef obstacle_hpp
#define obstacle_hpp

#include <opencv2/opencv.hpp>

using namespace cv;

class Obstacle {
    public:
        // member variables
        Mat frame;
        Point frame_size;
        LineTypes lineType = LINE_8;
        int pixel_value;
        int thickness;
        int shift;
        int infilation;
        int border;

        // member functions
        Obstacle();
        Point getObstacleCenter();
        int getBlackPixelNumber();
        void setFrameSize(Point);
        void setInfilation(int);
        void setBorder(int);
        void setThickness(int);
        void setShift(int);
        void setPixelValue(int);
        void show();
};

#endif // obstacle_hpp
