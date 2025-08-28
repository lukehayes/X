#include "X/GL/IndexBuffer.h"

namespace X::GL
{
IndexBuffer::IndexBuffer(
	std::vector<unsigned int>& data
) : data(data)
{
	glGenBuffers(1, &this->id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->data.at(0)) * this->data.size(), this->data.data(), GL_STATIC_DRAW);
}


void
IndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
}

void
IndexBuffer::UnBind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


}
