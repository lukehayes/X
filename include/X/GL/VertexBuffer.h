#ifndef GL_VERTEXBUFFER_H
#define GL_VERTEXBUFFER_H

#include "X/GL/BufferType.h"

#include "glad/glad.h"

namespace X::GL
{
class VertexBuffer
{
	public:
	GLuint vertexArrayObject;
	GLuint vertexBufferObject;
	GLuint indexBufferObject;
};
}

void VertexBufferMake(X::GL::VertexBuffer* buffer, X::GL::BufferType bufferType);
void VertexBufferSetData(X::GL::VertexBuffer* buffer, X::GL::BufferType bufferType);


#endif // !GL_VERTEXBUFFER_H
