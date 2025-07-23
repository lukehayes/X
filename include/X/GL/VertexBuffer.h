#ifndef GL_VERTEXBUFFER_H
#define GL_VERTEXBUFFER_H

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

void VertexBufferMake(X::GL::VertexBuffer* buffer);
void VertexBufferSetData(X::GL::VertexBuffer* buffer);


#endif // !GL_VERTEXBUFFER_H
