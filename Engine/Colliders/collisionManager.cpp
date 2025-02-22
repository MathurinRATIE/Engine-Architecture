#include "collisionManager.h"

CollisionManager::~CollisionManager()
{
	std::map<Collider2D*, ColliderEvent*>::iterator colliderEventsIterator;
	for (colliderEventsIterator = mColliderEvents.begin(); colliderEventsIterator != mColliderEvents.end(); colliderEventsIterator++)
	{
		delete(colliderEventsIterator->second);
	}
}

bool CollisionManager::IsColliding(Collider2D* pCollider)
{
	for (std::pair<Collider2D*, ColliderEvent*> collider2 : mColliderEvents)
	{
		if (pCollider != collider2.first && pCollider->CheckCollisions(collider2.first->GetHitBox()))
		{
			return true;
		}
	}

	return false;
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
				case ColliderState::CollisionGounded:
					newState = ColliderState::CollisionEnter;
					break;
				}

				isColliding = true;
				collider1.second->NotifyListeners(collider2.first, newState);
				break;
			}
			else if (collider1 != collider2 && collider1.first->CheckGrounded(collider2.first->GetHitBox())) {
				isColliding = true;
				collider1.second->NotifyListeners(collider2.first, ColliderState::CollisionGounded);
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
			case ColliderState::CollisionGounded:
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
