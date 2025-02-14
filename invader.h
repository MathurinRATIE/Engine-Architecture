#pragma once
#include "scene.h"
#include "direction.h"
#include "bulletActor.h"
#include "collider2DComponent.h"
#include "movementsComponent.h"

class Invader : public Actor
{
public:
	Invader(Scene* pScene, Window* pWindow, Renderer* pRenderer, std::vector<Component*> pComponents, Transform2D pTransform = Transform2D(), Direction startingDirection = Direction::Right, float mSpeedX = 1.0f, float mSpeedY = 1.0f, ActorState pState = ActorState::Active);

	void UpdateActor(unsigned int pDeltaTime) override;

	Rectangle GetRect() override;

private:
	Scene* mScene;
	Rectangle* mRect;
	Movements* mMovements;
	Renderer* mRenderer;
	Actor** mCollidingActor;
	unsigned int timeSinceLastShot = 0;
};
