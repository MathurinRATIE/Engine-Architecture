#pragma once
#include "actor.h"

class PlatformActor : public Actor
{
public:
	PlatformActor(Scene* pScene, Window* pWindow, RendererSdl* pRenderer, std::vector<Component*> pComponents, ActorState pState = ActorState::Active, Transform2D pTransform = Transform2D());
};

