#include "meshActor.h"
#include "spriteComponent.h"
#include "meshComponent.h"
#include "playerControllerComponent.h"
#include "collider3DComponent.h"

MeshActor::MeshActor(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, ActorState pState, Transform3D pTransform) : Actor(pScene, pWindow, pRenderer, pComponents, pState, pTransform)
{
	mMeshComponent = new MeshComponent(this);
	RendererGl* renderer = static_cast<RendererGl*>(pRenderer);
	renderer->AddMesh(mMeshComponent);
	AddComponent(mMeshComponent);

	Collider3D* collider = new Collider3D(this);
	AddComponent(collider);
}

void MeshActor::UpdateActor()
{
}
