#include "platformer.h"
#include "platformActor.h"
#include "collisionManager.h"

void Platformer::Start(Renderer* pRenderer, Window* pWindow)
{
	mRenderer = pRenderer;
	mWindow = pWindow;

	mPlayer = new PlatformerPlayerActor(this, mWindow, mRenderer, {}, Transform2D({ mWindow->GetDimensions().x / 2, mWindow->GetDimensions().y / 2 }, { 64, 64 }), 50.0f);
	
	PlatformActor* platform = new PlatformActor(this, mWindow, mRenderer, {}, ActorState::Active, Transform2D({ mWindow->GetDimensions().x / 2, mWindow->GetDimensions().y / 2 + 100 }, { 105, 23 }));
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
		Color color = Color(0.0f, 1.0f, 1.0f, 1.0f);
		mRenderer->DrawRect(actor->GetComponentOfType<Collider2D>()->GetHitBox(), color);
	}*/

	mRenderer->DrawSprites();
}

void Platformer::Close()
{
}
