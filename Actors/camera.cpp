#include "camera.h"
#include "rendererGl.h"
#include "playerControllerComponent.h"
#include "collider3DComponent.h"

Camera::Camera(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, ActorState pState, Transform3D pTransform) : Actor(pScene, pWindow, pRenderer, pComponents, pState, pTransform)
{
	Collider3D* collider = new Collider3D(this);
	AddComponent(collider);

	PlayerControllerComponent* playerController = new PlayerControllerComponent(this);
	AddComponent(playerController);
}

Camera::~Camera()
{
}

void Camera::UpdateActor()
{
	Actor::UpdateActor();
	
	// Compute view Matrix
	Vector3 camPosition = mTransform.GetPosition();
	Vector3 target = mTransform.GetPosition() + mTransform.Forward() * 100.0f;
	Vector3 up = Vector3::unitZ;
	Matrix4Row view = Matrix4Row::CreateLookAt(camPosition, target, up);

	// Apply the view Matrix
	RendererGl* renderer = static_cast<RendererGl*>(mRenderer);
	renderer->SetViewMatrix(view);
}
