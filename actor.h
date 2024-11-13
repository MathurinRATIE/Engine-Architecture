#pragma once
#include <vector>

enum ActorState;

class Actor
{
public :
	Actor();

	void Start();
	void AttachScene(Scene* scene);
	void AddComponent(Component* component);
	void RemoveComponent(Component* component);
	void SetActive();
	void Update();
	void Destroy();

protected :
	Scene* mSceneOwner;
	ActorState state;
	Transform2D transform;
	std::vector<Component> components;
};

enum class ActorState
{
	Active,
	Paused,
	Dead
};