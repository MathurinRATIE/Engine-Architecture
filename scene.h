#pragma once
#include <SDL_events.h>
#include <string>
#include <vector>
#include "renderer.h"
#include "component.h"
#include "actor.h"
#include "assets.h"

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

	void UpdateAllActors(unsigned int pDeltaTime);

	void AddPendingActors();
	void RemovePendingActors();
	void AddActor(Actor* pActor);
	void AddPendingActor(Actor* pActor);
	void AddPendingRemoveActor(Actor* pActor);
	void RemoveActor(Actor* pActor);
	std::vector<Actor*> GetActors();
	Renderer* GetRenderer();
	void Unload();

protected :
	Renderer* mRenderer;
	Window* mWindow;
	std::vector<Actor*> mActors;
	std::vector<Actor*> mPendingActors;
	std::vector<Actor*> mPendingRemoveActors;
};
