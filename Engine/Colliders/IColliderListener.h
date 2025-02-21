#pragma once
class Collider2D;
enum class ColliderState;

class IColliderListener
{
public:
	virtual ~IColliderListener() = default;
	virtual void OnNotifyCollider(Collider2D* pCollider, ColliderState pState) = 0;
};
