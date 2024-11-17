#include "playerActor.h"

Player::Player(Scene* pScene, Window* pWindow, std::vector<Component*> pComponents, Transform2D pTransform, float mSpeedX, float mSpeedY, ActorState pState) : Actor(pScene, pWindow, pComponents, pState, pTransform)
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
}

void Player::UpdateActor(unsigned int pDeltaTime)
{

}

void Player::SetDirectionX(Direction pDirectionX)
{
	mMovements->SetDirectionX(pDirectionX);
}

void Player::SetDirectionY(Direction pDirectionY)
{
	mMovements->SetDirectionY(pDirectionY);
}

Rectangle Player::GetRect()
{
	return *mRect;
}
