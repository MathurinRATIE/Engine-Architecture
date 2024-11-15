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

void Component::Update(unsigned int deltaTime)
{
}

void Component::OnEnd()
{
}

int Component::GetUpdateOrder()
{
	return mUpdateOrder;
}
