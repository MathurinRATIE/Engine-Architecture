#pragma once
#include "actorState.h"
#include "rectangle.h"
#include "window.h"
#include "transform2D.h"
#include <vector>

class Scene;
class IRenderer;
class Component;
class SpriteComponent;

class Actor
{
protected:
	Scene* mSceneOwner;
	Window* mWindow;
	IRenderer* mRenderer;
	ActorState mState;
	Transform2D mTransform;
	SpriteComponent* mSprite;
	std::vector<Component*> mComponents;
	std::vector<std::string> mTags;

public :
	Actor(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, ActorState pState = ActorState::Active, Transform2D pTransform = Transform2D());
	virtual ~Actor();
	Actor(const Actor&) = delete;
	Actor& operator=(const Actor&) = delete;

	void Start();
	void Update();
	void UpdateComponents();
	virtual void UpdateActor();

	void SetActive(bool pIsActive);

	virtual Rectangle GetRect();
	Scene* GetScene();
	ActorState GetState();
	Transform2D* GetTransform();
	std::vector<Component*> GetComponents();
	SpriteComponent* GetSpriteComponent();
	std::vector<std::string> GetAllTags();
	bool HasTag(std::string);

	void AttachScene(Scene* pScene);
	void AddComponent(Component* pComponent);
	void RemoveComponent(Component* pComponent);
	void SetTransform(Transform2D pTransform);
	void SetSprite(SpriteComponent* pSprite);
	bool AddTag(std::string pTag);
	bool RemoveTag(std::string pTag);

	template<typename T>
	inline T* GetComponentOfType() const
	{
		T* result = nullptr;
		for (Component* component : mComponents)
		{
			result = dynamic_cast<T*>(component);
			if (result != nullptr)
			{
				return result;
			}
		}
		return nullptr;
	}
};
