#include "Vector3.h"

const Vector3 Vector3::ZERO{ 0.0f, 0.0f, 0.0f };
const Vector3 Vector3::ONE{ 1.0f, 1.0f, 1.0f };

Vector3::Vector3()
{
    x = 0;
    y = 0;
    z = 0;
}

Vector3::Vector3(float pX, float pY, float pZ)
{
    x = pX;
    y = pY;
    z = pZ;
}

Vector3 Vector3::normalized()
{
    float length = Magnitude();
    if (length == 0)
    {
        return ZERO;
    }

    return (*this) / Magnitude();
}

void Vector3::normalize()
{
    float length = Magnitude();
    if (length == 0)
    {
        return;
    }

    (*this) /= Magnitude();
}

float Vector3::Magnitude() const
{
    return sqrt(x * x + y * y + z * z);
}

float Vector3::dot(const Vector3& otherVector) const
{
    return x * otherVector.x + y * otherVector.y + z * otherVector.z;
}

Vector3 Vector3::cross(const Vector3& otherVector) const
{
    return { y * otherVector.z - z * otherVector.y, z * otherVector.x - x * otherVector.z, x * otherVector.y - y * otherVector.x };
}

std::string Vector3::ToString() const
{
    return "( " + std::to_string(x) + " , " + std::to_string(y) + " , " + std::to_string(z) + " )";
}

void Vector3::operator+=(const Vector3& right)
{
    x += right.x;
    y += right.y;
    z += right.z;
}

void Vector3::operator-=(const Vector3& right)
{
    x -= right.x;
    y -= right.y;
    z -= right.z;
}

void Vector3::operator*=(const float value)
{
    x *= value;
    y *= value;
    z *= value;
}

void Vector3::operator/=(const float value)
{
    x /= value;
    y /= value;
    z /= value;
}

Vector3 operator+(const Vector3& left, const Vector3& right)
{
    return Vector3(left.x + right.x, left.y + right.y, left.z + right.z);
}

Vector3 operator-(const Vector3& left, const Vector3& right)
{
    return Vector3(left.x - right.x, left.y - right.y, left.z - right.z);
}

Vector3 operator*(const Vector3& left, const float value)
{
    return Vector3(left.x * value, left.y * value, left.z * value);
}

Vector3 operator*(const float value, const Vector3& right)
{
    return Vector3(value * right.x, value * right.y, value * right.z);
}

Vector3 operator/(const Vector3& left, const float value)
{
    if (value != 0.0f)
    {
        return Vector3(left.x / value, left.y / value, left.z / value);
    }
    else
    {
        throw std::invalid_argument("Cannot divide by zero.");
    }
}

Vector3 operator/(const float value, const Vector3& right)
{
    if (right.x != 0.0f && right.y != 0.0f && right.z != 0.0f)
    {
        return Vector3(value / right.x, value / right.y, value / right.z);
    }
    else
    {
        throw std::invalid_argument("Cannot divide by zero.");
    }
}