#include "pinControllerComponent.h"
#include "collider3DComponent.h"
#include "collisionManager.h"
#include "actor.h"
#include "engineTime.h"
#include "pin.h"

PinControllerComponent::PinControllerComponent(Actor* pOwner, int pUpdateOrder) : MoveComponent(pOwner, pUpdateOrder)	// todo : add an ignore collisions parameter
{
	mRigidBody = new RigidBody(mOwner, 0.0f, false);
}

PinControllerComponent::~PinControllerComponent()
{
	delete mRigidBody;
}

void PinControllerComponent::Update()
{
	// Translations
	mRigidBody->Update();

	Vector3* velocity = mRigidBody->GetVelocity();
	Vector3 movement = (Vector3::Cross(Vector3::unitZ, mOwner->GetTransform()->Right()) * velocity->x
					  + Vector3::Cross(Vector3::unitZ, mOwner->GetTransform()->Forward()) * velocity->y) * Time::deltaTime;

	Vector3 position = mOwner->GetTransform()->GetPosition() + movement;	// Apply movement
	mOwner->GetTransform()->SetPosition(position);

	Collider3D* collider = mOwner->GetComponentOfType<Collider3D>();
	if (CollisionManager::Instance().IsColliding(collider))		// Verify collisions
	{
		if (collider->GetCollidingActor()->HasTag("Pin"))
		{
			Pin* pin = static_cast<Pin*>(collider->GetCollidingActor());

			float force = mRigidBody->GetVelocity()->Length();
			Vector3 direction = mOwner->GetTransform()->GetPosition() - pin->GetTransform()->GetPosition();
			direction.Normalize();
			Vector3 velocity = direction * force * 0.2;

			pin->GetComponentOfType<PinControllerComponent>()->AddVelocity(velocity);
		}
	}
}

void PinControllerComponent::AddVelocity(Vector3 pVelocity)
{
	mRigidBody->AddVelocity(pVelocity);
}
