// Copyright (c) 2018 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

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
