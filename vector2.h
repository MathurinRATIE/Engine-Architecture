#pragma once
#include <iostream>
#include <string>
#include <cmath>

#pragma once
struct Vector2
{
	Vector2();
	Vector2(float pX, float pY);

	Vector2 normalized();
	void normalize();
	float Magnitude() const;
	float dot(const Vector2& otherVector) const;
	float cross(const Vector2& otherVector) const;
	std::string ToString() const;

	void operator+=(const Vector2& right);
	void operator-=(const Vector2& right);
	void operator*=(const float value);
	void operator/=(const float value);

	friend Vector2 operator+(const Vector2& left, const Vector2& right);
	friend Vector2 operator-(const Vector2& left, const Vector2& right);
	friend Vector2 operator*(const Vector2& left, const float value);
	friend Vector2 operator*(const float value, const Vector2& right);
	friend Vector2 operator/(const Vector2& left, const float value);
	friend Vector2 operator/(const float value, const Vector2& right);

	const static Vector2 ZERO;
	const static Vector2 ONE;

	float x;
	float y;
};
