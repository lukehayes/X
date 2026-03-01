#ifndef X_MESH__QUADMESH_H
#define X_MESH__QUADMESH_H


#include "glad/glad.h"
#include <vector>

namespace X::Mesh
{
class QuadMesh
{
public:
	QuadMesh(const std::vector<float> vertices, const std::vector<unsigned int> indices)
	: vertices(vertices), indices(indices)
	{ this->Generate(); }

	QuadMesh() { this->Generate(); }

	void Generate()
	{
		glGenVertexArrays(1, &this->vao);
		glGenBuffers(1, &this->vbo);
		glGenBuffers(1, &this->ibo);
	}

	void BindVertexArray()
	{
		glBindVertexArray(this->vao);
	}

	void SetArrayBufferData()
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
		glBufferData(
			GL_ARRAY_BUFFER,
			sizeof(vertices.at(0)) * vertices.size(),
			vertices.data(),
			GL_STATIC_DRAW
		);
	}

	void SetArrayBufferData(const std::vector<float> &data)
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
		glBufferData(
			GL_ARRAY_BUFFER,
			sizeof(data.at(0)) * data.size(),
			data.data(),
			GL_STATIC_DRAW
		);
	}

	void SetElementBufferData()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);
		glBufferData(
			GL_ELEMENT_ARRAY_BUFFER,
			sizeof(indices.at(0)) * indices.size(),
			indices.data(),
			GL_STATIC_DRAW
		);
	}

	void SetElementBufferData(const std::vector<unsigned int> &data)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);
		glBufferData(
			GL_ELEMENT_ARRAY_BUFFER,
			sizeof(data.at(0)) * data.size(),
			data.data(),
			GL_STATIC_DRAW
		);
	}

	void SetAttribPointer(int position, int size, int stride, int pointer)
	{
		glVertexAttribPointer(
			position, 
			size,
			GL_FLOAT,
			GL_FALSE,
			sizeof(float) * stride,
			(void*)(sizeof(float) * pointer)
		);
		glEnableVertexAttribArray(position);
	}



private:
	std::vector<float> vertices;
	std::vector<unsigned int> indices;
	GLuint vao;
	GLuint vbo;
	GLuint ibo;
};

}

#endif // X_MESH__QUADMESH_H
