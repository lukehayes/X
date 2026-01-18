#ifndef X_GL_GLPROGRAM
#define X_GL_GLPROGRAM

#include "X/Math/GLM.h"
#include "X/GL/VertexAttribute.h"
#include "glad/glad.h"
#include <vector>

namespace X::GL
{
struct GLProgram
{
};

inline GLProgram GLProgramCreate()
{
	GLProgram program;

	return program;
}

GLuint SetVertexArray(int count = 1)
{
	GLuint vao;
	glGenVertexArrays(count, &vao);
	glBindVertexArray(vao);

	return vao;

}

GLuint SetVertexBuffer(int count = 1)
{
	GLuint vbo;

	glGenBuffers(count, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	return vbo;
}


GLuint SetIndexBuffer(const std::vector<unsigned int> indices)
{
	GLuint ibo;

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices.at(0)) * indices.size(), indices.data(), GL_STATIC_DRAW);

	return ibo;
}

void SetBufferData(GLenum bufferType, const std::vector<float> data)
{
	glBufferData(
		bufferType,
		sizeof(data.at(0)) * data.size(),
		data.data(),
		GL_STATIC_DRAW
	);
}

void buildGL()
{
    std::vector<GLfloat> vertices = {
		0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f,
		0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, 0.5f,  0.0f, 0.0f, 1.0f, 1.0f

	};


	X::GL::SetVertexArray();
	X::GL::SetVertexBuffer();

	X::GL::SetBufferData(
		GL_ARRAY_BUFFER,
		vertices
	);

	X::GL::SetVertexAttribute(
		0,
		3,
		6,
		0
	);


	X::GL::SetVertexAttribute(
		1,
		3,
		6,
		3
	);



	std::vector<unsigned int> indices = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};


	X::GL::SetIndexBuffer(indices);
}



}

#endif // X_GL_GLPROGRAM
