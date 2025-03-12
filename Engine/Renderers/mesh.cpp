#include "mesh.h"
#include "texture.h"
#include "assets.h"

Mesh::Mesh()
{
    mVertexArray = new VertexArray(cubeVertices, 28, cubeIndices, 36);

    mVertexShader = new Shader();
    mFragmentShader = new Shader();
    mVertexShader->Load("mesh.vs", ShaderType::VERTEX);
    mFragmentShader->Load("mesh.fs", ShaderType::FRAGMENT);

    mShaderProgram = new ShaderProgram();
    mShaderProgram->Compose({ &mVertexShader, &mFragmentShader });

    mTextures.emplace_back(&Assets::GetTextureFromName("Wall"));
}

Mesh::~Mesh()
{
    delete mVertexShader;
}

void Mesh::Unload()
{
    delete mVertexArray;
}

void Mesh::AddTexture(Texture* pTexture)
{
    mTextures.push_back(pTexture);
}

/*void Mesh::CreateShaderProgram(std::string pVertexShaderFile, std::string pFragmentShaderFile)
{
    mVertexShader->Load(pVertexShaderFile, ShaderType::VERTEX);
    mFragmentShader->Load(pFragmentShaderFile, ShaderType::FRAGMENT);
    mShaderProgram->Compose({ &mVertexShader, &mFragmentShader });
}*/

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
