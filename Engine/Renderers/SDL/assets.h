#pragma once
#include <map>
#include <string>

class RendererSdl;
class Texture;
class IRenderer;

class Assets
{
public :
	static std::map<std::string, Texture> mTextures;

	static Texture LoadTexture(IRenderer& pRenderer, std::string& pFileName, std::string& pName);
	static Texture& GetTextureFromName(std::string& pName);
	static void Clear();

private :
	Assets() = default;
	static Texture LoadTextureFromFile(IRenderer& pRenderer, std::string& pFileName);
};
