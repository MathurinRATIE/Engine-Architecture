#include "cubeActor.h"
#include "spriteComponent.h"
#include "meshComponent.h"
#include "playerControllerComponent.h"
#include "collider3DComponent.h"

CubeActor::CubeActor(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, ActorState pState, Transform3D pTransform) : Actor(pScene, pWindow, pRenderer, pComponents, pState, pTransform)
{
	MeshComponent* meshComponent = new MeshComponent(this);
	RendererGl* renderer = static_cast<RendererGl*>(pRenderer);
	renderer->AddMesh(meshComponent);
	AddComponent(meshComponent);

	/*Texture texture = Assets::GetTextureFromName("Wall");
	SpriteComponent* sprite = new SpriteComponent(this, texture, IRenderer::Flip::None);*/

	Collider3D* collider = new Collider3D(this);
	AddComponent(collider);
}

void CubeActor::UpdateActor()
{
}
