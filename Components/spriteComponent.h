#pragma once
#include "texture.h"
#include "actor.h"
#include "scene.h"
#include "component.h"
#include "renderer.h"

class SpriteComponent : public Component
{
public :
	SpriteComponent(Actor* pOwner, Texture& pTexture, Renderer::Flip pFlip, int pDrawOrder = 100);
	virtual ~SpriteComponent();
	SpriteComponent() = delete;
	SpriteComponent(const SpriteComponent&) = delete;
	SpriteComponent& operator= (const SpriteComponent&) = delete;

	virtual void SetTexture(const Texture& pTexture);
	virtual void Draw(Renderer& pRenderer);
	void SetFlipX(bool isFlipped);
	void SetFlipY(bool isFlipped);

	int GetDrawOrder() const;
	int GetTexWidth() const;
	int GetTexHeight() const;
	Texture GetTexture() const;
	Renderer::Flip GetFlip() const;

protected :
	Texture mTexture;
	Renderer::Flip mFlip;
	int mDrawOrder;
	int mTexWidth;
	int mTexHeight;
};
