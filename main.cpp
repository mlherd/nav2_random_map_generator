#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>

using namespace cv;
using namespace std;

int 
count_total_black_pixel_number(Mat image) {
    auto total_pixel_number = image.rows * image.cols;
    auto total_black_pixel_number = total_pixel_number - countNonZero(image);
    return total_black_pixel_number;
}

int 
check_area(Mat original_image, Mat new_image, Mat new_obstacle) {
    int total_black_pixels_obstacle = count_total_black_pixel_number(new_obstacle);
    int total_black_pixels_original_image = count_total_black_pixel_number(original_image);
    int total_black_pixels_new_image = count_total_black_pixel_number(new_image);
    if (total_black_pixels_original_image + total_black_pixels_obstacle == total_black_pixels_new_image){
        return true;
    }
    return false;
}

int 
random_generator(int min, int max) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> range(min, max);
    return range(generator);
}

void
run()
{
    auto original_image = imread("1.png", CV_LOAD_IMAGE_GRAYSCALE);
    auto new_image = original_image.clone();

    auto obstacle_center =  Point(0, 0);
    auto obstacle_image_size = Point(0, 0);
    auto obstacle_image_center = Point(0, 0);
    auto size = Point(384,384);

    auto obstacle = Mat(obstacle_image_size, CV_8UC1, 255);

    auto pixel_value = 0;
    auto thickness= -1;
    auto lineType=LINE_8;
    auto shift = 0;

    auto obstacle_number = 100;
    auto robot_size = 50;
    auto adjusted_radius = 0;

    for (int i=0; i < obstacle_number; i++) {
        auto radius = random_generator(10, 50);
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
            auto obstacle_center =  Point(random_generator(0, original_image.cols), random_generator(0, original_image.rows));
            circle(obstacle, obstacle_image_center, adjusted_radius, pixel_value, thickness, lineType, shift );
            circle(new_image, obstacle_center, adjusted_radius, pixel_value, thickness, lineType, shift );

            if (check_area(original_image, new_image, obstacle)) {
                circle(original_image, obstacle_center, radius, pixel_value, thickness, lineType, shift );
                location_search = false;
            }
            try_counter = try_counter + 1;
        }
    }
    cout << count_total_black_pixel_number(original_image);
    cv::resize(original_image, original_image, size);
    namedWindow( "original image", WINDOW_AUTOSIZE );
//    namedWindow( "obstacle", WINDOW_AUTOSIZE );
//    namedWindow( "new image", WINDOW_AUTOSIZE );

    imshow( "original image", original_image );
//    imshow( "obstacle", obstacle );
//    imshow( "new image", new_image );

    vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);
    imwrite("saved_map1.png", original_image, compression_params);
}

int 
main( int argc, char** argv )
{
    run();
    cvWaitKey(0);
    return 0;
}
