#include "X/GL/VertexBuffer.h"


void VertexBufferMake(X::GL::VertexBuffer* buffer)
{
	glGenVertexArrays(1, &buffer->vertexArrayObject);
	glBindVertexArray(buffer->vertexArrayObject);

	glGenBuffers(1, &buffer->vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER,buffer->vertexBufferObject);
}

void VertexBufferSetData(X::GL::VertexBuffer* buffer)
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

	static const GLfloat data[] = {
	   -1.0f, -1.0f, 0.0f,
	   1.0f, -1.0f, 0.0f,
	   0.0f,  1.0f, 0.0f,
	};

	glBufferData (
		GL_ARRAY_BUFFER,
		sizeof(data),
		data,
		GL_STATIC_DRAW
	);
}
