#pragma once
#include <string>
#include <fstream>

enum ShaderType {
	VERTEX,
	FRAGMENT,
	TESSELATION_CONTROL,
	TESSELATION_EVALUATION,
	GEOMETRY,
};
class Shader
{
protected:
	std::string mCode;
	unsigned int mId;
	ShaderType mType;
public:
	//Feel free to change the shader path  if needed
	static const std::string SHADER_PATH;

	Shader();
	Shader(int pId, std::string pFile, ShaderType pShaderType);
	~Shader();

	int GetID() const { return mId; }
	ShaderType GetType() const { return mType; }
	void Load(std::string pFileName, ShaderType pShaderType);

	std::string& GetCode();
};