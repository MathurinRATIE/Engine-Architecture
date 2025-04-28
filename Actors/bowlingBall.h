#pragma once
#include "actor.h"

class BowlingBall : public Actor
{
public:
	BowlingBall(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents = {}, ActorState pState = ActorState::Active, Transform3D pTransform = Transform3D());
	~BowlingBall();
};

