#pragma once
#include "rectangle.h"
#include "component.h"

class Collider2D : public Component
{
public :
	Collider2D(Rectangle rect, Actor* pOwner, int pUpdateOrder = 100, bool pIsActive = true);

	void Update(float pDeltaTime) override;

	bool CheckCollisions(Rectangle pBox);
	Rectangle GetHitBox();

protected :
	Rectangle mHitBox;
};
