#include "ball.h"
Ball::Ball(Window* pWindow)
{
	rWindow = pWindow;

	mRectangle = new Rectangle(Vector2(rWindow->GetDimensions() / 2 - Vector2(mWidth, mHeight)), Vector2(mWidth, mHeight));
}

int Ball::Move(float pDeltaTime, bool pIsLaunched)
{
	if (pIsLaunched) {
		mRectangle->position.x += mSpeedX * pDeltaTime;
		mRectangle->position.y += mSpeedY * pDeltaTime;

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

void Ball::BounceX(bool pIsBaseSpeedReversed)
{
	if (pIsBaseSpeedReversed) 
	{
		mSpeedX = -mBaseSpeed;
	}
	else
	{
		mSpeedX = mBaseSpeed;
	}
}

void Ball::BounceY(bool pIsBaseSpeedReversed)
{
	if (pIsBaseSpeedReversed)
	{
		mSpeedY = -mBaseSpeed;
	}
	else
	{
		mSpeedY = mBaseSpeed;
	}
}

void Ball::SpeedUp()
{
	mBaseSpeed += 0.001f;
	mSpeedX += 0.001f;
	mSpeedY += 0.001f;
}

void Ball::Reset()
{
	mBaseSpeed = 0.5f;
	mSpeedX = 0.5f;
	mSpeedY = 0.5f;
}

Rectangle Ball::GetRect()
{
	return *mRectangle;
}
