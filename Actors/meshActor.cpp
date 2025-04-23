#include "meshActor.h"
#include "spriteComponent.h"
#include "meshComponent.h"
#include "playerControllerComponent.h"
#include "collider3DComponent.h"

MeshActor::MeshActor(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, ActorState pState, Transform3D pTransform, std::string pMeshName, std::string pTextureName, std::string pShaderProgramName) : Actor(pScene, pWindow, pRenderer, pComponents, pState, pTransform)
{
	MeshComponent* meshComponent = new MeshComponent(this);
	meshComponent->SetMesh(*Assets::GetMeshFromName(pMeshName));
	Texture* texture = &Assets::GetTextureFromName(pTextureName);
	meshComponent->GetMesh()->AddTexture(texture);
	int index = meshComponent->GetTextureIndex(pTextureName);
	meshComponent->SetTextureIndex(index);
	meshComponent->GetMesh()->SetShaderProgram(Assets::GetShaderProgramFromName(pShaderProgramName));

	RendererGl* renderer = static_cast<RendererGl*>(pRenderer);
	renderer->AddMesh(meshComponent);
	AddComponent(meshComponent);

	Collider3D* collider = new Collider3D(this);
	AddComponent(collider);
}

void MeshActor::UpdateActor()
{
}
