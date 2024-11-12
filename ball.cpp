#include "ball.h"
Ball::Ball()
{
	mRectangle = new Rectangle(Vector2(395, 295), Vector2(10, 10));

	mSpeedX = mBaseSpeed;
	mSpeedY = mBaseSpeed;
}

int Ball::Move(float deltaTime, bool isLaunched)
{
	if (isLaunched) {
		mRectangle->position.x += mSpeedX * deltaTime;
		mRectangle->position.y += mSpeedY * deltaTime;

		if (mRectangle->position.y < mRectangle->dimensions.y || mRectangle->position.y > 600 - mRectangle->dimensions.y)
			BounceY();

		if (mRectangle->position.x < mRectangle->dimensions.x)
		{
			BounceX();
			mRectangle->position.x = 395;
			mRectangle->position.y = 295;

			return 2;
		}
		if (mRectangle->position.x > 800 - mRectangle->dimensions.x)
		{
			BounceX();
			mRectangle->position.x = 395;
			mRectangle->position.y = 295;

			return 1;
		}
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
	return *mRectangle;
}

