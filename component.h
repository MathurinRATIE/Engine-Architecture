#pragma once

class Component
{
public :
	Component(Actor* pOwner, int pUpdateOrder = 100, bool pIsActive = true) : mOwner(pOwner), mUpdateOrder(pUpdateOrder), mIsActive(pIsActive) {};
	virtual ~Component();
	Component(const Component&) = delete;

	virtual void OnStart();
	virtual void Update(float deltaTime);
	virtual void OnEnd();

	int GetUpdateOrder();

protected :
	bool mIsActive;
	Actor* mOwner;
	int mUpdateOrder;
};
