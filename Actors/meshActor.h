#pragma once
#include "actor.h"

class MeshComponent;

class MeshActor : public Actor
{
public:
	MeshActor(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, ActorState pState = ActorState::Active, Transform3D pTransform = Transform3D(), std::string pMeshName = "Cube", std::string pTextureName = "Wall");

	void UpdateActor() override;

	MeshComponent* mMeshComponent;
};

