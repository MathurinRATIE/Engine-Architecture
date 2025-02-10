#pragma once

class Actor;

class Component
{
public :
	Component(Actor* pOwner, int pUpdateOrder = 100, bool pIsActive = true);
	virtual ~Component();
	Component(const Component&) = delete;

	virtual void OnStart();
	virtual void Update(unsigned int deltaTime);
	virtual void OnEnd();       

	int GetUpdateOrder();
	Actor* GetOwner();

protected :
	bool mIsActive;
	Actor* mOwner;
	int mUpdateOrder;
};
