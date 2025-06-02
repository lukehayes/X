#include "X/GL/VertexBuffer.h"


void MakeVertexBuffer(X::GL::VertexBuffer* buffer)
{
	glGenVertexArrays(1, &buffer->vertexArrayObject);
	glBindVertexArray(buffer->vertexArrayObject);


	glGenBuffers(1, &buffer->vertexBufferObject);
	glBindBuffer(1,buffer->vertexBufferObject);

}
