#pragma once
#include <SDL_rect.h>
#include "Vector2.h"

struct Rectangle
{
    Rectangle(Vector2 newPosition, Vector2 newDimensions);

    Vector2 position;
    Vector2 dimensions;

    bool CheckCollisions(Rectangle otherRectangle);

    SDL_Rect ToSdlRect() const
    {
        return SDL_Rect{
            static_cast<int>(position.x),
            static_cast<int>(position.y),
            static_cast<int>(dimensions.x),
            static_cast<int>(dimensions.y) };
    }
};
