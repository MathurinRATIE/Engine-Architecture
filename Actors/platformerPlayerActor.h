#pragma once
#include <filesystem>
#include "actor.h"
#include "renderer.h"
#include "movementsComponent.h"
#include "animatedSpriteComponent.h"
#include "collider2DComponent.h"


class PlatformerPlayerActor : public Actor
{
public :
	PlatformerPlayerActor(Scene* pScene, Window* pWindow, Renderer* pRenderer, std::vector<Component*> pComponents, Transform2D pTransform = Transform2D(), float mSpeedX = 1.0f, ActorState pState = ActorState::Active);
	
	void UpdateActor() override;

	void SetDirection(Direction pDirection);

	std::vector<Texture*> LoadTexturesFromFolder(std::string pFolder);

	Rectangle GetRect() override;

protected :
	Rectangle* mRect;
	Movements* mMovements;
	Renderer* mRenderer;
	Actor* mCollidingActor;
	AnimatedSpriteComponent* mAnimatedSprite;
	std::map <std::string, std::vector<Texture*>> mAnimations;
};
