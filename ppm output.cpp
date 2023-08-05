#include <iostream>

int main() {
    int cols = 200;
    int lines = 100;

    // estrutura de um arquivo ppm
    std::cout << "P3\n";
    std::cout << cols << " " << lines << "\n255\n";

    int i, j, ir, ig, ib;
    double r, g, b;

    for (j = lines-1; j >= 0; j--) {
        for (i = 0; i < cols; i++) {
            // r, g, b variam de 0 ate 1, por convencao
            r = double(i) / double(cols);
            g = double(j)/double(lines);
            b = 0.2;

            // multiplicar para ficarem no range de 0 a 255
            ir = int(255.99*r);
            ig = int(255.99*g);
            ib = int(255.99*b);

            // printar os pixels
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}