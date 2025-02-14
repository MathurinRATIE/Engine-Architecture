#include "spaceInvaders.h"

void SpaceInvaders::Start(Renderer* pRenderer, Window* pWindow)
{
	mRenderer = pRenderer;
	mWindow = pWindow;

	mPlayer = new Player(this, mWindow, mRenderer, {}, Transform2D({ mWindow->GetDimensions().x / 2, mWindow->GetDimensions().y - 75 }, {30, 30}), 3.0f);
	Invader* spaceShip = new Invader(this, mWindow, mRenderer, {}, Transform2D({mWindow->GetDimensions().x / 2, 75}, {15, 15}), Direction::Right, 1.5f);
}

void SpaceInvaders::Update(unsigned int pDeltaTime)
{
	for (Actor* actor : mActors)
	{
		actor->Update(pDeltaTime);
	}

	AddPendingActors();
	RemovePendingActors();
}

void SpaceInvaders::Render()
{
	Color color = Color(253, 168, 132, 255);

	mRenderer->DrawSprites();
}

void SpaceInvaders::OnInput(SDL_Event pEvent)
{
	switch (pEvent.type)
	{
	case SDL_KEYDOWN:
		if (pEvent.key.keysym.sym == SDLK_q)
		{
			mPlayer->SetDirectionX(Direction::Left);
		}
		if (pEvent.key.keysym.sym == SDLK_d)
		{
			mPlayer->SetDirectionX(Direction::Right);
		}
		break;
	case SDL_KEYUP:
		if (pEvent.key.keysym.sym == SDLK_q || pEvent.key.keysym.sym == SDLK_d)
		{
			mPlayer->SetDirectionX(Direction::None);
		}
		break;
	default:
		break;
	}
}

void SpaceInvaders::Close()
{
}
