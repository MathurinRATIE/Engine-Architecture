#include "sampleSceneOpenGL.h"
#include "cubeActor.h"
#include "camera.h"
#include "texture.h"

void SampleSceneOpenGL::Start(IRenderer* pRenderer, Window* pWindow)
{
	mRenderer = pRenderer;
	mWindow = pWindow;

	Assets::LoadTexture(mRenderer, "Imports/Wall.png", "Wall");

	CubeActor* cubeActor = new CubeActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(0, 0, 0)));
	AddPendingActor(cubeActor);

	Camera* camera = new Camera(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(-5, 0, 0)));
}

void SampleSceneOpenGL::Update()
{
	for (Actor* actor : mActors)
	{
		actor->Update();
	}

	AddPendingActors();
	RemovePendingActors();
}

void SampleSceneOpenGL::Render()
{
	mRenderer->Draw();
}

void SampleSceneOpenGL::Close()
{
}
