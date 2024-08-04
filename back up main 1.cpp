/*#include "color.h"
#include "vec3.h"


#include <iostream>

using namespace std;

int main() {
    const int img_w = 256;
    const int img_h = 256;

    color** img_buffer = (color**) malloc(sizeof(color*)*img_w);

    for (int i = 0; i < img_h; i++) {
        img_buffer[i] = (color*)malloc(sizeof(color) * img_h);
        
    }

    for(int i = 0; i < img_w; i++){ 
        for (int j = 0; j < img_h; j++) {
            img_buffer[i][j] = color();
        } 
    }

    img_buffer[100][100] = color(200);

    cout << "P3\n" << img_w << ' ' << img_h << "\n255\n";

    for (int j = 0; j < img_h; j++) {
        clog << "\rScanlines Remaining: " << (img_h - j) << ' ' << flush;
        for (int i = 0; i < img_w; i++) {


            write_color(std::cout, img_buffer[j][i]);
        }
    };

    clog << "\rDone.                \n";


    for (int i = 0; i < img_h; i++) {
        free(img_buffer[i]);
    }

    free(img_buffer);
    return 0;
}
*/