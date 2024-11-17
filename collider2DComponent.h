#pragma once
#include "rectangle.h"
#include "component.h"

class Collider2D : public Component
{
public :
	Collider2D(Rectangle* pRect, Actor* pOwner, bool* isColliding = nullptr, int pUpdateOrder = 100, bool pIsActive = true);

	void Update(unsigned int pDeltaTime) override;

	bool CheckCollisions(Rectangle pBox);
	Rectangle GetHitBox();

protected :
	Rectangle* mHitBox;
	bool* mIsColliding;
};
