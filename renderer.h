#pragma once
#include "SDL_image.h"
#include "rectangle.h"
#include "window.h"
#include "vector4.h"

class Renderer
{
public:
	Renderer();
	Renderer(const Renderer&) = delete;
	Renderer& operator= (const Renderer&) = delete;

	bool Initialize(Window* rWindow);
	void BeginDraw();
	void EndDraw();
	void Close();

	void DrawRect(Rectangle& rRect, Color pColor);
	SDL_Renderer* GetRenderer();

private:
	SDL_Renderer* mSdlRenderer;
};
