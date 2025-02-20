#pragma once
#include "moveComponent.h"
#include "IInputListener.h"
#include "actor.h"
#include "animatedSpriteComponent.h"

class PlayerControllerComponent : public MoveComponent, public IInputListener
{
public :
	PlayerControllerComponent(Actor* pOwner, int pUpdateOrder = 100);

	void OnNotify(SDL_Event& pEvent) override;
};
