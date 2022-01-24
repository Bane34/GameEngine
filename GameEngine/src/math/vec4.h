#pragma once

#include <iostream>

namespace bane {
	struct vec4 {
		float x, y, z, w;

		vec4();
		vec4(const float& x, const float& y,
			 const float& z, const float& w);

		vec4& add(const vec4& other);
		vec4& substract(const vec4& other);
		vec4& multiply(const vec4& other);
		vec4& divide(const vec4& other);

		vec4& add(float n);
		vec4& substract(float n);
		vec4& multiply(float n);
		vec4& divide(float n);

		float dot(const vec4& other);

		friend std::ostream& operator<<(std::ostream& stream, const vec4& other);
	};

	using v4 = vec4;
}