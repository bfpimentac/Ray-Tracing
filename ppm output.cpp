#include <iostream>
// #include <random>

#include "sphere.hpp"
#include "material.hpp"
#include "camera.hpp"

#include "float.h"

// std::random_device rd;
// std::mt19937 gen(rd());
// std::uniform_real_distribution<float> dist(0.0, 1.0);


vec3 color(const ray& r, hitable *world, int depth) {
    hit_record rec;
    if (world->hit(r, 0.001, FLT_MAX, rec)) {
        ray scattered;
        vec3 attenuation;
        if (depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
            return attenuation*color(scattered, world, depth+1);
        } else {
            return vec3(0, 0, 0);
        }

    } else {
        // normaliza o vetor diretor do raio
        vec3 unit_direction = unit_vector(r.direction());
        float t = 0.5*(unit_direction.y() + 1.0);
        return (1.0-t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
    }
}

int main() {
    int nx = 600;
    int ny = 300;
    int ns = 300; // numero de amostras p anti-aliasing

    // estrutura de um arquivo ppm
    std::cout << "P3\n";
    std::cout << nx << " " << ny << "\n255\n";

    //int const n_objects = 4;
    hitable *list[4];
    list[0] = new sphere(vec3(0, 0, -1), 0.5, new lambertian(vec3(0.8, 0.3, 0.3)));
    list[1] = new sphere(vec3(0, -100.5, -1), 100, new lambertian(vec3(0.8, 0.8, 0.0)));
    list[2] = new sphere(vec3(1, 0, -1), 0.5, new metal(vec3(0.8, 0.6, 0.2), 0.3));
    list[3] = new sphere(vec3(-1, 0, -1), 0.5, new metal(vec3(0.8, 0.8, 0.8), 1.0));
    hitable *world = new hitable_list(list, 4);

    int i, j, s, ir, ig, ib;
    float u, v;
    camera cam;

    for (j = ny-1; j >= 0; j--) {
        for (i = 0; i < nx; i++) {
            vec3 col(0, 0, 0);

            for (s = 0; s < ns; s++) {
                // u e v sao as coordenadas do pixel
                u = float(i + dist(gen)) / float(nx); // u e v variam de 0 a 1
                v = float(j + dist(gen)) / float(ny);

                // raios, origin e um ponto e lower_left_corner + u*horizontal + v*vertical e o vetor + offset
                ray r = cam.get_ray(u, v);

                //(r, g, b)
                vec3 p = r.point_at_parameter(2.0);

                col += color(r, world, 0);
            }

            col /= float(ns); // media das cores
            
            col = vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2])); // gamma correction
            // multiplicar para ficarem no range de 0 a 255
            ir = int(255.99*col[0]);
            ig = int(255.99*col[1]);
            ib = int(255.99*col[2]);

            // printar os pixels
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}