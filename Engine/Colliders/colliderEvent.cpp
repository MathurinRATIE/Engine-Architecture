#include "colliderEvent.h"

ColliderEvent::~ColliderEvent()
{
	mListeners.clear();
}

void ColliderEvent::Subscribe(IColliderListener* pListener)
{
	mListeners.push_back(pListener);
}

void ColliderEvent::Unsubscribe(IColliderListener* pListener)
{
	std::vector<IColliderListener*>::iterator listenersIterator;
	if ((listenersIterator = std::find(mListeners.begin(), mListeners.end(), pListener)) != mListeners.end())
	{
		mListeners.erase(listenersIterator);
	}
}

void ColliderEvent::NotifyListeners(Collider3D* pCollider, ColliderState pState) const
{
	for (IColliderListener* listener : mListeners)
	{
		listener->OnNotifyCollider(pCollider, pState);
	}
}
