#pragma once
#include "rectangle.h"
#include "vector2.h"
#include "window.h"

class BallActor
{
public:
	BallActor(Window* window);

	int Move(float deltaTime, bool isLaunched);
	void BounceX(bool isBaseSpeedReversed);
	void BounceY(bool isBaseSpeedReversed);
	void SpeedUp();
	void Reset();
	Rectangle GetRect();

private:
	const float mWidth = 10;
	const float mHeight = 10;
	float mBaseSpeed = 0.5f;
	float mSpeedX = mBaseSpeed;
	float mSpeedY = mBaseSpeed;
	Rectangle* mRectangle;
	Window* mWindow;
};
