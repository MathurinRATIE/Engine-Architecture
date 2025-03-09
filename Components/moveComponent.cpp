#include "moveComponent.h"
#include "actor.h"
#include "engineTime.h"
#include "collider2DComponent.h"
#include "collisionManager.h"

MoveComponent::MoveComponent(Actor* pOwner, int pUpdateOrder) : Component(pOwner, pUpdateOrder)
{
	mSpeed = 0.0f;
}

Vector2 MoveComponent::GetSpeed() const
{
	return mSpeed;
}

void MoveComponent::SetSpeed(Vector2 pSpeed)
{
	mSpeed = pSpeed;
}

void MoveComponent::Update()
{
	if (!Maths::NearZero(mSpeed.SqrLength()))
	{
		Vector3 movement = (mOwner->GetTransform()->Right() * mSpeed.x +	// Calculate movement
			mOwner->GetTransform()->Up() * mSpeed.y) * Time::deltaTime;

		Vector3 position = mOwner->GetTransform()->GetPosition() + movement;	// Apply movement
		mOwner->GetTransform()->SetPosition(position);

		if (CollisionManager::Instance().IsColliding(mOwner->GetComponentOfType<Collider2D>()))		// Verify collisions
		{
			position -= movement;
			mOwner->GetTransform()->SetPosition(position);
		}
	}
}
