#ifndef square_hpp
#define square_hpp

#include "obstacle.hpp"

class Square : public Obstacle {
    public:
        // member variables
        int size;
        int max_size;
        int min_size;

        // member functions
        Square();
        Square(int size, int min, int max);
        void setMaxSize(int);
        void setMinSize(int);
        void setSize(int);
};

#endif // square_hpp
