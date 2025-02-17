#include "platformerPlayerActor.h"

PlatformerPlayerActor::PlatformerPlayerActor(Scene* pScene, Window* pWindow, Renderer* pRenderer, std::vector<Component*> pComponents, Transform2D pTransform, float mSpeedX, ActorState pState) : Actor(pScene, pWindow, pComponents)
{
	mSceneOwner = pScene;
	mWindow = pWindow;
	mTransform = pTransform;
	mRenderer = pRenderer;
	mRect = new Rectangle(mTransform.GetPosition(), mTransform.GetScale());
	mCollidingActor = nullptr;

	Collider2D* collider = new Collider2D(mRect, this, mCollidingActor);
	Component* colliderComponent = dynamic_cast<Component*>(collider);
	AddComponent(colliderComponent);

	mAnimations["walk"] = LoadTexturesFromFolder("JackSparrow\\Walk");
	mAnimations["idle"] = LoadTexturesFromFolder("JackSparrow\\Idle");
	mAnimations["run"] = LoadTexturesFromFolder("JackSparrow\\Run");
	mAnimations["jump"] = LoadTexturesFromFolder("JackSparrow\\Jump");

	AnimatedSpriteComponent* animatedSprite = new AnimatedSpriteComponent(this, mAnimations["idle"], 1);
	mAnimatedSprite = animatedSprite;
	AddComponent(animatedSprite);
	SetSprite(animatedSprite);

	mMovements = new Movements(&mRect->mPosition, this, pWindow, mCollidingActor, mSpeedX, 0.0f);
	Component* movementsComponent = dynamic_cast<Component*>(mMovements);
	AddComponent(movementsComponent);
}

void PlatformerPlayerActor::UpdateActor()
{
}

void PlatformerPlayerActor::SetDirection(Direction pDirection)
{
	mMovements->SetDirectionX(pDirection);
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
