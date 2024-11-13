#include "vector4.h"

const Vector4 Vector4::ZERO{ 0.0f, 0.0f, 0.0f, 0.0f };
const Vector4 Vector4::ONE{ 1.0f, 1.0f, 1.0f, 1.0f };

Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vector4::Vector4(float pX, float pY, float pZ, float pW)
{
	x = pX;
	y = pY;
	z = pZ;
	w = pW;
}

Vector4 Vector4::normalized()
{
	float length = Magnitude();
	if (length == 0)
	{
		return ZERO;
	}
	
	return (*this) / Magnitude();
}

void Vector4::normalize()
{
	float length = Magnitude();
	if (length == 0)
	{
		return;
	}

	(*this) /= Magnitude();
}

float Vector4::Magnitude() const
{
	return sqrt(x*x + y*y + z*z + w*w);
}

std::string Vector4::ToString() const
{
	return "( " + std::to_string(x) + " , " + std::to_string(y) + " , " + std::to_string(z) + " , " + std::to_string(w) + " )";
}

void Vector4::operator+=(const Vector4& right)
{
    x += right.x;
    y += right.y;
    z += right.z;
    w += right.w;
}

void Vector4::operator-=(const Vector4& right)
{
    x -= right.x;
    y -= right.y;
    z -= right.z;
    w -= right.w;
}

void Vector4::operator*=(const float value)
{
    x *= value;
    y *= value;
    z *= value;
    w *= value;
}

void Vector4::operator/=(const float value)
{
    x /= value;
    y /= value;
    z /= value;
    w /= value;
}

Vector4 operator+(const Vector4& left, const Vector4& right)
{
    return Vector4(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
}

Vector4 operator-(const Vector4& left, const Vector4& right)
{
    return Vector4(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
}

Vector4 operator*(const Vector4& left, const float value)
{
    return Vector4(left.x * value, left.y * value, left.z * value, left.w * value);
}

Vector4 operator*(const float value, const Vector4& right)
{
    return Vector4(value * right.x, value * right.y, value * right.z, value * right.w);
}

Vector4 operator/(const Vector4& left, const float value)
{
    if (value != 0.0f)
    {
        return Vector4(left.x / value, left.y / value, left.z / value, left.w / value);
    }
    else
    {
        throw std::invalid_argument("Cannot divide by zero.");
    }
}

Vector4 operator/(const float value, const Vector4& right)
{
    if (right.x != 0.0f && right.y != 0.0f && right.z != 0.0f && right.w != 0.0f)
    {
        return Vector4(value / right.x, value / right.y, value / right.z, value / right.w);
    }
    else
    {
        throw std::invalid_argument("Cannot divide by zero.");
    }
}