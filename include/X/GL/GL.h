#ifndef X_GL_GL_H
#define X_GL_GL_H

#include "glad/glad.h"
#include <vector>

namespace X::GL
{
	enum BufferType
	{
		ARRAY_BUFFER         = GL_ARRAY_BUFFER,
		ELEMENT_ARRAY_BUFFER = GL_ELEMENT_ARRAY_BUFFER
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
		glBindVertexArray(glState->vao);
	}

	void GenerateVertexBuffer(GL* glState, int count = 1)
	{
		glBindBuffer(GL_ARRAY_BUFFER, glState->vbo);
		glGenBuffers(count, &glState->vbo);
	}

	void GenerateIndexBuffer(GL* glState, int count = 1)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glState->ibo);
		glGenBuffers(count, &glState->ibo);
	}

	template<class T>
	void SetBufferData(BufferType bufferType, GLuint buffer, const std::vector<T> data)
	{
		glBindBuffer(bufferType, buffer);
		glBufferData(
			bufferType,
			sizeof(T) * data.size(),
			data.data(),
			GL_STATIC_DRAW
		);
	}

	void SetVertexAttribute(int position, int size, int stride, int pointer )
	{
		glVertexAttribPointer(position,size,GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(sizeof(float) * pointer));
		glEnableVertexAttribArray(position);
	}
}




#endif  // X_GL_GL_H
