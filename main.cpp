#include <iostream>
#include <SDL.h>
#include <glew.h>
#include "game.h"
#include "pong.h"
#include "mainScene.h"
#include "spaceInvaders.h"

using namespace std;

#define GLEW_STATIC

int main(int argc, char* argv[])
{
	/*Game* pong = new Game("My Pong Game", {new Pong()});
	pong->Initialize();*/

	/*Game* actorComponentScene = new Game("Actor/Component", {new MainScene()});
	actorComponentScene->Initialize();*/

	Game* spaceInvaders = new Game("Space Invaders", { new SpaceInvaders() });
	spaceInvaders->Initialize();

	return 0;
}
