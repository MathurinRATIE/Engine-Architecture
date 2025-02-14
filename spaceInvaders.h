#pragma once
#include "scene.h"
#include "playerActor.h"
#include "invader.h"
#include "transform2D.h"

class SpaceInvaders : public Scene
{
public :
	SpaceInvaders() : Scene(), mPlayer(nullptr) {};

	void Start(Renderer* pRenderer, Window* pWindow) override;
	void Update(unsigned int pDeltaTime) override;
	void Render() override;
	void OnInput(SDL_Event pEvent) override;
	void Close() override;

private:
	Player* mPlayer;
};
