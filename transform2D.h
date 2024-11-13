#pragma once
#include "vector2.h"

class Transform2D
{
public :
	Vector2 mPosition = Vector2::ZERO;
	Vector2 mScale = Vector2::ONE;
	float mRotation = 0.0f;
};

