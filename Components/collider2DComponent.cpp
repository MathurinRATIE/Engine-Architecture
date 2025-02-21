#include "actor.h"
#include "scene.h"
#include "collider2DComponent.h"
#include "collisionManager.h"

Collider2D::Collider2D(Rectangle* pRect, Actor* pOwner, Actor* pCollidingActor, int pUpdateOrder, bool pIsActive) : Component(pOwner, pUpdateOrder, pIsActive), IColliderListener()
{
	mOwner = pOwner;
    mHitBox = pRect;
	mCollidingActor = pCollidingActor;
	mState = ColliderState::CollisionNone;

	CollisionManager::Instance().SubscribeTo(this, this);
}

void Collider2D::Update()
{
	for (Actor* actor : mOwner->GetScene()->GetActors())
	{
		if (actor != mOwner)
		{
			if (Collider2D* collider = actor->GetComponentOfType<Collider2D>())
			{
				if (CheckCollisions(collider->GetHitBox()))
				{
					mCollidingActor = actor;
				}
			}
		}
	}
}

bool Collider2D::CheckCollisions(Rectangle pBox)
{
	// This
	float selfXMin = mHitBox->mPosition.x;
	float selfXMax = mHitBox->mPosition.x + mHitBox->mDimensions.x;
	float selfYMin = mHitBox->mPosition.y;
	float selfYMax = mHitBox->mPosition.y + mHitBox->mDimensions.y;

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
	return *mHitBox;
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
}
