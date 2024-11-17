#pragma once
#include "playerActor.h"
#include "wallActor.h"
#include "scene.h"

class MainScene : public Scene
{
public :
	MainScene() : Scene() {};

	void Start(Renderer* pRenderer, Window* pWindow) override;
	void Update(unsigned int pDeltaTime) override;
	void Render() override;
	void OnInput(SDL_Event pEvent) override;
	void Close() override;

private :
	Player* mPlayer;
	Wall* mWall;
};
