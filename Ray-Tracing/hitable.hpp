#ifndef HITABLEH
#define HITABLEH

#include "ray.hpp"

class material;


struct hit_record {
    float t; // t do ponto de intersecao mais proximo
    vec3 p; // ponto de intersecao
    vec3 normal; // normal do ponto de intersecao
    material *mat_ptr; // ponteiro para o material do objeto
};

class hitable {
    public:
        // verifica se o raio r atinge o objeto
        virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;

};

#endif