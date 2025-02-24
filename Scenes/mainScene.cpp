
#include "mainScene.h"

void MainScene::Start(RendererSdl* pRenderer, Window* pWindow)
{
	mRenderer = pRenderer;
	mWindow = pWindow;

	mPlayer = new PlayerActor(this, pWindow, mRenderer, {}, Transform2D({ mWindow->GetDimensions().x / 2, mWindow->GetDimensions().y / 2 }, {15, 15}));
	mWall = new WallActor(this, pWindow, mRenderer, {}, Transform2D({ mWindow->GetDimensions().x / 2 + 100, mWindow->GetDimensions().y / 2 - 150 }, { 15, 15 }));
}

void MainScene::Update()
{
	UpdateAllActors();
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

void MainScene::Close()
{
	delete(mPlayer);
}
