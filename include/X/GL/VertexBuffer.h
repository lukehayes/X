#ifndef GL_VERTEXBUFFER_H
#define GL_VERTEXBUFFER_H

#include "glad/glad.h"

namespace X::GL
{
class VertexBuffer
{
	public:

	VertexBuffer();
	VertexBuffer(const VertexBuffer& rhs) = delete;
	VertexBuffer& operator=(const VertexBuffer& rhs) = delete;

	VertexBuffer(const VertexBuffer&& rhs);
	VertexBuffer& operator=(const VertexBuffer&& rhs);


	~VertexBuffer();


	void Create();
	void SetData();
	void Release();


	GLuint vertexArrayObject;
	GLuint vertexBufferObject;
	GLuint indexBufferObject;
};
}


#endif // !GL_VERTEXBUFFER_H
