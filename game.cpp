#include "game.h"

Game::Game(std::string pTitle, std::vector<Scene*> pScenes):mScenes(pScenes), mLoadedScene(0), mIsRunning(true)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
    }
    else
    {
        std::cout << "SDL initialization succeeded!";
    }
    glewExperimental = GL_TRUE;
    if (glewInit() == GLEW_OK) {
        std::cout << "Glew initialized successfully\n";
    }
    //Create window
    rWindow = new Window(800, 600);
    rRenderer = new Renderer(rWindow);

    //Load first scene
    if (mScenes.size() > 0)
    {
        mScenes[mLoadedScene]->Start(rRenderer);
    }

    Update();
}

void Game::Initialize()
{
    if (rWindow->Open()) Loop();
}

void Game::Loop()
{
    while (mIsRunning)
    {
        Update();
        CheckInputs();
        mScenes[mLoadedScene]->Update();
    }
    Close();
}

void Game::Render()
{
    rRenderer->BeginDraw();

    mScenes[mLoadedScene]->Render();

    rRenderer->EndDraw();
}

void Game::Update()
{

}

void Game::CheckInputs()
{
    if (mIsRunning)
    {
        mIsRunning = mScenes[mLoadedScene]->OnInput();
    }
}

void Game::Close()
{
    delete(rWindow);
}
