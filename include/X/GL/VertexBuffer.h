#ifndef GL_VERTEXBUFFER_H
#define GL_VERTEXBUFFER_H

#include "glad/glad.h"
#include <vector>

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

	static VertexBuffer Make(
		GLuint idx,
		GLuint sz,
		const std::vector<float>& data,
		const std::vector<unsigned int>& indices
	);

	void Create();
	void SetData();
	void Release();


	GLuint vertexArrayObject;
	GLuint vertexBufferObject;
	GLuint indexBufferObject;
};
}


#endif // !GL_VERTEXBUFFER_H
