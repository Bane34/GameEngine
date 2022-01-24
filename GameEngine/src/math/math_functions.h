#pragma once

#include <cmath>

namespace bane {
	constexpr double PI = 3.141592654f;
	
	inline double abs(const double& n) {
		return (n >= 0) ? n : -n;
	}

	inline double to_radians(const double& angle) {
		return (angle * PI) / 180;
	}

	inline double distance(double x1, double y1, double x2, double y2) {
		int x = x2 - x1;
		int y = y2 - y1;

		return sqrt(x * x + y * y);
	}
}