#pragma once
#include <filesystem>
#include "actor.h"
#include "renderer.h"
#include "moveComponent.h"
#include "animatedSpriteComponent.h"
#include "collider2DComponent.h"


class PlatformerPlayerActor : public Actor
{
public :
	PlatformerPlayerActor(Scene* pScene, Window* pWindow, Renderer* pRenderer, std::vector<Component*> pComponents, Transform2D pTransform = Transform2D(), float pSpeed = 1.0f, ActorState pState = ActorState::Active);
	
	void UpdateActor() override;

	void SetSpeed(Vector2 pSpeed);

	std::vector<Texture*> LoadTexturesFromFolder(std::string pFolder);

	Rectangle GetRect() override;
	Vector2 GetBaseSpeed();

protected :
	Vector2 mSpeed;
	Rectangle* mRect;
	MoveComponent* mMoveComponent;
	Renderer* mRenderer;
	Actor* mCollidingActor;
	AnimatedSpriteComponent* mAnimatedSprite;
	std::map <std::string, std::vector<Texture*>> mAnimations;
};
