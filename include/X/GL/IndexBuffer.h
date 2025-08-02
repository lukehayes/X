#ifndef X_GL_GENERIC_BUFFER_H

#include "glad/glad.h"
#include <vector>

namespace X::GL
{

class IndexBuffer
{
public:

	IndexBuffer(
		std::vector<unsigned int> data
	) {
		glGenBuffers(1, &this->id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(data.at(0)) * data.size(), data.data(), GL_STATIC_DRAW);
	}


	GLuint id;
};
}



#endif // !X_GL_GENERIC_BUFFER_H
