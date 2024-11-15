#pragma once
#include <SDL_rect.h>
#include "Vector2.h"

struct Rectangle
{
    Rectangle();
    Rectangle(Vector2 newPosition, Vector2 newDimensions);

    Vector2 mPosition;
    Vector2 mDimensions;

    SDL_Rect ToSdlRect() const
    {
        return SDL_Rect{
            static_cast<int>(mPosition.x),
            static_cast<int>(mPosition.y),
            static_cast<int>(mDimensions.x),
            static_cast<int>(mDimensions.y) };
    }
};
