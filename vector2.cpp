#include "vector2.h"

const Vector2 Vector2::ZERO{ 0.0f, 0.0f };
const Vector2 Vector2::ONE{1.0f, 1.0f};

Vector2::Vector2() : x(0.0f), y(0.0f) {};

Vector2::Vector2(float x, float y) : x(x), y(y) {};

void Vector2::normalize() 
{
    float length = GetMagnitude();
    if (length == 0)
    {
        return;
    }

    (*this) /= GetMagnitude();
}

Vector2 Vector2::normalized() 
{
    float length = GetMagnitude();
    if (length == 0)
    {
        return ZERO;
    }

    return (*this) / GetMagnitude();
}

float Vector2::GetMagnitude() const 
{
    return std::sqrt(x * x + y * y);
}

float Vector2::dot(const Vector2& otherVector) const
{
    return x * otherVector.x + y * otherVector.y;
}

float Vector2::cross(const Vector2& otherVector) const
{
    return x * otherVector.y - y * otherVector.x;
}

std::string Vector2::ToString() const
{
    return "( " + std::to_string(x) + " , " + std::to_string(y) + " )";
}

void Vector2::operator+=(const Vector2& right)
{
    x += right.x;
    y += right.y;
}

void Vector2::operator-=(const Vector2& right)
{
    x -= right.x;
    y -= right.y;
}

void Vector2::operator*=(const float value)
{
    x *= value;
    y *= value;
}

void Vector2::operator/=(const float value)
{
    x /= value;
    y /= value;
}

Vector2 operator+(const Vector2& left, const Vector2& right)
{
    return Vector2(left.x + right.x, left.y + right.y);
}

Vector2 operator-(const Vector2& left, const Vector2& right)
{
    return Vector2(left.x - right.x, left.y - right.y);
}

Vector2 operator*(const Vector2& left, const float value)
{
    return Vector2(left.x * value, left.y * value);
}

Vector2 operator*(const float value, const Vector2& right)
{
    return Vector2(value * right.x, value * right.y);
}

Vector2 operator/(const Vector2& left, const float value)
{
    if (value != 0.0f)
    {
        return Vector2(left.x / value, left.y / value);
    }
    else
    {
        throw std::invalid_argument("Cannot divide by zero.");
    }
}

Vector2 operator/(const float value, const Vector2& right)
{
    if (right.x != 0.0f && right.y != 0.0f)
    {
        return Vector2(value / right.x, value / right.y);
    }
    else
    {
        throw std::invalid_argument("Cannot divide by zero.");
    }
}