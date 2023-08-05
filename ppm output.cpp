#include <iostream>
#include "point and vector.h"

int main() {
    int cols = 200;
    int lines = 100;

    // estrutura de um arquivo ppm
    std::cout << "P3\n";
    std::cout << cols << " " << lines << "\n255\n";

    int i, j, ir, ig, ib;

    for (j = lines-1; j >= 0; j--) {
        for (i = 0; i < cols; i++) {
            //(r, g, b)
            vec3 col(double(i) / double(cols), double(j)/double(lines), 0.2);

            // multiplicar para ficarem no range de 0 a 255
            ir = int(255.99*col[0]);
            ig = int(255.99*col[1]);
            ib = int(255.99*col[2]);

            // printar os pixels
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}