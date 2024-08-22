#ifndef CAMERA_H
#define CAMERA_H

#include "rtweekend.h"

#include "hittable.h"

class camera {
public:
	double aspect_ratio = 1.0;
	int img_w = 100;

	void render(const hittable& world) {
		initialize();

		std::cout << "P3\n" << img_w << ' ' << img_h << "\n255\n";

		for (int j = 0; j < img_h; j++) {
			std::clog << "\rScanlines Remaining: " << (img_h - j) << ' ' << std::flush;
			for (int i = 0; i < img_w; i++) {
				auto pixel_center = pixel00_loc + (i * pix_du) + (j * pix_dv);
				auto ray_direction = pixel_center - center;
				ray r(center, ray_direction);

				color pix_color = ray_color(r, world);
				write_color(std::cout, pix_color);
			}
		};

		std::clog << "\rDone.                \n";

	}

private:
	int img_h;
	point3 center;
	point3 pixel00_loc;
	vec3 pix_du;
	vec3 pix_dv;

	void initialize() {
		img_h = int(img_w / aspect_ratio);
		img_h = (img_h < 1) ? 1 : img_h;

		center = point3(0, 0, 0);

		//Dimenções da Viewport
		auto focal_lenght = 1.0;
		auto viewp_h = 2.0;
		auto viewp_w = viewp_h * (double(img_w) / img_h);

		//Calcula os vetores atraves dos cantos vertical e horizontal;
		auto viewp_u = vec3(viewp_w, 0, 0);
		auto viewp_v = vec3(0, -viewp_h, 0);

		//Calcula os vetores delta de pixel pra pixel
		pix_du = viewp_u / img_w;
		pix_dv = viewp_v / img_h;

		//Calcula a posição do pixel no calto superior exquerdo ( o primeiro pixel )
		auto veiw_upper_left = center - vec3(0, 0, focal_lenght) - viewp_u / 2 - viewp_v / 2;
		pixel00_loc = veiw_upper_left + 0.5 * (pix_du + pix_dv);


	}

	color ray_color(const ray& r, const hittable& world) const {
		hit_record rec;

		if (world.hit(r, interval(0, infinity), rec)) {
			return 0.5 * (rec.normal + color(1, 1, 1));
		}

		vec3 unit_direction = unit_vector(r.direction());
		auto a = 0.5 * (unit_direction.y() + 1.0);
		return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);

	}

};


#endif