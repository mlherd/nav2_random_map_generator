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

#include "../include/ramp.hpp"

using namespace cv;

Ramp::Ramp() {
    Ramp::length = 1;
    Ramp::width = 1;

    // Set the obstacle frame size
    Ramp::setFrameSize(Point (Ramp::length,  Ramp::width));
    Ramp::frame = Ramp::frame*0;
    Ramp::createGradientFrame(Point (Ramp::length,  Ramp::width));
}

Ramp::Ramp(int l, int w){
    Ramp::length = l;
    Ramp::width = w;

    // Set the obstacle frame size
    Ramp::setFrameSize(Point (Ramp::length,  Ramp::width));
    Ramp::frame = Mat::zeros(frame_size, CV_8UC1);
    Ramp::createGradientFrame(Point (Ramp::length,  Ramp::width));
    
    float gs {255.0};
    float f {0.0};
    // Draw gradient in the frame
    for (int r = 0; r < (2*Ramp::gradient_frame.cols)/5; r++) {
        f = (float)255/ ((2*(float)Ramp::gradient_frame.cols)/5);
        gs = gs - f;
        Ramp::gradient_frame.col(r).setTo((int)gs);
    }
    for (int r = (2*Ramp::gradient_frame.cols/5); r < (3*Ramp::gradient_frame.cols)/5; r++) {
        Ramp::gradient_frame.col(r).setTo(0);
    }
    gs = 0;
    for (int r = (3*Ramp::gradient_frame.cols)/5; r < Ramp::gradient_frame.cols; r++) {
        f = (float)255/ ((2*(float)Ramp::gradient_frame.cols)/5);
        gs = gs + f;
        Ramp::gradient_frame.col(r).setTo((int)gs);
    }
}

void
Ramp::createGradientFrame(Point size) {
    Ramp::gradient_frame = Mat::zeros(size, CV_8UC1);
}