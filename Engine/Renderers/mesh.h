#pragma once
#include <vector>

class Texture;
class VertexArray;
class ShaderProgram;
class Shader;

class Mesh
{
public:
	Mesh();
	~Mesh();

	void Unload();
	void AddTexture(Texture* pTexture);

    //void CreateShaderProgram(std::string pVertexShaderFile, std::string pFragmentShaderFile);

	ShaderProgram* GetShaderProgram();
    VertexArray* GetVertexArray();
    Texture* GetTexture(size_t pTextureIndex);

private:
	std::vector<Texture*> mTextures;
	VertexArray* mVertexArray;
	Shader* mVertexShader;
	Shader* mFragmentShader;
	ShaderProgram* mShaderProgram;
};

constexpr float cubeVertices[] = {
    // Positions          // Coordonnées de texture
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,   // Face avant
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,   // Face arrière
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
   4,  5,  6,  5,  7,  6,  // Face arrière
   8,  9,  10, 9,  11, 10, // Face gauche
   12, 13, 14, 13, 15, 14, // Face droite
   16, 17, 18, 17, 19, 18, // Face bas
   20, 21, 22, 21, 23, 22  // Face haut
};