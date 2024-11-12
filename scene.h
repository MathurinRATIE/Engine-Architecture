#pragma once
#include <SDL_events.h>
#include "renderer.h"
#include <string>

#pragma once
class Scene
{
public :
	Scene();

	virtual void Start(Renderer* pRenderer) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual bool OnInput() = 0;
	virtual void Close() = 0;

protected :
	Renderer* mRenderer;
};

