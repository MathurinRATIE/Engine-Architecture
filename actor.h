#pragma once
#include "actorState.h"
#include "rectangle.h"
#include "window.h"
#include "transform2D.h"
#include <vector>

class Scene;
class Component;
class SpriteComponent;

class Actor
{
public :
	Actor(Scene* pScene, Window* pWindow, std::vector<Component*> pComponents, ActorState pState = ActorState::Active, Transform2D pTransform = Transform2D());
	virtual ~Actor();
	Actor(const Actor&) = delete;
	Actor& operator=(const Actor&) = delete;

	void Start();
	void Update(unsigned int pDeltaTime);
	void UpdateComponents(unsigned int pDeltaTime);
	virtual void UpdateActor(unsigned int pDeltaTime);

	void SetActive(bool pIsActive);

	virtual Rectangle GetRect();
	Scene* GetScene();
	ActorState GetState();
	Transform2D GetTransform();
	std::vector<Component*> GetComponents();
	SpriteComponent* GetSpriteComponent();

	void AttachScene(Scene* pScene);
	void AddComponent(Component* pComponent);
	void RemoveComponent(Component* pComponent);
	void SetTransform(Transform2D pTransform);
	void SetSprite(SpriteComponent* pSprite);

protected :
	Scene* mSceneOwner;
	Window* mWindow;
	ActorState mState;
	Transform2D mTransform;
	SpriteComponent* mSprite;
	std::vector<Component*> mComponents;
};
