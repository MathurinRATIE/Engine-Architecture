#include "vector2.h"

const Vector2 Vector2::ZERO{ 0.0f, 0.0f };
const Vector2 Vector2::ONE{1.0f, 1.0f};

Vector2::Vector2(float newX, float newY)
{
    x = newX;
    y = newY;
}

void Vector2::normalize() 
{
    (*this) /= GetMagnitude();
}

Vector2 Vector2::normalized() 
{
    return (*this) / GetMagnitude();
}


float Vector2::GetMagnitude() const 
{
    return std::sqrt(x * x + y * y);
}

float Vector2::dot(Vector2& otherVector) const 
{
    return x * otherVector.x + y * otherVector.y;
}

float Vector2::cross(Vector2& otherVector) const 
{
    return x * otherVector.y - y * otherVector.x;
}

inline void Vector2::operator+=(Vector2& right)
{
    x += right.x;
    y += right.y;
}

inline void Vector2::operator-=(Vector2& right)
{
    x -= right.x;
    y -= right.y;
}

inline void Vector2::operator*=(float value)
{
    x *= value;
    y *= value;
}

inline void Vector2::operator/=(float value)
{
    x /= value;
    y /= value;
}

inline Vector2 operator+(Vector2& left, Vector2& right) 
{
    return Vector2(left.x + right.x, left.y + right.y);
}

inline Vector2 operator-(Vector2& left, Vector2& right) 
{
    return Vector2(left.x - right.x, left.y - right.y);
}

inline Vector2 operator*(Vector2& left, float value) 
{
    return Vector2(left.x * value, left.y * value);
}

inline Vector2 operator*(float value, Vector2& right) 
{
    return Vector2(value * right.x, value * right.y);
}

inline Vector2 operator/(Vector2& left, float value) 
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

inline Vector2 operator/(float value, Vector2& right) 
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