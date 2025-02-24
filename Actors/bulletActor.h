#pragma once
#include "collider2DComponent.h"
#include "movementsComponent.h"
#include "playerActor.h"
#include "actor.h"

class BulletActor : public Actor
{
public :
	BulletActor(Scene* pScene, Window* pWindow, RendererSdl* pRenderer, std::vector<Component*> pComponents, Actor* pOwner, Direction pDirectionY = Direction::Down, Transform2D pTransform = Transform2D(), ActorState pState = ActorState::Active);

	Rectangle GetRect() override;

	void UpdateActor() override;

private :
	Rectangle* mRect;
	MovementComponent* mMovements;
	Actor* mOwnerActor;
	Direction mDirectionY;
};

