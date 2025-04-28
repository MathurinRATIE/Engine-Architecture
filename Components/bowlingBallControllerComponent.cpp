#include "bowlingBallControllerComponent.h"
#include "collider3DComponent.h"
#include "collisionManager.h"
#include "actor.h"
#include "engineTime.h"
#include "pin.h"
#include "PinControllerComponent.h"

BowlingBallControllerComponent::BowlingBallControllerComponent(Actor* pOwner, int pUpdateOrder) : MoveComponent(pOwner, pUpdateOrder), IInputListener()	// todo : add an ignore collisions parameter
{
	InputManager::Instance().SubscribeTo(SDLK_z, this);
	InputManager::Instance().SubscribeTo(SDLK_q, this);
	InputManager::Instance().SubscribeTo(SDLK_s, this);
	InputManager::Instance().SubscribeTo(SDLK_d, this);
	InputManager::Instance().SubscribeTo(SDLK_SPACE, this);

	mRigidBody = new RigidBody(mOwner, 0.0f, false);
}

BowlingBallControllerComponent::~BowlingBallControllerComponent()
{
	delete mRigidBody;
}

void BowlingBallControllerComponent::OnNotifyInput(SDL_Event& pEvent)
{
	switch (pEvent.key.keysym.sym)
	{
	case SDLK_z:
		if (pEvent.type == SDL_KEYDOWN)
		{
			mForce += 0.01f;
		}
		break;
	case SDLK_q:
		if (pEvent.type == SDL_KEYDOWN)
		{
			mDirection += 0.01f;
		}
		break;
	case SDLK_s:
		if (pEvent.type == SDL_KEYDOWN)
		{
			mForce -= 0.01f;
		}
		break;
	case SDLK_d:
		if (pEvent.type == SDL_KEYDOWN)
		{
			mDirection -= 0.01f;
		}
		break;
	case SDLK_SPACE:
		if (pEvent.type == SDL_KEYDOWN)
		{
			if (mIsLaunched && !mShouldLaunch)
			{
				mIsLaunched = false;
			}
			else
			{
				mShouldLaunch = true;
			}
		}
		break;
	}
}

void BowlingBallControllerComponent::Update()
{
	// Translations
	mRigidBody->Update();

	if (mShouldLaunch)
	{
 		mRigidBody->SetVelocityX(mForce);
		mRigidBody->SetVelocityY(mDirection);

		mIsLaunched = true;
		mShouldLaunch = false;
	}

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
			Vector3 velocity = direction * force * 0.5;

			pin->GetComponentOfType<PinControllerComponent>()->AddVelocity(velocity);
		}
	}
}
