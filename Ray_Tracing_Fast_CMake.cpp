
#include "rtweekend.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"


using namespace std;

// use type BR.txt|cmd


int main() {
    hittable_list world;

    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));
    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));

    camera cam;

    cam.aspect_ratio = 14.6 / 16;
    cam.img_w = 350;

    cam.render(world);

    return 0;
}
