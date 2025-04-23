#pragma once
#include "scene.h"

class BowlingScene : public Scene
{
public :
	BowlingScene() : Scene() {};

	void Start(IRenderer* pRenderer, Window* pWindow) override;
	void Update() override;
	void Render() override;
	void Close() override;
};
