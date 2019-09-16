#ifndef map_hpp
#define map_hpp

#include <opencv2/opencv.hpp>

using namespace cv;

class Map {
    public:
        Mat map;
        Point size;
        
        Map();
        Map(Point map_size);
        void showMap();
        void loadMap();
        Mat getMap();
        void cloneMap(Mat copy_map);
        void clearMap();
        int getBlackPixelNumber();
        int getTargetPose(int pose_number, int distance , int center = 0);
        int getInitailPose(int center = 0);
        Point getMapCenter();
        void setMapSize(Point size);
        Point getMapSize();
        void saveMap();
};

#endif // map_hpp