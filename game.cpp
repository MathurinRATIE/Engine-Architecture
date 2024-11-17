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
    mWindow = new Window(800, 600);
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
        unsigned int deltaTime = Time::ComputeDeltaTime();
        CheckInputs();
        Update(deltaTime);
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

void Game::Update(unsigned int pDeltaTime)
{
    mScenes[mLoadedScene]->Update(pDeltaTime);
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
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                mIsRunning = false;
                break;
            default:
                break;
            }

            mScenes[mLoadedScene]->OnInput(event);
        }
    }
}

void Game::Close()
{
    mWindow->Close();
}
