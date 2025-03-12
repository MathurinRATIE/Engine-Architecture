#pragma once
#include "vertexArray.h"
#include "shaderProgram.h"
#include "IRenderer.h"

class SpriteComponent;
class MeshComponent;

class RendererGl : public IRenderer
{
private:
	Window* mWindow;
	Shader* mVertexShader;
	Shader* mFragmentShader;
	ShaderProgram* mSpriteShaderProgram;
	VertexArray* mSpriteVao;
	SDL_GLContext mContext;
	Matrix4Row mSpriteViewProj;
	Matrix4Row mView;
	Matrix4Row mProj;
	std::vector<MeshComponent*> mMeshComponents;

public:
	RendererGl();
	virtual ~RendererGl();
	RendererGl(const RendererGl&) = delete;
	RendererGl& operator=(const RendererGl&) = delete;

	bool Initialize(Window* rWindow) override;
	void BeginDraw() override;
	void Draw() override;
	void DrawSprites() override;
	void DrawMeshes();
	void EndDraw() override;

	void DrawSprite(Actor* pOwner, Texture pTexture, Rectangle rectangle, Vector2 origin, Flip flip = Flip::None) const override;
	void AddSprite(SpriteComponent* pSprite) override;
	void RemoveSprite(SpriteComponent* pSprite) override;
	void AddMesh(MeshComponent* pMeshComponent);
	void RemoveMesh(MeshComponent* pMeshComponent);
	void Close() override;

	void SetViewMatrix(Matrix4Row pView);
	RendererType GetType() override;
};

constexpr float vertices[] = {
-0.5f,  0.5f, 0.0f,		0.0f, 0.0f,		// TOP		LEFT
 0.5f,  0.5f, 0.0f,		1.0f, 0.0f,		// TOP		RIGHT
 0.5f, -0.5f, 0.0f,		1.0f, 1.0f,		// BOTTOM	RIGHT
-0.5f, -0.5f, 0.0f,		0.0f, 1.0f };	// BOTTOM	LEFT

constexpr unsigned int indices[] = {
0, 1, 2,
2, 3, 0
};
