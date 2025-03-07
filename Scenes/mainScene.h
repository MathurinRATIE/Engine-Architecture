#pragma once
#include "playerActor.h"
#include "wallActor.h"
#include "scene.h"

class MainScene : public Scene
{
public :
	MainScene() : Scene() {};

	void Start(IRenderer* pRenderer, Window* pWindow) override;
	void Update() override;
	void Render() override;
	void Close() override;

private :
	PlayerActor* mPlayer;
	WallActor* mWall;
};
