#pragma once
#include "scene.h"
#include "direction.h"
#include "bulletActor.h"
#include "collider3DComponent.h"
#include "movementsComponent.h"
#include "engineTime.h"

class InvaderActor : public Actor
{
public:
	InvaderActor(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, Transform3D pTransform = Transform3D(), Direction startingDirection = Direction::Right, float mSpeedX = 1.0f, float mSpeedY = 1.0f, ActorState pState = ActorState::Active);

	void UpdateActor() override;

	Rectangle GetRect() override;

private:
	Scene* mScene;
	Rectangle* mRect;
	MovementComponent* mMovements;
	float timeSinceLastShot = 0;
};
