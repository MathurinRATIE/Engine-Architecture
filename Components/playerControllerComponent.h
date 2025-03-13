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
	Vector3 mMovement = Vector3::zero;
	Vector3 mCurrentlyAppliedMovement = Vector3::zero;
	bool mIsJumpping = false;
	bool mGrounded = false;
	int mMouseDeltaX;
	int mMouseDeltaY;
};
