#pragma once
#include "rectangle.h"
#include "vector2.h"
#include "window.h"

class Paddle
{
public:
	Paddle(bool side, Window* window);

	void MoveUp(float deltaTime, float mMultiplier);
	void MoveDown(float deltaTime, float mMultiplier);
	void FollowBall(float ballYCoord, float pDeltaTime);
	void Reset();
	Rectangle GetRect();

private:
	const float mHeight = 80;
	const float mWidth = 10;
	const float mSpeed = 1.0f;
	bool mAiMoveDown = false;
	float mSpeedMultiplier = 0.0f;
	Rectangle* mRectangle;
	Window* mWindow;
};