
#include "mainScene.h"

void MainScene::Start(Renderer* pRenderer, Window* pWindow)
{
	mRenderer = pRenderer;
	mWindow = pWindow;

	mPlayer = new Player(this, pWindow, {}, Transform2D({ mWindow->GetDimensions().x / 2, mWindow->GetDimensions().y / 2 }, {15, 15}));
	mWall = new Wall(this, pWindow, {}, Transform2D({ mWindow->GetDimensions().x / 2 + 100, mWindow->GetDimensions().y / 2 - 150 }, { 15, 15 }));
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
	Rectangle playerRect = mPlayer->GetRect();
	Color playerColor = Color(253, 168, 132, 255);
	mRenderer->DrawRect(playerRect, playerColor);

	Rectangle wallRect = mWall->GetRect();
	Color wallColor = Color(82, 255, 100, 255);
	mRenderer->DrawRect(wallRect, wallColor);
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
			mPlayer->SetDirectionY(Direction::Down);
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
