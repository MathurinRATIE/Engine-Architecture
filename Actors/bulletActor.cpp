#include "bulletActor.h"

BulletActor::BulletActor(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, Actor* pOwner, Direction pDirectionY, Transform3D pTransform, ActorState pState) : Actor(pScene, pWindow, pRenderer, pComponents, pState, pTransform)
{
    mSceneOwner = pScene;
    mWindow = pWindow;
    mComponents = pComponents;
    mOwnerActor = pOwner;
    mTransform = pTransform;
    mState = pState;
    mRect = new Rectangle(Vector2(mTransform.GetPosition().x, mTransform.GetPosition().y), Vector2(mTransform.GetScale().x, mTransform.GetScale().y));
    mDirectionY = pDirectionY;

    Collider3D* collider = new Collider3D(this);
    AddComponent(collider);

    Texture* bulletTexture = new Texture();
    RendererSdl* renderer = static_cast<RendererSdl*>(mRenderer);
    if (renderer)
    {
        bulletTexture->Load(*renderer, "Imports/Bullet.png");
    }
    SpriteComponent* sprite = new SpriteComponent(this, *bulletTexture, IRenderer::Flip::None);
    SetSprite(sprite);

    //mMovements = new MovementComponent(&mRect->mPosition, this, pWindow, mCollidingActor, 1.0f, 5.0f);
    //AddComponent(mMovements);
    //mMovements->SetDirectionY(pDirectionY);
}

void BulletActor::UpdateActor()
{
    /*if (mDirectionY == Direction::Up && mCollidingActor != nullptr && mCollidingActor != mOwnerActor)
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
    }*/
}

Rectangle BulletActor::GetRect()
{
    return *mRect;
}
