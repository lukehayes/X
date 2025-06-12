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

	this->compile(
		this->vshSource,
		"VERTEX",
		X::GL::ShaderType::VERTEX);

	// FRAGMENT SHADER

	this->compile(
		this->fshSource,
		"FRAGMENT",
		X::GL::ShaderType::FRAGMENT);

	this->program = glCreateProgram();

	glAttachShader(this->program, this->vshProgram);
	glAttachShader(this->program, this->fshProgram);
	glLinkProgram(this->program);

}

void Shader::SetUniformMat4(glm::mat4 matrix, const char* name)
{
	int location = glGetUniformLocation(this->program, name);
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::setUniformFloat(float val, const char* name)
{
	int location = glGetUniformLocation(this->program, name);
	glUniform1f(location, val);
}

void Shader::setUniformVec3(glm::vec3 val, const char* name)
{
	int location = glGetUniformLocation(this->program, name);
	glUniform3f(location, val.x, val.y, val.z);

}
void Shader::compile(const std::string& source, const std::string& name, ShaderType type)
{
	// Read File
	std::ifstream shaderSrcInput;
	std::stringstream shaderStream;

	shaderSrcInput.open(source);

	shaderStream << shaderSrcInput.rdbuf();

	shaderSrcInput.close();

	if(name == "VERTEX")
	{
		this->vshProgram = glCreateShader(type);
	}

	if(name == "FRAGMENT")
	{
		this->fshProgram = glCreateShader(type);
	}


	std::string vString = shaderStream.str();
	const char* vShader = vString.c_str();

	if(name == "VERTEX")
	{
		glShaderSource(this->vshProgram, 1, &vShader, NULL);
		glCompileShader(this->vshProgram);
		this->checkCompileErrors(this->vshProgram, name);
	}

	if(name == "FRAGMENT")
	{
		glShaderSource(this->fshProgram, 1, &vShader, NULL);
		glCompileShader(this->fshProgram);
		this->checkCompileErrors(this->fshProgram, name);
	}
	// TODO Add errors

	// glAttachShader(this->program, this->vshProgram);
	// glAttachShader(this->program, this->fshProgram);
	// glLinkProgram(this->program);
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
