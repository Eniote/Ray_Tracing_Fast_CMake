#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

/*
esta sendo usado double mas float funciona do mesmo jeito
a escolha é uma troca enter memoria ou precisão e isso se
torna importante quando queremos usar hardware com recursos
limitados como a gpu

nota pessoal: acho que minha GPU nao aceita double
*/

class vec3 {
public:
	double e[3];

	vec3() : e{ 0, 0, 0 } {}
	vec3(double e0, double e1, double e2) : e{ e0, e1, e2 } {}
	vec3(double e0) : e{ e0, e0, e0 } {}
	vec3(const vec3& v) : e{ v.e[0], v.e[1], v.e[2] } {} //copia um vetor

	double x() const { return e[0]; } //o cost depois da assinatura da função
	double y() const { return e[1]; } //indica que o metodo nao pode auterar
	double z() const { return e[2]; } // o obijeto de onde esta sendo chamado

	vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
	double operator[](int i) const { return e[i]; }
	double& operator[](int i) { return e[i]; }

	vec3& operator+=(const vec3& v) {
		e[0] += v.e[0];
		e[1] += v.e[1];
		e[2] += v.e[2];

		return *this;
	}

	vec3& operator*=(const vec3& v) {
		e[0] *= v.e[0];
		e[1] *= v.e[1];
		e[2] *= v.e[2];

		return *this;
	}

	vec3& operator/=(double t) {
		return *this *= 1 / t;
	}

	double length() const {
		return std::sqrt(length_squered());
	}

private:
	double length_squered() const {
		return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
	}
};

// point3 é um apelido de vec3
using point3 = vec3;

// utilidades
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) {
	return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
	return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
	return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3& v) {
	return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) {
	return t * v; // isso funciona porque ja existe uma operação para t*v definida anteriormente
}

inline vec3 operator/(const vec3& v, double t) {
	return (1 / t) * v;
}

inline double dot(const vec3& u, const vec3& v) {
	return u.e[0] * v.e[0]
		+ u.e[1] * v.e[1]
		+ u.e[2] * v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
	return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
				u.e[2] * v.e[0] - u.e[0] * v.e[2],
				u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v) {
	return v / v.length();
}

#endif