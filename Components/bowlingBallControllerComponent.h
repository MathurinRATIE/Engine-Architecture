#pragma once
#include "moveComponent.h"
#include "IInputListener.h"
#include "rigidBody.h"
#include "bowlingBall.h"

class BowlingBallControllerComponent : public MoveComponent, public IInputListener
{
public :
	BowlingBallControllerComponent(Actor* pOwner, int pUpdateOrder = 100);
	~BowlingBallControllerComponent();

	void OnNotifyInput(SDL_Event& pEvent) override;
	void Update() override;

private:
	RigidBody* mRigidBody;
	Actor* mArrow;
	float mForce = 3;
	float mDirection = 0.1;
	bool mIsLaunched = false;
	bool mShouldLaunch = false;
	bool mShouldReset = false;
	Vector3 mInitialPosition;
};
