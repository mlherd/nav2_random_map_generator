#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>

using namespace cv;
using namespace std;

namespace nav2_random_map_generator
{
    class RandomMap
    {
        public:
            Mat original_image;
            Mat new_image;
            Mat obstacle;

            Point obstacle_center;
            Point obstacle_image_size;
            Point obstacle_image_center;
            Point size;

            int obstacle_number;
            int robot_size;
            int adjusted_radius;

            int pixel_value;
            int thickness;
            int shift;
            LineTypes lineType;

            //Random Map Class Default Constructor
            RandomMap(){ 
                obstacle_center =  Point(0, 0);
                obstacle_image_size = Point(0, 0);
                obstacle_image_center = Point(0, 0);
                size = Point(384,384);

                obstacle = Mat(obstacle_image_size, CV_8UC1, 255);

                pixel_value = 0;
                thickness= -1;
                lineType=LINE_8;
                shift = 0;

                obstacle_number = 100;
                robot_size = 50;
                adjusted_radius = 0;
            }

            // Count the total number of black pixels in a given map
            int 
            getTotalBlackPixelNumber(Mat image) {
                auto total_pixel_number = image.rows * image.cols;
                auto total_black_pixel_number = total_pixel_number - countNonZero(image);
                return total_black_pixel_number;
            }

            // Count the total number of black pixels in a given map
            int 
            checkArea(Mat original_image, Mat new_image, Mat new_obstacle) {
                int total_black_pixels_obstacle = getTotalBlackPixelNumber(new_obstacle);
                int total_black_pixels_original_image = getTotalBlackPixelNumber(original_image);
                int total_black_pixels_new_image = getTotalBlackPixelNumber(new_image);
                if (total_black_pixels_original_image + total_black_pixels_obstacle == total_black_pixels_new_image){
                    return true;
                }
                return false;
            }

            // Random number generator
            int 
            randomNumberGenerator(int min, int max) {
                random_device rd;
                mt19937 generator(rd());
                uniform_int_distribution<> range(min, max);
                return range(generator);
            }

            // returns available target points
            int
            getFreeTargetPose (int pose_number, int distance , int center = 0) {
                Mat locations;   // output, locations of non-zero pixels
                findNonZero(original_image, locations);
                // access pixel coordinates
                Point pnt = locations.at<Point>(0);
                cout << pnt;
            }

            // Loads and image from maps directory
            void
            loadImage() {
                original_image = imread("maps/e524806506b152b5289cbfb2b76e2a04.png", CV_LOAD_IMAGE_GRAYSCALE);
            }

            // save maps in a directory
            void
            saveMap() {
                vector<int> compression_params;
                compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
                compression_params.push_back(9);
                imwrite("saved_map1.png", original_image, compression_params);
            }

            // shows map in a window
            void
            showMap() {
                cv::resize(original_image, original_image, size);
                namedWindow( "original image", WINDOW_AUTOSIZE );
                imshow( "original image", original_image );
            }

            // genarate a random map
            cv::Mat
            generateMap()
            {
                loadImage();
                new_image = original_image.clone();

                for (int i=0; i < obstacle_number; i++) {
                    auto radius = randomNumberGenerator(10, 50);
                    adjusted_radius = radius + robot_size;

                    obstacle_image_size.x = (2*adjusted_radius)+2;
                    obstacle_image_size.y = (2*adjusted_radius)+2;
                    obstacle_image_center.x = obstacle_image_size.x/2;
                    obstacle_image_center.y = obstacle_image_size.y/2;

                    obstacle = Mat(obstacle_image_size, CV_8UC1, 255);

                    bool location_search = true;
                    auto try_counter = 0;

                    while(location_search) {
                        if (try_counter == 100) {
                            location_search = false;
                        } 
                        auto new_image = original_image.clone();
                        auto obstacle_center =  Point(randomNumberGenerator(0, original_image.cols), randomNumberGenerator(0, original_image.rows));
                        circle(obstacle, obstacle_image_center, adjusted_radius, pixel_value, thickness, lineType, shift );
                        circle(new_image, obstacle_center, adjusted_radius, pixel_value, thickness, lineType, shift );

                        if (checkArea(original_image, new_image, obstacle)) {
                            circle(original_image, obstacle_center, radius, pixel_value, thickness, lineType, shift );
                            location_search = false;
                        }
                        try_counter = try_counter + 1;
                    }
                }
                showMap();
                saveMap();
                getFreeTargetPose(0,0,0);
                return original_image;
            }
    };
} // Namespace nav2_random_map_generator

int 
main( int argc, char** argv )
{
    nav2_random_map_generator::RandomMap mapGenerator;
    auto newMap = mapGenerator.generateMap();
    cvWaitKey(0);
    return 0;
}
