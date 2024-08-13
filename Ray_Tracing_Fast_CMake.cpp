#include "color.h"
#include "ray.h"
#include "vec3.h"


#include <iostream>

using namespace std;

// use type BR.txt|cmd

double hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = center - r.origin();
    auto a = r.direction().length_squered();
    auto h = dot(r.direction(), oc);
    auto c = oc.length_squered() - radius * radius;
    auto discriminant = h*h - a * c;
    

    if (discriminant < 0) {
        return -1.0;
    }
    else {
        return(h - std::sqrt(discriminant)) / a;
    }
}

color ray_color(const ray& r) {
    auto t = hit_sphere(point3(0, 0, -1), 0.5, r);
    if (t > 0.0) {
        vec3 N = unit_vector(r.at(t) - vec3(0, 0, -1));
        return 0.5 * color(N.x() + 1, N.y() + 1, N.z() + 1);
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main() {
    auto aspect_ratio = 14/16.0;
    int img_w = 350;

    //Calcula img h
    int img_h = int(img_w / aspect_ratio);
    img_h = (img_h < 1) ? 1 : img_h;


    //Camera

    auto focal_length = 1.0; // A distancia entre a camera e o plano de progeção
    auto veiwp_h = 2.0;
    auto veiwp_w = veiwp_h * (double(img_w) / img_h);
    auto camera_center = point3(0, 0, 0);

    // vetores horizontais e verticais
    auto veiwp_u = vec3(veiwp_w, 0, 0);
    auto veiwp_v = vec3(0, -veiwp_h, 0);

    //-------------
    auto pix_du = veiwp_u / img_w;
    auto pix_dv = veiwp_v / img_h;


    //----------------
    auto veiwp_upper_left = camera_center - vec3(0, 0, focal_length) - veiwp_u / 2 - veiwp_v / 2;
    auto pixel00_loc = veiwp_upper_left + 0.5 * (pix_du + pix_dv);

    cout << "P3\n" << img_w << ' ' << img_h << "\n255\n";

    for (int j = 0; j < img_h; j++) {
        clog << "\rScanlines Remaining: " << (img_h - j) << ' ' << flush;
        for (int i = 0; i < img_w; i++) {
            auto pixel_center = pixel00_loc + (i * pix_du) + (j * pix_dv);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pix_color = ray_color(r);
            write_color(std::cout, pix_color);
        }
    };

    clog << "\rDone.                \n";

    return 0;
}
