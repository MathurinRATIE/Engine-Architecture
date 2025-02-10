#pragma once
#include "texture.h"
#include "actor.h"
#include "component.h"

class SpriteComponent
{
public :
	SpriteComponent(Actor* pOwner, Texture& pTexture, int pDrawOrder = 100);
	virtual ~SpriteComponent();
	SpriteComponent() = delete;
	SpriteComponent(const SpriteComponent&) = delete;
	SpriteComponent& operator= (const SpriteComponent&) = delete;

	virtual void SetTexture(const Texture& pTexture);
	virtual void Draw(Renderer& pRenderer);

	int GetDrawOrder() const;
	int GetTexWidth() const;
	int GetTexHeight() const;

protected :
	Texture mTexture;
	int mDrawOrder;
	int mTexWidth;
	int mTexHeight;
};

