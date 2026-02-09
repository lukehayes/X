#include "X/GL/VertexBuffer.h"
#include "glad/glad.h"
#include <print>

namespace X::GL
{

VertexBuffer::VertexBuffer(
	const std::vector<GLfloat>& data,
	GLenum buffer_type
) : data(data), bufferType(buffer_type)
{
	glBindBuffer(GL_ARRAY_BUFFER, this->id);
	this->bufferType = buffer_type;
}

VertexBuffer::~VertexBuffer()
{
	this->Destroy();
	std::println("Vertex Buffer Deleted");
}

void 
VertexBuffer::SetBufferData()
{
	glBufferData(
		this->bufferType,
		sizeof(this->data.at(0)) * this->data.size(),
		this->data.data(),
		GL_STATIC_DRAW
	);
}

void 
VertexBuffer::SetVertexAttribute(int vertex_position,int vertex_size, int vertex_stride, int vertex_offset)
{

	// std::println("Vertex Position {}", vertex_position);
	// std::println("Vertex Size {}", vertex_size);
	// std::println("Vertex Stride {}", vertex_stride);
	// std::println("Vertex Offset {}", vertex_offset);
	std::println("Setting Vertex Attribute {}", vertex_position);
	std::println("----------------------------------------");



	glVertexAttribPointer(
		vertex_position,
		vertex_size,
		GL_FLOAT,
		GL_FALSE,
		sizeof(float) * vertex_stride,
		(void*)(sizeof(float) * vertex_offset)
	);

	glEnableVertexAttribArray(vertex_position);

}

void
VertexBuffer::Bind()
{
	std::println("Bind VBO");
	glBindBuffer(this->bufferType, this->id);
}

void
VertexBuffer::UnBind()
{
	std::println("UnBind VBO");
	glBindBuffer(this->bufferType, 0);
}

void
VertexBuffer::Destroy()
{
}

}
