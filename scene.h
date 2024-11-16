#pragma once
#include <SDL_events.h>
#include <string>
#include <vector>
#include "renderer.h"
#include "component.h"
#include "actor.h"

#pragma once
class Scene
{
public :
	Scene();

	virtual void Start(Renderer* pRenderer, Window* pWindow) = 0;
	virtual void Update(unsigned int pDeltaTime) = 0;
	virtual void Render() = 0;
	virtual void OnInput(SDL_Event pEvent) = 0;
	virtual void Close() = 0;

	void AddActor(Actor* pActor);
	void RemoveActor(Actor* pActor);
	std::vector<Actor*> GetActors();

protected :
	Renderer* mRenderer;
	Window* mWindow;
	std::vector<Actor*> mActors;
};
