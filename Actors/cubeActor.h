#pragma once
#include "actor.h"

class CubeActor : public Actor
{
public:
	CubeActor(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, ActorState pState = ActorState::Active, Transform3D pTransform = Transform3D());
};

