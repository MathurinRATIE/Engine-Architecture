#pragma once
#include "scene.h"
#include "direction.h"
#include "transform2D.h"
#include "bulletActor.h"
#include "collider2DComponent.h"
#include "movementsComponent.h"
#include "actor.h"
#include "spriteComponent.h"
#include "engineTime.h"

class PlayerActor : public Actor
{
public :
	PlayerActor(Scene* pScene, Window* pWindow, Renderer* pRenderer, std::vector<Component*> pComponents, Transform2D pTransform = Transform2D(), float mSpeedX = 1.0f, float mSpeedY = 1.0f, ActorState pState = ActorState::Active);

	void UpdateActor() override;

	void SetDirectionX(Direction pDirectionX);
	void SetDirectionY(Direction pDirectionY);

	Rectangle GetRect() override;

private :
	Scene* mScene;
	Rectangle* mRect;
	MovementComponent* mMovements;
	Renderer* mRenderer;
	Actor* mCollidingActor;
	unsigned int timeSinceLastShot = 0;
};