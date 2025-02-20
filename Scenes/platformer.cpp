#include "platformer.h"

void Platformer::Start(Renderer* pRenderer, Window* pWindow)
{
	mRenderer = pRenderer;
	mWindow = pWindow;

	mPlayer = new PlatformerPlayerActor(this, mWindow, mRenderer, {}, Transform2D({ mWindow->GetDimensions().x / 2, mWindow->GetDimensions().y - 75 }, { 64, 64 }), 50.0f);
}

void Platformer::Update()
{
	for (Actor* actor : mActors)
	{
		actor->Update();
	}

	AddPendingActors();
	RemovePendingActors();
}

void Platformer::Render()
{
	mRenderer->DrawSprites();
}

void Platformer::Close()
{
}
