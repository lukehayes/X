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
	};
}

void VertexBufferMake(X::GL::VertexBuffer* buffer);


#endif // !GL_VERTEXBUFFER_H
