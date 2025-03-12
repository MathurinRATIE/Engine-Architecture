#include "platformActor.h"
#include "collider3DComponent.h"
#include "spriteComponent.h"
#include "texture.h"

PlatformActor::PlatformActor(Scene* pScene, Window* pWindow, IRenderer* pRenderer, std::vector<Component*> pComponents, ActorState pState, Transform3D pTransform) : Actor(pScene, pWindow, pRenderer, pComponents, pState, pTransform)
{
    Rectangle* rect = new Rectangle(Vector2(mTransform.GetPosition().x, mTransform.GetPosition().y), Vector2(mTransform.GetScale().x, mTransform.GetScale().y));
    Collider3D* collider = new Collider3D(this);
    AddComponent(collider);

    Texture* platformTexture = new Texture();
    RendererSdl* renderer = static_cast<RendererSdl*>(pRenderer);
    if (renderer)
    {
        platformTexture->Load(*renderer, "Imports/Platform.png");
    }
    SpriteComponent* sprite = new SpriteComponent(this, *platformTexture, IRenderer::Flip::None);
    SetSprite(sprite);
}
