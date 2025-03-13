#include "mesh.h"
#include "texture.h"
#include "assets.h"

Mesh::Mesh(std::vector<Vertex> pVertices) : mVertices(pVertices)
{
    float* verticesArray = ToVerticeArray();
    mVertexArray = new VertexArray(verticesArray, mVertices.size());
    delete[] verticesArray;
    mShaderProgram = Assets::GetShaderProgramFromName("Mesh");
    mTextures.emplace_back(&Assets::GetTextureFromName("Wall"));
}

Mesh::~Mesh()
{
    delete mVertexArray;
}

void Mesh::Unload()
{
    delete mVertexArray;
}

void Mesh::AddTexture(Texture* pTexture)
{
    mTextures.push_back(pTexture);
}

float* Mesh::ToVerticeArray()
{
    float* verticesArray = new float[mVertices.size() * 8];
    int counter = 0;

    for (int i = 0; i < mVertices.size(); i++)
    {
        verticesArray[counter] = mVertices[i].mPosition.x;
        verticesArray[counter + 1] = mVertices[i].mPosition.y;
        verticesArray[counter + 2] = mVertices[i].mPosition.z;
        verticesArray[counter + 3] = mVertices[i].mNormal.x;
        verticesArray[counter + 4] = mVertices[i].mNormal.y;
        verticesArray[counter + 5] = mVertices[i].mNormal.z;
        verticesArray[counter + 6] = mVertices[i].mTexCoord.x;
        verticesArray[counter + 7] = mVertices[i].mTexCoord.y;
        counter += 8;
    }

    return verticesArray;
}

ShaderProgram* Mesh::GetShaderProgram()
{
    return mShaderProgram;
}

VertexArray* Mesh::GetVertexArray()
{
    return mVertexArray;
}

Texture* Mesh::GetTexture(size_t pTextureIndex)
{
    if (mTextures.size() > pTextureIndex)
    {
        return mTextures[pTextureIndex];
    }
    return nullptr;
}
