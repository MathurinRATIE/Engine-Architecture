#pragma once
#include "scene.h"
#include "direction.h"
#include "collider2DComponent.h"
#include "movementsComponent.h"

class SpaceShip : public Actor
{
public:
	SpaceShip(Scene* pScene, Window* pWindow, std::vector<Component*> pComponents, Transform2D pTransform = Transform2D(), Direction startingDirection = Direction::Right, float mSpeedX = 1.0f, float mSpeedY = 1.0f, ActorState pState = ActorState::Active);

	void UpdateActor(unsigned int pDeltaTime) override;

	Rectangle GetRect() override;

private:
	Rectangle* mRect;
	Movements* mMovements;
	bool* mIsColliding;
};
