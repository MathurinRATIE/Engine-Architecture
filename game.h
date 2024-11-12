#include <string>
#include <SDL.h>
#include <glew.h>
#include <vector>
#include "scene.h"
#pragma once

class Game
{
public :
	Game(std::string pTitle, std::vector<Scene*> pScenes);

	void Initialize();
	void Loop();
	void Render();
	void Update();
	void CheckInputs();
	void Close();

private :
	Window* rWindow;
	Renderer* rRenderer;
	std::string mTitle;
	std::vector<Scene*> mScenes;
	int mLoadedScene;
	bool mIsRunning;
};

