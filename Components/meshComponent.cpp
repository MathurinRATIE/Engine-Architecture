#include "meshComponent.h"
#include "scene.h"

MeshComponent::MeshComponent(Actor* pOwner)
{
	mMesh = new Mesh();
	Scene::ActiveScene
}

MeshComponent::~MeshComponent()
{
}

void MeshComponent::Draw(Matrix4Row viewProj)
{
}

void MeshComponent::SetMesh(Mesh& pMesh)
{
}

void MeshComponent::SetTextureIndex(size_t pTextureIndex)
{
}
