#ifndef map_hpp
#define map_hpp

#include <opencv2/opencv.hpp>

using namespace cv;

class Map {
    private:
        Mat map;
        Point size;
        
    public:
        Map();
        void showMap();
        void resizeMap(Point size);
        void loadMap();
        void clearMap();
        int getBlackPixelNumber();
        int getTargetPose(int pose_number, int distance , int center = 0);
        int getInitailPose(int center = 0);
        void saveMap();
};

#endif // map_hpp