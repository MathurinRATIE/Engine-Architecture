#pragma once
#include "actorState.h"
#include <vector>

class Actor
{
public :
	Actor(Scene* pScene, std::vector<Component*> pComponents, ActorState pState = ActorState::Active, Transform2D pTransform = Transform2D());

	void Start();
	void Update();
	void Destroy();

	void SetActive(bool pIsActive);

	Scene* GetScene();
	ActorState GetState();
	Transform2D GetTransform();

	void AttachScene(Scene* pScene);
	void AddComponent(Component* pComponent);
	void RemoveComponent(Component* pComponent);

protected :
	Scene* mSceneOwner;
	ActorState mState;
	Transform2D mTransform;
	std::vector<Component*> mComponents;
};