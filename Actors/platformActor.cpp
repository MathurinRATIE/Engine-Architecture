#include "platformActor.h"
#include "collider2DComponent.h"
#include "spriteComponent.h"
#include "texture.h"

PlatformActor::PlatformActor(Scene* pScene, Window* pWindow, RendererSdl* pRenderer, std::vector<Component*> pComponents, ActorState pState, Transform2D pTransform) : Actor(pScene, pWindow, pRenderer, pComponents, pState, pTransform)
{
    Rectangle* rect = new Rectangle(mTransform.GetPosition(), mTransform.GetScale());
    Collider2D* collider = new Collider2D(this);
    AddComponent(collider);

    Texture* platformTexture = new Texture();
    platformTexture->Load(*pRenderer, "Imports/Platform.png");
    SpriteComponent* sprite = new SpriteComponent(this, *platformTexture, RendererSdl::Flip::None);
    SetSprite(sprite);
}
