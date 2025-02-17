#include "ballActor.h"
BallActor::BallActor(Window* pWindow)
{
	mWindow = pWindow;

	mRectangle = new Rectangle(Vector2(mWindow->GetDimensions() / 2 - Vector2(mWidth, mHeight)), Vector2(mWidth, mHeight));
}

int BallActor::Move(float pDeltaTime, bool pIsLaunched)
{
	if (pIsLaunched) {
		mRectangle->mPosition.x += mSpeedX * pDeltaTime;
		mRectangle->mPosition.y += mSpeedY * pDeltaTime;

		if (mRectangle->mPosition.y < 0)
			BounceY(false);
		if (mRectangle->mPosition.y > mWindow->GetDimensions().y - mRectangle->mDimensions.y)
			BounceY(true);

		if (mRectangle->mPosition.x < 0)
		{
			BounceX(false);
			mRectangle->mPosition.x = (mWindow->GetDimensions().x - mWidth) / 2;
			mRectangle->mPosition.y = (mWindow->GetDimensions().y - mHeight) / 2;

			return 2;
		}
		if (mRectangle->mPosition.x > mWindow->GetDimensions().x - mRectangle->mDimensions.x)
		{
			BounceX(true);
			mRectangle->mPosition.x = (mWindow->GetDimensions().x - mWidth) / 2;
			mRectangle->mPosition.y = (mWindow->GetDimensions().y - mHeight) / 2;

			return 1;
		}
	}

	return 0;
}

void BallActor::BounceX(bool pIsBaseSpeedReversed)
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

void BallActor::BounceY(bool pIsBaseSpeedReversed)
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

void BallActor::SpeedUp()
{
	mBaseSpeed += 0.001f;
	mSpeedX += 0.001f;
	mSpeedY += 0.001f;
}

void BallActor::Reset()
{
	mBaseSpeed = 0.5f;
	mSpeedX = 0.5f;
	mSpeedY = 0.5f;
}

Rectangle BallActor::GetRect()
{
	return *mRectangle;
}
