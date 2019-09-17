#include <random>
#include "../include/map.hpp"
#include "../include/rmg.hpp"
#include "../include/circle.hpp"

using namespace cv;
using namespace std;

// Random Map Generator Consructor
RMG::RMG() {
    RMG::obstacle_number = 100;
    RMG::show_map = false;
}

// Random number generator
int 
RMG::randomNumberGenerator(int min, int max) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> range(min, max);
    return range(generator);
}

// Check if the new obstacle can be places at the location
bool 
RMG::checkArea(Map orig, Map temp, Circle obs) {
    if ( orig.getBlackPixelNumber() + obs.getBlackPixelNumber() == temp.getBlackPixelNumber()){
        return true;
    }
    return false;
}

// Generates a random map
void 
RMG::generateMap() { 
    // load a map (room) from the /maps directory
    // room_id = 0 radomly picked room
    Map original_map;
    original_map.loadMap();

    // create a temp map and clone the original map
    Map temp_map;
    temp_map.cloneMap(original_map.getMap());

    // infilate obstacle size by robot radius to create enough room between obstacles
    auto adjusted_radius {0};

    bool location_search = true;
    for (int i=0; i < RMG::obstacle_number; i++) {
        
        auto radius = RMG::randomNumberGenerator(10, 50);

        // create an obstacle image (map)
        Circle c(radius);

        location_search = true;
        auto try_counter = 0;

        while(location_search) {
            if (try_counter == 100) {
                location_search = false;
            }
            temp_map.cloneMap(original_map.getMap());

            // randomly pick a location for the new obstacle
            Point obstacle_location =  Point(
                RMG::randomNumberGenerator(0, original_map.getMap().cols),
                RMG::randomNumberGenerator(0, original_map.getMap().rows));

            auto adjusted_radius = c.radius + c.infilation/2;
            // draw the same cirle in temp_map
            circle(temp_map.map, obstacle_location, adjusted_radius, 
                c.pixel_value, c.thickness, c.lineType, c.shift);

            // check if there is enough room for the obstacle at the location
            if (RMG::checkArea(original_map, temp_map, c)){
                circle(original_map.map, obstacle_location, c.radius,  
                    c.pixel_value, c.thickness, c.lineType, c.shift);
                location_search = false;
            }
                try_counter = try_counter + 1;
        }
    }
    
    // scale down the map size to 384,384
    original_map.setMapSize(Point(384,384));
    original_map.show();
    original_map.save();
}
