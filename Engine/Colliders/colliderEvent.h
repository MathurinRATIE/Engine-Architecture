#pragma once
#include <vector>
#include "IColliderListener.h"
#include "collider3DComponent.h"

class ColliderEvent
{
public:
	~ColliderEvent();

	void Subscribe(IColliderListener* pListener);
	void Unsubscribe(IColliderListener* pListener);
	void NotifyListeners(Collider3D* pCollider, ColliderState pState) const;

private:
	std::vector<IColliderListener*> mListeners;
};
