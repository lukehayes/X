#include "X/GL/VertexArray.h"

namespace X::GL
{

VertexArray::VertexArray()  {
	glGenVertexArrays(1, &this->id);
}

VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &this->id);
}

VertexArray::VertexArray(VertexArray&& other)
: id(other.id) {}

VertexArray&
VertexArray::operator=(VertexArray&& other) {

	if (this == &other) return *this;

	this->id = other.id;

	return *this;
}

void
VertexArray::Bind()
{
	glBindVertexArray(this->id);
}
}
