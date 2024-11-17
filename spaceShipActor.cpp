#include "spaceShipActor.h"

SpaceShip::SpaceShip(Scene* pScene, Window* pWindow, std::vector<Component*> pComponents, Transform2D pTransform, Direction startingDirection, float mSpeedX, float mSpeedY, ActorState pState) : Actor(pScene, pWindow, pComponents, pState, pTransform)
{
	mWindow = pWindow;
	mTransform = pTransform;
	mRect = new Rectangle(mTransform.GetPosition(), mTransform.GetScale());
	mIsColliding = new bool();
	*mIsColliding = false;

	Collider2D* collider = new Collider2D(mRect, this, mIsColliding);
	Component* colliderComponent = dynamic_cast<Component*>(collider);
	AddComponent(colliderComponent);

	mMovements = new Movements(&mRect->mPosition, this, pWindow, mIsColliding, mSpeedX, mSpeedY);
	Component* movementsComponent = dynamic_cast<Component*>(mMovements);
	AddComponent(movementsComponent);

	mMovements->SetDirectionX(startingDirection);
}

void SpaceShip::UpdateActor(unsigned int pDeltaTime)
{
	if (mRect->mPosition.x < 0)
	{
		mMovements->SetDirectionX(Direction::Right);
	}
	else if (mRect->mPosition.x > mWindow->GetDimensions().x - mRect->mDimensions.x)
	{
		mMovements->SetDirectionX(Direction::Left);
	}
}

Rectangle SpaceShip::GetRect()
{
	return *mRect;
}