#pragma once
#include "rectangle.h"
#include "component.h"
#include "IColliderListener.h"

enum class ColliderState {
	CollisionEnter,
	CollisionTrigger,
	CollisionExit,
	CollisionNone
};

class Collider2D : public IColliderListener, public Component
{
public :
	Collider2D(Actor* pOwner, Actor* pCollidingActor = nullptr, int pUpdateOrder = 100, bool pIsActive = true);

	void Update() override;

	bool CheckCollisions(Rectangle pBox);
	Rectangle GetHitBox();
	void SetState(ColliderState pState);
	ColliderState GetState();

	void OnNotifyCollider(Collider2D* pCollider, ColliderState pState) override;

protected :
	Actor* mCollidingActor;
	ColliderState mState;
};
