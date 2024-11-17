#pragma once
#include "collider2DComponent.h"
#include "movementsComponent.h"
#include "playerActor.h"
#include "actor.h"

class Bullet : public Actor
{
public :
	Bullet(Scene* pScene, Window* pWindow, std::vector<Component*> pComponents, Actor* pOwner, Direction pDirectionY = Direction::Down, Transform2D pTransform = Transform2D(), ActorState pState = ActorState::Active);

	Rectangle GetRect() override;

	void UpdateActor(unsigned int pDeltaTime) override;

private :
	Rectangle* mRect;
	Movements* mMovements;
	Actor* mOwnerActor;
	Actor** mCollidingActor;
	Direction mDirectionY;
};

