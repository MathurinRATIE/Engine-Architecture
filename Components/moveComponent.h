#pragma once
#include "vector3.h"
#include "component.h"
#include "maths.h"
#include "inputManager.h"

class MoveComponent : public Component
{
public:
	MoveComponent(Actor* pOwner, int pUpdateOrder = 100);
	MoveComponent() = delete;
	MoveComponent(const MoveComponent&) = delete;
	MoveComponent& operator= (const MoveComponent&) = delete;

	Vector3 GetSpeed() const;
	void SetSpeed(Vector3 pSpeed);

	void Update() override;

protected:
	Vector3 mSpeed;
};
