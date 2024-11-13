#pragma once
#include <iostream>
#include <string>
#include <cmath>

#pragma once
struct Vector4
{
	Vector4();
	Vector4(float pX, float pY, float pZ, float pW);

	Vector4 normalized();
	void normalize();
	float Magnitude() const;
	std::string ToString() const;

	void operator+=(const Vector4& right);
	void operator-=(const Vector4& right);
	void operator*=(const float value);
	void operator/=(const float value);

	friend Vector4 operator+(const Vector4& left, const Vector4& right);
	friend Vector4 operator-(const Vector4& left, const Vector4& right);
	friend Vector4 operator*(const Vector4& left, const float value);
	friend Vector4 operator*(const float value, const Vector4& right);
	friend Vector4 operator/(const Vector4& left, const float value);
	friend Vector4 operator/(const float value, const Vector4& right);

	const static Vector4 ZERO;
	const static Vector4 ONE;

	float x;
	float y;
	float z;
	float w;
};

using Color = Vector4;