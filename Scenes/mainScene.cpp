
#include "mainScene.h"

void MainScene::Start(IRenderer* pRenderer, Window* pWindow)
{
	mRenderer = pRenderer;
	mWindow = pWindow;

	mPlayer = new PlayerActor(this, pWindow, mRenderer, {}, Transform3D(Vector3(mWindow->GetDimensions().x / 2, mWindow->GetDimensions().y / 2, 0), Vector3(15, 15, 0)));
	mWall = new WallActor(this, pWindow, mRenderer, {}, Transform3D(Vector3(mWindow->GetDimensions().x / 2 + 100, mWindow->GetDimensions().y / 2 - 150, 0), Vector3(15, 15, 0)));
}

void MainScene::Update()
{
	UpdateAllActors();
}

void MainScene::Render()
{
	/*Rectangle playerRect = mPlayer->GetRect();
	Color playerColor = Color(253, 168, 132, 255);
	mRenderer->DrawRect(playerRect, playerColor);

	Rectangle wallRect = mWall->GetRect();
	Color wallColor = Color(82, 255, 100, 255);
	mRenderer->DrawRect(wallRect, wallColor);*/
}

void MainScene::Close()
{
	delete(mPlayer);
}
