#ifndef SHPEREH
#define SPHEREH

#include "hitable.hpp"


class sphere: public hitable {
    public:
        vec3 center;
        float radius;
        material *mat_ptr;

        sphere() {}
        sphere(vec3 cen, float r, material* m_p) : center(cen), radius(r), mat_ptr(m_p) {};

        virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;
};

bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
    vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = dot(oc, r.direction());
    float c = dot(oc, oc) - radius*radius;
    float discriminant = b*b - a*c;

    if (discriminant > 0) {
        float temp = (-b - sqrt(b*b-a*c))/a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp; // t do ponto de intersecao mais proximo
            rec.p = r.point_at_parameter(rec.t); // ponto de intersecao
            rec.normal = (rec.p - center) / radius; // normal do ponto de intersecao
            return true;
        }

        // caso a primeira raiz nao satisfaca a condicao, testaremos a segunda
        temp = (-b + sqrt(b*b-a*c))/a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp; // t do ponto de intersecao mais proximo
            rec.p = r.point_at_parameter(rec.t); // ponto de intersecao
            rec.normal = (rec.p - center) / radius; // normal do ponto de intersecao
            return true;
        }
    }
    return false;
}

#endif