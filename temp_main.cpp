#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>
#include "include/map.hpp"
#include "include/rmg.hpp"

using namespace cv;
using namespace std;

int 
main( int argc, char** argv )
{
    RMG generator;
    generator.generateMap();
    return 0;
}