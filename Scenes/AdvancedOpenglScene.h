#pragma once
#include "scene.h"
#include "shader.h"
#include "shaderProgram.h"

class AdvancedOpenglScene: public Scene
{
private:
    Shader mVertexShader, mFragmentShader, mTessControlShader, mTessEvalShader;
    ShaderProgram mSimpleProgram;
public:
    AdvancedOpenglScene();
    ~AdvancedOpenglScene() = default;
    void Start(IRenderer* pRenderer, Window* pWindow) override;
    void Render() override;
    void Update() override;
    void Close() override;
};
