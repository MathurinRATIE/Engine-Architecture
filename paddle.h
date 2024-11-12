#pragma once
#include "rectangle.h"
#include "vector2.h"

class Paddle
{
public:
	Paddle(bool side);

	void MoveUp(float deltaTime);
	void MoveDown(float deltaTime);
	Rectangle GetRect();

private:
	const float mSpeed = 0.5f;
	Rectangle* mRectangle;
};