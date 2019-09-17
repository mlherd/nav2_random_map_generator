#ifndef circle_hpp
#define circle_hpp

#include "obstacle.hpp"
#include <opencv2/opencv.hpp>

using namespace cv;

class Circle : public Obstacle {
    public:
        // member variables
        int radius;
        int max_obstacle_radius = 50;
        int min_obstacle_radius = 10;

        // member functions
        Circle();
        Circle(int r);
        void setMaxRadius(int);
        void setMinRadius(int);
};

#endif // circle_hpp
