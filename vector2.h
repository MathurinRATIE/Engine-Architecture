#pragma once
#include <iostream>
#include <cmath>

#pragma once
struct Vector2
{
	Vector2(float newX = 0.0f, float newY = 0.0f);

	Vector2 normalized();
	void normalize();
	float GetMagnitude() const;
	float dot(Vector2& otherVector) const;
	float cross(Vector2& otherVector) const;

	inline void operator+=(Vector2& right);
	inline void operator-=(Vector2& right);
	inline void operator*=(float value);
	inline void operator/=(float value);

	const static Vector2 ZERO;
	const static Vector2 ONE;

	float x;
	float y;
};

