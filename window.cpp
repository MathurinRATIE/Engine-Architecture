#include "window.h"

Window::Window(int pWidth, int pHeight) :mSdlWindow(nullptr), mDimensions({ pWidth, pHeight })
{
}

bool Window::Open()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        Log::Error(LogType::Video, "Unable to initialize video");
        return false;
    }
    mSdlWindow = SDL_CreateWindow("Engine Architecture Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, static_cast<int>(mDimensions.x), static_cast<int>(mDimensions.y), SDL_WINDOW_OPENGL);
    if (!mSdlWindow)
    {
        Log::Error(LogType::System, "Failed to create window");
        return false;
    }
    return true;
}
