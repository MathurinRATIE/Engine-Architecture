#pragma once
#include "rendererSdl.h"
#include "rendererGl.h"

class Texture
{
public :
	Texture();
	~Texture();

	bool Load(IRenderer& pRenderer, const std::string& pFileName);
	void Unload();
	void SetActive();
	void UpdateInfo(int& pWidthOut, int& pHeightOut);

	int GetWidth();
	int GetHeight();
	SDL_Texture* GetSdlTexture();

protected :
	std::string mFileName;
	int mWidth = 0;
	int mHeight;
	SDL_Texture* mSDLTexture = nullptr;
	unsigned int mTextureId;
	bool LoadSdl(RendererSdl* pRenderer, const std::string& pFileName, SDL_Surface* pSurface);
	bool LoadGl(RendererGl* pRenderer, const std::string& pFileName, SDL_Surface* pSurface);
};
