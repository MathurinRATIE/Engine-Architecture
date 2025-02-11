#pragma once
#include <map>
#include <string>

class Renderer;
class Texture;

class Assets
{
public :
	static std::map<std::string, Texture> mTextures;

	static Texture LoadTexture(Renderer& pRenderer, std::string& pFileName, std::string& pName);
	static Texture& GetTextureFromName(std::string& pName);
	static void Clear();

private :
	Assets() = default;
	static Texture LoadTextureFromFile(Renderer& pRenderer, std::string& pFileName);
};
