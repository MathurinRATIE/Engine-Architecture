#pragma once
#include "moveComponent.h"
#include "IInputListener.h"
#include "animatedSpriteComponent.h"
#include "rigidBody.h"

class PlayerControllerComponent : public MoveComponent, public IInputListener
{
public :
	PlayerControllerComponent(Actor* pOwner, int pUpdateOrder = 100);
	~PlayerControllerComponent();

	void OnNotifyInput(SDL_Event& pEvent) override;
	void Update() override;

private:
	RigidBody* mRigidBody;
	bool mIsJumpping = false;
	bool mGrounded = false;
};
