#include "rectangle.h"

Rectangle::Rectangle(Vector2 pPosition, Vector2 pDimensions)
{
	position = pPosition;
	dimensions = pDimensions;
}

bool Rectangle::CheckCollisions(Rectangle pRectangle)
{
	// This
	float selfXMin = position.x;
	float selfXMax = position.x + dimensions.x;
	float selfYMin = position.y;
	float selfYMax = position.y + dimensions.y;

	// Other
	float otherXMin = pRectangle.position.x;
	float otherXMax = pRectangle.position.x + pRectangle.dimensions.x;
	float otherYMin = pRectangle.position.y;
	float otherYMax = pRectangle.position.y + pRectangle.dimensions.y;

	if (!((selfXMin > otherXMax ||
		selfXMax < otherXMin) ||
		(selfYMin > otherYMax ||
		selfYMax < otherYMin)))
	{
		return true;
	}

	return false;
}