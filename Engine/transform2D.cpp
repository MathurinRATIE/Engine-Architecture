#include "transform2D.h"

Transform2D::Transform2D()
{
    mPosition = Vector2::ZERO;
    mScale = Vector2::ONE;
    mRotationZ = 0.0f;
}

Vector2 Transform2D::GetPosition()
{
    return mPosition;
}

Vector2 Transform2D::GetScale()
{
    return mScale;
}

float Transform2D::GetRotation()
{
    return mRotationZ;
}

void Transform2D::SetPosition(Vector2 pPosition)
{
    mPosition = pPosition;
}

void Transform2D::SetScale(Vector2 pScale)
{
    mScale = pScale;
}

void Transform2D::SetRotation(float pRotation)
{
    mRotationZ = pRotation;
}

bool Transform2D::operator!=(Transform2D right)
{
    return mPosition != right.mPosition || mScale != right.mScale || mRotationZ != right.mRotationZ;
}

bool Transform2D::operator==(Transform2D right)
{
    return mPosition == right.mPosition && mScale == right.mScale && mRotationZ == right.mRotationZ;
}

Vector2 Transform2D::Right() const
{
    return Vector2(Maths::Cos(mRotationZ), -Maths::Sin(mRotationZ));
}

Vector2 Transform2D::Up() const
{
    return Vector2(Maths::Sin(mRotationZ), -Maths::Cos(mRotationZ));
}
