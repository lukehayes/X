#ifndef X_GL_GENERIC_BUFFER_H
#define X_GL_GENERIC_BUFFER_H

#include "glad/glad.h"
#include <vector>

namespace X::GL
{

class IndexBuffer
{
public:

	IndexBuffer() = delete;

	IndexBuffer(
		std::vector<unsigned int>& data
	);

	void Bind();
	void UnBind();
	void SetIndexBuffer();
	
	// TODO Refactor this part later
	std::vector<unsigned int> data;
	GLuint id;
};
}



#endif // !X_GL_GENERIC_BUFFER_H
