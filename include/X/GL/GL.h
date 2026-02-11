#ifndef X_GL_GL_H
#define X_GL_GL_H

#include "glad/glad.h"

namespace X::GL
{
	enum BufferType
	{
		ARRAY_BUFFER,
		ELEMENT_ARRAY_BUFFER
	};

	struct GL
	{
		GLuint vao;
		GLuint vbo;
		GLuint ibo;
	};

	void GenerateVertexArray(GL* glState, int count = 1)
	{
		glGenVertexArrays(count, &glState->vao);
	}

	void GenerateVertexBuffer(GL* glState, int count = 1)
	{
		glGenBuffers(count, &glState->vbo);
	}

	void GenerateIndexBuffer(GL* glState, int count = 1)
	{
		glGenBuffers(count, &glState->ibo);
	}

	void SetVertexAttribute(int position, int size, int stride, int pointer )
	{
		glVertexAttribPointer(position,size,GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(sizeof(float) * pointer));
		glEnableVertexAttribArray(position);
	}
}




#endif  // X_GL_GL_H
