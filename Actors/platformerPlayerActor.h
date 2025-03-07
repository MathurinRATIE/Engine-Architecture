#pragma once
#include <filesystem>
#include "actor.h"
#include "rendererSdl.h"
#include "playerControllerComponent.h"
#include "animatedSpriteComponent.h"
#include "collider2DComponent.h"


class PlatformerPlayerActor : public Actor
{
public :
	PlatformerPlayerActor(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, Transform2D pTransform = Transform2D(), float pSpeed = 1.0f, ActorState pState = ActorState::Active);
	
	void UpdateActor() override;

	std::vector<Texture*> LoadTexturesFromFolder(std::string pFolder);

	Vector2 GetBaseSpeed();

protected :
	Vector2 mSpeed;
	PlayerControllerComponent* mPlayerControllerComponent;
	AnimatedSpriteComponent* mAnimatedSprite;
	std::map <std::string, std::vector<Texture*>> mAnimations;
};
