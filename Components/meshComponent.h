#pragma once
#include "component.h"
#include "matrix4Row.h"
#include "mesh.h"

class MeshComponent : public Component
{
public:
	MeshComponent(Actor* pOwner);
	virtual ~MeshComponent();
	
	virtual void Draw(Matrix4Row viewProj);

	virtual void SetMesh(Mesh& pMesh);
	void SetTextureIndex(int pTextureIndex);

protected:
	Mesh* mMesh;
	unsigned int mTextureIndex;
};
