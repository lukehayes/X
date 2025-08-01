#ifndef X_GL_VERTEX_BUFFER_H
#define X_GL_VERTEX_BUFFER_H

#include "glad/glad.h"
#include <print>

namespace X::GL
{

class VertexArray
{
public:

	VertexArray();
	~VertexArray();

	VertexArray(VertexArray&& other);
	VertexArray& operator=(VertexArray&& other);

	VertexArray(const VertexArray& other) = delete;
	VertexArray& operator=(VertexArray& other) = delete;

	GLuint id;

};

}





#endif // !X_GL_VERTEX_BUFFER_H
