#ifndef X_GL_GLPROGRAM
#define X_GL_GLPROGRAM

#include "X/Math/GLM.h"
#include "X/GL/VertexAttribute.h"
#include "X/Gfx/Color.h"
#include "glad/glad.h"
#include <vector>

namespace X::GL
{
struct GLProgram
{
	GLuint vao;
	GLuint vbo;
	GLuint ibo;
};

inline GLProgram GLProgramCreate()
{
	GLProgram program;

	return program;
}

void SetVertexArray(X::GL::GLProgram* program, int count = 1)
{
	glGenVertexArrays(count, &program->vao);
	glBindVertexArray(program->vao);
}

void SetVertexBuffer(X::GL::GLProgram* program, int count = 1)
{
	glGenBuffers(count, &program->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, program->vbo);
}


void SetIndexBuffer(X::GL::GLProgram* program, const std::vector<unsigned int> indices)
{
	glGenBuffers(1, &program->ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, program->ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices.at(0)) * indices.size(), indices.data(), GL_STATIC_DRAW);
}

void SetBufferData(GLenum bufferType, const std::vector<float> data)
{
	glBufferData(
		bufferType,
		sizeof(data.at(0)) * data.size(),
		data.data(),
		GL_STATIC_DRAW
	);
}

X::GL::GLProgram* buildGL(X::GL::GLProgram* program, const X::Gfx::Color color)
{
    std::vector<GLfloat> vertices = {
		0.5f,  0.5f,  0.0f, color.r, color.g, color.b,
		0.5f,  -0.5f, 0.0f, color.r, color.g, color.b,
        -0.5f, -0.5f, 0.0f, color.r, color.g, color.b,
		-0.5f, 0.5f,  0.0f, color.r, color.g, color.b

	};

	X::GL::SetVertexArray(program);
	X::GL::SetVertexBuffer(program);

	X::GL::SetBufferData(
		GL_ARRAY_BUFFER,
		vertices
	);

	X::GL::SetVertexAttribute(
		0,
		3,
		6,
		0
	);


	X::GL::SetVertexAttribute(
		1,
		3,
		6,
		3
	);



	std::vector<unsigned int> indices = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};


	X::GL::SetIndexBuffer(program, indices);

	return program;
}


void DeleteGLProgram(X::GL::GLProgram* program)
{
	glDeleteVertexArrays(1, &program->vao);
	glDeleteBuffers(1, &program->vbo);
	glDeleteBuffers(1, &program->ibo);
}


}

#endif // X_GL_GLPROGRAM
