#include "scene.h"

Scene::Scene()
{
}

void Scene::AddActor(Actor* pActor)
{
	mActors.push_back(pActor);
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
