#include "texture.h"

bool Texture::Load(Renderer& pRenderer, const std::string& pFileName)
{
	// Create Surface from File
	mFileName = pFileName;
	SDL_Surface* surface = IMG_Load(mFileName.c_str());
	
	if (!surface)
	{
		Log::Error(LogType::Application, "Failed to load texture file :" + mFileName);
		return false;
	}

	mWidth = surface->w;
	mHeight = surface->h;

	// Create Texture from Surface
	mSDLTexture = SDL_CreateTextureFromSurface(pRenderer.GetRenderer(), surface);
	SDL_FreeSurface(surface);
	
	if (!mSDLTexture)
	{
		Log::Error(LogType::Render, "Failed to convert surface to texture :" + mFileName);
		return false;
	}

	Log::Info("Loaded texture : " + mFileName);
	return true;
}

void Texture::Unload()
{
	if (mSDLTexture)
	{
		SDL_DestroyTexture(mSDLTexture);
	}
}

void Texture::UpdateInfo(int& pWidthOut, int& pHeightOut)
{
	pWidthOut = mWidth;
	pHeightOut = mHeight;
}

int Texture::GetWidth()
{
	return mWidth;
}

int Texture::GetHeight()
{
	return mHeight;
}
