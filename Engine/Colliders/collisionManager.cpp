#include "collisionManager.h"

CollisionManager::~CollisionManager()
{
	std::map<Collider2D*, ColliderEvent*>::iterator colliderEventsIterator;
	for (colliderEventsIterator = mColliderEvents.begin(); colliderEventsIterator != mColliderEvents.end(); colliderEventsIterator++)
	{
		delete(colliderEventsIterator->second);
	}
}

void CollisionManager::CheckCollisions()
{
	for (std::pair<Collider2D*, ColliderEvent*> collider1 : mColliderEvents)
	{
		ColliderState previousState = collider1.first->GetState();
		bool isColliding = false;

		for (std::pair<Collider2D*, ColliderEvent*> collider2 : mColliderEvents)
		{
			if (collider1 != collider2 && collider1.first->CheckCollisions(collider2.first->GetHitBox()))
			{
				ColliderState newState = previousState;
				switch (previousState)
				{
				case ColliderState::CollisionEnter:
					newState = ColliderState::CollisionTrigger;
					break;
				case ColliderState::CollisionExit:
					newState = ColliderState::CollisionEnter;
					break;
				case ColliderState::CollisionNone:
					newState = ColliderState::CollisionEnter;
					break;
				}

				isColliding = true;
				collider1.second->NotifyListeners(collider2.first, newState);
			}
		}

		if (!isColliding)
		{
			switch (previousState)
			{
			case ColliderState::CollisionEnter:
				collider1.second->NotifyListeners(nullptr, ColliderState::CollisionExit);
				break;
			case ColliderState::CollisionTrigger:
					collider1.second->NotifyListeners(nullptr, ColliderState::CollisionExit);
					break;
			case ColliderState::CollisionExit:
				collider1.first->SetState(ColliderState::CollisionNone);
				break;
			}
		}
	}
}

void CollisionManager::SubscribeTo(Collider2D* pCollider, IColliderListener* pListener)
{
	size_t hasKey = mColliderEvents.count(pCollider);
	if (hasKey == 0)
	{
		mColliderEvents[pCollider] = new ColliderEvent();
	}

	mColliderEvents[pCollider]->Subscribe(pListener);
}

CollisionManager& CollisionManager::Instance()
{
	static CollisionManager instance;
	return instance;
}
