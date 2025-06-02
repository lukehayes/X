#include "X/GL/VertexBuffer.h"


void VertexBufferMake(X::GL::VertexBuffer* buffer)
{
	glGenVertexArrays(1, &buffer->vertexArrayObject);
	glBindVertexArray(buffer->vertexArrayObject);


	glGenBuffers(1, &buffer->vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER,buffer->vertexBufferObject);

}
