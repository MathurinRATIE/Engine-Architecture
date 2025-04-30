#include "bowlingBallControllerComponent.h"
#include "collider3DComponent.h"
#include "collisionManager.h"
#include "actor.h"
#include "engineTime.h"
#include "pin.h"
#include "PinControllerComponent.h"
#include "scene.h"

BowlingBallControllerComponent::BowlingBallControllerComponent(Actor* pOwner, int pUpdateOrder) : MoveComponent(pOwner, pUpdateOrder), IInputListener()	// todo : add an ignore collisions parameter
{
	InputManager::Instance().SubscribeTo(SDLK_z, this);
	InputManager::Instance().SubscribeTo(SDLK_q, this);
	InputManager::Instance().SubscribeTo(SDLK_s, this);
	InputManager::Instance().SubscribeTo(SDLK_d, this);
	InputManager::Instance().SubscribeTo(SDLK_SPACE, this);

	mRigidBody = new RigidBody(mOwner, 0.0f, false);

	mInitialPosition = mOwner->GetTransform()->GetPosition();
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
			if (mForce < 10)
			{
				mForce += 0.03f;
				float added = Maths::ATan2(Maths::Abs(mDirection), mForce) - Maths::ATan2(Maths::Abs(mDirection), mForce - 0.03f);
				mArrow->GetTransform()->Rotate(added, mArrow->GetTransform()->Right());
			}
		}
		break;
	case SDLK_q:
		if (pEvent.type == SDL_KEYDOWN)
		{
			if (mDirection > -5)
			{
				mDirection -= 0.03f;
				float added = Maths::ATan2(mDirection, mForce) - Maths::ATan2(mDirection + 0.03f, mForce);
				mArrow->GetTransform()->Rotate(added, mArrow->GetTransform()->Right());
			}
		}
		break;
	case SDLK_s:
		if (pEvent.type == SDL_KEYDOWN)
		{
			if (mForce > 0.03f)
			{
				mForce -= 0.03f;
				float added = Maths::ATan2(Maths::Abs(mDirection), mForce) - Maths::ATan2(Maths::Abs(mDirection), mForce + 0.03f);
				mArrow->GetTransform()->Rotate(added, mArrow->GetTransform()->Right());
			}
		}
		break;
	case SDLK_d:
		if (pEvent.type == SDL_KEYDOWN)
		{
			if (mDirection < 5)
			{
				mDirection += 0.03f;
				float added = Maths::ATan2(mDirection, mForce) - Maths::ATan2(mDirection - 0.03f, mForce);
				mArrow->GetTransform()->Rotate(added, mArrow->GetTransform()->Right());
			}
		}
		break;
	case SDLK_SPACE:
		if (pEvent.type == SDL_KEYDOWN)
		{
			if (mIsLaunched && !mShouldLaunch)
			{
				mShouldReset = true;
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
	if (!mArrow)
	{
		mArrow = mOwner->GetScene()->GetActorsFromTag("Arrow")[0];
		mArrow->GetTransform()->Rotate(Maths::ToRad(90), mArrow->GetTransform()->Forward());
	}

	Vector3 arrowPosition = mArrow->GetTransform()->GetPosition();
	Vector3 arrowScale = mArrow->GetTransform()->GetScale();
	float arrowLength = Maths::Sqrt(mForce * mForce + mDirection * mDirection) / 2;

	mArrow->GetTransform()->SetPosition(Vector3(2 + mForce / 4, mDirection / 4, arrowPosition.z));
	mArrow->GetTransform()->SetScale(Vector3(arrowLength, arrowScale.y, arrowScale.z));

	// Translations
	mRigidBody->Update();

	if (mShouldLaunch)
	{
 		mRigidBody->SetVelocityX(mForce);
		mRigidBody->SetVelocityY(mDirection);

		mIsLaunched = true;
		mShouldLaunch = false;
	}
	else if (mShouldReset)
	{
		mRigidBody->SetVelocity(Vector3());
		mOwner->GetTransform()->SetPosition(mInitialPosition);
		
		std::vector<Actor*> actors = mOwner->GetScene()->GetActors();
		for (Actor* actor : actors)
		{
			if (actor->HasTag("Pin"))
			{
				Pin* pin = static_cast<Pin*>(actor);
				pin->Reset();
			}
		}

		mIsLaunched = false;
		mShouldReset = false;
	}

	Vector3* velocity = mRigidBody->GetVelocity();
	mRigidBody->SetVelocity(*velocity * 0.9999);

	Vector3 movement = Vector3(velocity->x, velocity->y, 0) * Time::deltaTime;

	Vector3 position = mOwner->GetTransform()->GetPosition() + movement;	// Apply movement
	mOwner->GetTransform()->SetPosition(position);

	Collider3D* collider = mOwner->GetComponentOfType<Collider3D>();
	if (CollisionManager::Instance().IsColliding(collider))		// Verify collisions
	{
		if (collider->GetCollidingActor()->HasTag("Pin"))
		{
			Pin* pin = static_cast<Pin*>(collider->GetCollidingActor());

			float force = mRigidBody->GetVelocity()->Length();
			Vector3 direction = pin->GetTransform()->GetPosition() - mOwner->GetTransform()->GetPosition();
			direction.Normalize();
			Vector3 velocity = direction * force * 2;

			pin->GetComponentOfType<PinControllerComponent>()->SetVelocity(velocity);
		}
		else if (!collider->GetCollidingActor()->HasTag("Arrow"))
		{
			// Revert Movement
			position = mOwner->GetTransform()->GetPosition() - movement;
			mOwner->GetTransform()->SetPosition(position);
		}
	}
}
