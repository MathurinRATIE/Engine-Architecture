#pragma once
#include "mesh.h"
#include "component.h"
#include "matrix4Row.h"

class MeshComponent : public Component
{
public:
	MeshComponent(Actor* pOwner);
	virtual ~MeshComponent();
	
	virtual void Draw(Matrix4Row viewProj);

	virtual void SetMesh(Mesh& pMesh);
	void SetTextureIndex(size_t pTextureIndex);

protected:
	Mesh* mMesh;
	size_t mTextureIndex;
};
