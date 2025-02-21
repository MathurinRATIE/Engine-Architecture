#include "actor.h"
#include "scene.h"
#include "collider2DComponent.h"
#include "collisionManager.h"

Collider2D::Collider2D(Actor* pOwner, Actor* pCollidingActor, int pUpdateOrder, bool pIsActive) : Component(pOwner, pUpdateOrder, pIsActive), IColliderListener()
{
	mOwner = pOwner;
	mCollidingActor = pCollidingActor;
	mState = ColliderState::CollisionNone;

	CollisionManager::Instance().SubscribeTo(this, this);
}

void Collider2D::Update()
{
}

bool Collider2D::CheckCollisions(Rectangle pBox)
{
	Rectangle hitBox = mOwner->GetRect();
	// This
	float selfXMin = hitBox.mPosition.x;
	float selfXMax = hitBox.mPosition.x + hitBox.mDimensions.x;
	float selfYMin = hitBox.mPosition.y;
	float selfYMax = hitBox.mPosition.y + hitBox.mDimensions.y;

	// Other
	float otherXMin = pBox.mPosition.x;
	float otherXMax = pBox.mPosition.x + pBox.mDimensions.x;
	float otherYMin = pBox.mPosition.y;
	float otherYMax = pBox.mPosition.y + pBox.mDimensions.y;

	if (!((selfXMin > otherXMax ||
		selfXMax < otherXMin) ||
		(selfYMin > otherYMax ||
			selfYMax < otherYMin)))
	{
		return true;
	}

	return false;
}

Rectangle Collider2D::GetHitBox()
{
	return mOwner->GetRect();
}

void Collider2D::SetState(ColliderState pState)
{
	mState = pState;
}

ColliderState Collider2D::GetState()
{
	return mState;
}

void Collider2D::OnNotifyCollider(Collider2D* pCollider, ColliderState pState)
{
	SetState(pState);

	printf("Colliiiiiiiiide !");
}
