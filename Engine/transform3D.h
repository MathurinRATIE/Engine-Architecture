#pragma once
#include "vector3.h"
#include "maths.h"
#include "matrix4Row.h"
#include "component.h"

class Transform3D : public Component
{
public :
	Transform3D(Vector3 pPosition = Vector3::zero, Vector3 pScale = Vector3::one, Quaternion pRotation = Quaternion::Identity);

	Vector3 GetPosition();
	Vector3 GetScale();
	Quaternion GetRotation();
	Matrix4Row GetWorldTransform();

	void SetPosition(Vector3 pPosition);
	void SetScale(Vector3 pScale);
	void SetRotation(Quaternion pRotation);
	void SetOwner(Actor* pOwner);
	void ComputeWorldTransform();

	bool operator!=(Transform3D right);
	bool operator==(Transform3D right);

	Vector3 Right() const;
	Vector3 Up() const;
	Vector3 Forward() const;

private :
	Vector3 mPosition;
	Vector3 mScale;
	Quaternion mRotation;
	Matrix4Row mWorldTransform;
	bool mNeedsUpdate;
};
