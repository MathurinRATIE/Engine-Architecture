#include "mesh.h"
#include "assets.h"

Mesh::Mesh()
{
    mVertexArray = new VertexArray(cubeVertices, 28, cubeIndices, 36);
    mVertexShader->Load("basic.vs", ShaderType::VERTEX);
    mFragmentShader->Load("basic.fs", ShaderType::FRAGMENT);
    mShaderProgram->Compose({ &mVertexShader, &mFragmentShader });
    mTextures.emplace_back(&Assets::GetTextureFromName("pokeball"));
}

Mesh::~Mesh()
{
    delete mFragmentShader;
    delete mVertexShader;
    delete mShaderProgram;
}

void Mesh::Unload()
{
    delete mVertexArray;
}

void Mesh::AddTexture(Texture* pTexture)
{
    mTextures.push_back(pTexture);
}

ShaderProgram* Mesh::GetShaderProgram()
{
    return mShaderProgram;
}

VertexArray* Mesh::GetVertexArray()
{
    return mVertexArray;
}

Texture* Mesh::GetTexture(int pTextureIndex)
{
    if (mTextures.size() >= pTextureIndex - 1)
    {
        return mTextures[pTextureIndex];
    }
    return nullptr;
}
