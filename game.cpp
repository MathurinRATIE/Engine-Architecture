#include "game.h"

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
    rWindow = new Window(800, 600);
    rRenderer = new Renderer();

    //Load first scene
    if (mScenes.size() > 0)
    {
        mScenes[mLoadedScene]->Start(rRenderer);
    }
}

void Game::Initialize()
{
    if (rWindow->Open() && rRenderer->Initialize(rWindow)) Loop();
}

void Game::Loop()
{
    while (mIsRunning)
    {
        CheckInputs();
        Update();
        Render();
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
    mScenes[mLoadedScene]->Update();
}

void Game::CheckInputs()
{
    if (mIsRunning)
    {

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type) {
            case SDL_QUIT:
                mIsRunning = false;
                break;
            default:
                mScenes[mLoadedScene]->OnInput(event);
                break;
            }
        }
    }
}

void Game::Close()
{
    rWindow->Close();
}
