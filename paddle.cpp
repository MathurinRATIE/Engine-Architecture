#include "paddle.h"

Paddle::Paddle(bool side)
{
	float xPos = 0;
	if (side)
	{
		xPos = 10;
	}
	else
	{
		xPos = 780;
	}

	mRectangle = new Rectangle(Vector2(xPos, 280), Vector2(10, 40));
}

void Paddle::MoveUp(float deltaTime)
{
	mRectangle->position.y -= mSpeed * deltaTime;

	if (mRectangle->position.y < 0)
	{
		mRectangle->position.y = 0;
	}
}

void Paddle::MoveDown(float deltaTime)
{
	mRectangle->position.y += mSpeed * deltaTime;

	if (mRectangle->position.y > 560)
	{
		mRectangle->position.y = 560;
	}
}

Rectangle Paddle::GetRect()
{
	return *mRectangle;
}
