#pragma once
#include "collider3DComponent.h"
#include "movementsComponent.h"
#include "playerActor.h"
#include "actor.h"

class BulletActor : public Actor
{
public :
	BulletActor(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, Actor* pOwner, Direction pDirectionY = Direction::Down, Transform3D pTransform = Transform3D(), ActorState pState = ActorState::Active);

	Rectangle GetRect() override;

	void UpdateActor() override;

private :
	Rectangle* mRect;
	MovementComponent* mMovements;
	Actor* mOwnerActor;
	Direction mDirectionY;
};

