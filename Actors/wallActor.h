#pragma once
#include "scene.h"
#include "direction.h"
#include "transform2D.h"
#include "collider2DComponent.h"
#include "movementsComponent.h"
#include "actor.h"

class WallActor : public Actor
{
public:
	WallActor(Scene* pScene, Window* pWindow, RendererSdl* pRenderer, std::vector<Component*> pComponents, Transform2D pTransform = Transform2D(), ActorState pState = ActorState::Active);

	void UpdateActor() override;

	Rectangle GetRect() override;

private:
	Rectangle* mRect;
};