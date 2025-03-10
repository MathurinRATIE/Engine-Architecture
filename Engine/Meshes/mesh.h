#pragma once
#include <vector>
#include "texture.h"

class Mesh
{
public:
	Mesh();
	~Mesh();

	void Unload();
	void AddTexture(Texture* pTexture);

	ShaderProgram* GetShaderProgram();
    VertexArray* GetVertexArray();
    Texture* GetTexture(int pTextureIndex);

private:
	std::vector<Texture*> mTextures;
	VertexArray* mVertexArray;
	Shader* mVertexShader;
	Shader* mFragmentShader;
	ShaderProgram* mShaderProgram;
};

constexpr float cubeVertices[] = {
    // Positions          // Coordonn�es de texture
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,   // Face avant
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,   // Face arri�re
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,   // Face gauche
    -0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 1.0f,

     0.5f, -0.5f, -0.5f,  0.0f, 0.0f,   // Face droite
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,   // Face bas
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,   // Face haut
     0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f
};

constexpr unsigned int cubeIndices[] = {
   0,  2,  1,  1,  2,  3,  // Face avant
   4,  5,  6,  5,  7,  6,  // Face arri�re
   8,  9,  10, 9,  11, 10, // Face gauche
   12, 13, 14, 13, 15, 14, // Face droite
   16, 17, 18, 17, 19, 18, // Face bas
   20, 21, 22, 21, 23, 22  // Face haut
};