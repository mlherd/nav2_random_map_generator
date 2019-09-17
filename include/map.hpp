#ifndef map_hpp
#define map_hpp

#include <opencv2/opencv.hpp>

using namespace cv;

class Map {
    public:
        // member variables
        Mat map;
        Point size;
        
        // member functions
        Map();
        Map(Point);
        void show();
        void loadMap();
        Mat getMap();
        void cloneMap(Mat);
        void clearMap();
        int getBlackPixelNumber();
        int getTargetPose(int pose_number, int distance , int center = 0);
        int getInitailPose(int center = 0);
        Point getMapCenter();
        void setMapSize(Point);
        Point getMapSize();
        void save();
};

#endif // map_hpp
