
// Includes from the standard library
#include <limits> // the limits header
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <exception>

// Include for Google logging library Horray
#include <glog/logging.h>

// Include for SYCL - the front-end of DPC++
#include <CL/sycl.hpp>

// Includes for vector/matrix/geometric operations
#include "geometry.h"

using namespace std;

// ********************************************************************************
// The render function is at the heart of the work that the raytracer does
// ********************************************************************************

void render() {
    const int width    = 1024;
    const int height   = 768;
    std::vector<Vec3f> framebuffer(width*height);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    // cycle thru the height and width of the framebuffer, fill with stuff
    for (size_t j = 0; j<height; j++) {
        for (size_t i = 0; i<width; i++) {
            framebuffer[i+j*width] = Vec3f(j/float(height),i/float(width), 0);
        }
    }
    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Elapsed time:  " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[msecs]" << std::endl;

    std::ofstream ofs; // save the framebuffer to file
    ofs.open("imgs/lesson1.ppm");
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (size_t i = 0; i < height*width; ++i) {
        for (size_t j = 0; j<3; j++) {
            ofs << (char)(255 * std::max(0.f, std::min(1.f, framebuffer[i][j])));
        }
    }
    ofs.close();
}

// ********************************************************************************
// The main function is the entry-point for the program
// ********************************************************************************

int main(int argc, char** argv) try {
    
    // Initialize Google's logging library.
    google::InitGoogleLogging(argv[0]);
        
    render();
    return 0;
} catch( exception &e ) {
    std::cerr << "Exception thrown:  " << e.what() << std::endl;
    LOG(INFO) << "Exception thrown:  " << e.what();
    return 1;
}
