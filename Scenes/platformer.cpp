#include "platformer.h"
#include "platformActor.h"
#include "collisionManager.h"

void Platformer::Start(IRenderer* pRenderer, Window* pWindow)
{
	mRenderer = pRenderer;
	mWindow = pWindow;

	mPlayer = new PlatformerPlayerActor(this, mWindow, mRenderer, {}, Transform3D(Vector3(mWindow->GetDimensions().x / 2, mWindow->GetDimensions().y / 2, 0.0f), Vector3(64, 64, 0)), 50.0f);
	
	PlatformActor* platform1 = new PlatformActor(this, mWindow, mRenderer, {}, ActorState::Active, Transform3D(Vector3(mWindow->GetDimensions().x / 2, mWindow->GetDimensions().y / 2 + 100, 0), Vector3(105, 23, 0)));
	PlatformActor* platform2 = new PlatformActor(this, mWindow, mRenderer, {}, ActorState::Active, Transform3D(Vector3(mWindow->GetDimensions().x / 2 - 150, mWindow->GetDimensions().y / 2 + 50, 0), Vector3(105, 23, 0)));
	PlatformActor* platform3 = new PlatformActor(this, mWindow, mRenderer, {}, ActorState::Active, Transform3D(Vector3(mWindow->GetDimensions().x / 2 - 350, mWindow->GetDimensions().y / 2 + 25, 0), Vector3(105, 23, 0)));
}

void Platformer::Update()
{
	CollisionManager::Instance().CheckCollisions();
	for (Actor* actor : mActors)
	{
		actor->Update();
	}

	AddPendingActors();
	RemovePendingActors();
}

void Platformer::Render()
{
	/*for (Actor* actor : mActors)            // Draw COLLISIONS
	{
		SpriteComponent* sprite = actor->GetComponentOfType<SpriteComponent>();
		if (sprite)
		{
			mRenderer->DrawSprite(actor, sprite->GetTexture(), actor->GetRect(), Vector2(actor->GetTransform()->GetWorldTransform().GetXAxis().x, actor->GetTransform()->GetWorldTransform().GetYAxis().y));
		}
	}*/

	mRenderer->DrawSprites();
}

void Platformer::Close()
{
}
