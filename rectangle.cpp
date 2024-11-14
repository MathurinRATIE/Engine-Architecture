#include "rectangle.h"

Rectangle::Rectangle()
{
	position = Vector2(0, 0);
	dimensions = Vector2(1, 1);
}

Rectangle::Rectangle(Vector2 pPosition, Vector2 pDimensions)
{
	position = pPosition;
	dimensions = pDimensions;
}