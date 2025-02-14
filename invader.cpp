#include "invader.h"

Invader::Invader(Scene* pScene, Window* pWindow, Renderer* pRenderer, std::vector<Component*> pComponents, Transform2D pTransform, Direction startingDirection, float mSpeedX, float mSpeedY, ActorState pState) : Actor(pScene, pWindow, pComponents, pState, pTransform)
{
	mScene = pScene;
	mWindow = pWindow;
	mTransform = pTransform;
	mRenderer = pRenderer;
	mRect = new Rectangle(mTransform.GetPosition(), mTransform.GetScale());
	mCollidingActor = nullptr;

	Collider2D* collider = new Collider2D(mRect, this, mCollidingActor);
	Component* colliderComponent = dynamic_cast<Component*>(collider);
	AddComponent(colliderComponent);

	Texture* invaderTexture = new Texture();
	invaderTexture->Load(*mRenderer, "Imports/Invader.png");
	SpriteComponent* sprite = new SpriteComponent(this, *invaderTexture);
	SetSprite(sprite);

	mMovements = new Movements(&mRect->mPosition, this, pWindow, mCollidingActor, mSpeedX, mSpeedY);
	Component* movementsComponent = dynamic_cast<Component*>(mMovements);
	AddComponent(movementsComponent);

	mMovements->SetDirectionX(startingDirection);
}

void Invader::UpdateActor(unsigned int pDeltaTime)
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

		Bullet* bullet = new Bullet(mSceneOwner, mWindow, mRenderer, {}, this, Direction::Down, Transform2D({ mRect->mPosition.x + 5, mRect->mPosition.y + mRect->mDimensions.y + 1 }, { 5, 20 }));
	}
}

Rectangle Invader::GetRect()
{
	return *mRect;
}