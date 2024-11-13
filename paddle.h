#pragma once
#include "rectangle.h"
#include "vector2.h"
#include "window.h"

class Paddle
{
public:
	Paddle(bool side, Window* window);

	void MoveUp(float deltaTime);
	void MoveDown(float deltaTime);
	void FollowBall(float ballYCoord);
	Rectangle GetRect();

private:
	const float mHeight = 80;
	const float mWidth = 10;
	const float mSpeed = 0.8f;
	Rectangle* mRectangle;
	Window* rWindow;
};