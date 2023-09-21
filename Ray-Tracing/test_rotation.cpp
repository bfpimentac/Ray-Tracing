#include "matrix.hpp"
#include <cmath>

// oi bea bea 😎

int main() {
    // Cria um vetor
    vec3 vetor(1, 2, 3);

    // Cria uma matriz de rotação em torno do eixo x
    double angle = M_PI / 2; // 90 graus em radianos
    Matrix rotation_Matrix = Matrix::rotation_x(angle);

    // Aplica a matriz de rotação ao vetor
    vec3 rotated_vector = rotation_Matrix * vetor;

    // Imprime o vetor rotacionado
    std::cout << rotated_vector << std::endl;

    return 0;
}
