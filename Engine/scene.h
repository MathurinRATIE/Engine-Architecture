#pragma once
#include <SDL_events.h>
#include <string>
#include <vector>
#include "rendererSdl.h"
#include "component.h"
#include "actor.h"
#include "assets.h"

#pragma once
class Scene
{
public :
	Scene();

	virtual void Start(IRenderer* pRenderer, Window* pWindow) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Close() = 0;

	void UpdateAllActors();

	void AddPendingActors();
	void RemovePendingActors();
	void AddActor(Actor* pActor);
	void AddPendingActor(Actor* pActor);
	void AddPendingRemoveActor(Actor* pActor);
	void RemoveActor(Actor* pActor);
	std::vector<Actor*> GetActors();
	IRenderer* GetRenderer();
	void Unload();

protected :
	IRenderer* mRenderer = nullptr;
	Window* mWindow = nullptr;
	std::vector<Actor*> mActors = {};
	std::vector<Actor*> mPendingActors = {};
	std::vector<Actor*> mPendingRemoveActors = {};
};
