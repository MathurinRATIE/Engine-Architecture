#include "actor.h"
#include "scene.h"
#include "collider3DComponent.h"
#include "collisionManager.h"

Collider3D::Collider3D(Actor* pOwner, Vector3 pBeforeOffset, Vector3 pAfterOffset, Actor* pCollidingActor, int pUpdateOrder, bool pIsActive) : Component(pOwner, pUpdateOrder, pIsActive), IColliderListener()
{
	mOwner = pOwner;
	mBeforeOffset = pBeforeOffset;
	mAfterOffset = pAfterOffset;
	mCollidingActor = pCollidingActor;
	mState = ColliderState::CollisionNone;

	CollisionManager::Instance().SubscribeTo(this, this);
}

void Collider3D::Update()
{
}

bool Collider3D::CheckCollisions(Collider3D* pCollider)
{
	Cube selfHitBox = GetHitBox();
	Cube otherHitBox = pCollider->GetHitBox();

	// This
	float selfXMin = selfHitBox.mPosition.x;
	float selfXMax = selfHitBox.mPosition.x + selfHitBox.mDimensions.x;
	float selfYMin = selfHitBox.mPosition.y;
	float selfYMax = selfHitBox.mPosition.y + selfHitBox.mDimensions.y;
	float selfZMin = selfHitBox.mPosition.z;
	float selfZMax = selfHitBox.mPosition.z + selfHitBox.mDimensions.z;

	// Other
	float otherXMin = otherHitBox.mPosition.x;
	float otherXMax = otherHitBox.mPosition.x + otherHitBox.mDimensions.x;
	float otherYMin = otherHitBox.mPosition.y;
	float otherYMax = otherHitBox.mPosition.y + otherHitBox.mDimensions.y;
	float otherZMin = otherHitBox.mPosition.z;
	float otherZMax = otherHitBox.mPosition.z + otherHitBox.mDimensions.z;

	if (!((selfXMin > otherXMax ||
		selfXMax < otherXMin) ||
		(selfYMin > otherYMax ||
			selfYMax < otherYMin) ||
		(selfZMin > otherZMax ||
			selfZMax < otherZMin)))
	{
		mCollidingActor = pCollider->mOwner;
		return true;
	}

	return false;
}

bool Collider3D::CheckGrounded(Cube potherHitBox)
{
	Cube hitBox = GetHitBox();
	// This
	float selfXMin = hitBox.mPosition.x;
	float selfXMax = hitBox.mPosition.x + hitBox.mDimensions.x;
	float selfYMin = hitBox.mPosition.y;
	float selfYMax = hitBox.mPosition.y + hitBox.mDimensions.y;
	float selfZMax = hitBox.mPosition.z + hitBox.mDimensions.z;

	// Other
	float otherXMin = potherHitBox.mPosition.x;
	float otherXMax = potherHitBox.mPosition.x + potherHitBox.mDimensions.x;
	float otherYMin = potherHitBox.mPosition.y;
	float otherYMax = potherHitBox.mPosition.y + potherHitBox.mDimensions.y;
	float otherZMin = potherHitBox.mPosition.z;

	if (!((selfXMin > otherXMax ||
		selfXMax < otherXMin) ||
		 (selfYMin > otherYMax ||
		selfYMax < otherYMin)) &&
		abs(selfZMax - otherZMin) < 0.1)
	{
		return true;
	}

	return false;
}

Cube Collider3D::GetHitBox()
{
	Vector3 position = mOwner->GetTransform()->GetPosition();
	position.x -= mBeforeOffset.x;
	position.y -= mBeforeOffset.y;
	position.z -= mBeforeOffset.z;
	
	Vector3 scale = mOwner->GetTransform()->GetScale();
	scale.x += mBeforeOffset.x + mAfterOffset.x;
	scale.y += mBeforeOffset.y + mAfterOffset.y;
	scale.z += mBeforeOffset.z + mAfterOffset.z;

	return { position, scale };
}

void Collider3D::SetState(ColliderState pState)
{
	mState = pState;
}

ColliderState Collider3D::GetState()
{
	return mState;
}

Actor* Collider3D::GetCollidingActor()
{
	return mCollidingActor;
}

void Collider3D::OnNotifyCollider(Collider3D* pCollider, ColliderState pState)
{
	SetState(pState);

	if (pCollider)
	{
		mCollidingActor = pCollider->GetOwner();
	}
}
