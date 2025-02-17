#pragma once
#include <vector>
#include "spriteComponent.h"
#include "engineTime.h"


class AnimatedSpriteComponent: public SpriteComponent
{
public :
	AnimatedSpriteComponent(Actor* pOwner, const std::vector<Texture*>& pTextures, int pDrawOrder);
	virtual ~AnimatedSpriteComponent();
	AnimatedSpriteComponent() = delete;
	AnimatedSpriteComponent(const AnimatedSpriteComponent&) = delete;
	AnimatedSpriteComponent& operator=(const AnimatedSpriteComponent&) = delete;

	float GetAnimationFps() const;
	void SetAnimationTextures(const std::vector<Texture*>& pTextures);
	void SetAnimationFps(float pFps);

	void Update() override;

private :
	std::vector<Texture*> mAnimationTextures;
	float mCurrentFrame;
	float mAnimFps;
};
