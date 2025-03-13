#pragma once
#define TINYOBJLOADER_IMPLEMENTATION
#include <map>
#include <string>
#include "shaderProgram.h"

class RendererSdl;
class Texture;
class Mesh;
class IRenderer;

class Assets
{
public :
	static std::map<std::string, Texture> mTextures;
	static std::map<std::string, ShaderProgram*> mShaderPrograms;
	static std::map<std::string, Mesh*> mMeshes;

	static Texture LoadTexture(IRenderer* pRenderer, std::string pFileName, std::string pName);
	static ShaderProgram* LoadShaderProgram(std::string pVertexShaderName, std::string pFragmentShaderName, std::string pName);
	static Mesh* LoadMesh(std::string pFileName, std::string pName);
	static Texture& GetTextureFromName(std::string pName);
	static ShaderProgram* GetShaderProgramFromName(std::string pName);
	static Mesh* GetMeshFromName(std::string pName);
	static void Clear();

private :
	Assets() = default;
	static Texture LoadTextureFromFile(IRenderer* pRenderer, std::string& pFileName);
	static ShaderProgram* LoadShaderProgramFromShaderNames(std::string pVertexShaderName, std::string pFragmentShaderName);
	static Mesh* LoadMeshFromFile(std::string& pFileName);
};
