#include "scene.h"
#include "component.h"
#include "actor.h"
#include "spriteComponent.h"

Actor::Actor(Scene* pScene, Window* pWindow, Renderer* pRenderer, std::vector<Component*> pComponents, ActorState pState, Transform2D pTransform)
{
	mSceneOwner = pScene;
	mWindow = pWindow;
	mRenderer = pRenderer;
	mComponents = pComponents;
	mState = pState;
	mTransform = pTransform;

	mSceneOwner->AddPendingActor(this);
}

Actor::~Actor()
{
	mSceneOwner->AddPendingRemoveActor(this);
}

void Actor::Start()
{
}

void Actor::Update()
{
	if (mState == ActorState::Active)
	{
		UpdateComponents();
		UpdateActor();
	}
}

void Actor::UpdateComponents()
{
	for (Component* component : mComponents)
	{
		component->Update();
	}
}

void Actor::UpdateActor()
{
}

void Actor::AttachScene(Scene* pScene)
{
	mSceneOwner = pScene;
}

void Actor::AddComponent(Component* pComponent)
{
	int order = pComponent->GetUpdateOrder();
	auto iterator = mComponents.begin();

	for (; iterator != mComponents.end(); iterator++)
	{
		if (order < (*iterator)->GetUpdateOrder())
		{
			break;
		}
	}

	mComponents.insert(iterator, pComponent);
}

void Actor::RemoveComponent(Component* pComponent)
{
	auto iterator = std::find(mComponents.begin(), mComponents.end(), pComponent);

	if (iterator != mComponents.end())
	{
		mComponents.erase(iterator);
	}
}

void Actor::SetTransform(Transform2D pTransform)
{
	mTransform = pTransform;
}

void Actor::SetSprite(SpriteComponent* pSprite)
{
	mSprite = pSprite;
}

void Actor::SetActive(bool pIsActive)
{
	if (pIsActive)
	{
		mState = ActorState::Active;
	}
	else
	{
		mState = ActorState::Paused;
	}
}

Rectangle Actor::GetRect()
{
	return Rectangle(mTransform.GetPosition(), mTransform.GetScale());
}

Scene* Actor::GetScene()
{
	return mSceneOwner;
}

ActorState Actor::GetState()
{
	return mState;
}

Transform2D Actor::GetTransform()
{
	return mTransform;
}

std::vector<Component*> Actor::GetComponents()
{
	return mComponents;
}

SpriteComponent* Actor::GetSpriteComponent()
{
	return mSprite;
}
