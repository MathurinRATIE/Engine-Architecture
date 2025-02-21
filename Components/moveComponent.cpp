#include "moveComponent.h"
#include "actor.h"
#include "engineTime.h"
#include "collider2DComponent.h"

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
	Collider2D* collider = mOwner->GetComponentOfType<Collider2D>();
	if (collider != nullptr && collider->GetState() != ColliderState::CollisionNone)
	{
		return;
	}

	if (!Maths::NearZero(mSpeed.SqrLength()))
	{
		Vector2 position = mOwner->GetTransform().GetPosition();
		position += (mOwner->GetTransform().Right() * mSpeed.x
				    + mOwner->GetTransform().Up() * mSpeed.y) * Time::deltaTime;

		Transform2D transform = mOwner->GetTransform();   // TODO : WTF can't i make this in one line
		transform.SetPosition(position);
		mOwner->SetTransform(transform);
	}
}
