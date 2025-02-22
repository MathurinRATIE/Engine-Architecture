#pragma once
#include <map>
#include "vector2.h"
#include "component.h"

class RigidBody : public Component
{
public:
	RigidBody(Actor* pOwner, float pMass, bool pEnableGravity);

	void AddVelocity(Vector2 pVelocity);
	void SetVelocity(Vector2 pVelocity);
	void SetVelocityX(float pVelocityX);
	void SetVelocityY(float pVelocityY);
	Vector2 GetVelocity();

	void Update() override;

private:
	float mMass;
	Vector2 mVelocity;
	std::map<std::string, Vector2> mForces;
};

