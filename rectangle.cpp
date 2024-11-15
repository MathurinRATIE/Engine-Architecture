#include "rectangle.h"

Rectangle::Rectangle()
{
	mPosition = Vector2(0, 0);
	mDimensions = Vector2(1, 1);
}

Rectangle::Rectangle(Vector2 pPosition, Vector2 pDimensions)
{
	mPosition = pPosition;
	mDimensions = pDimensions;
}