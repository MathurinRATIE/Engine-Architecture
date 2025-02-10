#include "spriteComponent.h"

SpriteComponent::SpriteComponent(Actor* pOwner, Texture& pTexture, int pDrawOrder) :
	Component(pOwner),
	mTexture(pTexture),
	mDrawOrder(pDrawOrder),
	mTexWidth(pTexture.GetWidth()),
	mTexHeight(pTexture.GetHeight())
{
		mOwner->GetScene().GetRenderer().AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::SetTexture(const Texture& pTexture)
{
}

void SpriteComponent::Draw(Renderer& pRenderer)
{
}

int SpriteComponent::GetDrawOrder() const
{
	return mDrawOrder;
}

int SpriteComponent::GetTexWidth() const
{
	return mTexWidth;
}

int SpriteComponent::GetTexHeight() const
{
	return mTexHeight;
}
