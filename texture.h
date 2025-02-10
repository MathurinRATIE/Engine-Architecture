#pragma once
#include "renderer.h"

class Texture
{
public :
	bool Load(Renderer& pRenderer, const std::string& pFileName);
	void Unload();
	void UpdateInfo(int& pWidthOut, int& pHeightOut);

	int GetWidth();
	int GetHeight();

protected :
	std::string mFileName;
	int mWidth;
	int mHeight;
	SDL_Texture* mSDLTexture;
};
