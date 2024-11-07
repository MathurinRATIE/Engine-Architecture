#include "vector2.h"

const Vector2 Vector2::ZERO(0.0f, 0.0f);
const Vector2 Vector2::ONE(1.0f, 1.0f);

Vector2::Vector2(float newX, float newY)
{
    x = newX;
    y = newY;
}

Vector2 Vector2::normalize() const {
    float length = std::sqrt(x * x + y * y);

    if (length == 0.0f) {
        return ZERO;
    }
    else {
        return Vector2(x / length, y / length);
    }
}

float Vector2::dot(const Vector2& other) const {
    return x * other.x + y * other.y;
}

float Vector2::cross(const Vector2& other) const {
    return x * other.y - y * other.x;
}


Vector2 Vector2::operator+(const Vector2& other) const {
    return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const {
    return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(float scalar) const {
    return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::operator/(float scalar) const {
    if (scalar != 0.0f) {
        return Vector2(x / scalar, y / scalar);
    }
    else {
        throw std::invalid_argument("Cannot divide by zero.");
    }
}