#include "paddle.h"

Paddle::Paddle(bool pSide, Window* pWindow)
{
	mWindow = pWindow;

	float xPos = 0;
	if (pSide)
	{
		xPos = mWidth;
	}
	else
	{
		xPos = mWindow->GetDimensions().x - mWidth * 2;
	}

	mRectangle = new Rectangle(Vector2(xPos, (mWindow->GetDimensions().y - mHeight) / 2), Vector2(mWidth, mHeight));
}

void Paddle::MoveUp(float pDeltaTime, float mMultiplier)
{
	mRectangle->mPosition.y -= mSpeed * mMultiplier * pDeltaTime;

	if (mRectangle->mPosition.y < 0)
	{
		mRectangle->mPosition.y = 0;
	}
}

void Paddle::MoveDown(float pDeltaTime, float mMultiplier)
{
	mRectangle->mPosition.y += mSpeed * mMultiplier * pDeltaTime;

	if (mRectangle->mPosition.y > mWindow->GetDimensions().y - mHeight)
	{
		mRectangle->mPosition.y = mWindow->GetDimensions().y - mHeight;
	}
}

void Paddle::FollowBall(float pBallYCoord, float pDeltaTime)
{
	// Check next movement
	if (mRectangle->mPosition.y > pBallYCoord)
	{
		mAiMoveDown = false;
		MoveUp(pDeltaTime, 0.5f);

		mSpeedMultiplier = -1.0f;
	}
	else if (mRectangle->mPosition.y + mHeight < pBallYCoord)
	{
		mAiMoveDown = true;
		MoveDown(pDeltaTime, 0.5f);

		mSpeedMultiplier = 1.0f;
	}
	else
	{
		if (mSpeedMultiplier != 0)
		{
			mRectangle->mPosition.y += mSpeed * mSpeedMultiplier * pDeltaTime;

			mSpeedMultiplier /= 1.05f;
			if (abs(mSpeedMultiplier) < 0.1f)
			{
				mSpeedMultiplier = 0;
			}
		}
	}

	// Don't exit screen
	if (mRectangle->mPosition.y < 0)
	{
		mRectangle->mPosition.y = 0;
	}
	else if (mRectangle->mPosition.y > mWindow->GetDimensions().y - mHeight)
	{
		mRectangle->mPosition.y = mWindow->GetDimensions().y - mHeight;
	}
}

void Paddle::Reset()
{
	mRectangle->mPosition.y = (mWindow->GetDimensions().y - mHeight) / 2;
	mSpeedMultiplier = 0;
}

Rectangle Paddle::GetRect()
{
	return *mRectangle;
}
