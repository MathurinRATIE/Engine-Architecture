#include "game.h"
#include "inputManager.h"

Game::Game(std::string pTitle, std::vector<Scene*> pScenes): mScenes(pScenes), mLoadedScene(0), mIsRunning(true)
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
    mWindow = new Window(800, 800);
    mRenderer = new Renderer();
}

void Game::Initialize()
{
    bool windowOppenedSuccessfully = mWindow->Open();
    bool rendererInitializedSuccessfully = mRenderer->Initialize(mWindow);

    //Load first scene
    if (mScenes.size() > 0)
    {
        mScenes[mLoadedScene]->Start(mRenderer, mWindow);
    }

    if (windowOppenedSuccessfully && rendererInitializedSuccessfully) Loop();
}

void Game::Loop()
{
    while (mIsRunning)
    {
        Time::ComputeDeltaTime();
        CheckInputs();
        Update();
        Render();
        Time::DelayTime();
    }
    Close();
}

void Game::Render()
{
    mRenderer->BeginDraw();

    mScenes[mLoadedScene]->Render();

    mRenderer->EndDraw();
}

void Game::Update()
{
    mScenes[mLoadedScene]->Update();
}

void Game::CheckInputs()
{
    if (mIsRunning)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            InputManager::Instance().HandleInputs(event);
        }
    }
}

void Game::Close()
{
    mWindow->Close();
}
