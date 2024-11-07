#include <SDL_events.h>
#include "renderer.h"
#include <string>

#pragma once
class Scene
{
public :
	Scene();
	Scene(std::shared_ptr<Renderer> pRenderer, std::string pTitle = "Scene");

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void OnInput(SDL_Event) = 0;
	virtual void Close() = 0;

private :
	std::shared_ptr<Renderer> mRenderer;
	std::string mTitle;
};

