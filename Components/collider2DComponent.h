#pragma once
#include "rectangle.h"
#include "vector4.h"
#include "component.h"
#include "IColliderListener.h"

enum class ColliderState {
	CollisionEnter,
	CollisionTrigger,
	CollisionExit,
	CollisionNone,
	CollisionGounded
};

class Collider2D : public IColliderListener, public Component
{
public :
	Collider2D(Actor* pOwner, Vector4 pOffset = Vector4(), Actor* pCollidingActor = nullptr, int pUpdateOrder = 100, bool pIsActive = true);

	void Update() override;

	bool CheckCollisions(Collider2D* pCollider);
	bool CheckGrounded(Rectangle pBox);
	Rectangle GetHitBox();
	void SetState(ColliderState pState);
	ColliderState GetState();
	Actor* GetCollidingActor();

	void OnNotifyCollider(Collider2D* pCollider, ColliderState pState) override;

protected :
	Vector4 mOffset;
	Actor* mCollidingActor;
	ColliderState mState;
};
