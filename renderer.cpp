#include "renderer.h"

Renderer::Renderer():mSdlRenderer(nullptr)
{
}

bool Renderer::Initialize(Window* rWindow)
{
    mSdlRenderer = SDL_CreateRenderer(rWindow->GetSdlWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!mSdlRenderer)
    {
        Log::Error(LogType::Video, "Failed to create Renderer");
        return false;
    }
   if(IMG_Init(IMG_INIT_PNG) == 0)
   {
       Log::Error(LogType::Video, "Unable to initialize SDL_Image");
       return false;
   }
    return true;
}

void Renderer::BeginDraw()
{
    SDL_SetRenderDrawColor(mSdlRenderer, 120, 120, 255, 255);
    SDL_RenderClear(mSdlRenderer);
}

void Renderer::EndDraw()
{
    SDL_RenderPresent(mSdlRenderer);
}

void Renderer::Close()
{
    SDL_DestroyRenderer(mSdlRenderer);
}

void Renderer::DrawRect(Rectangle& pRect, Color pColor)
{
    SDL_SetRenderDrawColor(mSdlRenderer, pColor.x, pColor.y, pColor.z, pColor.w);
    SDL_Rect sdlRect = pRect.ToSdlRect();
    SDL_RenderFillRect(mSdlRenderer, &sdlRect);
}

SDL_Renderer* Renderer::GetRenderer()
{
    return mSdlRenderer;
}
