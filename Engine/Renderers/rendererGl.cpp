#include "rendererGl.h"
#include "spriteComponent.h"
#include "actor.h"
#include "glew.h"
#include "SDL.h"

RendererGl::RendererGl(std::string pVertexShaderFileName, std::string pFragmentShaderFileName):mWindow(nullptr), mVao(nullptr), mContext(nullptr), mVertexShaderFileName(pVertexShaderFileName), mFragmentShaderFileName(pFragmentShaderFileName)
{
}

RendererGl::~RendererGl()
{
    delete mVao;
    delete mVertexShader;
    delete mFragmentShader;
    delete mShaderProgram;
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
    mVao = new VertexArray(vertices, 4, indices, 6);

    mShaderProgram = new ShaderProgram();

    std::vector<Shader*> shaders;
    mVertexShader = new Shader(0, "VertexShader", ShaderType::VERTEX);
    mVertexShader->Load(mVertexShaderFileName, ShaderType::VERTEX);
    shaders.push_back(mVertexShader);
    mFragmentShader = new Shader(1, "FragmentShader", ShaderType::FRAGMENT);
    mFragmentShader->Load(mFragmentShaderFileName, ShaderType::FRAGMENT);
    shaders.push_back(mFragmentShader);
    mShaderProgram->Compose(shaders);

    Texture pokeballTexture = Texture();
    pokeballTexture.Load(*static_cast<IRenderer*>(this), "Imports/pokeball.png");

    mViewProj = Matrix4Row::CreateSimpleViewProj(800, 800);     // TODO : link to the window size

    return true;
}

void RendererGl::BeginDraw()
{
    glClearColor(0.45f, 0.45f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    if (mShaderProgram != nullptr) mShaderProgram->Use();

    //mShaderProgram->setMatrix4Row("uViexProj", mViewProj);
    mVao->SetActive();
}

void RendererGl::Draw()
{
    //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void RendererGl::DrawSprites()
{
    for (SpriteComponent* sprite : mSprites)
    {
        DrawSprite(sprite->GetOwner(), sprite->GetTexture(), sprite->GetOwner()->GetRect(), { sprite->GetOwner()->GetTransform()->GetPosition().x, sprite->GetOwner()->GetTransform()->GetPosition().y }, sprite->GetFlip());
    }
}

void RendererGl::EndDraw()
{
    SDL_GL_SwapWindow(mWindow->GetSdlWindow());
}

void RendererGl::DrawSprite(Actor* pOwner, Texture pTexture, Rectangle rectangle, Vector2 origin, Flip flip) const
{
    mShaderProgram->Use();
    pOwner->GetTransform()->ComputeWorldTransform();

    Matrix4Row scaleMatrix = Matrix4Row::CreateScale(pTexture.GetWidth(), pTexture.GetHeight(), 0.0f);
    Matrix4Row world = scaleMatrix * pOwner->GetTransform()->GetWorldTransform();
    
    mShaderProgram->setMatrix4Row("uWorldTransform", world);
    pTexture.SetActive();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
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

void RendererGl::Close()
{
    SDL_GL_DeleteContext(mContext);
    delete mVao;
}

IRenderer::RendererType RendererGl::GetType()
{
	return RendererType::OPENGL;
}
