#include "color.h"
#include "vec3.h"


#include <iostream>

using namespace std;

int main() {
    int img_w = 256;
    int img_h = 256;

    cout << "P3\n" << img_w << ' ' << img_h << "\n255\n";

    for (int j = 0; j < img_h; j++) {
        clog << "\rScanlines Remaining: " << (img_h - j) << ' ' << flush;
        for (int i = 0; i < img_w; i++) {
            auto pix_color =  color(double(0)   /(img_w-1), 
                                    double(0) /(img_h-1), 
                                    double(0)   /(img_h-1));


            write_color(std::cout, pix_color);
        }
    };

    clog << "\rDone.                \n";

    return 0;
}
