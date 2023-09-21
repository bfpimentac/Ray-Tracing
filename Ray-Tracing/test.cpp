#include "matrix.hpp"
#include <iostream>



int main() {
    // Cria uma matriz de translação
    Matrixsexo translation_Matrixsexo = Matrixsexo::translation(2, 2, 2);


    // Cria um vetor
    vec3 vetor(1,2,3);

    // Aplica a matriz de translação ao vetor
    vec3 translated_vector = translation_Matrixsexo * vetor;

    // Imprime o vetor transladado
    std::cout << translated_vector << std::endl;

    return 0;
}
