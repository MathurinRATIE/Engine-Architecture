#pragma once
#include <iostream>
#include <string>
#include <cmath>

#pragma once
struct Vector3
{
	Vector3();
	Vector3(float pX, float pY, float pZ);

	Vector3 normalized();
	void normalize();
	float Magnitude() const;
	float dot(const Vector3& otherVector) const;
	Vector3 cross(const Vector3& otherVector) const;
	std::string ToString() const;

	void operator+=(const Vector3& right);
	void operator-=(const Vector3& right);
	void operator*=(const float value);
	void operator/=(const float value);

	friend Vector3 operator+(const Vector3& left, const Vector3& right);
	friend Vector3 operator-(const Vector3& left, const Vector3& right);
	friend Vector3 operator*(const Vector3& left, const float value);
	friend Vector3 operator*(const float value, const Vector3& right);
	friend Vector3 operator/(const Vector3& left, const float value);
	friend Vector3 operator/(const float value, const Vector3& right);

	const static Vector3 ZERO;
	const static Vector3 ONE;

	float x;
	float y;
	float z;
};
