#pragma once
#include <map>
#include <string>
#include "vector3.h"
#include "component.h"

class RigidBody : public Component
{
public:
	RigidBody(Actor* pOwner, float pMass, bool pEnableGravity);

	void AddVelocity(Vector3 pVelocity);
	void SetVelocity(Vector3 pVelocity);
	void SetVelocityX(float pVelocityX);
	void SetVelocityY(float pVelocityY);
	void SetVelocityZ(float pVelocityZ);
	Vector3* GetVelocity();

	void Update() override;

private:
	float mMass;
	Vector3 mVelocity;
	std::map<std::string, Vector3> mForces;
};

