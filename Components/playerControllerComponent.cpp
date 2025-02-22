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
			/*case SDLK_z:
				if (pEvent.type == SDL_KEYDOWN)
				{
					mRigidBody->SetMinVelocityY(30.0f);
					mOwner->GetComponentOfType<AnimatedSpriteComponent>()->SetAnimationTextures("walkBack");
					mOwner->GetComponentOfType<SpriteComponent>()->SetFlipX(false);
				}
				else
				{
					mRigidBody->SetVelocityY(0.0f);
				}
				break;
			case SDLK_s:
				if (pEvent.type == SDL_KEYDOWN)
				{
					mRigidBody->SetMinVelocityY(-30.0f);
					mOwner->GetComponentOfType<AnimatedSpriteComponent>()->SetAnimationTextures("walkFront");
					mOwner->GetComponentOfType<SpriteComponent>()->SetFlipX(false);
				}
				else
				{
					mRigidBody->SetVelocityY(0.0f);
				}
				break;*/
		case SDLK_q:
			if (pEvent.type == SDL_KEYDOWN)
			{
				mRigidBody->SetVelocityX(-80.0f);
				mOwner->GetComponentOfType<AnimatedSpriteComponent>()->SetAnimationTextures("walkSide");
				mOwner->GetComponentOfType<SpriteComponent>()->SetFlipX(false);
			}
			else
			{
				mOwner->GetComponentOfType<AnimatedSpriteComponent>()->SetAnimationTextures("idleSide");
				mRigidBody->SetVelocityX(0.0f);
			}
			break;
		case SDLK_d:
			if (pEvent.type == SDL_KEYDOWN)
			{
				mRigidBody->SetVelocityX(80.0f);
				mOwner->GetComponentOfType<AnimatedSpriteComponent>()->SetAnimationTextures("walkSide");
				mOwner->GetComponentOfType<SpriteComponent>()->SetFlipX(true);
			}
			else
			{
				mOwner->GetComponentOfType<AnimatedSpriteComponent>()->SetAnimationTextures("idleSide");
				mRigidBody->SetVelocityX(0.0f);
			}
			break;
		case SDLK_SPACE:
			if (pEvent.type == SDL_KEYDOWN)
			{
				mIsJumpping = true;
				mRigidBody->SetVelocityY(200.0f);
			}
		}
	}
	if (pEvent.key.keysym.sym == SDLK_SPACE && pEvent.type == SDL_KEYUP)
	{
		mIsJumpping = false;
	}
}

void PlayerControllerComponent::Update()
{
	mRigidBody->Update();
	Vector2* velocity = mRigidBody->GetVelocity();

	if (!Maths::NearZero(velocity->SqrLength()) && mOwner->GetComponentOfType<Collider2D>()->GetState() == ColliderState::CollisionGounded && !mIsJumpping)
	{
		mRigidBody->SetVelocityY(0.0f);
	}

	if (mOwner->GetComponentOfType<Collider2D>()->GetState() == ColliderState::CollisionGounded)
	{
		if (!mGrounded)
		{
			mRigidBody->SetVelocityX(0.0f);
		}

		mGrounded = true;
		printf("GROUNDED");
	}
	else {
		mGrounded = false;
		printf("In the air");
	}

	Vector2 movement = (mOwner->GetTransform()->Right() * velocity->x 
		              + mOwner->GetTransform()->Up()* velocity->y) * Time::deltaTime;

	Vector2 position = mOwner->GetTransform()->GetPosition() + movement;	// Apply movement
	mOwner->GetTransform()->SetPosition(position);

	if (CollisionManager::Instance().IsColliding(mOwner->GetComponentOfType<Collider2D>()))		// Verify collisions
	{
		position -= movement;
		mOwner->GetTransform()->SetPosition(position);
		mRigidBody->SetVelocityY(0.0f);
	}
}
