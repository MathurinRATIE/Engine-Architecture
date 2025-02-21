#pragma once
#include <map>
#include "colliderEvent.h"


class CollisionManager
{
public:
	CollisionManager() = default;
	~CollisionManager();
	CollisionManager(const CollisionManager&) = delete;
	CollisionManager& operator=(const CollisionManager&) = delete;

	void CheckCollisions();
	void SubscribeTo(Collider2D* pCollider, IColliderListener* pListener);

	static CollisionManager& Instance();

private:
	std::map<Collider2D*, ColliderEvent*> mColliderEvents;
};
