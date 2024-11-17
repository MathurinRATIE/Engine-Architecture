#pragma once
#include "scene.h"
#include "direction.h"
#include "transform2D.h"
#include "collider2DComponent.h"
#include "movementsComponent.h"
#include "actor.h"

class Wall : public Actor
{
public:
	Wall(Scene* pScene, Window* pWindow, std::vector<Component*> pComponents, Transform2D pTransform = Transform2D(), ActorState pState = ActorState::Active);

	void UpdateActor(unsigned int pDeltaTime) override;

	Rectangle GetRect() override;

private:
	Rectangle* mRect;
};