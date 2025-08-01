#include "X/GL/VertexBuffer.h"

#include <algorithm>
#include <print>

namespace X::GL
{


VertexBuffer::VertexBuffer()
{
	this->Create();
	this->SetData();
	std::println("Vertext Buffer Created");
}

VertexBuffer::VertexBuffer(const VertexBuffer&& rhs)
	: vertexBufferObject(rhs.vertexBufferObject),
	indexBufferObject(rhs.indexBufferObject)
{
	std::println("Move copy");
}

VertexBuffer&
VertexBuffer::operator=(const VertexBuffer&& rhs)
{
	if (this != &rhs)
	{
		std::println("Move assign");
		this->Release();
		std::swap(vertexBufferObject, const_cast<GLuint&>(rhs.vertexBufferObject));
		std::swap(indexBufferObject,  const_cast<GLuint&>(rhs.indexBufferObject));
	}

	return *this;
}

VertexBuffer::~VertexBuffer()
{
	this->Release();

	std::println("Vertex Buffer Deleted");
}

void
VertexBuffer::Release()
{
	glDeleteBuffers(1, &vertexBufferObject);
	vertexBufferObject = 0;

	glDeleteBuffers(1, &indexBufferObject);
	indexBufferObject = 0;

}



void
VertexBuffer::Create()
{
	glGenBuffers(1, &this->vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER ,this->vertexBufferObject);

	glGenBuffers(1, &this->indexBufferObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexBufferObject);
}

void
VertexBuffer::SetData()
{
	GLuint index         = X::GL::VTX_ATTRIB_POSITION;
	GLuint size          = 3;
	GLenum type          = GL_FLOAT;
	GLboolean normalized = GL_FALSE;
	GLuint stride        = 0;
	GLvoid* pointer      = (void*)0;

	glVertexAttribPointer(
		index,
		size,
		type,
		normalized,
		stride,
		pointer
	);

	glEnableVertexAttribArray(index);

	// VERTEX this
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferObject);

	// Square Data
	static const GLfloat data[] = {
		0.5f,  0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	glBufferData (
		GL_ARRAY_BUFFER,
		sizeof(data),
		data,
		GL_STATIC_DRAW
	);

	// ELEMENT_BUFFER
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexBufferObject);
	unsigned int indices[] = {
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	glBufferData (
		GL_ELEMENT_ARRAY_BUFFER,
		sizeof(indices),
		//sizeof(indices),
		indices,
		GL_STATIC_DRAW
	);
}

VertexBuffer
VertexBuffer::Make(
	GLuint idx,
	GLuint sz,
	const std::vector<float>& data,
	const std::vector<unsigned int>& indices
)
{

	VertexBuffer buffer;

	GLuint index         = idx;
	GLuint size          = sz;
	GLenum type          = GL_FLOAT;
	GLboolean normalized = GL_FALSE;
	GLuint stride        = 0;
	GLvoid* pointer      = (void*)0;

	glVertexAttribPointer(
		index,
		size,
		type,
		normalized,
		stride,
		pointer
	);

	glEnableVertexAttribArray(index);
	glBindBuffer(GL_ARRAY_BUFFER, buffer.vertexBufferObject);

	glBufferData (
		GL_ARRAY_BUFFER,
		sizeof(data.at(0)) * data.size(),
		data.data(),
		GL_STATIC_DRAW
	);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer.indexBufferObject);

	glBufferData (
		GL_ELEMENT_ARRAY_BUFFER,
		sizeof(data.at(0)) * data.size(),
		indices.data(),
		GL_STATIC_DRAW
	);

	return buffer;
}

}
