#include "invaderActor.h"

InvaderActor::InvaderActor(Scene* pScene, Window* pWindow, Renderer* pRenderer, std::vector<Component*> pComponents, Transform2D pTransform, Direction startingDirection, float mSpeedX, float mSpeedY, ActorState pState) : Actor(pScene, pWindow, pRenderer, pComponents, pState, pTransform)
{
	mScene = pScene;
	mWindow = pWindow;
	mTransform = pTransform;
	mRenderer = pRenderer;
	mRect = new Rectangle(mTransform.GetPosition(), mTransform.GetScale());

	Collider2D* collider = new Collider2D(this);
	AddComponent(collider);

	Texture* invaderTexture = new Texture();
	invaderTexture->Load(*mRenderer, "Imports/Invader.png");
	SpriteComponent* sprite = new SpriteComponent(this, *invaderTexture, Renderer::Flip::None);
	SetSprite(sprite);

	//mMovements = new MovementComponent(&mRect->mPosition, this, pWindow, mCollidingActor, mSpeedX, mSpeedY);
	//AddComponent(mMovements);

	mMovements->SetDirectionX(startingDirection);
}

void InvaderActor::UpdateActor()
{
	if (mRect->mPosition.x <= 0)
	{
		mMovements->SetDirectionX(Direction::Right);
	}
	else if (mRect->mPosition.x >= mWindow->GetDimensions().x - mRect->mDimensions.x)
	{
		mMovements->SetDirectionX(Direction::Left);
	}

	timeSinceLastShot += Time::deltaTime;

	if (timeSinceLastShot >= 1000)
	{
		timeSinceLastShot -= 1000;

		BulletActor* bullet = new BulletActor(mSceneOwner, mWindow, mRenderer, {}, this, Direction::Down, Transform2D({ mRect->mPosition.x + 5, mRect->mPosition.y + mRect->mDimensions.y + 1 }, { 5, 20 }));
	}
}

Rectangle InvaderActor::GetRect()
{
	return *mRect;
}