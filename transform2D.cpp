#include "transform2D.h"

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
    return mRotation;
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
    mRotation = pRotation;
}
