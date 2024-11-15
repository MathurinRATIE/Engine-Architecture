#include "actor.h"
#include "component.h"

Component::~Component()
{
	mOwner->RemoveComponent(this);
}

void Component::OnStart()
{
}

void Component::Update(float deltaTime)
{
}

void Component::OnEnd()
{
}

int Component::GetUpdateOrder()
{
	return mUpdateOrder;
}
