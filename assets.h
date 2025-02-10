#pragma once
#include <map>
#include "texture.h"

class Assets
{
public :
	static std::map<std::string, Texture> mTextures;

	static Texture LoadTexture(Renderer& pRenderer, const std::string& pFileName, const std::string& pName);
	static Texture& GetTextureFromName(const std::string& pName);
	static void Clear();

private :
	Assets() = default;
	static Texture LoadTextureFromFile(Renderer& pRenderer, const std::string& pFileName);
};

