#pragma once
#include "scene.h"
#include "platformerPlayerActor.h"

class Platformer : public Scene
{
public :
	Platformer() : Scene(), mPlayer(nullptr) {};

	void Start(RendererSdl* pRenderer, Window* pWindow) override;
	void Update() override;
	void Render() override;
	void Close() override;

private :
	PlatformerPlayerActor* mPlayer;
};

