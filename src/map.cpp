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

#include "../include/map.hpp"

using namespace cv;
using namespace std;

Map::Map() {
    Map::map;
    Map::size;
}

Map::Map(Point map_size = Point (1,1)) {
    Map::map = 255 * Mat::ones(map_size, CV_8UC1);
    Map::size = map_size;
}

void 
Map::loadMap(string id) {
    string address = "../maps/" + id + ".png";
    cout << address;
    Map::map = imread(address, CV_LOAD_IMAGE_GRAYSCALE);
    Map::size = Map::map.size();
}

Mat 
Map::getMap() {
    return Map::map;
}

void 
Map::cloneMap (Mat copy_map) {
    Map::map = copy_map.clone();
}

void 
Map::show() {
    namedWindow("Map", WINDOW_AUTOSIZE);
    imshow("Map", Map::map);
    cvWaitKey(0);
}

void 
Map::setMapSize(Point new_size) { 
    cv::resize(Map::map, Map::map, new_size);
    Map::size = new_size;
}

Point 
Map::getMapSize() {
    return Map::size;
}

Point
Map::getMapCenter() {
    return (Map::map.size()/2);
}

void 
Map::clearMap() {
    Map::map = 255 * Mat::ones(Map::size, CV_8UC1);
}

int 
Map::getBlackPixelNumber() {
    auto total_pixel_number = Map::map.rows * Map::map.cols;
    auto total_black_pixel_number = total_pixel_number - countNonZero(Map::map);
    return total_black_pixel_number;
}

void 
Map::save() {
    vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);
    imwrite("../random_maps/random_map.png", Map::map, compression_params);
}

Mat
Map::invertColors(Mat map) {
    return (255 - map);
}

void 
Map::saveAsGazeboMap() {
    Mat inverted_map = Map::invertColors(Map::map).clone();
    vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);
    imwrite("../random_world/media/materials/texture/random_world.png", inverted_map, compression_params);
}

void
Map::saveAsPGM() {
    std::vector<int> compression_params; // Stores the compression parameters
    compression_params.push_back(CV_IMWRITE_PXM_BINARY); // Set to PXM compression
    compression_params.push_back(0); // Set type of PXM in our case PGM
    cv::imwrite("../random_maps/random_map.pgm", Map::map, compression_params);
}

// TODO -> this feature haven't fully implemented yet!
int 
Map::getTargetPose(int pose_number, int distance , int center) {
    cout << "Not Complete!!!";
    Mat locations;   // output, locations of non-zero pixels
    findNonZero(Map::map, locations);
    // access pixel coordinates
    Point pnt = locations.at<Point>(0);
    cout << pnt;
}

// TODO -> this feature haven't fully implemented yet!
int 
Map::getInitailPose(int center) {
    cout << "Not Implemented!!!";
}
