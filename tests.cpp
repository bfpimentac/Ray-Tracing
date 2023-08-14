#include <iostream>
#include "point and vector.h"

int main() {
    vec3 vetor1(1, 2, 1), vetor2(2, 1, 2);

    // operacoes entre 2 vetores
    std::cout << "operator+: " << operator+(vetor1, vetor2)<< "\n";
    std::cout << "operator-: " << operator-(vetor1, vetor2)<< "\n";
    std::cout << "operator*: " << operator*(vetor1, vetor2)<< "\n";
    std::cout << "operator/: " << operator/(vetor1, vetor2)<< "\n";
    std::cout << "dot: " << dot(vetor1, vetor2)<< "\n";
    std::cout << "cross: " << cross(vetor1, vetor2)<< "\n";

    // normaliza o vetor
    vetor1.make_unit_vector();
    std::cout << "normalizacao: " << vetor1 << "\n";
    
    vetor1.vetor[0] = 1; vetor1.vetor[1] = 2; vetor1.vetor[2] = 1;

    // operacao vetor com escalar
    std::cout << "operator*: " << operator*(vetor1, 3)<< "\n";
    std::cout << "operator*: " << operator*(3, vetor1)<< "\n";
    std::cout << "operator/: " << operator/(vetor1, 2)<< "\n";
    std::cout << "operator/: " << operator/(2, vetor1)<< "\n";

    // operacoes com atribuicao
    std::cout << "operator+: " << vetor1.operator+=(vetor2)<< "\n";
    vetor1.vetor[0] = 1; vetor1.vetor[1] = 2; vetor1.vetor[2] = 1;

    std::cout << "operator-: " << vetor1.operator-=(vetor2)<< "\n";
    vetor1.vetor[0] = 1; vetor1.vetor[1] = 2; vetor1.vetor[2] = 1;

    std::cout << "operator*: " << vetor1.operator*=(vetor2)<< "\n";
    vetor1.vetor[0] = 1; vetor1.vetor[1] = 2; vetor1.vetor[2] = 1;

    std::cout << "operator/: " << vetor1.operator/=(vetor2)<< "\n";
    vetor1.vetor[0] = 1; vetor1.vetor[1] = 2; vetor1.vetor[2] = 1;

    // normalizacao e retorna o vetor normalizado
    std::cout << "unit_vector: " << unit_vector(vetor1)<< "\n";

    // pega o vetor pelo cin
    //vec3 vetor3;
    //std::cin >> vetor3;
    //std::cout << vetor3 << '\n';

    // retorna a norma
    std::cout << vetor1.length() << "\n";

    // retorna a norma ao quadrado
    std::cout << vetor1.squared_length() << "\n";

    // acessando o index i do vetor
    std::cout << vetor1[0] << "\n";

    // retornando o vetor com coordenadas invertidas
    std::cout << -vetor1 << "\n";
}