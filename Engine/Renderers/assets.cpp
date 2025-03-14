#include "assets.h"
#include <sstream>
#include "log.h"
#include "texture.h"
#include "rendererSdl.h"
#include "tiny_obj_loader.h"
#include "mesh.h"

std::map<std::string, Texture> Assets::mTextures = {};
std::map<std::string, ShaderProgram*> Assets::mShaderPrograms = {};
std::map<std::string, Mesh*> Assets::mMeshes = {};

Texture Assets::LoadTexture(IRenderer* pRenderer, std::string pFileName, std::string pName)
{
    mTextures[pName] = LoadTextureFromFile(pRenderer, pFileName);
    return mTextures[pName];
}

ShaderProgram* Assets::LoadShaderProgram(std::string pVertexShaderName, std::string pFragmentShaderName, std::string pName)
{
    mShaderPrograms[pName] = LoadShaderProgramFromShaderNames(pVertexShaderName, pFragmentShaderName);
    return mShaderPrograms[pName];
}

Mesh* Assets::LoadMesh(std::string pFileName, std::string pName)
{
    mMeshes[pName] = LoadMeshFromFile(pFileName);
    return mMeshes[pName];
}

Texture& Assets::GetTextureFromName(std::string pName)
{
    if (mTextures.find(pName) == mTextures.end())
    {
        std::ostringstream loadError;
        loadError << "Texture " << pName << " does not exist in assets manager \n";
        Log::Error(LogType::Application, loadError.str());
    }
    return mTextures[pName];
}

ShaderProgram* Assets::GetShaderProgramFromName(std::string pName)
{
    if (mShaderPrograms.find(pName) == mShaderPrograms.end())
    {
        std::ostringstream loadError;
        loadError << "ShaderProgram " << pName << " does not exist in assets manager \n";
        Log::Error(LogType::Application, loadError.str());
    }
    return mShaderPrograms[pName];
}

Mesh* Assets::GetMeshFromName(std::string pName)
{
    if (mMeshes.find(pName) == mMeshes.end())
    {
        std::ostringstream loadError;
        loadError << "Mesh " << pName << " does not exist in assets manager \n";
        Log::Error(LogType::Application, loadError.str());
    }
    return mMeshes[pName];
}

void Assets::Clear()
{
    for (auto texturesIter : mTextures)
    {
        texturesIter.second.Unload();
    }
    for (auto shadersIter : mShaderPrograms)
    {
        shadersIter.second->Unload();
    }
    mTextures.clear();
    mShaderPrograms.clear();
}

Texture Assets::LoadTextureFromFile(IRenderer* pRenderer, std::string& pFileName)
{
    Texture texture;
    texture.Load(*pRenderer, pFileName);
    return texture;
}

ShaderProgram* Assets::LoadShaderProgramFromShaderNames(std::string pVertexShaderName, std::string pFragmentShaderName)
{
    Shader vertexShader = Shader();
    Shader fragmentShader = Shader();
    vertexShader.Load(pVertexShaderName, ShaderType::VERTEX);
    fragmentShader.Load(pFragmentShaderName, ShaderType::FRAGMENT);

    ShaderProgram* shaderProgram = new ShaderProgram();
    shaderProgram->Compose({ &vertexShader, &fragmentShader });

    return shaderProgram;
}

Mesh* Assets::LoadMeshFromFile(std::string& pFileName)
{
    tinyobj::attrib_t attributes;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warning, errors;
    std::string dir = "Imports/Meshes/";

    bool success = LoadObj(& attributes, & shapes, & materials, & warning, & errors, (dir + pFileName).c_str());
    if (!success)
    {
        Log::Error(LogType::Application, "Mesh " + pFileName + " does not exist or is not .obj");
        return nullptr;
    }
    
    std::vector<Vertex> vertices{};
    for (int i = 0; i < shapes.size(); i++)
    {
        tinyobj::shape_t& shape = shapes[i];
        tinyobj::mesh_t& mesh = shape.mesh;

        for (int j = 0; j < mesh.indices.size(); j++)
        {
            tinyobj::index_t ind = mesh.indices[j];

            Vector3 position = Vector3{
                attributes.vertices[ind.vertex_index * 3],
                attributes.vertices[ind.vertex_index * 3 + 1],
                attributes.vertices[ind.vertex_index * 3 + 2],
            };
            Vector3 normal = Vector3{
                attributes.normals[ind.normal_index * 3],
                attributes.normals[ind.normal_index * 3 + 1],
                attributes.normals[ind.normal_index * 3 + 2],
            };
            Vector2 texCoord = Vector2{
                attributes.texcoords[ind.texcoord_index * 2],
                attributes.texcoords[ind.texcoord_index * 2 + 1],
            };
            Vertex vertice = { position, normal, texCoord };

            vertices.push_back(vertice);
        }
    }
    Log::Info("Mesh " + pFileName + " successfully loaded");

    return new Mesh(vertices);
}
