#pragma once
#include "rectangle.h"
#include "vector2.h"

class Ball
{
public:
	Ball();

	int Move(float deltaTime, bool isLaunched);
	void BounceX();
	void BounceY();
	Rectangle GetRect();

private:
	const float mBaseSpeed = 0.5f;
	float mSpeedX;
	float mSpeedY;
	Rectangle* mRectangle;
};