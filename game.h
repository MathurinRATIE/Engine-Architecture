#pragma once
#include <string>
#include <SDL.h>
#include <glew.h>
#include <vector>
#include "scene.h"
#include "time.h"

class Game
{
public :
	Game(std::string pTitle, std::vector<Scene*> pScenes);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	void Initialize();

private :
	Window* rWindow;
	Renderer* rRenderer;
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
