#include <iostream>
#include <SDL.h>
#include <glew.h>
#include "game.h"
#include "pong.h"

using namespace std;

#define GLEW_STATIC

int main(int argc, char* argv[])
{
	Game* pong = new Game("My Pong Game", { new Pong() });
	pong->Initialize();

	return 0;
}
