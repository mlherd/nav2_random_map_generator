#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>
#include "../include/map.hpp"
#include "../include/rmg.hpp"
#include "../include/circle.hpp"

using namespace cv;
using namespace std;

int 
main( int argc, char** argv )
{   
    RMG generator;
    generator.generateMap();
    return 0;
}