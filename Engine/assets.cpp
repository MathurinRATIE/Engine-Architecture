#include "assets.h"
#include <sstream>
#include "log.h"
#include "texture.h"
#include "renderer.h"

std::map<std::string, Texture> Assets::mTextures = {};

Texture Assets::LoadTexture(Renderer& pRenderer, std::string& pFileName, std::string& pName)
{
    mTextures[pName] = LoadTextureFromFile(pRenderer, pFileName);
    return mTextures[pName];
}

Texture& Assets::GetTextureFromName(std::string& pName)
{
    if (mTextures.find(pName) == mTextures.end())
    {
        std::ostringstream loadError;
        loadError << "Texture " << pName << " does not exist in assets manager \n";
        Log::Error(LogType::Application, loadError.str());
    }
    return mTextures[pName];
}

void Assets::Clear()
{
    for (auto iter : mTextures)
    {
        iter.second.Unload();
    }
    mTextures.clear();
}

Texture Assets::LoadTextureFromFile(Renderer& pRenderer, std::string& pFileName)
{
    Texture texture;
    texture.Load(pRenderer, pFileName);
    return texture;
}
