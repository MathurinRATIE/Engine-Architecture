#include "spaceShipActor.h"

SpaceShip::SpaceShip(Scene* pScene, Window* pWindow, Renderer* pRenderer, std::vector<Component*> pComponents, Transform2D pTransform, Direction startingDirection, float mSpeedX, float mSpeedY, ActorState pState) : Actor(pScene, pWindow, pComponents, pState, pTransform)
{
	mWindow = pWindow;
	mTransform = pTransform;
	mRect = new Rectangle(mTransform.GetPosition(), mTransform.GetScale());
	Actor* collidingActor = nullptr;
	mCollidingActor = &collidingActor;

	Collider2D* collider = new Collider2D(mRect, this, mCollidingActor);
	Component* colliderComponent = dynamic_cast<Component*>(collider);
	AddComponent(colliderComponent);

	mMovements = new Movements(&mRect->mPosition, this, pWindow, mCollidingActor, mSpeedX, mSpeedY);
	Component* movementsComponent = dynamic_cast<Component*>(mMovements);
	AddComponent(movementsComponent);

	Texture* pokeballTexture = new Texture();
	pokeballTexture->Load(*pRenderer, "Imports/pokeball.png");
	SpriteComponent* sprite = new SpriteComponent(this, *pokeballTexture);

	mMovements->SetDirectionX(startingDirection);
}

void SpaceShip::UpdateActor(unsigned int pDeltaTime)
{
	if (mRect->mPosition.x <= 0)
	{
		mMovements->SetDirectionX(Direction::Right);
	}
	else if (mRect->mPosition.x >= mWindow->GetDimensions().x - mRect->mDimensions.x)
	{
		mMovements->SetDirectionX(Direction::Left);
	}

	timeSinceLastShot += pDeltaTime;

	if (timeSinceLastShot >= 1000)
	{
		timeSinceLastShot -= 1000;

		Bullet* bullet = new Bullet(mSceneOwner, mWindow, {}, this, Direction::Down, Transform2D({ mRect->mPosition.x + 5, mRect->mPosition.y + mRect->mDimensions.y }, { 5, 20 }));
	}
}

Rectangle SpaceShip::GetRect()
{
	return *mRect;
}