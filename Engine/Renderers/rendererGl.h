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
	//POSITION                      NORMALS                     TEXCOORDS
	-0.5f, 0.5f, 0.0f,              0.0f, 0.0f, 0.0f,           0.0f, 0.0f,     //top left
	0.5f, 0.5f, 0.0f,               0.0f, 0.0f, 0.0f,           1.0f, 0.0f,     //top right
	-0.5f, -0.5f, 0.0f,             0.0f, 0.0f, 0.0f,           0.0f, 1.0f,      //bottom left
	0.5f, -0.5f, 0.0f,              0.0f, 0.0f, 0.0f,           1.0f, 1.0f,     //bottom right
};
