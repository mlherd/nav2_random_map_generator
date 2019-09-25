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

#include <opencv2/opencv.hpp>
#include <iostream>
#include "../include/rmg.hpp"
#include <string>

using namespace cv;
using namespace std;

int 
main( int argc, char** argv )
{   
    string argument_names[12] = {"Map Id",
                                "Number of Circles", 
                                "Number of Squares", 
                                "Robot size (px*0.03898)", 
                                "Map Size (x)", 
                                "Map Size (y)", 
                                "Min Circle Radius", 
                                "Max Circle Radius",
                                "Min Square Size",
                                "Max Circle Radius",
                                "Add Ramp",
                                "Show Map"
                                };

    int counter; 
    cout << "Random Map Generator" << endl; 

    if(string(argv[1]) == "h"){
        cout << "--Argument List--" << endl;
        for(int i=0; i < 12; i++) {
            cout << argument_names[i] << endl;
        }
        return 0;
    }

    else if(argc != 13) {
        cout << "Wrong Number Arguments" << endl;
        cout << "You entered " << argc << " arguments" << endl;
        return 0;
    }
    else 
    {
        cout << "Settings:" << endl;
        for(counter=0; counter < argc - 1; counter++) {
            cout << argument_names[counter] << ": " << argv[counter + 1] << endl;
        }
    }

    RMG generator (atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), 
            atoi(argv[6]), atoi(argv[7]), atoi(argv[8]), atoi(argv[9]), atoi(argv[10]), atoi(argv[11]), atoi(argv[12]));
    generator.generateMap();
    return 0;
}
