#include <iostream>
#include <cmath>

#pragma once
class Vector2
{
public :
	Vector2(float newX = 0.0f, float newY = 0.0f);

	Vector2 normalize() const;
	float dot(const Vector2& other) const;
	float cross(const Vector2& other) const;

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator*(float scalar) const;
	Vector2 operator/(float scalar) const;

	static const Vector2 ZERO;
	static const Vector2 ONE;

	float x;
	float y;
};

