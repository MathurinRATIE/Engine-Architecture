#pragma once
#include <vector>
#include "SDL_image.h"
#include "rectangle.h"
#include "window.h"
#include "vector4.h"
#include "actor.h"
#include "maths.h"

class SpriteComponent;
class Texture;

class Renderer
{
public:
	enum class Flip
	{
		None = SDL_FLIP_NONE,
		Horizontal = SDL_FLIP_HORIZONTAL,
		Vertical = SDL_FLIP_VERTICAL
	};

	Renderer();
	Renderer(const Renderer&) = delete;
	Renderer& operator= (const Renderer&) = delete;

	bool Initialize(Window* rWindow);
	void BeginDraw();
	void EndDraw();
	void Close();

	void DrawRect(Rectangle rRect, Color pColor);
	SDL_Renderer* GetRenderer();

	void DrawSprites();
	void DrawSprite(Actor* pOwner, Texture pTexture, Rectangle rectangle, Vector2 origin, Renderer::Flip flip) const;
	void AddSprite(SpriteComponent* pSprite);
	void RemoveSprite(SpriteComponent* pSprite);

private:
	SDL_Renderer* mSdlRenderer;
	std::vector<SpriteComponent*> mSprites;
};
