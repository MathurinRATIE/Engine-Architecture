#include "movementsComponent.h"

Movements::Movements(Vector2* pPosition, Actor* pOwner, bool* pIsColliding, float pSpeedX, float pSpeedY, int pUpdateOrder, bool pIsActive) : Component(pOwner, pUpdateOrder, pIsActive)
{
	mPosition = pPosition;
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
		default:
			break;
		}
	}
	else  // Reverse movement if colliding other Collider2D
	{
		switch (mDirectionX)
		{
		case Right:
			mPosition->x -= mSpeedX;
			break;
		case Left:
			mPosition->x += mSpeedX;
			break;
		}

		switch (mDirectionY)
		{
		case Up:
			mPosition->y += mSpeedY;
			break;
		case Down:
			mPosition->y -= mSpeedY;
			break;
		default:
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
