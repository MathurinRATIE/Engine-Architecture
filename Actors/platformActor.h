#pragma once
#include "actor.h"

class PlatformActor : public Actor
{
public:
	PlatformActor(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, ActorState pState = ActorState::Active, Transform3D pTransform = Transform3D());
};

