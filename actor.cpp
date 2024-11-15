#include "scene.h"
#include "component.h"
#include "transform2D.h"
#include "actor.h"

Actor::Actor(Scene* pScene, std::vector<Component*> pComponents, ActorState pState, Transform2D pTransform)
{

}

void Actor::Start()
{
}

void Actor::AttachScene(Scene* pScene)
{
}

void Actor::AddComponent(Component* pComponent)
{
}

void Actor::RemoveComponent(Component* pComponent)
{
}

void Actor::SetActive(bool pIsActive)
{
}

void Actor::Update()
{
}

void Actor::Destroy()
{
}
