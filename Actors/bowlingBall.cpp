#include "bowlingBall.h"
#include "collider3DComponent.h"
#include "bowlingBallControllerComponent.h"
#include "meshComponent.h"
#include "assets.h"
#include "rendererGl.h"
#include "scene.h"

BowlingBall::BowlingBall(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, ActorState pState, Transform3D pTransform) : Actor(pScene, pWindow, pRenderer, pComponents, pState, pTransform)
{
	Collider3D* collider = new Collider3D(this);
	AddComponent(collider);

	BowlingBallControllerComponent* controller = new BowlingBallControllerComponent(this);
	AddComponent(controller);

	MeshComponent* meshComponent = new MeshComponent(this);
	meshComponent->SetMesh(*Assets::GetMeshFromName("Sphere"));
	Texture* texture = &Assets::GetTextureFromName("Ball");
	meshComponent->GetMesh()->AddTexture(texture);
	int index = meshComponent->GetTextureIndex("Ball");
	meshComponent->SetTextureIndex(index);
	meshComponent->GetMesh()->SetShaderProgram(Assets::GetShaderProgramFromName("Mesh"));

	RendererGl* renderer = static_cast<RendererGl*>(pRenderer);
	renderer->AddMesh(meshComponent);
	AddComponent(meshComponent);
}

BowlingBall::~BowlingBall()
{
}