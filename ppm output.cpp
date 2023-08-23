#include <iostream>
#include <random>

#include "sphere.hpp"
#include "hitablelist.hpp"
#include "camera.hpp"

#include "float.h"

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<float> dist(0.0, 1.0);

// pega um ponto aleatorio da esfera unitaria
vec3 random_in_unit_sphere() {
    vec3 p;
    do {
        p = 2.0*vec3(dist(gen), dist(gen), dist(gen)) - vec3(1, 1, 1);
    } while (p.squared_length() >= 1.0);

    return p;
}


vec3 color(const ray& r, hitable *world) {
    hit_record rec;
    if (world->hit(r, 0.0001, FLT_MAX, rec)) {
        vec3 target = rec.p + rec.normal + random_in_unit_sphere();

        return 0.5*color(ray(rec.p, target-rec.p), world); // recursao
        //return 0.5*vec3(rec.normal.x()+1, rec.normal.y()+1, rec.normal.z()+1);
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

    int const n_objects = 2;
    hitable *list[n_objects];
    list[0] = new sphere(vec3(0, 0, -1), 0.5);
    list[1] = new sphere(vec3(0, -100.5, -1), 100);
    //list[2] = new sphere(vec3(0, 0, -120), 100);
    hitable *world = new hitable_list(list, n_objects);

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

                col += color(r, world);
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