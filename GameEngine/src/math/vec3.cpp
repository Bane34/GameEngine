#include "vec3.h"

namespace bane {
	vec3::vec3() : x(0.0f), y(0.0f), z(0.0f) {}
	
	vec3::vec3(const float& x, const float& y, const float& z) : x(x), y(y), z(z) {}

	vec3& vec3::add(const vec3& other) {
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	vec3& vec3::substract(const vec3& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	vec3& vec3::multiply(const vec3& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}

	vec3& vec3::divide(const vec3& other) {
		if (other.x == 0.0f || other.y == 0.0f || other.z == 0.0f) {
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}
		else {
			x /= other.x;
			y /= other.y;
			z /= other.z;
		}

		return *this;
	}

	vec3& vec3::add(float n) {
		x += n;
		y += n;
		z += n;

		return *this;
	}

	vec3& vec3::substract(float n) {
		x -= n;
		y -= n;
		z -= n;

		return *this;
	}

	vec3& vec3::multiply(float n) {
		x *= n;
		y *= n;
		z *= n;

		return *this;
	}

	vec3& vec3::divide(float n) {
		if (n == 0.0f) {
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}
		else {
			x /= n;
			y /= n;
			z /= n;
		}

		return *this;
	}

	float vec3::magnitude() const {
		return sqrt(x * x + y * y + z * z);
	}

	vec3 vec3::normalize() const {
		float magnitude = this->magnitude();
		return vec3(x / magnitude, y / magnitude, z / magnitude);
	}

	float vec3::dot(const vec3& other) const {
		return (x * other.x + y * other.y + z * other.z);
	}

	std::ostream& operator<<(std::ostream& stream, const vec3& v) {
		std::cout << "(" << v.x << ", " << v.y << ", " << v.z << ")\n";

		return stream;
	}
}