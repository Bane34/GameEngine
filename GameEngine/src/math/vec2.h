#pragma once

#include <iostream>
#include <cmath>

namespace bane {
	struct vec2 {
		float x, y;

		vec2();
		vec2(const float& x, const float& y);

		vec2& add(const vec2& other);
		vec2& substract(const vec2& other);
		vec2& multiply(const vec2& other);
		vec2& divide(const vec2& other);

		vec2& add(float n);
		vec2& substract(float n);
		vec2& multiply(float n);
		vec2& divide(float n);

		float magnitude() const;
		vec2 normalize() const;
		float dot(const vec2& other) const;

		friend std::ostream& operator<<(std::ostream& stream, const vec2& v);
	};

	using v2 = vec2;
}