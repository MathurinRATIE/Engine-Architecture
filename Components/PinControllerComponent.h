#pragma once
#include "moveComponent.h"
#include "IInputListener.h"
#include "rigidBody.h"

class PinControllerComponent : public MoveComponent
{
public :
	PinControllerComponent(Actor* pOwner, int pUpdateOrder = 100);
	~PinControllerComponent();

	void Update() override;
	void SetVelocity(Vector3 pVelocity);

private:
	RigidBody* mRigidBody;
	float mForce = 5;
	float mDirection = 0;
	bool mIsLaunched = false;
	bool mShouldLaunch = false;
};
