#pragma once
#include "scene.h"

class MainScene : public Scene
{
	MainScene() : Scene() {};

	void Start(Renderer* pRenderer, Window* pWindow) override;
	void Update(unsigned int pDeltaTime) override;
	void Render() override;
	void OnInput(SDL_Event pEvent) override;
	void Close() override;
};
