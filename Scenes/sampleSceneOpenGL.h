#pragma once
#include "scene.h"

class SampleSceneOpenGL : public Scene
{
public :
	SampleSceneOpenGL() : Scene() {};

	void Start(IRenderer* pRenderer, Window* pWindow) override;
	void Update() override;
	void Render() override;
	void Close() override;
};

