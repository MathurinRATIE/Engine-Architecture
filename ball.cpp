#include "ball.h"
Ball::Ball(Window* window)
{
	rWindow = window;

	mRectangle = new Rectangle(Vector2(rWindow->GetDimensions() / 2 - Vector2(mWidth, mHeight)), Vector2(mWidth, mHeight));
}

int Ball::Move(float deltaTime, bool isLaunched)
{
	if (isLaunched) {
		mRectangle->position.x += mSpeedX * deltaTime;
		mRectangle->position.y += mSpeedY * deltaTime;

		if (mRectangle->position.y < 0)
			BounceY(false);
		if (mRectangle->position.y > rWindow->GetDimensions().y - mRectangle->dimensions.y)
			BounceY(true);

		if (mRectangle->position.x < 0)
		{
			BounceX(false);
			mRectangle->position.x = (rWindow->GetDimensions().x - mWidth) / 2;
			mRectangle->position.y = (rWindow->GetDimensions().y - mHeight) / 2;

			return 2;
		}
		if (mRectangle->position.x > rWindow->GetDimensions().x - mRectangle->dimensions.x)
		{
			BounceX(true);
			mRectangle->position.x = (rWindow->GetDimensions().x - mWidth) / 2;
			mRectangle->position.y = (rWindow->GetDimensions().y - mHeight) / 2;

			return 1;
		}
	}

	return 0;
}

void Ball::BounceX(bool isBaseSpeedReversed)
{
	if (isBaseSpeedReversed) 
	{
		mSpeedX = -mBaseSpeed;
	}
	else
	{
		mSpeedX = mBaseSpeed;
	}
}

void Ball::BounceY(bool isBaseSpeedReversed)
{
	if (isBaseSpeedReversed)
	{
		mSpeedY = -mBaseSpeed;
	}
	else
	{
		mSpeedY = mBaseSpeed;
	}
}

Rectangle Ball::GetRect()
{
	return *mRectangle;
}

