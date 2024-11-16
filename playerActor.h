#pragma once
#include "scene.h"
#include "direction.h"
#include "transform2D.h"
#include "collider2DComponent.h"
#include "movementsComponent.h"
#include "actor.h"

class Player : public Actor
{
public :
	Player(Scene* pScene, std::vector<Component*> pComponents, ActorState pState = ActorState::Active, Transform2D pTransform = Transform2D());

	void UpdateActor(unsigned int pDeltaTime) override;

	void SetDirectionX(Direction pDirectionX);
	void SetDirectionY(Direction pDirectionY);

	Rectangle GetRect();

private :
	Direction mDirectionX;
	Direction mDirectionY;
	Rectangle* mRect;
};