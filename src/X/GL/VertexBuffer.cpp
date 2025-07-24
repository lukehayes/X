#include "X/GL/VertexBuffer.h"

#include <print>

namespace X::GL
{

VertexBuffer::VertexBuffer()
{
	this->Create();
	this->SetData();
	std::println("Vertext Buffer Created");
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &this->vertexArrayObject);
	glDeleteBuffers(1, &this->vertexBufferObject);
	glDeleteBuffers(1, &this->indexBufferObject);

	std::println("Vertext Buffer Deleted");
}

void
VertexBuffer::Create()
{
	glGenVertexArrays(1, &this->vertexArrayObject);
	glBindVertexArray(this->vertexArrayObject);

	glGenBuffers(1, &this->vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER ,this->vertexBufferObject);

	glGenBuffers(1, &this->indexBufferObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexBufferObject);
}

void
VertexBuffer::SetData()
{
	GLuint index         = 0;
	//GLuint size          = sizeof(GLuint) * 3;
	GLuint size          = 3;
	GLenum type          = GL_FLOAT;
	GLboolean normalized = GL_FALSE;
	GLuint stride        = 0;
	GLvoid* pointer      = (void*)0;

	glVertexAttribPointer(
		index,
		size,
		type,
		normalized,
		stride,
		pointer
	);

	glEnableVertexAttribArray(index);

	// VERTEX this
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferObject);

	// Square Data
	static const GLfloat data[] = {
		0.5f,  0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	glBufferData (
		GL_ARRAY_BUFFER,
		sizeof(data),
		data,
		GL_STATIC_DRAW
	);

	// ELEMENT_BUFFER
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexBufferObject);
	unsigned int indices[] = {
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	glBufferData (
		GL_ELEMENT_ARRAY_BUFFER,
		22,
		//sizeof(indices),
		indices,
		GL_STATIC_DRAW
	);
}

}

