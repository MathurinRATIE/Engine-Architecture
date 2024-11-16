
#include "mainScene.h"

void MainScene::Start(Renderer* pRenderer, Window* pWindow)
{
	mPlayer = new Player(this, {});
	Actor* playerActor = dynamic_cast<Actor*>(mPlayer);
	AddActor(playerActor);
}

void MainScene::Update(unsigned int pDeltaTime)
{
	for (Actor* actor : mActors)
	{
		actor->Update(pDeltaTime);
	}
}

void MainScene::Render()
{
	Rectangle rect = mPlayer->GetRect();
	Color color = { 253, 168, 132, 255 };

	mRenderer->DrawRect(rect, color);
}

void MainScene::OnInput(SDL_Event pEvent)
{
	switch (pEvent.type)
	{
	case SDL_KEYDOWN :
		if (pEvent.key.keysym.sym == SDLK_z)
		{
			mPlayer->SetDirectionY(Direction::Up);
		}
		if (pEvent.key.keysym.sym == SDLK_s)
		{
			mPlayer->SetDirectionX(Direction::Down);
		}
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
		if (pEvent.key.keysym.sym == SDLK_z || pEvent.key.keysym.sym == SDLK_s)
		{
			mPlayer->SetDirectionY(Direction::None);
		}
		if (pEvent.key.keysym.sym == SDLK_q || pEvent.key.keysym.sym == SDLK_d)
		{
			mPlayer->SetDirectionX(Direction::None);
		}
		break;
	default:
		break;
	}
}

void MainScene::Close()
{
	delete(mPlayer);
}
