#include "paddle.h"

Paddle::Paddle(bool side, Window* window)
{
	rWindow = window;

	float xPos = 0;
	if (side)
	{
		xPos = mWidth;
	}
	else
	{
		xPos = rWindow->GetDimensions().x - mWidth * 2;
	}

	mRectangle = new Rectangle(Vector2(xPos, (rWindow->GetDimensions().y - mHeight) / 2), Vector2(mWidth, mHeight));
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

	if (mRectangle->position.y > rWindow->GetDimensions().y - mHeight)
	{
		mRectangle->position.y = rWindow->GetDimensions().y - mHeight;
	}
}

void Paddle::FollowBall(float ballYCoord)
{
	mRectangle->position.y = ballYCoord;

	if (mRectangle->position.y < 0)
	{
		mRectangle->position.y = 0;
	}
	else if (mRectangle->position.y > rWindow->GetDimensions().y - mHeight)
	{
		mRectangle->position.y = rWindow->GetDimensions().y - mHeight;
	}
}

Rectangle Paddle::GetRect()
{
	return *mRectangle;
}
