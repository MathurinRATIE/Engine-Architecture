#include "platformer.h"

void Platformer::Start(Renderer* pRenderer, Window* pWindow)
{
	mRenderer = pRenderer;
	mWindow = pWindow;

	mPlayer = new PlatformerPlayerActor(this, mWindow, mRenderer, {}, Transform2D({ mWindow->GetDimensions().x / 2, mWindow->GetDimensions().y - 75 }, { 64, 64 }), 3.0f);
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

void Platformer::OnInput(SDL_Event pEvent)
{
	switch (pEvent.type)
	{
	case SDL_KEYDOWN:
		switch (pEvent.key.keysym.sym)
		{
		case SDLK_q:
			mPlayer->SetDirection(Direction::Left);
			break;
		case SDLK_d:
			mPlayer->SetDirection(Direction::Right);
			break;
		case SDLK_SPACE:
			// Jump
			break;
		}
		break;
	case SDL_KEYUP:
		if (pEvent.key.keysym.sym == SDLK_q || pEvent.key.keysym.sym == SDLK_d)
		{
			mPlayer->SetDirection(Direction::None);
		}
		break;
	}
}

void Platformer::Close()
{
}
