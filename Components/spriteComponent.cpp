#include "spriteComponent.h"

SpriteComponent::SpriteComponent(Actor* pOwner, Texture& pTexture, Renderer::Flip pFlip, int pDrawOrder) :
	Component(pOwner),
	mTexture(pTexture),
	mFlip(pFlip),
	mDrawOrder(pDrawOrder),
	mTexWidth(pTexture.GetWidth()),
	mTexHeight(pTexture.GetHeight())
{
	mOwner->GetScene()->GetRenderer()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
	mOwner->GetScene()->GetRenderer()->RemoveSprite(this);
}

void SpriteComponent::SetTexture(const Texture& pTexture)
{
	mTexture = pTexture;
	mTexture.UpdateInfo(mTexWidth, mTexHeight);
}

void SpriteComponent::Draw(Renderer& pRenderer)
{
	Vector2 origin{ mTexWidth / 2.0f, mTexHeight / 2.0f };
	pRenderer.DrawSprite(mOwner, mTexture, Rectangle(), origin, mFlip);
}

void SpriteComponent::SetFlip(Renderer::Flip pFlip)
{
	mFlip = pFlip;
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

Texture SpriteComponent::GetTexture() const
{
	return mTexture;
}

Renderer::Flip SpriteComponent::GetFlip() const
{
	return mFlip;
}
