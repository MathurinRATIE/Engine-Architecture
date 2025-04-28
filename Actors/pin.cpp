#include "pin.h"
#include "collider3DComponent.h"
#include "PinControllerComponent.h"
#include "meshComponent.h"
#include "assets.h"
#include "rendererGl.h"

Pin::Pin(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, ActorState pState, Transform3D pTransform) : Actor(pScene, pWindow, pRenderer, pComponents, pState, pTransform)
{
	Collider3D* collider = new Collider3D(this);
	AddComponent(collider);

	PinControllerComponent* controller = new PinControllerComponent(this);
	AddComponent(controller);

	MeshComponent* meshComponent = new MeshComponent(this);
	meshComponent->SetMesh(*Assets::GetMeshFromName("Pin"));
	Texture* texture = &Assets::GetTextureFromName("Pin");
	meshComponent->GetMesh()->AddTexture(texture);
	int index = meshComponent->GetTextureIndex("Pin");
	meshComponent->SetTextureIndex(index);
	meshComponent->GetMesh()->SetShaderProgram(Assets::GetShaderProgramFromName("Mesh"));

	RendererGl* renderer = static_cast<RendererGl*>(pRenderer);
	renderer->AddMesh(meshComponent);
	AddComponent(meshComponent);

	AddTag("Pin");
}

Pin::~Pin()
{
}