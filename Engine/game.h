#pragma once
#include <string>
#include <SDL.h>
#include <glew.h>
#include <vector>
#include "scene.h"
#include "engineTime.h"
#include "IRenderer.h"
#include "rendererGl.h"

class Game
{
public :
	Game(std::string pTitle, std::vector<Scene*> pScenes, IRenderer::RendererType pType);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	void Initialize();

private :
	Window* mWindow;
	IRenderer* mRenderer;
	std::string mTitle;
	std::vector<Scene*> mScenes;
	int mLoadedScene;
	bool mIsRunning;

	void Loop();
	void Render();
	void Update();
	void CheckInputs();
	void Close();
};
