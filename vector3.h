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
	float dot(const Vector3& pOtherVector) const;
	Vector3 cross(const Vector3& pOtherVector) const;
	std::string ToString() const;

	void operator+=(const Vector3& pRight);
	void operator-=(const Vector3& pRight);
	void operator*=(const float pValue);
	void operator/=(const float pValue);

	friend Vector3 operator+(const Vector3& pLeft, const Vector3& pRight);
	friend Vector3 operator-(const Vector3& pLeft, const Vector3& pRight);
	friend Vector3 operator*(const Vector3& pLeft, const float pValue);
	friend Vector3 operator*(const float pValue, const Vector3& pRight);
	friend Vector3 operator/(const Vector3& pLeft, const float pValue);
	friend Vector3 operator/(const float pValue, const Vector3& pRight);

	const static Vector3 ZERO;
	const static Vector3 ONE;

	float x;
	float y;
	float z;
};
