#include "platformerPlayerActor.h"

PlatformerPlayerActor::PlatformerPlayerActor(Scene* pScene, Window* pWindow, Renderer* pRenderer, std::vector<Component*> pComponents, Transform2D pTransform, float pSpeed, ActorState pState) : Actor(pScene, pWindow, pComponents)
{
	mSpeed = Vector2(pSpeed, 0.0f);
	mSceneOwner = pScene;
	mWindow = pWindow;
	mTransform = pTransform;
	mRenderer = pRenderer;
	mRect = new Rectangle(mTransform.GetPosition(), mTransform.GetScale());
	mCollidingActor = nullptr;

	Collider2D* collider = new Collider2D(mRect, this, mCollidingActor);
	AddComponent(collider);

	mAnimations["walkSide"] = LoadTexturesFromFolder("JackSparrow\\WalkSide");
	mAnimations["walkBack"] = LoadTexturesFromFolder("JackSparrow\\WalkBack");
	mAnimations["walkFront"] = LoadTexturesFromFolder("JackSparrow\\WalkFront");
	mAnimations["idle"] = LoadTexturesFromFolder("JackSparrow\\Idle");
	//mAnimations["run"] = LoadTexturesFromFolder("JackSparrow\\Run");
	//mAnimations["jump"] = LoadTexturesFromFolder("JackSparrow\\Jump");

	AnimatedSpriteComponent* animatedSprite = new AnimatedSpriteComponent(this, mAnimations, "idle", 1, Renderer::Flip::Horizontal);
	mAnimatedSprite = animatedSprite;
	AddComponent(animatedSprite);
	SetSprite(animatedSprite);

	mPlayerControllerComponent = new PlayerControllerComponent(this);
	AddComponent(mPlayerControllerComponent);
}

void PlatformerPlayerActor::UpdateActor()
{
}

std::vector<Texture*> PlatformerPlayerActor::LoadTexturesFromFolder(std::string pFolder)
{
	std::vector<Texture*> textures = std::vector<Texture*>();
	std::string separator = "..\\Imports\\";
	std::string folderPath = SDL_GetBasePath() + separator + pFolder;

	for (auto& entry : std::filesystem::recursive_directory_iterator(folderPath))
	{
		auto extension = entry.path().extension().string();

		if (extension == ".png")
		{
			Texture* texture = new Texture();
			texture->Load(*mRenderer, entry.path().string());

			textures.push_back(texture);
		}
	}
	return textures;
}

Rectangle PlatformerPlayerActor::GetRect()
{
	return *mRect;
}

Vector2 PlatformerPlayerActor::GetBaseSpeed()
{
	return mSpeed;
}
