#pragma once
#include <map>
#include <string>

class RendererSdl;
class Texture;

class Assets
{
public :
	static std::map<std::string, Texture> mTextures;

	static Texture LoadTexture(RendererSdl& pRenderer, std::string& pFileName, std::string& pName);
	static Texture& GetTextureFromName(std::string& pName);
	static void Clear();

private :
	Assets() = default;
	static Texture LoadTextureFromFile(RendererSdl& pRenderer, std::string& pFileName);
};
