#include "rectangle.h"

Rectangle::Rectangle(Vector2 newPosition, Vector2 newDimensions)
{
	position = newPosition;
	dimensions = newDimensions;
}

bool Rectangle::CheckCollisions(Rectangle otherRectangle)
{
	// This
	float selfXMin = position.x;
	float selfXMax = position.x + dimensions.x;
	float selfYMin = position.y;
	float selfYMax = position.y + dimensions.y;

	// Other
	float otherXMin = otherRectangle.position.x;
	float otherXMax = otherRectangle.position.x + otherRectangle.dimensions.x;
	float otherYMin = otherRectangle.position.y;
	float otherYMax = otherRectangle.position.y + otherRectangle.dimensions.y;

	if (!((selfXMin > otherXMax ||
		selfXMax < otherXMin) ||
		(selfYMin > otherYMax ||
		selfYMax < otherYMin)))
	{
		return true;
	}

	return false;
}