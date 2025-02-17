#include "animatedSpriteComponent.h"

AnimatedSpriteComponent::AnimatedSpriteComponent(Actor* pOwner, const std::vector<Texture*>& pTextures, int pDrawOrder) : SpriteComponent(pOwner, *pTextures[0], pDrawOrder)
{
	mCurrentFrame = 0.0f;
	mAnimFps = 24.0f;
	mAnimationTextures = pTextures;

	SetAnimationTextures(mAnimationTextures);

	mOwner->GetScene()->GetRenderer()->AddSprite(this);
}

AnimatedSpriteComponent::~AnimatedSpriteComponent()
{
	for (Texture* texture : mAnimationTextures)
	{
		texture->Unload();
	}

	mOwner->GetScene()->GetRenderer()->RemoveSprite(this);
}

float AnimatedSpriteComponent::GetAnimationFps() const
{
	return mAnimFps;
}

void AnimatedSpriteComponent::SetAnimationTextures(const std::vector<Texture*>& pTextures)
{
	mAnimationTextures = pTextures;
	if (mAnimationTextures.size() > 0)
	{
		SetTexture(*mAnimationTextures[0]);
	}
}

void AnimatedSpriteComponent::SetAnimationFps(float pFps)
{
	mAnimFps = pFps;
}

void AnimatedSpriteComponent::Update()
{
	SpriteComponent::Update();

	if (mAnimationTextures.size() == 0) return;
	mCurrentFrame += mAnimFps * Time::deltaTime;
	while (mCurrentFrame >= mAnimationTextures.size())
	{
		mCurrentFrame -= mAnimationTextures.size();
	}
	SetTexture(*mAnimationTextures[static_cast<int>(mCurrentFrame)]);
}
