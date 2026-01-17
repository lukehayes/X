#ifndef X_GL_GLPROGRAM
#define X_GL_GLPROGRAM


#include "X/Math/GLM.h"
#include "X/GL/VertexBuffer.h"
#include "X/GL/Shader.h"

namespace X::GL
{
struct GLProgram
{
	GLProgram() {}
	glm::mat4 projection;
	glm::mat4 view;

	X::GL::Shader shader;
	X::GL::VertexBuffer buffer;

};

inline GLProgram GLProgramCreate()
{
	GLProgram program;


	return program;
}

void buildGL()
{
    std::vector<GLfloat> vertices = {
		0.5f,  0.5f,  0.0f,
		0.5f,  -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f,  0.0f
	};

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	int vertex_size        = 3;
	int vertex_stride      = 0;
	GLenum dataType        = GL_FLOAT;
	GLboolean isNormalized = GL_FALSE;
	GLvoid* pointer        = (void*)0;

	glEnableVertexAttribArray(X::GL::ATTRIB_VERTEX_POSITION);

	glVertexAttribPointer(
		X::GL::ATTRIB_VERTEX_POSITION,
		vertex_size,
		dataType,
		isNormalized,
		vertex_stride,
		pointer
	);

	glBufferData(
		GL_ARRAY_BUFFER,
		sizeof(vertices.at(0)) * vertices.size(),
		vertices.data(),
		GL_STATIC_DRAW
	);


	std::vector<unsigned int> indices = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	GLuint ibo;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices.at(0)) * indices.size(), indices.data(), GL_STATIC_DRAW);
}


}

#endif // X_GL_GLPROGRAM
