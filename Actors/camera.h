#pragma once
#include "actor.h"
class Camera : public Actor
{
public:
	Camera(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents = {}, ActorState pState = ActorState::Active, Transform3D pTransform = Transform3D());
	~Camera();

	void UpdateActor() override;
};
