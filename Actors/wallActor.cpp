#include "wallActor.h"

WallActor::WallActor(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, Transform2D pTransform, ActorState pState) : Actor(pScene, pWindow, pRenderer, pComponents, pState, pTransform)
{
	mTransform = pTransform;
	mRect = new Rectangle(mTransform.GetPosition(), mTransform.GetScale());

	Collider2D* collider = new Collider2D(this);
	AddComponent(collider);
}

void WallActor::UpdateActor()
{

}

Rectangle WallActor::GetRect()
{
	return *mRect;
}
