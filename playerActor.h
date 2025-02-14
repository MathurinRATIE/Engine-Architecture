#pragma once
#include "scene.h"
#include "direction.h"
#include "transform2D.h"
#include "bulletActor.h"
#include "collider2DComponent.h"
#include "movementsComponent.h"
#include "actor.h"
#include "spriteComponent.h"

class Player : public Actor
{
public :
	Player(Scene* pScene, Window* pWindow, Renderer* pRenderer, std::vector<Component*> pComponents, Transform2D pTransform = Transform2D(), float mSpeedX = 1.0f, float mSpeedY = 1.0f, ActorState pState = ActorState::Active);

	void UpdateActor(unsigned int pDeltaTime) override;

	void SetDirectionX(Direction pDirectionX);
	void SetDirectionY(Direction pDirectionY);

	Rectangle GetRect() override;

private :
	Scene* mScene;
	Rectangle* mRect;
	Movements* mMovements;
	Renderer* mRenderer;
	Actor* mCollidingActor;
	unsigned int timeSinceLastShot = 0;
};