#include "meshComponent.h"
#include "scene.h"
#include "rendererGl.h"
#include "texture.h"

MeshComponent::MeshComponent(Actor* pOwner) : Component(pOwner)
{
	mMesh = Assets::GetMeshFromName("Cube");
	RendererGl* renderer = static_cast<RendererGl*>(mOwner->GetScene()->GetRenderer());
	renderer->AddMesh(this);
}

MeshComponent::~MeshComponent()
{
	RendererGl* renderer = static_cast<RendererGl*>(mOwner->GetScene()->GetRenderer());
	renderer->RemoveMesh(this);
}

void MeshComponent::Draw(Matrix4Row viewProj)
{
	if (mMesh)
	{
		mOwner->GetTransform()->ComputeWorldTransform();
		Matrix4Row worldTransform = mOwner->GetTransform()->GetWorldTransform();
		mMesh->GetShaderProgram()->Use();
		mMesh->GetShaderProgram()->setMatrix4Row("uViewProj", viewProj);
		mMesh->GetShaderProgram()->setMatrix4Row("uWorldTransform", worldTransform);

		int tiling = mOwner->GetTransform()->GetScale().x;
		if (tiling < mOwner->GetTransform()->GetScale().y)
		{
			tiling = mOwner->GetTransform()->GetScale().y;
		}
		if (tiling < mOwner->GetTransform()->GetScale().z)
		{
			tiling = mOwner->GetTransform()->GetScale().z;
		}
		mMesh->GetShaderProgram()->setVector2f("uTiling", Vector2(tiling, tiling));
		
		Texture* texture = mMesh->GetTexture(mTextureIndex);
		if (texture)
		{
			texture->SetActive();
		}

		mMesh->GetVertexArray()->SetActive();

		bool useTesselation = mMesh->GetShaderProgram()->UseTesselation();
		glDrawArrays(useTesselation ? GL_PATCHES : GL_TRIANGLES, 0, mMesh->GetVertexArray()->GetVerticeCount());
	}
}

void MeshComponent::SetMesh(Mesh& pMesh)
{
	mMesh = &pMesh;
}

void MeshComponent::SetTextureIndex(size_t pTextureIndex)
{
	mTextureIndex = pTextureIndex;
}

Mesh* MeshComponent::GetMesh()
{
	return mMesh;
}

size_t MeshComponent::GetTextureIndex(std::string pTextureName)
{
	int i = 0;
	for (Texture* texture : mMesh->GetTextures())
	{
		if (texture->GetFileName() == Assets::GetTextureFromName(pTextureName).GetFileName())
		{
			return i;
		}

		i++;
	}

	Log::Error(LogType::Application, "Texture is not fount in the mesh : " + pTextureName);
	return -1;
}
