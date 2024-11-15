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

	void operator+=(const Vector4& pRight);
	void operator-=(const Vector4& pRight);
	void operator*=(const float pValue);
	void operator/=(const float pValue);

	friend Vector4 operator+(const Vector4& pLeft, const Vector4& pRight);
	friend Vector4 operator-(const Vector4& pLeft, const Vector4& pRight);
	friend Vector4 operator*(const Vector4& pLeft, const float pValue);
	friend Vector4 operator*(const float pValue, const Vector4& pRight);
	friend Vector4 operator/(const Vector4& pLeft, const float pValue);
	friend Vector4 operator/(const float pValue, const Vector4& pRight);

	const static Vector4 ZERO;
	const static Vector4 ONE;

	float x;
	float y;
	float z;
	float w;
};

using Color = Vector4;