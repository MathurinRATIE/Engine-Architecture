#include "playerControllerComponent.h"
#include "collider3DComponent.h"
#include "collisionManager.h"

PlayerControllerComponent::PlayerControllerComponent(Actor* pOwner, int pUpdateOrder) : MoveComponent(pOwner, pUpdateOrder), IInputListener()
{
	InputManager::Instance().SubscribeTo(SDLK_z, this);
	InputManager::Instance().SubscribeTo(SDLK_q, this);
	InputManager::Instance().SubscribeTo(SDLK_s, this);
	InputManager::Instance().SubscribeTo(SDLK_d, this);
	InputManager::Instance().SubscribeTo(SDLK_SPACE, this);
	InputManager::Instance().SubscribeTo(SDLK_LSHIFT, this);
	InputManager::Instance().SubscribeTo(SDL_WINDOW_MOUSE_CAPTURE, this);

	mRigidBody = new RigidBody(mOwner, 20.0f, true);
}

PlayerControllerComponent::~PlayerControllerComponent()
{
	delete mRigidBody;
}

void PlayerControllerComponent::OnNotifyInput(SDL_Event& pEvent)
{
	/*if (mOwner->GetComponentOfType<Collider3D>()->GetState() == ColliderState::CollisionGounded)
	{
		switch (pEvent.key.keysym.sym)
		{
		case SDLK_SPACE:
			if (pEvent.type == SDL_KEYDOWN)
			{
				mIsJumpping = true;
				mRigidBody->SetVelocityZ(200.0f);
			}
		}
	}
	if (pEvent.key.keysym.sym == SDLK_SPACE && pEvent.type == SDL_KEYUP)
	{
		mIsJumpping = false;
	}*/

	switch (pEvent.key.keysym.sym)
	{
	case SDLK_z:
		if (pEvent.type == SDL_KEYDOWN)
		{
			mMovement.x = 1;
		}
		else
		{
			mMovement.x = 0;
		}
		break;
	case SDLK_q:
		if (pEvent.type == SDL_KEYDOWN)
		{
			mMovement.y = -1;
		}
		else
		{
			mMovement.y = 0;
		}
		break;
	case SDLK_s:
		if (pEvent.type == SDL_KEYDOWN)
		{
			mMovement.x = -1;
		}
		else
		{
			mMovement.x = 0;
		}
		break;
	case SDLK_d:
		if (pEvent.type == SDL_KEYDOWN)
		{
			mMovement.y = 1;
		}
		else
		{
			mMovement.y = 0;
		}
		break;
	case SDLK_SPACE:
		if (pEvent.type == SDL_KEYDOWN)
		{
			//mIsJumpping = true;
			//mRigidBody->SetVelocityZ(200.0f);
			mMovement.z = 1;
		}
		else
		{
			mMovement.z = 0;
		}
	case SDLK_LSHIFT:
		if (pEvent.type == SDL_KEYDOWN)
		{
			mMovement.z = -1;
		}
		else
		{
			mMovement.z = 0;
		}
	}
}

void PlayerControllerComponent::Update()
{
	mRigidBody->Update();

	//if (mOwner->GetComponentOfType<Collider3D>()->GetState() == ColliderState::CollisionGounded)
	//{
		if (mMovement != mCurrentlyAppliedMovement)
		{
			mRigidBody->SetVelocityX(mMovement.x * 5.0f);
			mRigidBody->SetVelocityY(mMovement.y * 5.0f);
			mRigidBody->SetVelocityZ(mMovement.z * 5.0f);	// TODO : It is alway negative

			mCurrentlyAppliedMovement = mMovement;
		}
		//mGrounded = true;

		/*if (!mIsJumpping)
		{
			mRigidBody->SetVelocityZ(0.0f);
		}*/
	//}
	//else
	//{
		//mGrounded = false;
	//}

	Vector3* velocity = mRigidBody->GetVelocity();
	Vector3 movement = (mOwner->GetTransform()->Forward() * velocity->x
					  + mOwner->GetTransform()->Right() * velocity->y
					  + mOwner->GetTransform()->Up() * velocity->z) * Time::deltaTime;

	Vector3 position = mOwner->GetTransform()->GetPosition() + movement;	// Apply movement
	mOwner->GetTransform()->SetPosition(position);

	Collider3D* collider = mOwner->GetComponentOfType<Collider3D>();
	if (CollisionManager::Instance().IsColliding(collider))		// Verify collisions
	{
		position -= Vector3(movement.x, movement.y, 0);
		mOwner->GetTransform()->SetPosition(position);

		if (collider->CheckCollisions(collider->GetCollidingActor()->GetComponentOfType<Collider3D>()))
		{
			position += Vector3(movement.x, movement.y, 0);
			position -= Vector3(0, 0, movement.z);
			mOwner->GetTransform()->SetPosition(position);
			mRigidBody->SetVelocityZ(0.0f);

			if (collider->CheckCollisions(collider->GetCollidingActor()->GetComponentOfType<Collider3D>()))
			{
				position -= Vector3(movement.x, movement.y, 0);
				mOwner->GetTransform()->SetPosition(position);
			}
		}
	}
}
