#include "vec4.h"

namespace bane {
	vec4::vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }

	vec4::vec4(const float& x, const float& y,
			   const float& z, const float& w ) : x(x), y(y), z(z), w(w) { }

	vec4& vec4::add(const vec4& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;

		return *this;
	}

	vec4& vec4::substract(const vec4& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;

		return *this;
	}

	vec4& vec4::multiply(const vec4& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;

		return *this;
	}

	vec4& vec4::divide(const vec4& other) {
		if (other.x == 0.0f || other.y == 0.0f || other.z == 0.0f || other.w == 0.0f) {
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			w = 0.0f;
		}
		else {
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;
		}

		return *this;
	}

	vec4& vec4::add(float n) {
		x += n;
		y += n;
		z += n;
		w += n;

		return *this;
	}

	vec4& vec4::substract(float n) {
		x -= n;
		y -= n;
		z -= n;
		w -= n;

		return *this;
	}

	vec4& vec4::multiply(float n) {
		x *= n;
		y *= n;
		z *= n;
		w *= n;

		return *this;
	}
}