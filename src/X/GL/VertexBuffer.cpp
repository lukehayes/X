#include "X/GL/VertexBuffer.h"

#include <print>

namespace X::GL
{

VertexBuffer::VertexBuffer() {}

VertexBuffer::VertexBuffer(
	std::uint8_t attrib_position,
	std::uint8_t vertex_size,
	std::uint8_t vertex_stride,
	const std::vector<GLfloat>& data,
	GLenum buffer_type
) {

	glGenBuffers(1, &this->id);
	glBindBuffer(buffer_type, this->id);

	GLenum type          = GL_FLOAT;
	GLboolean normalized = GL_FALSE;
	GLvoid* pointer      = (void*)0;

	glEnableVertexAttribArray(attrib_position);

	glVertexAttribPointer(
		attrib_position,
		vertex_size,
		type,
		normalized,
		vertex_stride,
		pointer
	);

	glBufferData(buffer_type, sizeof(data.at(0)) * data.size(), data.data(), GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
	//this->Destroy();
	std::println("Vertex Buffer Deleted");
}

void
VertexBuffer::Destroy()
{
	glDeleteBuffers(1, &this->id);
	this->id = 0;
}

}
