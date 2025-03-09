#pragma once
#include "texture.h"

class Mesh
{
	Mesh();
	~Mesh();

	void Unload();
	void AddTexture(Texture* pTexture);

	ShaderProgram* GetShaderProgram();

private:
	std::vector<Texture*> mTextures;
	VertexArray* mVertexArray;
	Shader* mVertexShader;
	Shader* mFragmentShader;
	ShaderProgram* mShaderProgram;
};

