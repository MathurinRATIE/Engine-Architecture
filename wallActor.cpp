#include "wallActor.h"

Wall::Wall(Scene* pScene, Window* pWindow, std::vector<Component*> pComponents, ActorState pState, Transform2D pTransform) : Actor(pScene, pWindow, pComponents, pState, pTransform)
{
	mRect = new Rectangle(Vector2(mWindow->GetDimensions().x / 2 + 100, mWindow->GetDimensions().y / 2 - 150), Vector2(15, 15));

	Collider2D* collider = new Collider2D(mRect, this);
	Component* colliderComponent = dynamic_cast<Component*>(collider);
	AddComponent(colliderComponent);
}

void Wall::UpdateActor(unsigned int pDeltaTime)
{

}

Rectangle Wall::GetRect()
{
	return *mRect;
}
