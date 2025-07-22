#include "X/GL/VertexBuffer.h"


void VertexBufferMake(X::GL::VertexBuffer* buffer, X::GL::BufferType bufferType)
{
	glGenVertexArrays(1, &buffer->vertexArrayObject);
	glBindVertexArray(buffer->vertexArrayObject);

	glGenBuffers(1, &buffer->vertexBufferObject);
	glBindBuffer(bufferType,buffer->vertexBufferObject);

	glGenBuffers(1, &buffer->indexBufferObject);
	glBindBuffer(bufferType, buffer->indexBufferObject);
}

void VertexBufferSetData(X::GL::VertexBuffer* buffer, X::GL::BufferType bufferType)
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

	// Triangle Data
	//static const GLfloat data[] = {
	    //-0.5f, -0.5f, 0.0f,
	     //0.5f, -0.5f, 0.0f,
	     //0.0f,  0.5f, 0.0f
	//};


	// VERTEX BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, buffer->vertexBufferObject);

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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer->indexBufferObject);
	unsigned int indices[] = {
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	glBufferData (
		GL_ELEMENT_ARRAY_BUFFER,
		sizeof(data),
		indices,
		GL_STATIC_DRAW
	);
}
