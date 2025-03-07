#include "rendererSdl.h"
#include "spriteComponent.h"
#include "texture.h"

RendererSdl::RendererSdl():mSdlRenderer(nullptr)
{
}

bool RendererSdl::Initialize(Window* rWindow)
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

void RendererSdl::BeginDraw()
{
    SDL_SetRenderDrawColor(mSdlRenderer, 120, 120, 255, 255);
    SDL_RenderClear(mSdlRenderer);
}

void RendererSdl::Draw()
{
}

void RendererSdl::EndDraw()
{
    SDL_RenderPresent(mSdlRenderer);
}

void RendererSdl::Close()
{
    SDL_DestroyRenderer(mSdlRenderer);
}

void RendererSdl::DrawRect(Rectangle pRect, Color pColor)
{
    SDL_SetRenderDrawColor(mSdlRenderer, static_cast<int>(pColor.x * 255.0f), static_cast<int>(pColor.y * 255.0f), static_cast<int>(pColor.z * 255.0f), static_cast<int>(pColor.w * 255.0f));
    SDL_Rect sdlRect = pRect.ToSdlRect();
    SDL_RenderFillRect(mSdlRenderer, &sdlRect);
}

void RendererSdl::DrawSprites()
{
    for (SpriteComponent* sprite : mSprites)
    {
        DrawSprite(sprite->GetOwner(), sprite->GetTexture(), sprite->GetOwner()->GetRect(), sprite->GetOwner()->GetTransform()->GetPosition(), sprite->GetFlip());
    }
}

void RendererSdl::DrawSprite(Actor* pActor, Texture pTexture, Rectangle pRectangle, Vector2 pOrigin, Flip pFlip) const
{
    SDL_Rect destinationRect;
    Transform2D transform = *pActor->GetTransform();
    /*destinationRect.w = static_cast<int>(pTexture.GetWidth() * transform.GetScale().x);
    destinationRect.h = static_cast<int>(pTexture.GetWidth() * transform.GetScale().y);
    destinationRect.x = static_cast<int>(transform.GetPosition().x * pOrigin.x);
    destinationRect.y = static_cast<int>(transform.GetPosition().y * pOrigin.y);*/
    destinationRect.w = static_cast<int>(pRectangle.mDimensions.x);
    destinationRect.h = static_cast<int>(pRectangle.mDimensions.y);
    destinationRect.x = static_cast<int>(transform.GetPosition().x);
    destinationRect.y = static_cast<int>(transform.GetPosition().y);
    /*destinationRect.w = 800;
    destinationRect.h = 800;
    destinationRect.x = 0;
    destinationRect.y = 0;*/

    SDL_Rect* sourceSDL = nullptr;
    if (pRectangle != Rectangle::NullRect)
    {
        sourceSDL = new SDL_Rect{
            Maths::Round(0),
            Maths::Round(0),
            Maths::Round(static_cast<float>(pTexture.GetWidth())),
            Maths::Round(static_cast<float>(pTexture.GetHeight()))
        };
    }

    SDL_RenderCopyEx(mSdlRenderer,
        pTexture.GetSdlTexture(),
        sourceSDL,
        &destinationRect,
        -Maths::ToDeg(transform.GetRotation()),
        nullptr,
        static_cast<SDL_RendererFlip>(pFlip));

    delete sourceSDL;
}

void RendererSdl::AddSprite(SpriteComponent* pSprite)
{
    int spriteDrawOrder = pSprite->GetDrawOrder();
    std::vector<SpriteComponent*>::iterator spriteComponentIterator;
    
    for (spriteComponentIterator = mSprites.begin(); spriteComponentIterator != mSprites.end(); ++spriteComponentIterator)
    {
        if (spriteDrawOrder < (*spriteComponentIterator)->GetDrawOrder())
        {
            break;
        }
    }

    mSprites.insert(spriteComponentIterator, pSprite);
}

SDL_Renderer* RendererSdl::ToSdlRenderer()
{
    return mSdlRenderer;
}

void RendererSdl::RemoveSprite(SpriteComponent* pSprite)
{
    std::vector<SpriteComponent*>::iterator spriteComponentIterator;
    spriteComponentIterator = std::find(mSprites.begin(), mSprites.end(), pSprite);
    mSprites.erase(spriteComponentIterator);
}

IRenderer::RendererType RendererSdl::GetType()
{
    return RendererType::SDL;
}