#include "playerActor.h"

PlayerActor::PlayerActor(Scene* pScene, Window* pWindow, Renderer* pRenderer, std::vector<Component*> pComponents, Transform2D pTransform, float mSpeedX, float mSpeedY, ActorState pState) : Actor(pScene, pWindow, pRenderer, pComponents, pState, pTransform)
{
	mScene = pScene;
	mWindow = pWindow;
	mTransform = pTransform;
	mRenderer = pRenderer;
	mRect = new Rectangle(mTransform.GetPosition(), mTransform.GetScale());
	mCollidingActor = nullptr;

	Collider2D* collider = new Collider2D(this, mCollidingActor);
	AddComponent(collider);

	Texture* spaceShipTexture = new Texture();
	spaceShipTexture->Load(*mRenderer, "Imports/SpaceShip.png");
	SpriteComponent* sprite = new SpriteComponent(this, *spaceShipTexture, Renderer::Flip::None);
	SetSprite(sprite);

	mMovements = new MovementComponent(&mRect->mPosition, this, pWindow, mCollidingActor, mSpeedX, mSpeedY);
	AddComponent(mMovements);
}

void PlayerActor::UpdateActor()
{
	timeSinceLastShot += Time::deltaTime;

	if (timeSinceLastShot >= 1000)
	{
		timeSinceLastShot -= 1000;

		BulletActor* bullet = new BulletActor(mSceneOwner, mWindow, mRenderer, {}, this, Direction::Up, Transform2D({ mRect->mPosition.x + 5, mRect->mPosition.y - 19 }, { 5, 20 }));
		mScene->AddPendingActor(bullet);
	}
}

void PlayerActor::SetDirectionX(Direction pDirectionX)
{
	mMovements->SetDirectionX(pDirectionX);
}

void PlayerActor::SetDirectionY(Direction pDirectionY)
{
	mMovements->SetDirectionY(pDirectionY);
}

Rectangle PlayerActor::GetRect()
{
	return *mRect;
}
