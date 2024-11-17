#include "playerActor.h"

Player::Player(Scene* pScene, Window* pWindow, std::vector<Component*> pComponents, ActorState pState, Transform2D pTransform) : Actor(pScene, pWindow, pComponents, pState, pTransform)
{
	mRect = new Rectangle(Vector2(mWindow->GetDimensions().x / 2, mWindow->GetDimensions().y / 2), Vector2(15, 15));
	mIsColliding = new bool();
	*mIsColliding = false;

	Collider2D* collider = new Collider2D(mRect, this, mIsColliding);
	Component* colliderComponent = dynamic_cast<Component*>(collider);
	AddComponent(colliderComponent);

	mMovements = new Movements(&mRect->mPosition, this, mIsColliding, 1.0f, 1.0f);
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
