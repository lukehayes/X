#ifndef GL_VERTEXBUFFER_H
#define GL_VERTEXBUFFER_H

#include "glad/glad.h"
#include <vector>
#include <cstdint>

namespace X::GL
{

constexpr std::uint8_t ATTRIB_VERTEX_POSITION = 0;
constexpr std::uint8_t ATTRIB_VERTEX_COLOR    = 1;
constexpr std::uint8_t ATTRIB_VERTEX_COUNT    = 3;
constexpr std::uint8_t ATTRIB_STRIDE          = 6;

class VertexBuffer
{
public:

    VertexBuffer(
		const std::vector<GLfloat>& data,
		GLenum buffer_type
    );

    VertexBuffer(const VertexBuffer& rhs) = delete;
    VertexBuffer& operator=(const VertexBuffer& rhs) = delete;

    VertexBuffer(VertexBuffer&& rhs) = default;
    VertexBuffer& operator=(VertexBuffer&& rhs) = default;

    ~VertexBuffer();

    /**
    * Load the vertex data into the buffef.
    */
	void SetBufferData();

    /**
    * Set the buffers vertex attribute pointer.
    */
	void SetVertexAttribute(int vertex_position,int vertex_size, int vertex_stride, int vertex_offset);

    /**
    * Bind the vertex buffer.
    */
    void Bind();

    /**
    * Unbind the vertex buffer.
    */
    void UnBind();

    /**
    * Destroy the vertex buffer.
    */
    void Destroy();

    std::vector<GLfloat> data;
	GLenum bufferType;
    GLuint id;

};
}


#endif // !GL_VERTEXBUFFER_H
