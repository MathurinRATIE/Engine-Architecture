#include "moveComponent.h"
#include "actor.h"
#include "engineTime.h"
#include "collider3DComponent.h"
#include "collisionManager.h"

MoveComponent::MoveComponent(Actor* pOwner, int pUpdateOrder) : Component(pOwner, pUpdateOrder)
{
	mSpeed = Vector3::zero;
}

Vector3 MoveComponent::GetSpeed() const
{
	return mSpeed;
}

void MoveComponent::SetSpeed(Vector3 pSpeed)
{
	mSpeed = pSpeed;
}

void MoveComponent::Update()
{
	if (!Maths::NearZero(mSpeed.LengthSq()))
	{
		Vector3 movement = (mOwner->GetTransform()->Forward() * mSpeed.x +	// Calculate movement
							mOwner->GetTransform()->Right() * mSpeed.y + 
							mOwner->GetTransform()->Up() * mSpeed.z) * Time::deltaTime;

		Vector3 position = mOwner->GetTransform()->GetPosition() + movement;	// Apply movement
		mOwner->GetTransform()->SetPosition(position);

		if (CollisionManager::Instance().IsColliding(mOwner->GetComponentOfType<Collider3D>()))		// Verify collisions
		{
			position -= movement;
			mOwner->GetTransform()->SetPosition(position);
		}
	}
}
