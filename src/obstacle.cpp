#include "../include/obstacle.hpp"

using namespace cv;

Obstacle::Obstacle() {
    Obstacle::frame = 255 * Mat::ones(Point (1,1), CV_8UC1);
    Obstacle::frame_size =  Point (1,1);
    Obstacle::pixel_value = 0;
    Obstacle::thickness = -1;
    Obstacle::shift = 0;
    Obstacle::lineType = LINE_8;
    Obstacle::border = 2;
    Obstacle::infilation = 2; // robot size in px
}

void
Obstacle::setFrameSize(Point frame_size) {
    Obstacle::frame =  255 * Mat::ones(frame_size, CV_8UC1);
    Obstacle::frame_size = frame_size;
}

void
Obstacle::setInfilation(int inf_value) {
    Obstacle::infilation = inf_value;
}

void
Obstacle::setBorder(int border) {
    Obstacle::border = border;
}

Point
Obstacle::getObstacleCenter() {
    return Obstacle::frame_size/2;
}

void
Obstacle::setPixelValue(int px_value) {
    Obstacle::pixel_value = px_value;
}

void
Obstacle::setShift(int shift) {
    Obstacle::shift = shift;
}

void
Obstacle::setThickness(int thickness) {
    Obstacle::thickness = thickness;
}

int
Obstacle::getBlackPixelNumber() {
    auto total_pixel_number = Obstacle::frame.rows * Obstacle::frame.cols;
    auto total_black_pixel_number = total_pixel_number - countNonZero(Obstacle::frame);
    return total_black_pixel_number;
}

void
Obstacle::show(){
    namedWindow("Obstacle", WINDOW_AUTOSIZE);
    imshow("Obstacle", Obstacle::frame);
    cvWaitKey(0);
}
