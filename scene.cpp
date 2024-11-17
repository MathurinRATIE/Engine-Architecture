#include "scene.h"

Scene::Scene()
{
}

void Scene::AddPendingActors()
{
	for (Actor* actor : mPendingActors)
	{
		AddActor(actor);
	}

	mPendingActors.clear();
}

void Scene::RemovePendingActors()
{
	for (Actor* actor : mPendingRemoveActors)
	{
		RemoveActor(actor);
	}

	mPendingRemoveActors.clear();
}

void Scene::AddActor(Actor* pActor)
{
	mActors.push_back(pActor);
}

void Scene::AddPendingActor(Actor* pActor)
{
	mPendingActors.push_back(pActor);
}

void Scene::AddPendingRemoveActor(Actor* pActor)
{
	mPendingRemoveActors.push_back(pActor);
}

void Scene::RemoveActor(Actor* pActor)
{
	auto iterator = std::find(mActors.begin(), mActors.end(), pActor);

	if (iterator != mActors.end())
	{
		mActors.erase(iterator);

		for (Component* component : pActor->GetComponents())
		{
			pActor->RemoveComponent(component);
		}
		delete(pActor);
	}
}

std::vector<Actor*> Scene::GetActors()
{
	return mActors;
}
