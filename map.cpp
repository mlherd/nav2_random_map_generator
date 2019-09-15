#include "include/map.hpp"

using namespace cv;
using namespace std;

Map::Map() {
    Map::map;
    Map::size = Point(0,0);
}

void Map::loadMap() {
    Map::map = imread("maps/0001.png", CV_LOAD_IMAGE_GRAYSCALE);
}

void Map::showMap() {
    resizeMap(Point(384,384));
    namedWindow( "Map", WINDOW_AUTOSIZE );
    imshow( "Map", Map::map );
    cvWaitKey(0);
}

void Map::resizeMap(Point new_size) { 
    cv::resize(Map::map, Map::map, new_size);
    Map::size = new_size;
}

void Map::clearMap() {
    Map::map = 255 * Mat::ones(Map::size, CV_8UC1);
}

int Map::getBlackPixelNumber() {
    auto total_pixel_number = Map::map.rows * Map::map.cols;
    auto total_black_pixel_number = total_pixel_number - countNonZero(Map::map);
    return total_black_pixel_number;
}

void Map::saveMap() {
    vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);
    imwrite("saved_map1.png", Map::map, compression_params);
}

int Map::getTargetPose(int pose_number, int distance , int center) {
    Mat locations;   // output, locations of non-zero pixels
    findNonZero(Map::map, locations);
    // access pixel coordinates
    Point pnt = locations.at<Point>(0);
    cout << pnt;
}

//TODO
int Map::getInitailPose(int center) {
    Mat locations;   // output, locations of non-zero pixels
    findNonZero(Map::map, locations);
    // access pixel coordinates
    Point pnt = locations.at<Point>(0);
    cout << pnt;
}