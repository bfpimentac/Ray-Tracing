#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3 {
public:
    // constructor para quando não é dado as coordenadas
    vec3() {}

    // constructor para quando é dada as coordenadas
    vec3(double x, double y, double z) {
        vetor[0] = x; 
        vetor[1] = y; 
        vetor[2] = z;
    }


    // metodos para retornar as coordenadas do vetor
    inline double x() const {return vetor[0];}
    inline double y() const {return vetor[1];}
    inline double z() const {return vetor[2];}
    inline double r() const {return vetor[0];}
    inline double g() const {return vetor[1];}
    inline double b() const {return vetor[2];}


    // retorna uma referencia constante para o vetor
    inline const vec3& operator+() const {return *this;}

    // retorna o vetor com coordenadas invertidas
    inline vec3 operator-() const {
        return vec3(-vetor[0], -vetor[1], -vetor[2]);
    }

    // acessa o index "i" do vetor e retorna uma cópia
    inline double operator[](int i) const {
        return vetor[i];
    }

    // acessa o index "i" do vetor e retorna uma referencia
    inline double& operator[](int i) {
        return vetor[i];
    }


    // operacoes 
    inline vec3& operator+=(const vec3 &v2);
    inline vec3& operator-=(const vec3 &v2);
    inline vec3& operator*=(const vec3 &v2);
    inline vec3& operator/=(const vec3 &v2);
    inline vec3& operator*=(const double t);
    inline vec3& operator/=(const double t);

    // retorna a norma do vetor
    inline double length() const {
        return sqrt(vetor[0]*vetor[0] + vetor[1]*vetor[1] + vetor[2]*vetor[2]);
    }

    // retorna o quadrado da norma
    inline double squared_length() const {
        return vetor[0]*vetor[0] + vetor[1]*vetor[1] + vetor[2]*vetor[2];
    }

    // normaliza o vetor
    inline void make_unit_vector();

    double vetor[3];
};

inline std::istream& operator>>(std::istream &is, vec3 &t) {
    is >> t.vetor[0] >> t.vetor[1] >> t.vetor[2];
    return is;
}

inline std::ostream& operator<<(std::ostream &os, const vec3 &t) {
    os << t.vetor[0] << " " << t.vetor[1] << " " << t.vetor[2];
    return os;
}

inline void vec3::make_unit_vector() {
    double k = (1.0 / sqrt(vetor[0]*vetor[0] + vetor[1]*vetor[1] + vetor[2]*vetor[2]));
    vetor[0] *= k;
    vetor[1] *= k;
    vetor[2] *= k;
}

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.vetor[0]+v2.vetor[0], v1.vetor[1]+v2.vetor[1], v1.vetor[3]+v2.vetor[3]);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.vetor[0]-v2.vetor[0], v1.vetor[1]-v2.vetor[1], v1.vetor[3]-v2.vetor[3]);
}

inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.vetor[0]*v2.vetor[0], v1.vetor[1]*v2.vetor[1], v1.vetor[3]*v2.vetor[3]);
}

inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.vetor[0]/v2.vetor[0], v1.vetor[1]/v2.vetor[1], v1.vetor[3]/v2.vetor[3]);
}

inline vec3 operator*(const vec3 &v, double t) {
    return vec3(v.vetor[0]*t, v.vetor[1]*t, v.vetor[3]*t);
}

inline vec3 operator*(double t, const vec3 &v) {
    return vec3(v.vetor[0]*t, v.vetor[1]*t, v.vetor[3]*t);
}

inline vec3 operator/(double t, const vec3 &v) {
    return vec3(v.vetor[0]/t, v.vetor[1]/t, v.vetor[3]/t);
}

inline vec3 operator/(const vec3 &v, double t) {
    return vec3(v.vetor[0]/t, v.vetor[1]/t, v.vetor[3]/t);
}

inline double dot(const vec3 &v1, const vec3 &v2) {
    return v1.vetor[0]*v2.vetor[0] + v1.vetor[1]*v2.vetor[1] + v1.vetor[3]*v2.vetor[3];
}

inline vec3 cross(const vec3 &v1, const vec3 &v2) {
    return vec3((v1.vetor[1]*v2.vetor[2] - v1.vetor[2]*v2.vetor[1]), (-(v1.vetor[0]*v2.vetor[2] - v1.vetor[2]*v2.vetor[0])), (v1.vetor[0]*v2.vetor[1] - v1.vetor[1]*v2.vetor[0]));
}

inline vec3& vec3::operator+=(const vec3 &v) {
    vetor[0] += v.vetor[0];
    vetor[1] += v.vetor[1];
    vetor[2] += v.vetor[2];
    return *this;
}

inline vec3& vec3::operator*=(const vec3 &v) {
    vetor[0] *= v.vetor[0];
    vetor[1] *= v.vetor[1];
    vetor[2] *= v.vetor[2];
    return *this;
}

inline vec3& vec3::operator-=(const vec3 &v) {
    vetor[0] -= v.vetor[0];
    vetor[1] -= v.vetor[1];
    vetor[2] -= v.vetor[2];
    return *this;
}

inline vec3& vec3::operator/=(const vec3 &v) {
    vetor[0] /= v.vetor[0];
    vetor[1] /= v.vetor[1];
    vetor[2] /= v.vetor[2];
    return *this;
}

inline vec3& vec3::operator*=(const double t) {
    vetor[0] *= t;
    vetor[1] *= t;
    vetor[2] *= t;
    return *this;
}

inline vec3& vec3::operator/=(const double t) {
    vetor[0] /= t;
    vetor[1] /= t;
    vetor[2] /= t;
    return *this;
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}