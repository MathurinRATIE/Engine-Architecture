#include "rigidBody.h"
#include "actor.h"
#include "collider2DComponent.h"
#include "engineTime.h"

RigidBody::RigidBody(Actor* pOwner, float pMass, bool pEnableGravity) : Component(pOwner)
{
	if (pEnableGravity)
	{
		mForces["gravity"] = Vector2(0, -9.81f);
	}

	mMass = pMass;
}

void RigidBody::AddVelocity(Vector2 pVelocity)
{
	mVelocity += pVelocity;
}

void RigidBody::SetVelocity(Vector2 pVelocity)
{
	mVelocity = pVelocity;
}

void RigidBody::SetVelocityX(float pVelocityX)
{
	mVelocity.x = pVelocityX;
}

void RigidBody::SetVelocityY(float pVelocityY)
{
	mVelocity.y = pVelocityY;
}

Vector2* RigidBody::GetVelocity()
{
	return &mVelocity;
}

void RigidBody::Update()
{
	if (!(mOwner->GetComponentOfType<Collider2D>()->GetState() == ColliderState::CollisionGounded))
	{
		AddVelocity(mForces["gravity"] * mMass * Time::deltaTime);
	}
}
