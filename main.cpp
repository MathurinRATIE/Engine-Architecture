#include <iostream>
#include <SDL.h>
#include <glew.h>
#include "game.h"
#include "pong.h"
#include "mainScene.h"
#include "spaceInvaders.h"
#include "platformer.h"
#include "sampleSceneOpenGL.h"
#include "AdvancedOpenglScene.h"
#include "bowlingScene.h"

using namespace std;

#define GLEW_STATIC

int main(int argc, char* argv[])
{
	/*Game* pong = new Game("My Pong Game", {new Pong()});
	pong->Initialize();*/

	/*Game* actorComponentScene = new Game("Actor/Component", {new MainScene()});
	actorComponentScene->Initialize();*/

	/*Game* spaceInvaders = new Game("Space Invaders", {new SpaceInvaders()});
	spaceInvaders->Initialize();*/

	/*Game* platformer = new Game("Platformer", {new Platformer()}, IRenderer::RendererType::SDL);
	platformer->Initialize();*/

	/*Game* sampleSceneOpenGL = new Game("OpenGL", {new SampleSceneOpenGL()}, IRenderer::RendererType::OPENGL);
	sampleSceneOpenGL->Initialize();*/

	/*Game* marieScene = new Game("Scene Marie", { new AdvancedOpenglScene() }, IRenderer::RendererType::OPENGL);
	marieScene->Initialize();*/

	Game* bowling = new Game("Bowling", { new BowlingScene() }, IRenderer::RendererType::OPENGL);
	bowling->Initialize();

	return 0;
}
