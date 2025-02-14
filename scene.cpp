#include "scene.h"

Scene::Scene()
{
}

void Scene::UpdateAllActors(unsigned int pDeltaTime)
{
	for (Actor* actor : mActors)
	{
		actor->Update(pDeltaTime);
	}

	AddPendingActors();
	RemovePendingActors();
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

		std::vector<Component*> components = pActor->GetComponents();
		while (!components.empty())
		{
			pActor->RemoveComponent(components.back());
			components.pop_back();
		}

		mRenderer->RemoveSprite(pActor->GetSpriteComponent());
		delete(pActor);
	}
}

std::vector<Actor*> Scene::GetActors()
{
	return mActors;
}

Renderer* Scene::GetRenderer()
{
	return mRenderer;
}

void Scene::Unload()
{
	while (!mActors.empty())
	{
		RemoveActor(mActors.back());
	}

	Assets::Clear();
}
