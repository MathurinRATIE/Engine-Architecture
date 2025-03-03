#pragma once
#include "scene.h"
#include "playerActor.h"
#include "invaderActor.h"
#include "transform2D.h"

class SpaceInvaders : public Scene
{
public :
	SpaceInvaders() : Scene(), mPlayer(nullptr) {};

	void Start(IRenderer* pRenderer, Window* pWindow) override;
	void Update() override;
	void Render() override;
	void Close() override;

private:
	PlayerActor* mPlayer;
};
