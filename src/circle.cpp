#include "../include/circle.hpp"

using namespace cv;

Circle::Circle() {
    Circle::radius = 1;
    Circle::max_radius = 1;
    Circle::min_radius = 0;
    //
    Circle::setFrameSize(Point (2*Circle::radius + Circle::border + Circle::infilation, 
        2*Circle::radius +  Circle::border + Circle::infilation));
    //
    circle(Circle::frame, Circle::getObstacleCenter(), 
            Circle::radius + Circle::infilation/2, Circle::pixel_value, 
                Circle::thickness, Circle::lineType, Circle::shift);
}

Circle::Circle(int r, int max, int min){
    Circle::radius = r;
    Circle::max_radius = max;
    Circle::min_radius = min;
    //
    Circle::setFrameSize(Point (2*Circle::radius + Circle::border + Circle::infilation, 
        2*Circle::radius +  Circle::border + Circle::infilation));
    //
    circle(Circle::frame, Circle::getObstacleCenter(), 
            Circle::radius + Circle::infilation/2, Circle::pixel_value, 
                Circle::thickness, Circle::lineType, Circle::shift);
}

void
Circle::setMaxRadius(int r_max) {
    Circle::max_radius = r_max;
}

void
Circle::setMinRadius(int r_min) {
    Circle::min_radius = r_min;
}

void
Circle::setRadius(int r) {
    Circle::radius = r;
    Circle::setFrameSize(Point (2*Circle::radius + Circle::border + Circle::infilation, 2*Circle::radius +  Circle::border + Circle::infilation));
    //
    circle(Circle::frame, Circle::getObstacleCenter(), 
        Circle::radius + Circle::infilation/2, Circle::pixel_value, Circle::thickness, Circle::lineType, Circle::shift);
}
