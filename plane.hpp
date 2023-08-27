#ifndef PLANE_H
#define PLANE_H

#include <stdlib.h>
#include "hitable.hpp"
#include "ray.hpp"
#include <stdint.h>

class plane: public hitable {
    public:
        vec3 pp;
        vec3 normal;
        material *matPtr;

        //plane() {}
        plane(vec3 pointInPlane, vec3 planeNormalVec, material* planeMat)
        : pp(pointInPlane), normal(planeNormalVec), matPtr(planeMat){}   

        virtual bool hit(const ray& r, float tMin, float tMax, hit_record& rec) const;
};

bool plane::hit(const ray& r, float tMin, float tMax, hit_record& rec) const {
    double normalRayDot = dot(r.direction(), normal);
    
    if(abs(normalRayDot) < 1e-5) {
        return false;
    }

    float t = dot(pp - r.origin(), normal) / normalRayDot;

    if (t <= tMin || t >= tMax) {
        return false;
    }

    rec.t = t;
    rec.p = r.point_at_parameter(t);
    rec.normal = normal;
    rec.mat_ptr = matPtr;

    return true;     
}

#endif