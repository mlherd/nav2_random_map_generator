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
        Mat getMap();
        Point getMapCenter();
        Point getMapSize();
        int getBlackPixelNumber();
        int getTargetPose(int pose_number, int distance , int center = 0);
        int getInitailPose(int center = 0);
        void show();
        void loadMap();
        void setMapSize(Point);
        void cloneMap(Mat);
        void clearMap();
        void save();
        void saveAsGazeboMap();
        void saveAsPGM();
        Mat invertColors(Mat);
};

#endif // map_hpp
