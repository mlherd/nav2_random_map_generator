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

#ifndef map_hpp
#define map_hpp

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class Map {
    public:
        // member variables
        Mat map;
        Point size;

        // member functions
        Map();
        Map(Point);
        Mat getMap();
        Point getMapCenter();
        Point getMapSize();
        int getBlackPixelNumber();
        int getTargetPose(int pose_number, int distance , int center = 0);
        int getInitailPose(int center = 0);
        void show();
        void loadMap(string id);
        void setMapSize(Point);
        void cloneMap(Mat);
        void clearMap();
        void save();
        void saveAsGazeboMap();
        void saveAsPGM();
        Mat invertColors(Mat);
};

#endif // map_hpp
