#pragma once
#include "rendererSdl.h"

class Texture
{
public :
	bool Load(RendererSdl& pRenderer, const std::string& pFileName);
	void Unload();
	void UpdateInfo(int& pWidthOut, int& pHeightOut);

	int GetWidth();
	int GetHeight();
	SDL_Texture* GetSdlTexture();

protected :
	std::string mFileName;
	int mWidth = 0;
	int mHeight;
	SDL_Texture* mSDLTexture = nullptr;
};
