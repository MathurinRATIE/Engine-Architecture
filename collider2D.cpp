#include "collider2D.h"

Collider2D::Collider2D(Rectangle rect) : Component()
{
    mHitBox = rect;
}

bool Collider2D::CheckCollisions(Rectangle pBox)
{
	// This
	float selfXMin = mHitBox.position.x;
	float selfXMax = mHitBox.position.x + mHitBox.dimensions.x;
	float selfYMin = mHitBox.position.y;
	float selfYMax = mHitBox.position.y + mHitBox.dimensions.y;

	// Other
	float otherXMin = pBox.position.x;
	float otherXMax = pBox.position.x + pBox.dimensions.x;
	float otherYMin = pBox.position.y;
	float otherYMax = pBox.position.y + pBox.dimensions.y;

	if (!((selfXMin > otherXMax ||
		selfXMax < otherXMin) ||
		(selfYMin > otherYMax ||
			selfYMax < otherYMin)))
	{
		return true;
	}

	return false;
}
