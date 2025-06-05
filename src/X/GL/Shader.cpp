#include "X/GL/Shader.h"
#include "glad/glad.h"

#include <iostream>
#include <fstream>
#include <sstream>

namespace X::GL
{

Shader::Shader(
	const char* vsh,
	const char* fsh
) : vshSource(vsh),
	fshSource(fsh),
	vshProgram(0),
	fshProgram(0) {

	this->build();
}

Shader::Shader(
	const std::string& vsh,
	const std::string& fsh
) : vshSource(vsh),
	fshSource(fsh),
	vshProgram(0),
	fshProgram(0) {

	this->build();
}

Shader::Shader(const Shader& rhs) {}
Shader::Shader(const Shader&& rhs) {}

Shader&
Shader::operator=(Shader& rhs)  { return *this; }

Shader&
Shader::operator=(Shader&& rhs) { return *this; }

Shader::~Shader() {}


void Shader::build()
{
	// VERTEX SHADER

	this->compile("VERTEX", X::ShaderType::VERTEX);

	// FRAGMENT SHADER

	//this->compile("FRAGMENT", X::ShaderType::FRAGMENT);

	this->program = glCreateProgram();

	glAttachShader(this->program, this->vshProgram);
	glAttachShader(this->program, this->fshProgram);
	glLinkProgram(this->program);

}

void Shader::compile(const std::string& name, ShaderType type)
{
	// VERTEX SHADER

	// Read File
	std::ifstream shaderSrcInput;
	std::stringstream shaderStream;

	shaderSrcInput.open(this->vshSource);
	shaderStream << shaderSrcInput.rdbuf();
	shaderSrcInput.close();

	GLuint shaderProg = glCreateShader(type);

	std::string vString = shaderStream.str();
	const char* vShader = vString.c_str();

	// TODO Add errors
	glShaderSource(shaderProg, 1, &vShader, NULL);
	glCompileShader(shaderProg);

	this->checkCompileErrors(shaderProg, "VERTEX");
}


void Shader::checkCompileErrors(unsigned int shader, std::string type)
{
	int success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
}


void Shader::use() const
{
	glUseProgram(this->program);
}
}
