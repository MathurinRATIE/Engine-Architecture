#include "cubeActor.h"
#include "spriteComponent.h"
#include "meshComponent.h"

CubeActor::CubeActor(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, ActorState pState, Transform3D pTransform) : Actor(pScene, pWindow, pRenderer, pComponents, pState, pTransform)
{
	MeshComponent* meshComponent = new MeshComponent(this);
	RendererGl* renderer = static_cast<RendererGl*>(pRenderer);
	renderer->AddMesh(meshComponent);
	AddComponent(meshComponent);
}

void CubeActor::UpdateActor()
{
}
