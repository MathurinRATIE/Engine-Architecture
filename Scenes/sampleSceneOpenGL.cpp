#include "sampleSceneOpenGL.h"
#include "cubeActor.h"
#include "texture.h"

void SampleSceneOpenGL::Start(IRenderer* pRenderer, Window* pWindow)
{
	mRenderer = pRenderer;
	mWindow = pWindow;

	Assets::LoadTexture(mRenderer, "Imports/Wall.png", "Wall");

	CubeActor* cubeActor = new CubeActor(this, pWindow, pRenderer, {});
	AddPendingActor(cubeActor);
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
