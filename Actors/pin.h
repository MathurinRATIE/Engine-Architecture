#pragma once
#include "actor.h"

class Pin : public Actor
{
public:
	Pin(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents = {}, ActorState pState = ActorState::Active, Transform3D pTransform = Transform3D());
	~Pin();

	void Reset();

private:
	Vector3 mInitialPosition;
};

