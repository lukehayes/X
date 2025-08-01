#ifndef X_GL_GENERIC_BUFFER_H

#include "glad/glad.h"
#include <cstdint>

namespace X::GL
{
class GenericBuffer
{
public:

	GenericBuffer(
		std::uint8_t vtx_size,
		std::uint8_t vtx_stride,
		GLfloat data[],
		GLenum buffer_type
	) {
		glGenBuffers(1, &this->id);
		glBindBuffer(buffer_type, this->id);

	GLuint index         = X::GL::VTX_ATTRIB_POSITION;
	GLuint size          = 3;
	GLenum type          = GL_FLOAT;
	GLboolean normalized = GL_FALSE;
	GLuint stride        = 0;
	GLvoid* pointer      = (void*)0;

		glVertexAttribPointer(
			X::GL::VTX_ATTRIB_POSITION,

		)
	}


	GLuint id;
};
}



#endif // !X_GL_GENERIC_BUFFER_H
