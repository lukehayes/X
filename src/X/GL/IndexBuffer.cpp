#include "X/GL/IndexBuffer.h"

namespace X::GL
{
	IndexBuffer::IndexBuffer(
		std::vector<unsigned int> data
	) {
		glGenBuffers(1, &this->id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(data.at(0)) * data.size(), data.data(), GL_STATIC_DRAW);
	}
}
