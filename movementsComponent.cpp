#include "movementsComponent.h"

Movements::Movements(Vector2* pPosition, Actor* pOwner, Window* pWindow, bool* pIsColliding, float pSpeedX, float pSpeedY, int pUpdateOrder, bool pIsActive) : Component(pOwner, pUpdateOrder, pIsActive)
{
	mPosition = pPosition;
	mWindow = pWindow;
	mSpeedX = pSpeedX;
	mSpeedY = pSpeedY;
	mIsColliding = pIsColliding;
	mDirectionX = Direction::None;
	mDirectionY = Direction::None;
}

void Movements::Update(unsigned int pDeltaTime)
{
	if (mIsColliding == nullptr || !*mIsColliding)
	{
		switch (mDirectionX)
		{
		case Right:
			mPosition->x += mSpeedX;
			break;
		case Left:
			mPosition->x -= mSpeedX;
			break;
		}

		switch (mDirectionY)
		{
		case Up:
			mPosition->y -= mSpeedY;
			break;
		case Down:
			mPosition->y += mSpeedY;
			break;
		}

		if (mPosition->x < 0)
		{
			mPosition->x = 0;
		}
		else if (mPosition->x > mWindow->GetDimensions().x - mOwner->GetTransform().GetScale().x)
		{
			mPosition->x = mWindow->GetDimensions().x - mOwner->GetTransform().GetScale().x;
		}
		if (mPosition->y < 0)
		{
			mPosition->y = 0;
		}
		else if (mPosition->y > mWindow->GetDimensions().y - mOwner->GetTransform().GetScale().y)
		{
			mPosition->y = mWindow->GetDimensions().y - mOwner->GetTransform().GetScale().y;
		}

		mLastDirectionX = mDirectionX;
		mLastDirectionY = mDirectionY;
	}
	else  // Reverse movement if colliding other Collider2D
	{
		switch (mLastDirectionX)
		{
		case Right:
			mPosition->x -= mSpeedX;
			break;
		case Left:
			mPosition->x += mSpeedX;
			break;
		}

		switch (mLastDirectionY)
		{
		case Up:
			mPosition->y += mSpeedY;
			break;
		case Down:
			mPosition->y -= mSpeedY;
			break;
		}
	}
}

void Movements::SetSpeedX(float pSpeedX)
{
	mSpeedX = pSpeedX;
}

void Movements::SetSpeedY(float pSpeedY)
{
	mSpeedY = pSpeedY;
}

void Movements::SetDirectionX(Direction pDirectionX)
{
	mDirectionX = pDirectionX;
}

void Movements::SetDirectionY(Direction pDirectionY)
{
	mDirectionY = pDirectionY;
}

float Movements::GetSpeedX()
{
	return mSpeedX;
}

float Movements::GetSpeedY()
{
	return mSpeedY;
}

Direction Movements::GetDirectionX()
{
	return mDirectionX;
}

Direction Movements::GetDirectionY()
{
	return mDirectionY;
}

Vector2* Movements::GetPosition()
{
	return mPosition;
}
