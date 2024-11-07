#pragma once
#include "rectangle.h"
#include "window.h"

class Renderer
{
private:
	SDL_Renderer* mSdlRenderer;
public:
	Renderer(Window* rWindow);
	Renderer(const Renderer&) = delete;
	Renderer& operator= (const Renderer&) = delete;

	bool Initialize(Window* rWindow);
	void BeginDraw();
	void EndDraw();
	void Close();

	void DrawRect(Rectangle& rRect);
};
