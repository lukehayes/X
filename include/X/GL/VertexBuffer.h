#ifndef GL_VERTEXBUFFER_H
#define GL_VERTEXBUFFER_H

#include "glad/glad.h"

namespace X::GL
{
class VertexBuffer
{
	public:

	VertexBuffer();
	~VertexBuffer();

	void Create();
	void SetData();


	GLuint vertexArrayObject;
	GLuint vertexBufferObject;
	GLuint indexBufferObject;
};
}


#endif // !GL_VERTEXBUFFER_H
