#include "spaceInvaders.h"

void SpaceInvaders::Start(IRenderer* pRenderer, Window* pWindow)
{
	mRenderer = pRenderer;
	mWindow = pWindow;

	mPlayer = new PlayerActor(this, mWindow, mRenderer, {}, Transform2D({ mWindow->GetDimensions().x / 2, mWindow->GetDimensions().y - 75 }, {30, 30}), 3.0f);
	InvaderActor* spaceShip = new InvaderActor(this, mWindow, mRenderer, {}, Transform2D({mWindow->GetDimensions().x / 2, 75}, {15, 15}), Direction::Right, 1.5f);
}

void SpaceInvaders::Update()
{
	for (Actor* actor : mActors)
	{
		actor->Update();
	}

	AddPendingActors();
	RemovePendingActors();
}

void SpaceInvaders::Render()
{
	Color color = Color(253, 168, 132, 255);

	mRenderer->DrawSprites();
}

void SpaceInvaders::Close()
{
}
