#include "playerActor.h"

Player::Player(Scene* pScene, std::vector<Component*> pComponents, ActorState pState, Transform2D pTransform) : Actor(pScene, pComponents, pState, pTransform)
{
	mRect = new Rectangle();

	Collider2D* collider = new Collider2D(Rectangle({0, 0}, {5, 5}), this);
	Component* colliderComponent = dynamic_cast<Component*>(collider);
	AddComponent(colliderComponent);

	Movements* movements = new Movements(&mRect->mPosition, this, 1.0f, 1.0f);
	Component* movementsComponent = dynamic_cast<Component*>(movements);
	AddComponent(movementsComponent);
}

void Player::UpdateActor(unsigned int pDeltaTime)
{

}

void Player::SetDirectionX(Direction pDirectionX)
{
	mDirectionX = pDirectionX;
}

void Player::SetDirectionY(Direction pDirectionY)
{
	mDirectionY = pDirectionY;
}

Rectangle Player::GetRect()
{
	return *mRect;
}
