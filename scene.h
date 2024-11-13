#pragma once
#include <SDL_events.h>
#include "renderer.h"
#include <string>

#pragma once
class Scene
{
public :
	Scene();

	virtual void Start(Renderer* pRenderer, Window* pWindow) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;
	virtual void OnInput(SDL_Event event) = 0;
	virtual void Close() = 0;

protected :
	Renderer* rRenderer;
	Window* rWindow;
};

