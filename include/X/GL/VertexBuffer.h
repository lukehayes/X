#ifndef GL_VERTEXBUFFER_H
#define GL_VERTEXBUFFER_H

#include "glad/glad.h"
#include <vector>
#include <cstdint>

namespace X::GL
{

constexpr std::uint8_t ATTRIB_VERTEX_POSITION = 0;
constexpr std::uint8_t ATTRIB_VERTEX_COUNT    = 3;
constexpr std::uint8_t ATTRIB_STRIDE          = 0;

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

	VertexBuffer(const VertexBuffer& rhs) = delete;
	VertexBuffer& operator=(const VertexBuffer& rhs) = delete;

	VertexBuffer(VertexBuffer&& rhs) = default;
	VertexBuffer& operator=(VertexBuffer&& rhs) = default;

	~VertexBuffer();

	void Bind();
	void UnBind();
	void Destroy();

	std::vector<GLfloat> data;
	GLuint id;
	GLenum buffer_type;

};
}


#endif // !GL_VERTEXBUFFER_H
