#include "../include/circle.hpp"

using namespace cv;
using namespace std;

Circle::Circle() {
    Circle::radius = 1;
    //
    Circle::setFrameSize(Point (Circle::radius + Circle::infilation + Circle::border, Circle::radius + Circle::infilation + Circle::border));
    //
    circle(Circle::frame, Circle::getObstacleCenter(), 
                Circle::radius + Circle::infilation/2, Circle::pixel_value, Circle::thickness, Circle::lineType, Circle::shift);
}

Circle::Circle(int r){
    Circle::radius = r;
    //
    Circle::setFrameSize(Point (2*Circle::radius + Circle::border + Circle::infilation, 2*Circle::radius +  Circle::border + Circle::infilation));
    //
    circle(Circle::frame, Circle::getObstacleCenter(), 
                Circle::radius + Circle::infilation/2, Circle::pixel_value, Circle::thickness, Circle::lineType, Circle::shift);
}

void
Circle::setMaxRadius(int r_max) {
    Circle::max_obstacle_radius = r_max;
}

void
Circle::setMinRadius(int r_min) {
    Circle::min_obstacle_radius = r_min;
}
