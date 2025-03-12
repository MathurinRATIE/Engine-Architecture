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


	bool IsColliding(Collider3D* pCollider);
	void CheckCollisions();
	void SubscribeTo(Collider3D* pCollider, IColliderListener* pListener);

	static CollisionManager& Instance();

private:
	std::map<Collider3D*, ColliderEvent*> mColliderEvents;
};
