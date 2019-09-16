#include "include/map.hpp"

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
Map::loadMap() {
    Map::map = imread("maps/0001.png", CV_LOAD_IMAGE_GRAYSCALE);
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
Map::showMap() {
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
Map::saveMap() {
    vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);
    imwrite("saved_map1.png", Map::map, compression_params);
}

int 
Map::getTargetPose(int pose_number, int distance , int center) {
    Mat locations;   // output, locations of non-zero pixels
    findNonZero(Map::map, locations);
    // access pixel coordinates
    Point pnt = locations.at<Point>(0);
    cout << pnt;
}

//TODO
int 
Map::getInitailPose(int center) {
    Mat locations;   // output, locations of non-zero pixels
    findNonZero(Map::map, locations);
    // access pixel coordinates
    Point pnt = locations.at<Point>(0);
    cout << pnt;
}