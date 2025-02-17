#include "movementsComponent.h"

MovementComponent::MovementComponent(Vector2* pPosition, Actor* pOwner, Window* pWindow, Actor* pCollidingActor, float pSpeedX, float pSpeedY, int pUpdateOrder, bool pIsActive) : Component(pOwner, pUpdateOrder, pIsActive)
{
	mPosition = pPosition;
	mWindow = pWindow;
	mSpeedX = pSpeedX;
	mSpeedY = pSpeedY;
	mCollidingActor = pCollidingActor;
	mDirectionX = Direction::None;
	mDirectionY = Direction::None;
	mLastDirectionX = Direction::None;
	mLastDirectionY = Direction::None;
}

void MovementComponent::Update()
{
	if (mCollidingActor == nullptr)
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

	Transform2D transform = mOwner->GetTransform();
	transform.SetPosition(*mPosition);
	mOwner->SetTransform(transform);
}

void MovementComponent::SetSpeedX(float pSpeedX)
{
	mSpeedX = pSpeedX;
}

void MovementComponent::SetSpeedY(float pSpeedY)
{
	mSpeedY = pSpeedY;
}

void MovementComponent::SetDirectionX(Direction pDirectionX)
{
	mDirectionX = pDirectionX;
}

void MovementComponent::SetDirectionY(Direction pDirectionY)
{
	mDirectionY = pDirectionY;
}

float MovementComponent::GetSpeedX()
{
	return mSpeedX;
}

float MovementComponent::GetSpeedY()
{
	return mSpeedY;
}

Direction MovementComponent::GetDirectionX()
{
	return mDirectionX;
}

Direction MovementComponent::GetDirectionY()
{
	return mDirectionY;
}

Vector2* MovementComponent::GetPosition()
{
	return mPosition;
}
