#ifndef obstacle_hpp
#define obstacle_hpp

#include <opencv2/opencv.hpp>

using namespace cv;

class Obstacle {
    public:
        // member variables
        Mat frame;
        Point frame_size;
        LineTypes lineType = LINE_8;
        int pixel_value;
        int thickness;
        int shift;
        int infilation;
        int border;

        // member functions
        Obstacle();
        Point getObstacleCenter();
        int getBlackPixelNumber();
        void setFrameSize(Point);
        void setInfilation(int);
        void setBorder(int);
        void setThickness(int);
        void setShift(int);
        void setPixelValue(int);
        void show();
};

#endif // obstacle_hpp
