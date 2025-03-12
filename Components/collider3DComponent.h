#pragma once
#include "rectangle.h"
#include "vector4.h"
#include "component.h"
#include "IColliderListener.h"
#include "cube.h"

enum class ColliderState {
	CollisionEnter,
	CollisionTrigger,
	CollisionExit,
	CollisionNone,
	CollisionGounded
};

class Collider3D : public IColliderListener, public Component
{
public :
	Collider3D(Actor* pOwner, Vector3 pBeforeOffset = Vector3(), Vector3 pAfterOffset = Vector3(), Actor* pCollidingActor = nullptr, int pUpdateOrder = 100, bool pIsActive = true);

	void Update() override;

	bool CheckCollisions(Collider3D* pCollider);
	bool CheckGrounded(Cube pBox);
	Cube GetHitBox();
	void SetState(ColliderState pState);
	ColliderState GetState();
	Actor* GetCollidingActor();

	void OnNotifyCollider(Collider3D* pCollider, ColliderState pState) override;

protected :
	Vector3 mBeforeOffset;
	Vector3 mAfterOffset;
	Actor* mCollidingActor;
	ColliderState mState;
};
