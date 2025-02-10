#include "bulletActor.h"

Bullet::Bullet(Scene* pScene, Window* pWindow, std::vector<Component*> pComponents, Actor* pOwner, Direction pDirectionY, Transform2D pTransform, ActorState pState) : Actor(pScene, pWindow, pComponents, pState, pTransform)
{
    mSceneOwner = pScene;
    mWindow = pWindow;
    mComponents = pComponents;
    mOwnerActor = pOwner;
    mTransform = pTransform;
    mState = pState;
    mRect = new Rectangle(mTransform.GetPosition(), mTransform.GetScale());
    mDirectionY = pDirectionY;
    Actor* collidingActor = nullptr;
    mCollidingActor = &collidingActor;

    Collider2D* collider = new Collider2D(mRect, this, mCollidingActor, 99);
    Component* colliderComponent = dynamic_cast<Component*>(collider);
    AddComponent(colliderComponent);

    mMovements = new Movements(&mRect->mPosition, this, pWindow, mCollidingActor);
    Component* movementsComponent = dynamic_cast<Component*>(mMovements);
    AddComponent(movementsComponent);

    mMovements->SetDirectionY(pDirectionY);
}

void Bullet::UpdateActor(unsigned int pDeltaTime)
{
    if (mDirectionY == Direction::Up && *mCollidingActor != nullptr && *mCollidingActor != mOwnerActor)
    {
        mSceneOwner->AddPendingRemoveActor(*mCollidingActor);
    }
    else if (*mCollidingActor != nullptr && *mCollidingActor != mOwnerActor)
    {
        /*Player* player = dynamic_cast<Player*>(*mCollidingActor);

        if (player)
        {
            mSceneOwner->AddPendingRemoveActor(*mCollidingActor);
        }*/
    }

    *mCollidingActor = nullptr;

    if (mRect->mPosition.y <= -mRect->mDimensions.y || mRect->mPosition.x >= mWindow->GetDimensions().x)
    {
        mSceneOwner->AddPendingRemoveActor(this);
    }
}

Rectangle Bullet::GetRect()
{
    return *mRect;
}
