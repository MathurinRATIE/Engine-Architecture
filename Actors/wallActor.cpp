#include "wallActor.h"

WallActor::WallActor(Scene* pScene, Window* pWindow, std::vector<Component*> pComponents, Transform2D pTransform, ActorState pState) : Actor(pScene, pWindow, pComponents, pState, pTransform)
{
	mTransform = pTransform;
	mRect = new Rectangle(mTransform.GetPosition(), mTransform.GetScale());

	Collider2D* collider = new Collider2D(mRect, this);
	Component* colliderComponent = dynamic_cast<Component*>(collider);
	AddComponent(colliderComponent);
}

void WallActor::UpdateActor()
{

}

Rectangle WallActor::GetRect()
{
	return *mRect;
}
