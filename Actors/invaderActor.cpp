#include "invaderActor.h"

InvaderActor::InvaderActor(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, Transform3D pTransform, Direction startingDirection, float mSpeedX, float mSpeedY, ActorState pState) : Actor(pScene, pWindow, pRenderer, pComponents, pState, pTransform)
{
	mScene = pScene;
	mWindow = pWindow;
	mTransform = pTransform;
	mRenderer = pRenderer;
	mRect = new Rectangle(Vector2(mTransform.GetPosition().x, mTransform.GetPosition().y), Vector2(mTransform.GetScale().x, mTransform.GetScale().y));

	Collider3D* collider = new Collider3D(this);
	AddComponent(collider);

	Texture* invaderTexture = new Texture();
	RendererSdl* renderer = static_cast<RendererSdl*>(mRenderer);
	if (renderer)
	{
		invaderTexture->Load(*renderer, "Imports/Invader.png");
	}
	SpriteComponent* sprite = new SpriteComponent(this, *invaderTexture, IRenderer::Flip::None);
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

		BulletActor* bullet = new BulletActor(mSceneOwner, mWindow, mRenderer, {}, this, Direction::Down, Transform3D(Vector3(mRect->mPosition.x + 5, mRect->mPosition.y + mRect->mDimensions.y + 1, 0), Vector3(5, 20, 0)));
	}
}

Rectangle InvaderActor::GetRect()
{
	return *mRect;
}