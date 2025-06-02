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

	// Read File
	std::ifstream vertexInput;
	std::stringstream vertexStream;

	vertexInput.open(this->vshSource);
	vertexStream << vertexInput.rdbuf();
	vertexInput.close();

	this->vshProgram = glCreateShader(GL_VERTEX_SHADER);

	std::string vString = vertexStream.str();
	const char* vShader = vString.c_str();

	// TODO Add errors
	glShaderSource(this->vshProgram, 1, &vShader, NULL);
	glCompileShader(this->vshProgram);

	this->checkCompileErrors(this->vshProgram, "VERTEX");

	// FRAGMENT SHADER

	// Read File
	std::ifstream fragmentInput;
	std::stringstream fragmentStream;

	fragmentInput.open(this->vshSource);
	fragmentStream << fragmentInput.rdbuf();
	fragmentInput.close();

	this->vshProgram = glCreateShader(GL_VERTEX_SHADER);

	std::string fString = fragmentStream.str();
	const char* fShader = vString.c_str();
	this->fshProgram = glCreateShader(GL_FRAGMENT_SHADER);

	// TODO Add errors
	glShaderSource(this->fshProgram, 1, &fShader, NULL);
	glCompileShader(this->fshProgram);
	this->checkCompileErrors(this->fshProgram, "FRAGMENT");

	this->program = glCreateProgram();

	glAttachShader(this->program, this->vshProgram);
	glAttachShader(this->program, this->fshProgram);
	glLinkProgram(this->program);

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
