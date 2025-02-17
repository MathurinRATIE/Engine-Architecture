#pragma once
#include "vector2.h"
#include "maths.h"

class Transform2D
{
public :
	Transform2D();
	Transform2D(Vector2 pPosition, Vector2 pScale = Vector2::ONE, float pRotation = 0.0f) : mPosition(pPosition), mScale(pScale), mRotationZ(pRotation) {};

	Vector2 GetPosition();
	Vector2 GetScale();
	float GetRotation();

	void SetPosition(Vector2 pPosition);
	void SetScale(Vector2 pScale);
	void SetRotation(float pRotation);

	bool operator!=(Transform2D right);
	bool operator==(Transform2D right);

	Vector2 Right() const;
	Vector2 Up() const;

private :
	Vector2 mPosition;
	Vector2 mScale;
	float mRotationZ;
};
