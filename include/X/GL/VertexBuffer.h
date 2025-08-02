#ifndef GL_VERTEXBUFFER_H
#define GL_VERTEXBUFFER_H

#include "glad/glad.h"
#include <vector>
#include <cstdint>

namespace X::GL
{

class VertexBuffer
{
public:

	VertexBuffer(
		std::uint8_t attrib_position,
		std::uint8_t vtx_size,
		std::uint8_t vtx_stride,
		const std::vector<GLfloat>& data,
		GLenum buffer_type
	);

	VertexBuffer();
	VertexBuffer(const VertexBuffer& rhs) = delete;
	VertexBuffer& operator=(const VertexBuffer& rhs) = delete;

	VertexBuffer(const VertexBuffer&& rhs);
	VertexBuffer& operator=(const VertexBuffer&& rhs);

	~VertexBuffer();

	void Bind();
	void UnBind();
	void Destroy();

	GLuint id;
};
}


#endif // !GL_VERTEXBUFFER_H
