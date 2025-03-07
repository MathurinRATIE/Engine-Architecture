#include "sampleSceneOpenGL.h"

void SampleSceneOpenGL::Start(IRenderer* pRenderer, Window* pWindow)
{
	mRenderer = pRenderer;
	mWindow = pWindow;
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