#include "spaceInvaders.h"

void SpaceInvaders::Start(IRenderer* pRenderer, Window* pWindow)
{
	mRenderer = pRenderer;
	mWindow = pWindow;

	mPlayer = new PlayerActor(this, mWindow, mRenderer, {}, Transform3D(Vector3(mWindow->GetDimensions().x / 2, mWindow->GetDimensions().y - 75, 0.0f), Vector3(30, 30, 0.0f), Quaternion(0.0f, 0.0f, 3.0f, 1.0f)));
	InvaderActor* spaceShip = new InvaderActor(this, mWindow, mRenderer, {}, Transform3D(Vector3(mWindow->GetDimensions().x / 2, 75, 0.0f), Vector3(15, 15, 0)), Direction::Right, 1.5f);
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
