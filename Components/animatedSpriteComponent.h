#pragma once
#include <vector>
#include "spriteComponent.h"
#include "engineTime.h"


class AnimatedSpriteComponent: public SpriteComponent
{
public :
	AnimatedSpriteComponent(Actor* pOwner, std::map <std::string, std::vector<Texture*>> pAnimations, std::string pCurrentAnimationName, int pDrawOrder, IRenderer::Flip pFlip);
	virtual ~AnimatedSpriteComponent();
	AnimatedSpriteComponent() = delete;
	AnimatedSpriteComponent(const AnimatedSpriteComponent&) = delete;
	AnimatedSpriteComponent& operator=(const AnimatedSpriteComponent&) = delete;

	float GetAnimationFps() const;
	void SetAnimationTextures(const std::vector<Texture*>& pTextures);
	void SetAnimationTextures(std::string animationName);
	void SetAnimationFps(float pFps);

	void Update() override;

private :
	std::map <std::string, std::vector<Texture*>> mAnimations;
	std::vector<Texture*> mAnimationTextures;
	float mCurrentFrame;
	float mAnimFps;
};
