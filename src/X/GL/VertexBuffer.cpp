#include "X/GL/VertexBuffer.h"
#include <print>

namespace X::GL
{

VertexBuffer::VertexBuffer(
	const std::vector<GLfloat>& data,
	GLenum buffer_type
) : data(data), bufferType(buffer_type)
{

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
	glBindBuffer(this->bufferType, this->id);
}

void
VertexBuffer::UnBind()
{
	glBindBuffer(this->bufferType, 0);
}

void
VertexBuffer::Destroy()
{
	glDeleteBuffers(1, &this->id);
	this->id = 0;
}

}
