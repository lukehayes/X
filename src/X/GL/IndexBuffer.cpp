#include "X/GL/IndexBuffer.h"
#include <print>

namespace X::GL
{
IndexBuffer::IndexBuffer(
	std::vector<unsigned int>& data
) : data(data)
{
	glGenBuffers(1, &this->id);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 
				 sizeof(this->data.at(0)) * this->data.size(),
				  this->data.data(), GL_STATIC_DRAW);
}

void
IndexBuffer::Bind()
{
	std::println("Index Buffer Bound");
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
}

void
IndexBuffer::UnBind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void
IndexBuffer::SetIndexBuffer()
{
	std::println("Setting Buffer for ibo {}", this->id);

	glGenBuffers(1, &id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->data.at(0)) * this->data.size(), this->data.data(), GL_STATIC_DRAW);


}


}
