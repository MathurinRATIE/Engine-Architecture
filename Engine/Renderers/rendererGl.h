#pragma once
#include "IRenderer.h"
#include "vertexArray.h"
#include "shaderProgram.h"

class SpriteComponent;

class RendererGl : public IRenderer
{
private:
	Window* mWindow;
	Shader* mVertexShader;
	Shader* mFragmentShader;
	ShaderProgram* mShaderProgram;
	VertexArray* mVao;
	SDL_GLContext mContext;

public:
	RendererGl();
	virtual ~RendererGl();
	RendererGl(const RendererGl&) = delete;
	RendererGl& operator=(const RendererGl&) = delete;

	bool Initialize(Window* rWindow) override;
	void BeginDraw() override;
	void Draw() override;
	void DrawSprites() override;
	void EndDraw() override;


	void DrawSprite(Actor* pOwner, Texture pTexture, Rectangle rectangle, Vector2 origin, Flip flip = Flip::None) const override;
	void AddSprite(SpriteComponent* pSprite) override;
	void RemoveSprite(SpriteComponent* pSprite) override;
	void Close() override;
	RendererType GetType() override;
};
