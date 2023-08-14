#include <iostream>
#include "sphere.hpp"
#include "hitablelist.hpp"
#include "float.h"

vec3 color(const ray& r, hitable *world) {
    hit_record rec;
    if (world->hit(r, 0.0, FLT_MAX, rec)) {
        return 0.5*vec3(rec.normal.x()+1, rec.normal.y()+1, rec.normal.z()+1);

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

    // estrutura de um arquivo ppm
    std::cout << "P3\n";
    std::cout << nx << " " << ny << "\n255\n";
    
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);

    hitable *list[2];
    list[0] = new sphere(vec3(0, 0, -1), 0.5);
    list[1] = new sphere(vec3(0, -100.5, -1), 100);
    hitable *world = new hitable_list(list, 2);

    int i, j, ir, ig, ib;
    float u, v;

    for (j = ny-1; j >= 0; j--) {
        for (i = 0; i < nx; i++) {
            // u e v sao as coordenadas do pixel
            u = float(i) / float(nx);
            v = float(j) / float(ny);

            // raios, origin e um ponto e lower_left_corner + u*horizontal + v*vertical e o vetor + offset
            ray r(origin, lower_left_corner + u*horizontal + v*vertical);

            //(r, g, b)
            vec3 p = r.point_at_parameter(2.0);
            vec3 col = color(r, world);

            // multiplicar para ficarem no range de 0 a 255
            ir = int(255.99*col[0]);
            ig = int(255.99*col[1]);
            ib = int(255.99*col[2]);

            // printar os pixels
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}