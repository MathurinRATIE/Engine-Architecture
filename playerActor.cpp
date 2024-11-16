#include "playerActor.h"

Player::Player(Scene* pScene, std::vector<Component*> pComponents, ActorState pState, Transform2D pTransform) : Actor(pScene, pComponents, pState, pTransform)
{
	Collider2D* collider = new Collider2D(Rectangle({0, 0}, {5, 5}), this);
	AddComponent(collider);


}

void Player::UpdateActor(unsigned int pDeltaTime)
{
	switch (mDirection)
	{
	case Top :
		break;
	case Bootom:
		break;
	case Right:
		break;
	case Left:
		break;
	default:
		break;
	}
}

void Player::SetDirection(Direction pDirection)
{
	mDirection = pDirection;
}
