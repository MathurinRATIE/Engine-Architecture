#include "playerControllerComponent.h"

PlayerControllerComponent::PlayerControllerComponent(Actor* pOwner, int pUpdateOrder) : MoveComponent(pOwner, pUpdateOrder), IInputListener()
{
	InputManager::Instance().SubscribeTo(SDLK_z, this);
	InputManager::Instance().SubscribeTo(SDLK_q, this);
	InputManager::Instance().SubscribeTo(SDLK_s, this);
	InputManager::Instance().SubscribeTo(SDLK_d, this);
}

void PlayerControllerComponent::OnNotifyInput(SDL_Event& pEvent)
{
	switch (pEvent.key.keysym.sym)
	{
	case SDLK_z:
		if (pEvent.type == SDL_KEYDOWN)
		{
			mSpeed.y = 30.0f;
			mOwner->GetComponentOfType<AnimatedSpriteComponent>()->SetAnimationTextures("walkBack");
			mOwner->GetComponentOfType<SpriteComponent>()->SetFlipX(false);
		}
		else
		{
			mSpeed.y = 0.0f;
		}
		break;
	case SDLK_s:
		if (pEvent.type == SDL_KEYDOWN)
		{
			mSpeed.y = -30.0f;
			mOwner->GetComponentOfType<AnimatedSpriteComponent>()->SetAnimationTextures("walkFront");
			mOwner->GetComponentOfType<SpriteComponent>()->SetFlipX(false);
		}
		else
		{
			mSpeed.y = 0.0f;
		}
		break;
	case SDLK_q:
		if (pEvent.type == SDL_KEYDOWN)
		{
			mSpeed.x = -30.0f;
			mOwner->GetComponentOfType<AnimatedSpriteComponent>()->SetAnimationTextures("walkSide");
			mOwner->GetComponentOfType<SpriteComponent>()->SetFlipX(false);
		}
		else
		{
			mSpeed.x = 0.0f;
		}
		break;
	case SDLK_d:
		if (pEvent.type == SDL_KEYDOWN)
		{
			mSpeed.x = 30.0f;
			mOwner->GetComponentOfType<AnimatedSpriteComponent>()->SetAnimationTextures("walkSide");
			mOwner->GetComponentOfType<SpriteComponent>()->SetFlipX(true);
		}
		else
		{
			mSpeed.x = 0.0f;
		}
		break;
	}
}
