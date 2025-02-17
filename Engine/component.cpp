#include "actor.h"
#include "component.h"

Component::Component(Actor* pOwner, int pUpdateOrder, bool pIsActive) : mOwner(pOwner), mUpdateOrder(pUpdateOrder), mIsActive(pIsActive)
{
	mOwner->AddComponent(this);
}

Component::~Component()
{
	mOwner->RemoveComponent(this);
}

void Component::OnStart()
{
}

void Component::Update()
{
}

void Component::OnEnd()
{
}

int Component::GetUpdateOrder()
{
	return mUpdateOrder;
}

Actor* Component::GetOwner()
{
	return mOwner;
}
