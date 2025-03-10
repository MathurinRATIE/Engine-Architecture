#include "texture.h"

Texture::Texture()
{
}

Texture::~Texture()
{
}

bool Texture::Load(IRenderer& pRenderer, const std::string& pFileName)
{
	mFileName = pFileName;
	SDL_Surface* surface = IMG_Load(mFileName.c_str());
	
	if (!surface)
	{
		Log::Error(LogType::Application, "Failed to load texture file :" + mFileName);
		return false;
	}

	mWidth = surface->w;
	mHeight = surface->h;

	if (pRenderer.GetType() == IRenderer::RendererType::SDL)
	{
		return LoadSdl(dynamic_cast<RendererSdl*>(&pRenderer), pFileName, surface);
	}
	return LoadGl(dynamic_cast<RendererGl*>(&pRenderer), pFileName, surface);
}

void Texture::Unload()
{
	if (mSDLTexture)
	{
		SDL_DestroyTexture(mSDLTexture);
	}
	else
	{
		glDeleteTextures(1, &mTextureId);
	}
}

void Texture::SetActive()
{
	glBindTexture(GL_TEXTURE_2D, mTextureId);
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

SDL_Texture* Texture::GetSdlTexture()
{
	return mSDLTexture;
}

bool Texture::LoadSdl(RendererSdl* pRenderer, const std::string& pFileName, SDL_Surface* pSurface)
{
	mSDLTexture = SDL_CreateTextureFromSurface(pRenderer->ToSdlRenderer(), pSurface);
	SDL_FreeSurface(pSurface);

	if (!mSDLTexture)
	{
		Log::Error(LogType::Render, "Failed to convert surface to texture :" + mFileName);
		return false;
	}

	Log::Info("Loaded SDL texture : " + mFileName);
	return true;
}

bool Texture::LoadGl(RendererGl* pRenderer, const std::string& pFileName, SDL_Surface* pSurface)
{
	int format = 0;
	if (pSurface->format->format == SDL_PIXELFORMAT_RGB24)
	{
		format = GL_RGB;
	}
	else if (pSurface->format->format == SDL_PIXELFORMAT_RGBA32)
	{
		format = GL_RGBA;
	}

	glGenTextures(1, &mTextureId);
	glBindTexture(GL_TEXTURE_2D, mTextureId);
	glTexImage2D(GL_TEXTURE_2D, 0, format, mWidth, mHeight, 0, format, GL_UNSIGNED_BYTE, pSurface->pixels);
	SDL_FreeSurface(pSurface);
	Log::Info("Loaded GL Texture : " + mFileName);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;
}
