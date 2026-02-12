#ifndef X_GL_GL_H
#define X_GL_GL_H

#include "glad/glad.h"
#include <vector>
#include <print>

namespace X::GL
{
	enum BufferType
	{
		ARRAY_BUFFER         = GL_ARRAY_BUFFER,
		ELEMENT_ARRAY_BUFFER = GL_ELEMENT_ARRAY_BUFFER
	};

	struct GLState
	{
		GLuint vao;
		GLuint vbo;
		GLuint ibo;
		std::vector<float> verticies;
		std::vector<unsigned int> indices;
	};

	void GenerateVertexArray(GLState* glState, int count = 1)
	{
		glGenVertexArrays(count, &glState->vao);
		glBindVertexArray(glState->vao);
	}

	void GenerateVertexBuffer(GLState* glState, int count = 1)
	{
		glBindBuffer(GL_ARRAY_BUFFER, glState->vbo);
		glGenBuffers(count, &glState->vbo);
	}

	void GenerateIndexBuffer(GLState* glState, int count = 1)
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


	void PrintGLState(const GLState& glState)
	{
		std::println("---------------------");
		std::println("GLState:");
		std::println(" ");
		std::println("VAO: {}", glState.vao );
		std::println("VBO: {}", glState.vbo );
		std::println("IBO: {}", glState.ibo );
		std::println("---------------------");

	}
}




#endif  // X_GL_GL_H
