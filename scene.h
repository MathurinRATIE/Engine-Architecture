#pragma once
#include <SDL_events.h>
#include <string>
#include <vector>
#include "renderer.h"
#include "actor.h"

#pragma once
class Scene
{
public :
	Scene();

	virtual void Start(Renderer* pRenderer, Window* pWindow, std::vector<Actor*> pActors) = 0;
	virtual void Update(float pDeltaTime) = 0;
	virtual void Render() = 0;
	virtual void OnInput(SDL_Event pEvent) = 0;
	virtual void Close() = 0;

protected :
	Renderer* rRenderer;
	Window* rWindow;
	std::vector<Actor*> rActors;
};
