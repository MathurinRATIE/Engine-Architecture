#include "scene.h"

Scene::Scene()
{
}

Scene::Scene(std::shared_ptr<Renderer> pRenderer, std::string pTitle)
{
	mRenderer = pRenderer;
	mTitle = pTitle;
}
