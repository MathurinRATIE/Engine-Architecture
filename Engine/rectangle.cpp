#include "rectangle.h"

const Rectangle Rectangle::NullRect{ Vector2(0, 0), Vector2(0, 0) };

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

bool Rectangle::operator==(const Rectangle& right)
{
	return mPosition == right.mPosition && mDimensions == right.mDimensions;
}

bool Rectangle::operator!=(const Rectangle& right)
{
	return mPosition != right.mPosition || mDimensions != right.mDimensions;
}
