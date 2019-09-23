#ifndef circle_hpp
#define circle_hpp

#include "obstacle.hpp"

class Circle : public Obstacle {
    public:
        // member variables
        int radius;
        int max_radius;
        int min_radius;

        // member functions
        Circle();
        Circle(int r, int max, int min);
        void setMaxRadius(int);
        void setMinRadius(int);
        void setRadius(int);
};

#endif // circle_hpp
