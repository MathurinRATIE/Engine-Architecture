#pragma once
#include "scene.h"
#include "direction.h"
#include "transform3D.h"
#include "collider3DComponent.h"
#include "movementsComponent.h"
#include "actor.h"

class WallActor : public Actor
{
public:
	WallActor(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, Transform3D pTransform = Transform3D(), ActorState pState = ActorState::Active);

	void UpdateActor() override;

	Rectangle GetRect() override;

private:
	Rectangle* mRect;
};