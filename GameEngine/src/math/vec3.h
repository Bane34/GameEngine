#pragma once

#include <iostream>
#include <cmath>

namespace bane {
	struct vec3 {
		float x, y, z;

		vec3();
		vec3(const float& x, const float& y, const float& z);
		   
		vec3& add(const vec3& other);
		vec3& substract(const vec3& other);
		vec3& multiply(const vec3& other);
		vec3& divide(const vec3& other);
		   
		vec3& add(float n);
		vec3& substract(float n);
		vec3& multiply(float n);
		vec3& divide(float n);

		float magnitude() const;
		vec3  normalize() const;
		float dot(const vec3& other) const;

		friend std::ostream& operator<<(std::ostream& stream, const vec3& v);
	};

	using v3 = vec3;
}