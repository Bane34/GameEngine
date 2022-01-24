#include "vec2.h"

namespace bane {
	vec2::vec2() : x(0.0f), y(0.0f) {}

	vec2::vec2(const float& x, const float& y) : x(x), y(y) { }

	vec2& vec2::add(const vec2& other) {
		x += other.x;
		y += other.y;

		return *this;
	}

	vec2& vec2::substract(const vec2& other) {
		x -= other.x;
		y -= other.y;

		return *this;
	}

	vec2& vec2::multiply(const vec2& other) {
		x *= other.x;
		y *= other.y;

		return *this;
	}

	vec2& vec2::divide(const vec2& other) {
		if (other.x == 0.0f || other.y == 0.0f) {
			x = 0.0f;
			y = 0.0f;
		}
		else {
			x /= other.x;
			y /= other.y;
		}

		return *this;
	}

	vec2& vec2::add(float n) {
		x += n;
		y += n;

		return *this;
	}

	vec2& vec2::substract(float n) {
		x -= n;
		y -= n;

		return *this;
	}

	vec2& vec2::multiply(float n) {
		x *= n;
		y *= n;

		return *this;
	}

	vec2& vec2::divide(float n) {
		if (n == 0) {
			x = 0.0f;
			y = 0.0f;
		}
		else {
			x /= n;
			y /= n;
		}

		return *this;
	}

	float vec2::magnitude() const {
		return sqrt(x * x + y * y);
	}

	vec2 vec2::normalize() const {
		float magnitude = this->magnitude();
		return vec2(x / magnitude, y / magnitude);
	}

	float vec2::dot(const vec2& other) const {
		return (x * other.x + y * other.y);
	}

	std::ostream& operator<<(std::ostream& stream, const vec2& v){
		stream << "(" << v.x << ", " << v.y << ")\n";

		return stream;
	}
}