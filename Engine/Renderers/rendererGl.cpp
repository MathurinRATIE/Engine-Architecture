#include "rendererGl.h"
#include "spriteComponent.h"
#include "meshComponent.h"
#include "actor.h"
#include "glew.h"
#include "SDL.h"
#include "inputManager.h"
#include "meshActor.h"
#include "engineTime.h"

RendererGl::RendererGl(): mWindow(nullptr), mSpriteVao(nullptr), mContext(nullptr)
{
    mWindow = nullptr;
    mSpriteVao = nullptr;
    mContext = nullptr;
    mSpriteShaderProgram = nullptr;
    mSpriteViewProj = Matrix4Row::CreateSimpleViewProj(Window::Dimensions.x, Window::Dimensions.y);
    mView = Matrix4Row::CreateLookAt(Vector3(0, 0, 0), Vector3::unitX, Vector3::unitZ);
    mProj = Matrix4Row::CreatePerspectiveFOV(70.0f, Window::Dimensions.x, Window::Dimensions.y, 0.01f, 10000.0f);

}

RendererGl::~RendererGl()
{
    delete mSpriteVao;
    delete mSpriteShaderProgram;
}

bool RendererGl::Initialize(Window* rWindow)
{
    mWindow = rWindow;

    //Setting OpenGL attributes
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    //8 bits color buffer
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

    mContext = SDL_GL_CreateContext(mWindow->GetSdlWindow());
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        Log::Error(LogType::Video, "Failed to initialize GLEW");
        return false;
    }
    glGetError();

    if (IMG_Init(IMG_INIT_PNG) == 0)
    {
        Log::Error(LogType::Video, "Failed to initialize SDL_Image");
    }
    mSpriteVao = new VertexArray(vertices, 4);

    Assets::LoadShaderProgram("Texture", "texture.vs", "texture.fs");
    mSpriteShaderProgram = Assets::GetShaderProgramFromName("Texture");

    return true;
}

void RendererGl::BeginDraw()
{
    glClearColor(0.45f, 0.45f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RendererGl::Draw()
{
    glPolygonMode(GL_FRONT_AND_BACK, mWireframe ? GL_LINE : GL_FILL);

    DrawMeshes();
    DrawSprites();
}

void RendererGl::DrawSprites()
{
    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    glBlendEquationSeparate(GL_FUNC_ADD, GL_FUNC_ADD);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    if (mSpriteShaderProgram != nullptr)
    {
        mSpriteShaderProgram->Use();
    }
    mSpriteShaderProgram->setMatrix4Row("uViexProj", mSpriteViewProj);
    mSpriteVao->SetActive();

    for (SpriteComponent* sprite : mSprites)
    {
        sprite->Draw(*this);
    }
}

void RendererGl::DrawMeshes()
{
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);

    for (MeshComponent* mesh : mMeshComponents)
    {
        mesh->Draw(mView * mProj);
    }
}

void RendererGl::EndDraw()
{
    SDL_GL_SwapWindow(mWindow->GetSdlWindow());
}

void RendererGl::DrawSprite(Actor* pOwner, Texture pTexture, Rectangle rectangle, Vector2 origin, Flip flip) const
{
    mSpriteShaderProgram->Use();
    pOwner->GetTransform()->ComputeWorldTransform();

    Matrix4Row scaleMatrix = Matrix4Row::CreateScale(float(pTexture.GetWidth()), float(pTexture.GetHeight()), 0.0f);
    Matrix4Row world = scaleMatrix * pOwner->GetTransform()->GetWorldTransform();
    
    mSpriteShaderProgram->setMatrix4Row("uWorldTransform", world);
    pTexture.SetActive();
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void RendererGl::DrawCollision(Actor* pOwner)
{
    MeshActor* meshActor = static_cast<MeshActor*>(pOwner);        // TODO : not working

    if (meshActor->mMeshComponent != nullptr && Time::deltaTime > 1)
    {
        if (meshActor->mMeshComponent->GetMesh())
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

            ShaderProgram* shaderProgram = meshActor->mMeshComponent->GetMesh()->GetShaderProgram();
            shaderProgram->Use();

            Collider3D* collider = pOwner->GetComponentOfType<Collider3D>();
            Cube hitbox = collider->GetHitBox();

            Matrix4Row scaleMatrix = Matrix4Row::CreateScale(hitbox.mDimensions.x, hitbox.mDimensions.y, hitbox.mDimensions.z);
            Matrix4Row world = scaleMatrix * pOwner->GetTransform()->GetWorldTransform();
            shaderProgram->setMatrix4Row("uWorldTransform", world);
            shaderProgram->setMatrix4Row("uViewProj", mView * mProj);
            shaderProgram->setVector2f("uTiling", Vector2(1, 1));

            glDrawArrays(GL_TRIANGLES, 0, 32);
        }
    }
}

void RendererGl::AddSprite(SpriteComponent* pSprite)
{
    int spriteDrawOrder = pSprite->GetDrawOrder();
    std::vector<SpriteComponent*>::iterator sc;
    for (sc = mSprites.begin(); sc != mSprites.end(); ++sc)
    {
        if (spriteDrawOrder < (*sc)->GetDrawOrder()) break;
    }
    mSprites.insert(sc, pSprite);
}

void RendererGl::RemoveSprite(SpriteComponent* pSprite)
{
    std::vector<SpriteComponent*>::iterator sc;
    sc = std::find(mSprites.begin(), mSprites.end(), pSprite);
    mSprites.erase(sc);
}

void RendererGl::AddMesh(MeshComponent* pMeshComponent)
{
    mMeshComponents.push_back(pMeshComponent);
}

void RendererGl::RemoveMesh(MeshComponent* pMeshComponent)
{
    auto iterator = std::find(mMeshComponents.begin(), mMeshComponents.end(), pMeshComponent);

    if (iterator != mMeshComponents.end())
    {
        mMeshComponents.erase(iterator);
    }
}

void RendererGl::Close()
{
    SDL_GL_DeleteContext(mContext);
    delete mSpriteVao;
}

void RendererGl::SetViewMatrix(Matrix4Row pView)
{
    mView = pView;
}

IRenderer::RendererType RendererGl::GetType()
{
	return RendererType::OPENGL;
}
