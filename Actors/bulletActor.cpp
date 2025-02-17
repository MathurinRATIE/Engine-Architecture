#include "bulletActor.h"

BulletActor::BulletActor(Scene* pScene, Window* pWindow, Renderer* pRenderer, std::vector<Component*> pComponents, Actor* pOwner, Direction pDirectionY, Transform2D pTransform, ActorState pState) : Actor(pScene, pWindow, pComponents, pState, pTransform)
{
    mSceneOwner = pScene;
    mWindow = pWindow;
    mComponents = pComponents;
    mOwnerActor = pOwner;
    mTransform = pTransform;
    mState = pState;
    mRect = new Rectangle(mTransform.GetPosition(), mTransform.GetScale());
    mDirectionY = pDirectionY;
    mCollidingActor = nullptr;

    Collider2D* collider = new Collider2D(mRect, this, mCollidingActor, 99);
    Component* colliderComponent = dynamic_cast<Component*>(collider);
    AddComponent(colliderComponent);

    Texture* bulletTexture = new Texture();
    bulletTexture->Load(*pRenderer, "Imports/Bullet.png");
    SpriteComponent* sprite = new SpriteComponent(this, *bulletTexture);
    SetSprite(sprite);

    mMovements = new Movements(&mRect->mPosition, this, pWindow, mCollidingActor, 1.0f, 5.0f);
    Component* movementsComponent = dynamic_cast<Component*>(mMovements);
    AddComponent(movementsComponent);
    mMovements->SetDirectionY(pDirectionY);
}

void BulletActor::UpdateActor()
{
    if (mDirectionY == Direction::Up && mCollidingActor != nullptr && mCollidingActor != mOwnerActor)
    {
        mSceneOwner->AddPendingRemoveActor(mCollidingActor);
    }
    else if (mCollidingActor != nullptr && mCollidingActor != mOwnerActor)
    {
        PlayerActor* player = dynamic_cast<PlayerActor*>(mCollidingActor);

        if (player)
        {
            mSceneOwner->AddPendingRemoveActor(mCollidingActor);
        }
    }

    mCollidingActor = nullptr;

    if (mRect->mPosition.y <= 0 || mRect->mPosition.y >= mWindow->GetDimensions().x)
    {
        mSceneOwner->AddPendingRemoveActor(this);
    }
}

Rectangle BulletActor::GetRect()
{
    return *mRect;
}
