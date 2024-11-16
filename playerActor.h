#pragma once
#include "scene.h"
#include "direction.h"
#include "transform2D.h"
#include "collider2D.h"
#include "actor.h"

class Player : public Actor
{
public :
	Player(Scene * pScene, std::vector<Component*> pComponents, ActorState pState = ActorState::Active, Transform2D pTransform = Transform2D());

	void UpdateActor(unsigned int pDeltaTime) override;

	void SetDirection(Direction pDirection);

private :
	Direction mDirection;
};