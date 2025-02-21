#pragma once
#include <vector>
#include "IColliderListener.h"
#include "collider2DComponent.h"

class ColliderEvent
{
public:
	~ColliderEvent();

	void Subscribe(IColliderListener* pListener);
	void Unsubscribe(IColliderListener* pListener);
	void NotifyListeners(Collider2D* pCollider, ColliderState pState) const;

private:
	std::vector<IColliderListener*> mListeners;
};
