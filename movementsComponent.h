#pragma once
#include "direction.h"
#include "actor.h"
#include "vector2.h"
#include "component.h"

class Movements : public Component
{
public :
	Movements(Vector2* pPosition, Actor* pOwner, bool* pIsColliding = nullptr, float pSpeedX = 1.0f, float pSpeedY = 1.0f, int pUpdateOrder = 100, bool pIsActive = true);

	void Update(unsigned int pDeltaTime) override;

	void SetSpeedX(float pSpeedX);
	void SetSpeedY(float pSpeedY);
	void SetDirectionX(Direction pDirectionX);
	void SetDirectionY(Direction pDirectionY);

	float GetSpeedX();
	float GetSpeedY();
	Direction GetDirectionX();
	Direction GetDirectionY();

protected :
	float mSpeedX;
	float mSpeedY;
	Direction mDirectionX;
	Direction mDirectionY;
	Direction mLastDirectionX;
	Direction mLastDirectionY;
	Vector2* mPosition;
	bool* mIsColliding;
};

