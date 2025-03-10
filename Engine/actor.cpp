#include "scene.h"
#include "component.h"
#include "actor.h"
#include "spriteComponent.h"

Actor::Actor(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, ActorState pState, Transform3D pTransform)
{
	mSceneOwner = pScene;
	mWindow = pWindow;
	mRenderer = pRenderer;
	mComponents = pComponents;
	mState = pState;
	mTransform = pTransform;
	mSprite = nullptr;

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

void Actor::SetTransform(Transform3D pTransform)
{
	mTransform = pTransform;
}

void Actor::SetSprite(SpriteComponent* pSprite)
{
	mSprite = pSprite;
}

bool Actor::AddTag(std::string pTag)
{
	if (!HasTag(pTag))
	{
		mTags.push_back(pTag);
		return true;
	}

	return false;
}

bool Actor::RemoveTag(std::string pTag)
{
	auto tagIterator = std::find(mTags.begin(), mTags.end(), pTag);

	if (tagIterator != mTags.end())
	{
		mTags.erase(tagIterator);
		return true;
	}

	return false;
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
	return Rectangle(Vector2(mTransform.GetPosition().x, mTransform.GetPosition().y), Vector2(mTransform.GetScale().x, mTransform.GetScale().y));
}

Scene* Actor::GetScene()
{
	return mSceneOwner;
}

ActorState Actor::GetState()
{
	return mState;
}

Transform3D* Actor::GetTransform()
{
	return &mTransform;
}

std::vector<Component*> Actor::GetComponents()
{
	return mComponents;
}

SpriteComponent* Actor::GetSpriteComponent()
{
	return mSprite;
}

std::vector<std::string> Actor::GetAllTags()
{
	return mTags;
}

bool Actor::HasTag(std::string pTag)
{
	return (std::find(mTags.begin(), mTags.end(), pTag) != mTags.end());
}
