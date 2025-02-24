#include "actor.h"
#include "scene.h"
#include "collider2DComponent.h"
#include "collisionManager.h"

Collider2D::Collider2D(Actor* pOwner, Vector4 pOffset, Actor* pCollidingActor, int pUpdateOrder, bool pIsActive) : Component(pOwner, pUpdateOrder, pIsActive), IColliderListener()
{
	mOwner = pOwner;
	mOffset = pOffset;
	mCollidingActor = pCollidingActor;
	mState = ColliderState::CollisionNone;

	CollisionManager::Instance().SubscribeTo(this, this);
}

void Collider2D::Update()
{
}

bool Collider2D::CheckCollisions(Collider2D* pCollider)
{
	Rectangle selfHitBox = GetHitBox();
	Rectangle otherHitBox = pCollider->GetHitBox();

	// This
	float selfXMin = selfHitBox.mPosition.x;
	float selfXMax = selfHitBox.mPosition.x + selfHitBox.mDimensions.x;
	float selfYMin = selfHitBox.mPosition.y;
	float selfYMax = selfHitBox.mPosition.y + selfHitBox.mDimensions.y;

	// Other
	float otherXMin = otherHitBox.mPosition.x;
	float otherXMax = otherHitBox.mPosition.x + otherHitBox.mDimensions.x;
	float otherYMin = otherHitBox.mPosition.y;
	float otherYMax = otherHitBox.mPosition.y + otherHitBox.mDimensions.y;

	if (!((selfXMin > otherXMax ||
		selfXMax < otherXMin) ||
		(selfYMin > otherYMax ||
			selfYMax < otherYMin)))
	{
		mCollidingActor = pCollider->mOwner;
		return true;
	}

	return false;
}

bool Collider2D::CheckGrounded(Rectangle pBox)
{
	Rectangle hitBox = GetHitBox();
	// This
	float selfXMin = hitBox.mPosition.x;
	float selfXMax = hitBox.mPosition.x + hitBox.mDimensions.x;
	float selfYMax = hitBox.mPosition.y + hitBox.mDimensions.y;

	// Other
	float otherXMin = pBox.mPosition.x;
	float otherXMax = pBox.mPosition.x + pBox.mDimensions.x;
	float otherYMin = pBox.mPosition.y;

	if (!(selfXMin > otherXMax ||
		selfXMax < otherXMin) &&
		abs(selfYMax - otherYMin) < 0.1)
	{
		return true;
	}

	return false;
}

Rectangle Collider2D::GetHitBox()
{
	Rectangle rect = mOwner->GetRect();
	rect.mPosition.x -= mOffset.x;	// x --> horizontal before / y --> horizontal after / z --> vertical before / w --> vertical after
	rect.mPosition.y -= mOffset.z;
	rect.mDimensions.x += mOffset.x + mOffset.y;
	rect.mDimensions.y += mOffset.z + mOffset.w;

	return rect;
}

void Collider2D::SetState(ColliderState pState)
{
	mState = pState;
}

ColliderState Collider2D::GetState()
{
	return mState;
}

Actor* Collider2D::GetCollidingActor()
{
	return mCollidingActor;
}

void Collider2D::OnNotifyCollider(Collider2D* pCollider, ColliderState pState)
{
	SetState(pState);

	if (pCollider)
	{
		mCollidingActor = pCollider->GetOwner();
	}
}
