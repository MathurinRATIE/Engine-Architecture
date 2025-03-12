#include "transform3D.h"
#include "quaternion.h"
#include "actor.h"

Transform3D::Transform3D(Vector3 pPosition, Vector3 pScale, Quaternion pRotation)
{
    mPosition = pPosition;
    mScale = pScale;
    mRotation = pRotation;
    mNeedsUpdate = true;
}

Vector3 Transform3D::GetPosition()
{
    return mPosition;
}

Vector3 Transform3D::GetScale()
{
    return mScale;
}

Quaternion Transform3D::GetRotation()
{
    return mRotation;
}

Matrix4Row Transform3D::GetWorldTransform()
{
    return mWorldTransform;
}

void Transform3D::SetPosition(Vector3 pPosition)
{
    mPosition = pPosition;
}

void Transform3D::SetScale(Vector3 pScale)
{
    mScale = pScale;
}

void Transform3D::Rotate(float pRotation, Vector3 pAxis)
{
    Quaternion appliedRotation = Quaternion(pAxis, pRotation);
    mRotation = Quaternion::Concatenate(mRotation, appliedRotation);
}

void Transform3D::SetRotation(Quaternion pRotation)
{
    mRotation = pRotation;
}

void Transform3D::ComputeWorldTransform()
{
    if (!mNeedsUpdate)
    {
        return;
    }
    mNeedsUpdate = false;

    mWorldTransform = Matrix4Row::CreateScale(mScale);
    mWorldTransform *= Matrix4Row::CreateFromQuaternion(mRotation);
    mWorldTransform *= Matrix4Row::CreateTranslation(mPosition);
}

bool Transform3D::operator!=(Transform3D right)
{
    return mPosition != right.mPosition || mScale != right.mScale || mRotation != right.mRotation;
}

bool Transform3D::operator==(Transform3D right)
{
    return mPosition == right.mPosition && mScale == right.mScale && mRotation == right.mRotation;
}

Vector3 Transform3D::Right() const
{
    return Vector3::Transform(Vector3::unitY, mRotation);
}

Vector3 Transform3D::Up() const
{
    return Vector3::Transform(Vector3::unitZ, mRotation);
}

Vector3 Transform3D::Forward() const
{
    return Vector3::Transform(Vector3::unitX, mRotation);
}
