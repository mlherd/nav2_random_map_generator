#include <random>
#include "include/map.hpp"
#include "include/rmg.hpp"

using namespace cv;
using namespace std;

// Random Map Generator Consructor
RMG::RMG() {
    RMG::obstacle_number = 100;
    RMG::robot_size = 50; //in pixels
    RMG::pixel_value = 0;
    RMG::thickness = -1;
    RMG::shift = 0;
    RMG::lineType = LINE_8;
    RMG::show_map = false;
    RMG::max_obstacle_radius=50;
    RMG::min_obstacle_radius=10;
}

// Random number generator
int 
RMG::randomNumberGenerator(int min, int max) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> range(min, max);
    return range(generator);
}

bool 
RMG::checkArea(Map orig, Map temp, Map obs) {
    if ( orig.getBlackPixelNumber() + obs.getBlackPixelNumber() == temp.getBlackPixelNumber()){
        return true;
    }
    return false;
}

// Generates a random map
void 
RMG::generateMap() { 
    //load a map (room) from the /maps directory
    //room_id = 0 radomly picked room
    Map original_map;
    original_map.loadMap();

    //create a temp map and clone the original map
    Map temp_map;
    temp_map.cloneMap(original_map.getMap());

    // create an obstacle image (map)
    Map obstacle (Point (1,1));

    //infilate obstacle size by robot radius to create enough room between obstacles
    auto adjusted_radius {0};
    bool location_search = true;

    for (int i=0; i < RMG::obstacle_number; i++) {
        auto radius = RMG::randomNumberGenerator(10, 50);
        adjusted_radius = radius + RMG::robot_size;
        obstacle.clearMap();
        obstacle.setMapSize(Point ((2*adjusted_radius)+2,(2*adjusted_radius)+2));
        location_search = true;
        auto try_counter = 0;

        while(location_search) {
            if (try_counter == 100) {
                location_search = false;
            }

            temp_map.cloneMap(original_map.getMap());

            Point obstacle_location =  Point(RMG::randomNumberGenerator(0, original_map.getMap().cols), RMG::randomNumberGenerator(0, original_map.getMap().rows));
            
            //draw a cicle in obstacle image
            circle(obstacle.map, obstacle.getMapCenter(), adjusted_radius, RMG::pixel_value, RMG::thickness, RMG::lineType, RMG::shift);

            //draw the same cirle in temp_map
            circle(temp_map.map, obstacle_location, adjusted_radius, RMG::pixel_value, RMG::thickness, RMG::lineType, RMG::shift);

            //check if there is enough room for the obstacle at the location
            if (RMG::checkArea(original_map, temp_map, obstacle)){
                circle(original_map.map, obstacle_location, radius,  RMG::pixel_value, RMG::thickness, RMG::lineType, RMG::shift);
                location_search = false;
            }
                try_counter = try_counter + 1;
        }
    }
    //scale down the map size to 384,384
    original_map.setMapSize(Point(384,384));
    original_map.showMap();
}
