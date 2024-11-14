#pragma once
#include "rectangle.h"
#include "component.h"

class Collider2D : public Component
{
public :
	Collider2D(Rectangle rect);

	bool CheckCollisions(Rectangle pBox);

private :
	Rectangle mHitBox;
};
