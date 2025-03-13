#include "rigidBody.h"
#include "actor.h"
#include "collider3DComponent.h"
#include "engineTime.h"

RigidBody::RigidBody(Actor* pOwner, float pMass, bool pEnableGravity) : Component(pOwner)
{
	if (pEnableGravity)
	{
		mForces["gravity"] = Vector3(0, 0, -9.81f);
	}

	mMass = pMass;
}

void RigidBody::AddVelocity(Vector3 pVelocity)
{
	mVelocity += pVelocity;
}

void RigidBody::SetVelocity(Vector3 pVelocity)
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

void RigidBody::SetVelocityZ(float pVelocityZ)
{
	mVelocity.z = pVelocityZ;
}

Vector3* RigidBody::GetVelocity()
{
	return &mVelocity;
}

void RigidBody::Update()
{
	if (!(mOwner->GetComponentOfType<Collider3D>()->GetState() == ColliderState::CollisionGounded))
	{
		AddVelocity(mForces["gravity"] * mMass * Time::deltaTime);
	}
}
