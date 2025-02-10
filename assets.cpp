#include "assets.h"
#include <sstream>
#include "log.h"

Texture Assets::LoadTexture(Renderer& pRenderer, const std::string& pFileName, const std::string& pName)
{
    mTextures[pName] = LoadTextureFromFile(pRenderer, pFileName);
    return mTextures[pName];
}

Texture& Assets::GetTextureFromName(const std::string& pName)
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

Texture Assets::LoadTextureFromFile(Renderer& pRenderer, const std::string& pFileName)
{
    Texture texture;
    texture.Load(pRenderer, pFileName);
    return texture;
}
