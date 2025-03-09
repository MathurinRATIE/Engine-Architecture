#include "playerControllerComponent.h"
#include "collider2DComponent.h"
#include "collisionManager.h"

PlayerControllerComponent::PlayerControllerComponent(Actor* pOwner, int pUpdateOrder) : MoveComponent(pOwner, pUpdateOrder), IInputListener()
{
	InputManager::Instance().SubscribeTo(SDLK_q, this);
	InputManager::Instance().SubscribeTo(SDLK_d, this);
	InputManager::Instance().SubscribeTo(SDLK_SPACE, this);
	//InputManager::Instance().SubscribeTo(SDLK_z, this);
	//InputManager::Instance().SubscribeTo(SDLK_s, this);

	mRigidBody = new RigidBody(mOwner, 20.0f, true);
}

PlayerControllerComponent::~PlayerControllerComponent()
{
	delete mRigidBody;
}

void PlayerControllerComponent::OnNotifyInput(SDL_Event& pEvent)
{
	if (mOwner->GetComponentOfType<Collider2D>()->GetState() == ColliderState::CollisionGounded)
	{
		switch (pEvent.key.keysym.sym)
		{
		case SDLK_SPACE:
			if (pEvent.type == SDL_KEYDOWN)
			{
				mOwner->GetComponentOfType<AnimatedSpriteComponent>()->SetAnimationTextures("jump");
				mIsJumpping = true;
				mRigidBody->SetVelocityY(200.0f);
			}
		}
	}
	if (pEvent.key.keysym.sym == SDLK_SPACE && pEvent.type == SDL_KEYUP)
	{
		mIsJumpping = false;
	}

	switch (pEvent.key.keysym.sym)
	{
	case SDLK_q:
		if (pEvent.type == SDL_KEYDOWN)
		{
			mMovementDirection = -1;
		}
		else
		{
			mMovementDirection = 0;
		}
		break;
	case SDLK_d:
		if (pEvent.type == SDL_KEYDOWN)
		{
			mMovementDirection = 1;
		}
		else
		{
			mMovementDirection = 0;
		}
		break;
	}
}

void PlayerControllerComponent::Update()
{
	mRigidBody->Update();

	if (mOwner->GetComponentOfType<Collider2D>()->GetState() == ColliderState::CollisionGounded)
	{
		if (mMovementDirection != mCurrentlyAppliedDirection || !mGrounded)
		{
			switch (mMovementDirection)
			{
			case -1:
				mRigidBody->SetVelocityX(-80.0f);
				mOwner->GetComponentOfType<AnimatedSpriteComponent>()->SetAnimationTextures("walkSide");
				mOwner->GetComponentOfType<SpriteComponent>()->SetFlipX(false);
				break;
			case 0:
				mOwner->GetComponentOfType<AnimatedSpriteComponent>()->SetAnimationTextures("idleSide");
				mRigidBody->SetVelocityX(0.0f);
				break;
			case 1:
				mRigidBody->SetVelocityX(80.0f);
				mOwner->GetComponentOfType<AnimatedSpriteComponent>()->SetAnimationTextures("walkSide");
				mOwner->GetComponentOfType<SpriteComponent>()->SetFlipX(true);
				break;
			}
			mCurrentlyAppliedDirection = mMovementDirection;
		}
		mGrounded = true;

		if (!mIsJumpping)
		{
			mRigidBody->SetVelocityY(0.0f);
		}
	}
	else
	{
		mGrounded = false;
	}

	Vector2* velocity = mRigidBody->GetVelocity();
	Vector2 movement = (Vector2(mOwner->GetTransform()->Right().x, mOwner->GetTransform()->Right().y) * velocity->x
					  + Vector2(mOwner->GetTransform()->Up().x, mOwner->GetTransform()->Up().y) *velocity->y) * Time::deltaTime;

	Vector2 position = Vector2(mOwner->GetTransform()->GetPosition().x, mOwner->GetTransform()->GetPosition().y) + movement;	// Apply movement
	mOwner->GetTransform()->SetPosition(Vector3(position.x, position.y, 0.0f));

	Collider2D* collider = mOwner->GetComponentOfType<Collider2D>();
	if (CollisionManager::Instance().IsColliding(collider))		// Verify collisions
	{
		position -= {movement.x, 0};
		mOwner->GetTransform()->SetPosition(Vector3(position.x, position.y, 0.0f));

		if (collider->CheckCollisions(collider->GetCollidingActor()->GetComponentOfType<Collider2D>()))
		{
			position += {movement.x, 0};
			position -= {0, movement.y};
			mOwner->GetTransform()->SetPosition(Vector3(position.x, position.y, 0.0f));
			mRigidBody->SetVelocityY(0.0f);

			if (collider->CheckCollisions(collider->GetCollidingActor()->GetComponentOfType<Collider2D>()))
			{
				position -= {movement.x, 0};
				mOwner->GetTransform()->SetPosition(Vector3(position.x, position.y, 0.0f));
			}
		}
	}
}
