#pragma once
#include "vector2.h"
#include "Component.h"
#include "maths.h"

class MoveComponent : public Component
{
public:
	MoveComponent(Actor* pOwner, int pUpdateOrder = 100);
	MoveComponent() = delete;
	MoveComponent(const MoveComponent&) = delete;
	MoveComponent& operator= (const MoveComponent&) = delete;

	Vector2 GetSpeed() const;
	void SetSpeed(Vector2 pSpeed);

	void Update() override;

private:
	Vector2 mSpeed;
};
