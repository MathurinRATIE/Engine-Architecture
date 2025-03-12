#include "meshComponent.h"
#include "scene.h"
#include "rendererGl.h"
#include "texture.h"

MeshComponent::MeshComponent(Actor* pOwner) : Component(pOwner)
{
	mMesh = new Mesh();
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
		worldTransform *= worldTransform.CreateRotationX(0.5f);
		worldTransform *= worldTransform.CreateRotationZ(1.0f);
		mMesh->GetShaderProgram()->Use();
		mMesh->GetShaderProgram()->setMatrix4Row("uViewProj", viewProj);
		mMesh->GetShaderProgram()->setMatrix4Row("uWorldTransform", worldTransform);
		
		Texture* texture = mMesh->GetTexture(mTextureIndex);
		if (texture)
		{
			texture->SetActive();
		}

		mMesh->GetVertexArray()->SetActive();

		glDrawElements(GL_TRIANGLES, mMesh->GetVertexArray()->GetIndicesCount(), GL_UNSIGNED_INT, nullptr);
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
