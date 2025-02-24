#include "animatedSpriteComponent.h"

AnimatedSpriteComponent::AnimatedSpriteComponent(Actor* pOwner, std::map <std::string, std::vector<Texture*>> pAnimations, std::string pCurrentAnimationName, int pDrawOrder, RendererSdl::Flip pFlip) : SpriteComponent(pOwner, *pAnimations[pCurrentAnimationName][0], pFlip, pDrawOrder)
{
	mAnimations = pAnimations;
	mCurrentFrame = 0.0f;
	mAnimFps = 24.0f;

	SetAnimationTextures(pCurrentAnimationName);

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

void AnimatedSpriteComponent::SetAnimationTextures(std::string animationName)
{
	mAnimationTextures = mAnimations[animationName];
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
	mCurrentFrame += mAnimationTextures.size() * Time::deltaTime;
	while (mCurrentFrame >= mAnimationTextures.size())
	{
		mCurrentFrame -= mAnimationTextures.size();
	}
	SetTexture(*mAnimationTextures[static_cast<int>(mCurrentFrame)]);
}
