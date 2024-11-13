#pragma once

class Component
{
public :
	Component();
	virtual ~Component();
	Component(const Component&) = delete;

	void OnStart();
	void Update();
	void OnEnd();

protected :
	bool mIsActive;
	Actor* mOwner;
	int mUpdateOrder;
};

