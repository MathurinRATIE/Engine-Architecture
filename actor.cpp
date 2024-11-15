#include "scene.h"
#include "component.h"
#include "transform2D.h"
#include "actor.h"

Actor::Actor(Scene* pScene, std::vector<Component*> pComponents, ActorState pState, Transform2D pTransform)
{
	mSceneOwner->AddActor(this);
}

Actor::~Actor()
{
	mSceneOwner->RemoveActor(this);

	while (!mComponents.empty())
	{
		delete mComponents.back();
	}
}

void Actor::Start()
{
}

void Actor::Update(unsigned int pDeltaTime)
{
	if (mState == ActorState::Active)
	{
		UpdateComponents(pDeltaTime);
		UpdateActor(pDeltaTime);
	}
}

void Actor::UpdateComponents(unsigned int pDeltaTime)
{
	for (Component* component : mComponents)
	{
		component->Update(pDeltaTime);
	}
}

void Actor::UpdateActor(unsigned int pDeltaTime)
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

void Actor::SetActive(bool pIsActive)
{
}

Scene* Actor::GetScene()
{
	return mSceneOwner;
}

ActorState Actor::GetState()
{
	return ActorState();
}

Transform2D Actor::GetTransform()
{
	return Transform2D();
}

std::vector<Component*> Actor::GetComponents()
{
	return mComponents;
}
