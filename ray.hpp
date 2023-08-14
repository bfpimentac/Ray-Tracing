#ifndef RAYH
#define RAYH
#include "point and vector.hpp"


class ray {
    public:
        ray() {}
        ray(const vec3& p, const vec3& v) {
            point = p;
            vector = v;
        }

        vec3 origin() const {
            return point;
        }

        vec3 direction() const {
            return vector;
        }

        vec3 point_at_parameter(float t) const {
            return point + t*vector;
        }

        vec3 point;
        vec3 vector;
};


#endif