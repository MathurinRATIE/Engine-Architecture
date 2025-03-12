#pragma once
class Collider3D;
enum class ColliderState;

class IColliderListener
{
public:
	virtual ~IColliderListener() = default;
	virtual void OnNotifyCollider(Collider3D* pCollider, ColliderState pState) = 0;
};
