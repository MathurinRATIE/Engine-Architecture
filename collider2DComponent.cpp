#include "actor.h"
#include "scene.h"
#include "collider2DComponent.h"

Collider2D::Collider2D(Rectangle* pRect, Actor* pOwner, bool* pIsColliding, int pUpdateOrder, bool pIsActive) : Component(pOwner, pUpdateOrder, pIsActive)
{
    mHitBox = pRect;
	mIsColliding = pIsColliding;
}

void Collider2D::Update(unsigned int pDeltaTime)
{
	if (mIsColliding != nullptr)
	{
		for (Actor* actor : mOwner->GetScene()->GetActors())
		{
			if (actor != mOwner)
			{
				for (Component* component : actor->GetComponents())
				{
					Collider2D* collider = dynamic_cast<Collider2D*>(component);

					if (collider != nullptr)
					{
						*mIsColliding = CheckCollisions(collider->GetHitBox());
					}
				}
			}
		}
	}
}

bool Collider2D::CheckCollisions(Rectangle pBox)
{
	// This
	float selfXMin = mHitBox->mPosition.x;
	float selfXMax = mHitBox->mPosition.x + mHitBox->mDimensions.x;
	float selfYMin = mHitBox->mPosition.y;
	float selfYMax = mHitBox->mPosition.y + mHitBox->mDimensions.y;

	// Other
	float otherXMin = pBox.mPosition.x;
	float otherXMax = pBox.mPosition.x + pBox.mDimensions.x;
	float otherYMin = pBox.mPosition.y;
	float otherYMax = pBox.mPosition.y + pBox.mDimensions.y;

	if (!((selfXMin > otherXMax ||
		selfXMax < otherXMin) ||
		(selfYMin > otherYMax ||
			selfYMax < otherYMin)))
	{
		return true;
	}
	else
	{

	}

	return false;
}

Rectangle Collider2D::GetHitBox()
{
	return *mHitBox;
}
