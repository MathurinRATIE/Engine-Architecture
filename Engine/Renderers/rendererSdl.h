#pragma once
#include <vector>
#include "SDL_image.h"
#include "rectangle.h"
#include "window.h"
#include "vector4.h"
#include "actor.h"
#include "maths.h"
#include "IRenderer.h"

class SpriteComponent;
class Texture;

class RendererSdl : public IRenderer
{
public:
	RendererSdl();
	RendererSdl(const RendererSdl&) = delete;
	RendererSdl& operator= (const RendererSdl&) = delete;

	bool Initialize(Window* rWindow) override;
	void BeginDraw() override;
	virtual void Draw() override;
	void EndDraw() override;
	void Close() override;

	void DrawRect(Rectangle rRect, Color pColor);
	SDL_Renderer* GetRenderer();
	IRenderer::RendererType GetType() override;

	void DrawSprites();
	void DrawSprite(Actor* pOwner, Texture pTexture, Rectangle rectangle, Vector2 origin, Flip flip) const override;
	void AddSprite(SpriteComponent* pSprite) override;
	void RemoveSprite(SpriteComponent* pSprite) override;

private:
	SDL_Renderer* mSdlRenderer;
	std::vector<SpriteComponent*> mSprites;
};
