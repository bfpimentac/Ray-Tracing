#include "matrix.hpp"
#include <iostream>



int main() {
    // Cria uma matriz de translação
    Matrix translation_Matrix = Matrix::translation(1, 2, 3);

    // Cria um vetor
    vec3 vetor(1,2,3);

    // Aplica a matriz de translação ao vetor
    vec3 translated_vector = translation_Matrix * vetor;

    // Imprime o vetor transladado
    std::cout << translated_vector << std::endl;

    return 0;
}
