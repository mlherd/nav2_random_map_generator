#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>
#include "include/map.hpp"

using namespace cv;
using namespace std;

int 
main( int argc, char** argv )
{
    Map new_map;
    new_map.loadMap();
    new_map.showMap();
    new_map.clearMap();
    new_map.showMap();
    return 0;
}