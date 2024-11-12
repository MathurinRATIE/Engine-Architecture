#include "paddle.h"

Paddle::Paddle(bool side)
{
	float yPos = 0.0f;
	if (side)
	{
		yPos = 0.95f;
	}
	else
	{
		yPos = -0.95f;
	}

	mRectangle = new Rectangle(Vector2(0.0f, yPos), Vector2(0.02f, 0.15f));
}

void Paddle::MoveUp(float deltaTime)
{
	mRectangle->position.y += mSpeed * deltaTime;
}

void Paddle::MoveDown(float deltaTime)
{
	mRectangle->position.y -= mSpeed * deltaTime;
}

Rectangle Paddle::GetRect()
{
	return *mRectangle;
}
