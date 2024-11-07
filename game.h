#include <string>
#include <SDL.h>
#include <vector>
#include "scene.h"

#pragma once
class Game
{
public :
	Game(std::string mTitle, std::vector<std::shared_ptr<Scene>> pScenes);

	void Loop();
	void Render();
	void Update();
	void CheckForInputs();
	void Close();

private :
	SDL_Window* rWindow;
	std::string mTitle;
	bool mIsRunning;
};

