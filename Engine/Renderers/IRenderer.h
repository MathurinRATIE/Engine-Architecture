#pragma once
#include "actor.h"

class Texture;

class IRenderer
{
public:
    std::vector<SpriteComponent*> mSprites;

    enum class Flip
    {
        None = SDL_FLIP_NONE,
        Horizontal = SDL_FLIP_HORIZONTAL,
        Vertical = SDL_FLIP_VERTICAL
    };
    enum class RendererType
    {
        SDL,
        OPENGL
    };

    virtual ~IRenderer() = default;

    virtual bool Initialize(Window* rWindow) = 0;
    virtual void BeginDraw() = 0;
    virtual void Draw() = 0;
    virtual void DrawSprites() = 0;
    virtual void EndDraw() = 0;
    virtual void Close() = 0;
    virtual RendererType GetType() = 0;

    virtual void AddSprite(SpriteComponent* pSprite) = 0;
    virtual void RemoveSprite(SpriteComponent* pSprite) = 0;
    virtual void DrawSprite(Actor* pOwner, Texture pTexture, Rectangle rectangle, Vector2 origin, Flip flip = Flip::None) const = 0;
};
