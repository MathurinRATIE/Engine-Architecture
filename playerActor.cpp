#include "playerActor.h"

Player::Player(Scene* pScene, Window* pWindow, std::vector<Component*> pComponents, Transform2D pTransform, float mSpeedX, float mSpeedY, ActorState pState) : Actor(pScene, pWindow, pComponents, pState, pTransform)
{
	mWindow = pWindow;
	mTransform = pTransform;
	mRect = new Rectangle(mTransform.GetPosition(), mTransform.GetScale());
	Actor* collidingActor = nullptr;
	mCollidingActor = &collidingActor;

	Collider2D* collider = new Collider2D(mRect, this, mCollidingActor);
	Component* colliderComponent = dynamic_cast<Component*>(collider);
	AddComponent(colliderComponent);

	mMovements = new Movements(&mRect->mPosition, this, pWindow, mCollidingActor, mSpeedX, mSpeedY);
	Component* movementsComponent = dynamic_cast<Component*>(mMovements);
	AddComponent(movementsComponent);
}

void Player::UpdateActor(unsigned int pDeltaTime)
{
	timeSinceLastShot += pDeltaTime;

	if (timeSinceLastShot >= 1000)
	{
		timeSinceLastShot -= 1000;

		Bullet* bullet = new Bullet(mSceneOwner, mWindow, {}, this, Direction::Up, Transform2D({ mRect->mPosition.x + 5, mRect->mPosition.y - 20 }, { 5, 20 }));
	}
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
