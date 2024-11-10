#include "ball.h"
Ball::Ball()
{
	mRectangle = Rectangle(Vector2(0, 0), Vector2(.05f, .05f));

	mSpeedX = mBaseSpeed;
	mSpeedY = mBaseSpeed;
}

int Ball::Move(float deltaTime)
{
	mRectangle.position.x += mSpeedX * deltaTime;
	mRectangle.position.y += mSpeedY * deltaTime;

	if (mRectangle.position.y <= -1.0f + mRectangle.dimensions.y / 2 || mRectangle.position.y >= 1.0f - mRectangle.dimensions.y / 2)
		BounceY();

	if (mRectangle.position.x <= -1.0f + mRectangle.dimensions.x / 2)
	{
		BounceX();
		mRectangle.position.x == mSpeedX;
		mRectangle.position.y == mSpeedY;
		
		return 2;
	}
	if (mRectangle.position.x >= 1.0f - mRectangle.dimensions.x / 2)
	{
		BounceX();
		mRectangle.position.x == mSpeedX;
		mRectangle.position.y == mSpeedY;

		return 1;
	}

	return 0;
}

void Ball::BounceX()
{
	mSpeedX = -mSpeedX;
}

void Ball::BounceY()
{
	mSpeedY = -mSpeedY;
}

Rectangle Ball::GetRect()
{
	return mRectangle;
}

